#pragma once
#ifndef  _DENSITY
#define _DENSITY
#include<opencv2\opencv.hpp>
#include<yolo_v2_class.hpp>
class Density
{
public:
	Density() = default;
	~Density();
	bool judgedense(cv::Mat img,std::vector<bbox_t> result_vec, std::vector<std::string> obj_names);

private:

};


#endif // ! _DENSITY
