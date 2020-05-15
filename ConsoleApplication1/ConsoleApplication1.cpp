// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	//��ȡ���ص�һ��ͼƬ������ֱ��ͼ���⣬����ʾ������
	cv::Mat src_color = imread("C:\\Users\\lenovo\\Desktop\\��ͼͼƬ\\etest.jpg");
	//ͨ������
	std::vector<cv::Mat> channels;
	cv::split(src_color, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	//ֱ��ͼ����
	cv::Mat B1, G1, R1;
	equalizeHist(B, B);
	equalizeHist(G, G);
	equalizeHist(R, R);
	//ͨ���ϲ�
	Mat newChannels[3] = { B,G,R };
	Mat dst_color;
	merge(newChannels, 3, dst_color);

	cv::imshow("original Mat", src_color);
	cv::imshow("equalizeHist Mat", dst_color);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}

