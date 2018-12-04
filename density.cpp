#include "density.h"

Density::~Density()
{
}

bool Density::judgedense(cv::Mat img,std::vector<bbox_t> result_vec, std::vector<std::string> obj_names)
{
	int num = 0;
	std::vector<cv::Point> results;
	for (auto &i : result_vec) {
		if(obj_names[i.obj_id]=="person")
				results.push_back(cv::Point(i.x+i.w/2,i.y+i.h/2));
	}
	for (auto result : results)
	{
		num = 0;
		for (auto point : results)
		{
			if ((pow((result.x - point.x), 2)*1.0 + 1.0*pow((result.y - point.y), 2))< pow(img.cols / 10.0, 2))
			{
				num++;
			}
			if (num > 12)
				return true;
		}
	}
	
	return false;
}

