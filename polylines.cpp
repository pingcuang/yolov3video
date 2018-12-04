#include "Polylines.h"
 void Pyline::on_mouse(int event, int x, int y)
{
	 //std::cout << "internal:" << x << y << std::endl;
	cv::Point pt = cv::Point(x, y);
	if (!img.data) { printf("image is empty!\n");	return; }
	else if (event == CV_EVENT_LBUTTONDOWN)
	{
		pts.push_back(pt);
	}
	else if (event == CV_EVENT_RBUTTONDOWN)
	{
		contour.push_back(pts);
		drawContours(inpaint_mask, contour, 0, cv::Scalar::all(255), -1);
		
		cv::imshow(winname+"mask", inpaint_mask);
		cv::imwrite(winname + "mask.jpg", inpaint_mask);
		
	}
}

  void Pyline::on_mouse(int ev, int x, int y, int flags, void* obj)
 {
	 Pyline* app = reinterpret_cast<Pyline*>(obj);
	 //std::cout << "on_mouse" << x << y <<app<< std::endl;
     app->on_mouse(ev, x, y);
 }

 void Pyline::drawpoly(const std::string& _winname)
{
	cv::namedWindow(_winname);
	this->winname = _winname;
	cv::imshow(winname, img);
	inpaint_mask = img.clone();
	inpaint_mask = cv::Scalar::all(0);
	cv::setMouseCallback(winname, on_mouse, this);
	cv::waitKey(0);
}
std::vector<std::vector<cv::Point>> Pyline::getcontour()
{

	return contour;
}
Pyline::Pyline(cv::Mat image)
{
	img = image;
}

Pyline::~Pyline()
{
	pts.clear();
	contour.clear();
}
