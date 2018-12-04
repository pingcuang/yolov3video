#include"lk.h"

using namespace std;
using namespace cv;
//  描述：声明全局变量


lktrack::~lktrack()
{
}

// parameter: frame 输入的视频帧
//            output 有跟踪结果的视频帧
void lktrack::tracking(Mat &frame, Mat &output)
{
	cvtColor(frame, gray, CV_BGR2GRAY);
	frame.copyTo(output);
	// 添加特征点

	if (addNewPoints())
	{
		goodFeaturesToTrack(gray, features, maxCount, qLevel, minDist);
		points[0].insert(points[0].end(), features.begin(), features.end());
		initial.insert(initial.end(), features.begin(), features.end());
	}
	if (gray_prev.empty())
	{
		gray.copyTo(gray_prev);
	}
	// l-k光流法运动估计
	calcOpticalFlowPyrLK(gray_prev, gray, points[0], points[1], status, err);
	// 去掉一些不好的特征点
	int k = 0;
	for (size_t i = 0; i<points[1].size(); i++)
	{
		if (acceptTrackedPoint(i))
		{
			initial[k] = initial[i];
			points[1][k++] = points[1][i];
		}
	}
	points[1].resize(k);
	initial.resize(k);
	// 显示特征点和运动轨迹

	for (size_t i = 0; i<points[1].size(); i++)
	{
		line(output, initial[i], points[1][i], Scalar(0, 0, 255));
		circle(output, points[1][i], 1, Scalar(0, 255, 0), -1);
	}

	// 把当前跟踪结果作为下一此参考
	swap(points[1], points[0]);
	swap(gray_prev, gray);
}

//  检测新点是否应该被添加
// return: 是否被添加标志
bool lktrack::addNewPoints()
{
	return points[0].size() <= 10;
}

//决定哪些跟踪点被接受
bool lktrack::acceptTrackedPoint(int i)
{
	return status[i] && ((abs(points[0][i].x - points[1][i].x) + abs(points[0][i].y - points[1][i].y)) > 50);
}
void  lktrack::readvideo(string rtsp)
{
	Mat frame,out;
	VideoCapture capture;
	//rtsp = "rtsp://admin:a@111.23.244.163:1554/cam/realmonitor?channel=25&subtype=1";
	capture.open(rtsp);
	if (!capture.isOpened())
	{
		std::cout << "video not open." << std::endl;
	}
	while (true)
	{
		for (;;) {

			if (!capture.read(frame)) {
				std::cout << "No frame" << std::endl;
				capture.open(rtsp);
				break;
			}
		   tracking(frame, out);
			
		}
	}
}
//int main()
//{
//	lktrack lk;
//	lk.readvideo("rtsp://admin:a@111.23.244.163:1554/cam/realmonitor?channel=25&subtype=1");
//}