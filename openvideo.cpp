#define _CRT_SECURE_NO_WARNINGS
#define OPENCV
#define GPU
#include "openvideo.h"
#include <stdio.h>
#include <iostream>
#include "string.h"
#include"Windows.h"
#include<time.h>
#include <sstream>
#include<thread>
#include "Wininet.h"  
#include "ui_openvideo.h"
//#include"yolo_v2_class.hpp"
#include<tchar.h>
#include <mutex>
//#include <opencv2/opencv.hpp>
#include <ctime>
#include <vector>
#include<fstream>
#include<math.h>
#include"polylines.h"
#include "density.h"
#include"lk.h"
#pragma comment(lib,"wininet.lib")
#pragma comment(lib,"yolo_cpp_dll.lib")

using namespace cv;
using namespace std;
struct img_channel
{
	Mat image;
	string   channel;
	int i;
	
};
struct channel_num
{
	string  channel;
	int     num;
	int i;
	bool highdense;
};

Rect danger[10];
int odd = 0;
int o=25 ;
queue<img_channel> igc;
queue<channel_num> cnu;
string strResponse;
mutex mtx;
Density dense;
condition_variable decond, encond,mecond;
bool playend = false;
QString mo;
std::vector<std::string>  obj_names,head_names;
bool select_flag = false;
Mat masks[10];
std::vector<std::vector<std::vector<cv::Point>>> contours(10);
int finish[10];//读mask完成
int a[10] = {0};//画区域完成
lktrack lk[10] = {};
int tracking[10] = {0};
void A_on_Mouse0(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[0].x = x;
		danger[0].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[0].width= x-danger[0].x;
		danger[0].height= y-danger[0].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
string  rtsp2channel(QString rtsp)
{
	string s = rtsp.toStdString();
	int wen = s.find('?');
	string sub = s.substr(wen + 1, s.length() - wen - 1);
	int cha = sub.find("channel=");
	
	string sub1 = sub.substr(cha+8,sub.length()-cha-8);
	int jie = sub1.find('&');
	sub1 = sub1.substr(0,jie);
	return sub1;
}
std::string HttpRequest(char * lpHostName, short sPort, char * lpUrl, char * lpMethod, char * lpPostData, int nPostDataLen)
{
	WCHAR iphostName[256];
	std::memset(iphostName, 0, sizeof(iphostName));
	MultiByteToWideChar(CP_ACP, 0, lpHostName, strlen(lpHostName) + 1, iphostName,
		sizeof(iphostName) / sizeof(iphostName[0]));
	WCHAR ipmethod[256];
	std::memset(ipmethod, 0, sizeof(ipmethod));
	MultiByteToWideChar(CP_ACP, 0, lpMethod, strlen(lpMethod) + 1, ipmethod,
		sizeof(ipmethod) / sizeof(ipmethod[0]));
	WCHAR ipurl[256];
	std::memset(ipurl, 0, sizeof(ipurl));
	MultiByteToWideChar(CP_ACP, 0, lpUrl, strlen(lpUrl) + 1, ipurl,
		sizeof(ipurl) / sizeof(ipurl[0]));

	HINTERNET hInternet, hConnect = NULL, hRequest = NULL;

	BOOL bRet;
	std::string strResponse;

	hInternet = (HINSTANCE)InternetOpen(L"User-Agent", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (!hInternet)
		goto Ret0;

	hConnect = (HINSTANCE)InternetConnect(hInternet,iphostName, sPort, NULL, L"HTTP/1.1", INTERNET_SERVICE_HTTP, 0, 0);
	if (!hConnect)
		goto Ret0;

	hRequest = (HINSTANCE)HttpOpenRequest(hConnect, ipmethod, ipurl, L"HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, 0);
	if (!hRequest)
		goto Ret0;

	//bRet = HttpAddRequestHeaders(hRequest,"Content-Type: application/x-www-form-urlencoded",Len(FORMHEADERS),HTTP_ADDREQ_FLAG_REPLACE | HTTP_ADDREQ_FLAG_ADD);  
	//if(!bRet)  
	//goto Ret0;  

	bRet = HttpSendRequest(hRequest, NULL, 0, lpPostData, nPostDataLen);
	while (TRUE)
	{
		char cReadBuffer[4096];
		unsigned long lNumberOfBytesRead;
		bRet = InternetReadFile(hRequest, cReadBuffer, sizeof(cReadBuffer) - 1, &lNumberOfBytesRead);
		if (!bRet || !lNumberOfBytesRead)
			break;
		cReadBuffer[lNumberOfBytesRead] = 0;
		strResponse = strResponse + cReadBuffer;
	}

Ret0:
	if (hRequest)
		InternetCloseHandle(hRequest);
	if (hConnect)
		InternetCloseHandle(hConnect);
	if (hInternet)
		InternetCloseHandle(hInternet);

	return strResponse;
}
bool askhttp(string str_url, string parkcode, string channelcode, int num, bool debug)
{
	if (str_url.size() <7)
		return false;
	//分解url
	string sub1 = str_url.substr(7, str_url.length() - 7);
	int l = sub1.find(':');
	if (l<0)
		return false;
	string str_ip = sub1.substr(0, l);
	int l2 = sub1.find('/');
	if (l2<0)
		return false;
	string str_port = sub1.substr(l + 1, l2 - l - 1);
	string url = sub1.substr(l2, sub1.length() - l2);

	/*char a[10];
	sprintf_s(a, "%d", status);
	string status_t = a;*/
#ifdef _WIN32
	short uport = atoi(str_port.c_str());

	string sendData = url + "?" + "parkcode=" + parkcode + "&" + "channelcode=" + channelcode + "&" + "num=" + to_string(num);
	 strResponse = HttpRequest(const_cast<char *>(str_ip.c_str()), uport, const_cast<char *>(sendData.c_str()), "GET", NULL, 0);
	
	return true;
#else
	/*
	string sub1 = str_url.substr(7, str_url.length() - 7);
	int l = sub1.find(':');
	if (l<0)
	return false;
	string str_ip = sub1.substr(0, l);
	int l2 = sub1.find('/');
	if (l2<0)
	return false;
	string str_port = sub1.substr(l + 1, l2 - l - 1);
	string url = sub1.substr(l2, sub1.length() - l2);
	*/
	int sockfd, ret, i, h;
	struct sockaddr_in servaddr;
	char str1[4096], str2[4096], buf[4096], *str;
	socklen_t len;
	fd_set t_set1;
	struct timeval tv;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("创建网络连接失败,本线程即将终止---socket error!\n");
		return false;
	};

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	int port_i = atoi(str_port.c_str());
	servaddr.sin_port = htons(port_i);
	if (inet_pton(AF_INET, str_ip.c_str(), &servaddr.sin_addr) <= 0) {
		printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
		return false;
	};

	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		printf("连接到服务器失败,connect error!\n");
		return false;
	}
	if (debug) {
		printf("与远端建立了连接\n");
	}
	char tem_c[128];
	string str_tem = "POST " + url + "?code=" + code + "&jobcode=" + jobcode + other;
	sprintf(tem_c, "&status=%d HTTP/1.1\n", status);
	str_tem += tem_c;
	memset(str1, 0, 4096);
	strcat(str1, str_tem.c_str());
	strcat(str1, "Host: www.webxml.com.cn\n");
	strcat(str1, "Content-Type: application/x-www-form-urlencoded\n");
	strcat(str1, "Content-Length: ");
	//发送数据
	memset(str2, 0, 4096);
	strcat(str2, "qqCode=474497857");
	len = strlen(str2);
	sprintf(tem_c, "%d", len);
	strcat(str1, tem_c);
	strcat(str1, "\n\n");
	strcat(str1, str2);
	strcat(str1, "\r\n\r\n");

	if (debug) {
		printf("%s\n", str1);
	}

	ret = write(sockfd, str1, strlen(str1));
	if (ret < 0) {
		printf("发送失败！错误代码是%d，错误信息是'%s'\n", errno, strerror(errno));
		return false;
	}
	else {
		if (debug) {
			printf("消息发送成功，共发送了%d个字节！\n\n", ret);
		}
	}

	FD_ZERO(&t_set1);
	FD_SET(sockfd, &t_set1);

	sleep(2);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	h = select(sockfd + 1, &t_set1, NULL, NULL, &tv);
	if (h < 0) {
		close(sockfd);
		printf("在读取数据报文时SELECT检测到异常，该异常导致线程终止！\n");
		return false;
	};

	if (h > 0) {
		memset(buf, 0, 4096);
		i = read(sockfd, buf, 4095);
		if (i == 0) {
			close(sockfd);
			printf("读取数据报文时发现远端关闭，该线程终止！\n");
			return  false;
		}
		if (debug) {
			printf("读取数据  len:%d\n", i);
			printf("%s\n", buf);
		}
	}
	close(sockfd);
	return true;
#endif
}
int  draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,int ii)
{
	drawContours(mat_img, contours.at(ii), 0, cv::Scalar::all(255), 1);
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
	int hdcount = 0;
	int areanum = 0;
	for (auto &i : result_vec) {

		if (obj_names.size() > i.obj_id) {
			std::string obj_name = obj_names[i.obj_id];
			if (obj_name == "head" || obj_name == "person")
			{
				if (i.w * i.h > 10000)
					hdcount += int(10000.0*sqrt(i.w*i.h) / 20.0 / pow((i.y + 0.5*i.h), 2));
				else  if (i.w < i.h)
					hdcount++;
				else
					continue;
			/*}
			{	*/		
			//if (obj_name == "person")
			
				cv::Scalar color = obj_id_to_color(i.obj_id);
				cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 0.5);
				int foot = i.y + i.h; int left = i.x; int right = i.x + i.w;
				Point foot1 = Point(left, foot); Point foot2 = Point(right, foot);
			
				//contours = py0.contour;
				
				if (a[ii]&&contours.at(ii).size()>0) 
				{
					
					if (pointPolygonTest(contours.at(ii)[0], foot1, false)==1 && pointPolygonTest(contours.at(ii)[0], foot2, false) ==1&& obj_name == "person") {
						cv::putText(mat_img, "danger!", cv::Point2f(10, 100), cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 0, 255), 2);
						areanum++;
					}
				}
				if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
				cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
				int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
				/*cv::rectangle(mat_img, cv::Point2f(max((int)i.x - 1, 0), max((int)i.y - 30, 0)),
					cv::Point2f(min((int)i.x + max_width, mat_img.cols - 1), min((int)i.y, mat_img.rows - 1)),
					color, CV_FILLED, 8, 0);*/
				cv::putText(mat_img, obj_name, cv::Point2f(i.x, i.y), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, color, 1);
			}
		}
	}
	stringstream stream,stream1;
	stream << hdcount;
	string temp = stream.str();
	stream1 << areanum;
	string area = stream1.str();
	string count = "nums:" + temp+"      areanum:"+area;
	cv::putText(mat_img, count, cv::Point2f(0, 15), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(255, 0, 255), 1);
	return hdcount;

}
std::vector<std::string> objects_names_from_file(std::string const filename) {
	std::ifstream file(filename);
	std::vector<std::string> file_lines;
	if (!file.is_open()) return file_lines;
	for (std::string line; getline(file, line);) file_lines.push_back(line);
	std::cout << "object names loaded \n";
	return file_lines;
}
void   playdecetor(QString rtsp,int i)
{
	Mat allframes[10],toframes[10];
	img_channel imgcnnel;
		if(!rtsp.isEmpty()) 
		{
			Mat frame;
			VideoCapture capture;
			int odd = 0;
			capture.open(rtsp.toStdString());//打开摄像头，从摄像头中获取视频
			if (!capture.isOpened())
			{
				//std::cout << "video not open." << std::endl;
			}
			while (true)
			{
				
				for (;;) {
					if (!capture.read(frame)) {
						//std::cout << "No frame" << std::endl;
						capture.open(rtsp.toStdString());
						continue;
					}
					
					resize(frame, frame, Size(640, 360));
					
					if (odd == 0) {
						unique_lock<mutex> lck(mtx, defer_lock);
						lck.lock();
						while (igc.size() > 2000)
							decond.wait(lck);
						/*qDebug() << "igc:" << igc.size() << endl;
						qDebug() << "o:" << o<< endl;*/
						double times; int ccc = 0;
						if (tracking[i] == 0) {
							if (ccc == 0) {
								double start = static_cast<double>(getTickCount());
								allframes[i] = frame;
								lk[i].tracking(allframes[i], toframes[i]);
								frame = toframes[i];
								times = ((double)getTickCount() - start) / getTickFrequency();
							}ccc = ccc++ % 2;
						}
						cv::putText(frame, to_string(int(1000 * times)) + "ms", cv::Point2f(500, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(0, 255, 0), 2);
						imgcnnel.image = frame;
						imgcnnel.channel = rtsp2channel(rtsp);
						imgcnnel.i = i;
						if (finish[i] == 0)
						{
							masks[i] = frame;
							finish[i] = 1;
						}
						igc.push(imgcnnel);
						encond.notify_all();
						lck.unlock();
					}odd = (odd + 1) % o;
				}
			}
		}	
}
void openvideo::imgdetect()
{
	Detector detector("yolov3.cfg", "yolov3.weights");
	Detector dethead("head.cfg","head_51400.weights");
	while (true)
	{
		   unique_lock<mutex> lck1(mtx, defer_lock);
		    lck1.lock();
		    while (igc.empty())  encond.wait(lck1);
			img_channel imgc = igc.front();
			igc.pop();
			Mat frame = imgc.image;
			string channel = imgc.channel;
			int i = imgc.i;
			std::vector<bbox_t> result_vec = dethead.detect(frame, 0.15);
			int num = 0;
			if (dense.judgedense(frame, result_vec, obj_names))
			{
				cv::putText(frame, "highdense", cv::Point2f(200, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(0, 255, 0), 1);
				
				num = draw_boxes(frame, result_vec, head_names, i);
			}
			else {
				 result_vec = detector.detect(frame, 0.15);
				cv::putText(frame, "lowdense", cv::Point2f(200, 30), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(0, 255, 0), 1);
				num = draw_boxes(frame, result_vec, obj_names, i);
			}
			channel_num cn;
			cn.channel = channel;
			cn.num = num;
			cn.i = i;
			cnu.push(cn);
			//qDebug() << "cnu:" << cnu.size() << endl;
			char im[20];
			std::sprintf(im, "image%d", i);
			 cv::rectangle(frame, danger[i], (0, 0, 255), 2); 
			//qDebug() << danger[i].x<< danger[i].x << danger[i].width << danger[i].height<< endl;
			/*imshow(im, frame);
			cvWaitKey(1);*/
			QImage image = QImage((const uchar*)frame.data,
				frame.cols, frame.rows,
				QImage::Format_RGB888).rgbSwapped();
			switch (i) 
			{
			case 0:ui.video0->setPixmap(QPixmap::fromImage(image)); break;
			case 1:ui.video1->setPixmap(QPixmap::fromImage(image)); break;
			case 2:ui.video2->setPixmap(QPixmap::fromImage(image)); break;
			case 3:ui.video3->setPixmap(QPixmap::fromImage(image)); break;
			case 4:ui.video4->setPixmap(QPixmap::fromImage(image)); break;
			case 5:ui.video5->setPixmap(QPixmap::fromImage(image)); break;
			case 6:ui.video6->setPixmap(QPixmap::fromImage(image)); break;
			case 7:ui.video7->setPixmap(QPixmap::fromImage(image)); break;
			case 8:ui.video8->setPixmap(QPixmap::fromImage(image)); break;
			case 9:ui.video9->setPixmap(QPixmap::fromImage(image)); break;
			default:break;
			}
	
			decond.notify_all();
			lck1.unlock();

	}
	
}


openvideo::openvideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.yolov3->setVisible(false);
	ui.head->setVisible(false);
	//ui.rtsp1->setEnabled(false); ui.rtsp2->setEnabled(false); ui.rtsp3->setEnabled(false); ui.rtsp4->setEnabled(false); ui.rtsp5->setEnabled(false); ui.rtsp6->setEnabled(false); ui.rtsp7->setEnabled(false); ui.rtsp8->setEnabled(false); ui.rtsp9->setEnabled(false); ui.rtsp10->setEnabled(false);
	time_t rawtime;
	struct tm *ptminfo;

	time(&rawtime);
	ptminfo = localtime(&rawtime);
	if (ptminfo->tm_year + 1900 >= 2019)
		exit(0);
	
	ifstream Oread("rtsp.txt");
	string s;
	getline(Oread, s); if (ui.sulv->text().isEmpty())   ui.sulv->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp1->toPlainText().isEmpty())   ui.rtsp1->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp2->toPlainText().isEmpty())   ui.rtsp2->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp3->toPlainText().isEmpty())   ui.rtsp3->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp4->toPlainText().isEmpty())   ui.rtsp4->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp5->toPlainText().isEmpty())   ui.rtsp5->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp6->toPlainText().isEmpty())   ui.rtsp6->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp7->toPlainText().isEmpty())   ui.rtsp7->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp8->toPlainText().isEmpty())   ui.rtsp8->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp9->toPlainText().isEmpty())   ui.rtsp9->setText(QString::fromStdString(s));
	getline(Oread, s); if (ui.rtsp10->toPlainText().isEmpty())   ui.rtsp10->setText(QString::fromStdString(s));
	m_pGenderGroup = new QButtonGroup(this);
	m_pGenderGroup->addButton(ui.yolov3, 0);   
	m_pGenderGroup->addButton(ui.head, 1); 


	/*信号和槽*/
	connect(ui.play, SIGNAL(click()), this, SLOT(on_play_clicked()));//打开摄像头按钮
	connect(ui.ratio, SIGNAL(click()), this, SLOT(on_ratio_clicked()));
	connect(ui.rect1, SIGNAL(click()), this, SLOT(on_rect1_click())); connect(ui.rect2, SIGNAL(click()), this, SLOT(on_rect2_clicked())); connect(ui.rect3, SIGNAL(click()), this, SLOT(on_rect3_clicked())); connect(ui.rect4, SIGNAL(click()), this, SLOT(on_rect4_clicked())); connect(ui.rect5, SIGNAL(click()), this, SLOT(on_rect5_clicked())); connect(ui.rect6, SIGNAL(click()), this, SLOT(on_rect6_clicked())); connect(ui.rect7, SIGNAL(click()), this, SLOT(on_rect7_clicked())); connect(ui.rect8, SIGNAL(click()), this, SLOT(on_rect8_clicked())); connect(ui.rect9, SIGNAL(click()), this, SLOT(on_rect9_clicked())); connect(ui.rect10, SIGNAL(click()), this, SLOT(on_rect10_clicked()));
	connect(ui.detector, SIGNAL(click()),this, SLOT(on_detector_clicked()));//stop
	connect(m_pGenderGroup, SIGNAL(buttonClicked(int)), this, SLOT(RecvmodelID(int)));
	

}

void openvideo::RecvmodelID(int id)
{
	switch (id)
	{case 0:
		mo = "yolov3"; break;
	case 1:
		mo = "head"; 

	}
}
void openvideo::on_ratio_clicked()
{
		o = ui.sulv->text().toInt();
}
void openvideo::on_rect1_clicked()
{
	a[0] = 1;
	Pyline py0(masks[0]);
	py0.drawpoly("iframes1");	
	contours.at(0).assign(py0.contour.begin(), py0.contour.end());
}
void openvideo::on_play_clicked()
{
	ui.play->setEnabled(false);
	std::string  names_file = "coco.names";
	std::string  names_head = "head.names";
	/*std::string cfg_file = "yolov3.cfg";
	std::string  weights_file = "yolov3.weights";*/
	obj_names = objects_names_from_file(names_file);//获得分类对象名称
	head_names = objects_names_from_file(names_head);
	rtsp1 = ui.rtsp1->toPlainText();
	rtsp2 = ui.rtsp2->toPlainText();
	rtsp3= ui.rtsp3->toPlainText();
	rtsp4 = ui.rtsp4->toPlainText();
	rtsp5 = ui.rtsp5->toPlainText();
	rtsp6 = ui.rtsp6->toPlainText();
	rtsp7 = ui.rtsp7->toPlainText();
	rtsp8 = ui.rtsp8->toPlainText();
	rtsp9 = ui.rtsp9->toPlainText();
	rtsp10 = ui.rtsp10->toPlainText();
	ofstream	OsWrite("rtsp.txt");
	OsWrite<<ui.sulv->text().toInt()<<endl<<rtsp1.toStdString()<<endl<<rtsp2.toStdString() <<endl<<rtsp3.toStdString() <<endl<<rtsp4.toStdString() <<endl<<rtsp5.toStdString() <<endl<<rtsp6.toStdString() <<endl << rtsp7.toStdString() << endl << rtsp8.toStdString() << endl << rtsp9.toStdString() << endl << rtsp10.toStdString() << endl;
	OsWrite.close();

	std::thread t1([&]() { playdecetor(rtsp1, 0); });
	std::thread t2([&]() { playdecetor(rtsp2, 1); });
	std::thread t3([&]() { playdecetor(rtsp3, 2); });
	std::thread t4([&]() { playdecetor(rtsp4, 3); });
	std::thread t5([&]() { playdecetor(rtsp5, 4); });
	std::thread t6([&]() { playdecetor(rtsp6, 5); });
	std::thread t7([&]() { playdecetor(rtsp7, 6); });
	std::thread t8([&]() { playdecetor(rtsp8, 7); });
	std::thread t9([&]() { playdecetor(rtsp9, 8); });
	std::thread t10([&]() { playdecetor(rtsp10, 9); });
	t1.detach(); t2.detach(); t3.detach(); t4.detach(); t5.detach(); t6.detach(); t7.detach(); t8.detach(); t9.detach(); t10.detach();
	std::thread T1([&]() { imgdetect(); });
	T1.detach(); 
	std::thread t81([&]()
		{
	while (true)
		{
			//Sleep(500);
				unique_lock<mutex> lck2(mtx, defer_lock);
				lck2.lock();
				if  (cnu.empty())
						continue;
				channel_num cn;
				cn = cnu.front();
				cnu.pop();
				lck2.unlock();
			string channel = cn.channel;
			int nums = cn.num;
			int i = cn.i;
			askhttp("http://139.196.193.132:8999/ZhManageWebApi/receiveJkNum", "001", channel, nums, false);
			switch (i)
				{
				case 0:ui.num1->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 1:ui.num2->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 2:ui.num3->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 3:ui.num4->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break; 
				case 4:ui.num5->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 5:ui.num6->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break; 
				case 6:ui.num7->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 7:ui.num8->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 8:ui.num9->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				case 9:ui.num10->setText(QString::fromStdString(strResponse) + "num=" + QString::number(nums)); break;
				default: break;
				}
			/*std::queue<channel_num> empty;
			std::swap(cnu, empty);*/
			}
		});
	t81.detach();
	ui.play->setEnabled(true);
}
void openvideo::on_detector_clicked()
{
	exit(0);
}
void A_on_Mouse1(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[1].x = x;
		danger[1].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[1].width = x - danger[1].x;
		danger[1].height = y - danger[1].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect2_clicked()
{
	a[1] = 1;
	Pyline py1(masks[1]);
	py1.drawpoly("iframes2");
	contours.at(1).assign(py1.contour.begin(), py1.contour.end());
}
void A_on_Mouse2(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[2].x = x;
		danger[2].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[2].width = x - danger[2].x;
		danger[2].height = y - danger[2].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect3_clicked()
{
	a[2] = 1;
	Pyline py2(masks[2]);
	py2.drawpoly("iframes3");
	contours.at(2).assign(py2.contour.begin(), py2.contour.end());
}
void A_on_Mouse3(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[3].x = x;
		danger[3].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[3].width = x - danger[3].x;
		danger[3].height = y - danger[3].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect4_clicked()
{
	a[3] = 1;
	Pyline py3(masks[3]);
	py3.drawpoly("iframes4");
	contours.at(3).assign(py3.contour.begin(), py3.contour.end());
}
void A_on_Mouse4(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[4].x = x;
		danger[4].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[4].width = x - danger[4].x;
		danger[4].height = y - danger[4].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect5_clicked()
{
	a[4] = 1;
	Pyline py4(masks[4]);
	py4.drawpoly("iframes5");
	contours.at(4).assign(py4.contour.begin(), py4.contour.end());
}
void A_on_Mouse5(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[5].x = x;
		danger[5].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[5].width = x - danger[5].x;
		danger[5].height = y - danger[5].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect6_clicked()
{
	a[5] = 1;
	Pyline py5(masks[5]);
	py5.drawpoly("iframes6");
	contours.at(5).assign(py5.contour.begin(), py5.contour.end());
}
void A_on_Mouse6(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[6].x = x;
		danger[6].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[6].width = x - danger[6].x;
		danger[6].height = y - danger[6].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect7_clicked()
{
	a[6] = 1;
	Pyline py6(masks[6]);
	py6.drawpoly("iframes7");
	contours.at(6).assign(py6.contour.begin(), py6.contour.end());
}
void A_on_Mouse7(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[7].x = x;
		danger[7].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[7].width = x - danger[7].x;
		danger[7].height = y - danger[7].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect8_clicked()
{
	a[7] = 1;
	Pyline py7(masks[7]);
	py7.drawpoly("iframes8");
	contours.at(7).assign(py7.contour.begin(), py7.contour.end());
}
void A_on_Mouse8(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[8].x = x;
		danger[8].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[8].width = x - danger[8].x;
		danger[8].height = y - danger[8].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect9_clicked()
{
	a[8] = 1;
	Pyline py8(masks[8]);
	py8.drawpoly("iframes9");
	contours.at(8).assign(py8.contour.begin(), py8.contour.end());
}
void A_on_Mouse9(int event, int x, int y, int flags, void*param)//实现画矩形框
{
	Point p1, p2;
	if (event == EVENT_LBUTTONDOWN)
	{
		danger[9].x = x;
		danger[9].y = y;
		select_flag = true;
	}
	else if (select_flag &&event == EVENT_MOUSEMOVE)
	{
		danger[9].width = x - danger[9].x;
		danger[9].height = y - danger[9].y;
	}
	else if (select_flag && event == EVENT_LBUTTONUP)
	{
		select_flag = false;
	}
}
void openvideo::on_rect10_clicked()
{
	a[9] = 1;
	Pyline py9(masks[9]);
	py9.drawpoly("iframes10");
	contours.at(9).assign(py9.contour.begin(), py9.contour.end());
}
