#ifndef  _POLYLINE
#define _POLYLINE
#include<opencv2/opencv.hpp>
#include<iostream>

class Pyline
{
public:
	     Pyline() = default;
		 std::vector<std::vector<cv::Point>> contour;
		 Pyline(cv::Mat image);
		 ~Pyline();
		 void on_mouse(int event, int x, int y);
		 static void on_mouse(int event, int x, int y, int flags, void* yybird);
		 void drawpoly(const std::string& _winname);
		 std::vector<std::vector<cv::Point>> getcontour();
private:
	
	
	std::vector<cv::Point> pts;
	 cv::Mat img, inpaint_mask;
	 std::string winname;
};

#endif   //_POLYLINE