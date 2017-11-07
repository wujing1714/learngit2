#ifndef MAINPROCESS_H
#define MAINPROCESS_H
#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

class Object
{
public:
	Object();
	void initObj();
	void calSimilarMat(Point leftTop, Point rightButtom);
	void similarityMat2Position();
//private:
	//Ŀ��
	//Ŀ���λ�����Ͻ����꣨x,y��
	int x;
	int y;
	//Ŀ����С����width����height
	int width;
	int height;
	//Ŀ�������ӣ���tx,ty,s���ֱ���x����ƽ�ƣ�y����ƽ�ƣ����ű���
	float tx;
	float ty;
	float sx;
	float sy;
	//���ƾ���
	Mat similarMat;
	//ģ��
	//ģ���С����templateWidth����templateHeight
	int templateWidth;
	int templateHeight;
	//ģ����
	int templateNum;
	//ģ������
	Mat* templateFeature;
	//��������ƫ����
	float **ShiftSimilarMat;
};


class VideoMessage
{
public:
	VideoMessage(string fileName);
	Mat getNowFrame();
	int getFrameNum();

//private:
	Mat nowFrame;
	VideoCapture capture;
	int frameNum;
	double rate;
	
};



void on_mouse(int event, int x, int y, int flags, void* param);
#endif