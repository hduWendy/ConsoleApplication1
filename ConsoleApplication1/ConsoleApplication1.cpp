// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	//读取本地的一张图片，进行直方图均衡，并显示出来！
	cv::Mat src_color = imread("C:\\Users\\lenovo\\Desktop\\数图图片\\etest.jpg");
	//通道分离
	std::vector<cv::Mat> channels;
	cv::split(src_color, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	//直方图均衡
	cv::Mat B1, G1, R1;
	equalizeHist(B, B);
	equalizeHist(G, G);
	equalizeHist(R, R);
	//通道合并
	Mat newChannels[3] = { B,G,R };
	Mat dst_color;
	merge(newChannels, 3, dst_color);

	cv::imshow("original Mat", src_color);
	cv::imshow("equalizeHist Mat", dst_color);
	//等待用户按键
	waitKey(0);
	return 0;
}

