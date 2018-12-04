#pragma once
#include<opencv2/opencv.hpp>
#include <iostream>
#include <cstdio>
#include<vector>
class  lktrack
{
public:
	lktrack()= default;
	~lktrack();
	void tracking(cv::Mat &frame, cv::Mat &output);
	bool addNewPoints();
	bool acceptTrackedPoint(int i);
	void readvideo(std::string rtsp);
private:
	cv::Mat gray;  
	cv::Mat gray_prev; 
	std::vector<cv::Point2f> points[2];  
	std::vector<cv::Point2f> initial;    
	std::vector<cv::Point2f> features;   
	int maxCount = 500; // 检测的最大特征数
	double qLevel = 0.01;   // 特征检测的等级
	double minDist = 10.0;  // 两特征点之间的最小距离
	std::vector<uchar> status;   // 跟踪特征的状态，特征的流发现为1，否则为0
	std::vector<float> err;
	double t = 0;

};