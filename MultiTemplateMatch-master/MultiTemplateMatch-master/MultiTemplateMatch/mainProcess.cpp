/*************************************************************************************/
/********************��ģ��ֿ�ƥ��Ŀ������㷨***************************************/
/*********************nuaaylh030910225@163.com****************************************/
/***********https://github.com/Wulala1119/MultiTemplateMatch**************************/
//-------------------------------------include�ļ�-----------------------------------//

#include "mainProcess.h"
#include "dataStruct.h"
#include "initialize.h"
#include "tracking.h"

#define templateWidth 32
#define templateHeight 32
#define templateNum 10
#define gaussianSeed 1


//-------------------------------------ȫ�ֱ���--------------------------------------//
Point leftTopPoint = Point(0, 0);
Point rightButtomPoint = Point(0, 0);
//-------------------------------------������----------------------------------------//
int main()
{
	//---------------------------------��ʼ��----------------------------------------//
	//---------------------------------��ʼ�����ݽṹ--------------------------------//
	Object obj;
	cout << "1 ��ʼ���ԣ�" << endl;
	string fileName = "C:\\Users\\wulala1119\\Documents\\visual studio 2012\\Projects\\MultiTemplateMatch\\videosrc\\CarScale.avi";
	VideoMessage videoMessage(fileName);
	cout << "2 ��Ƶ����ɹ���" << endl;
	Mat nowFrame;
	namedWindow("VideoTrack");
	cvSetMouseCallback("VideoTrack",on_mouse,0);// Ϊ���ڰ������⺯��		
	nowFrame = videoMessage.getNowFrame();
	imshow("VideoTrack", nowFrame);
	waitKey(0);
	cout << "3 Ŀ����ѡ�У�" << endl;
	Mat seed = (Mat_<float>(2, 3) << 0.1, 0, 2, 0, 0.1, 2);
	initialize(obj, videoMessage, nowFrame, leftTopPoint, rightButtomPoint, templateWidth, templateHeight, templateNum, seed);
	cout << "4 ��ʼ���ɹ���" << endl;
	int frameNum = videoMessage.getFrameNum(); 
	int frameCount = 1;
	//---------------------------------����ѭ��--------------------------------------//
	while(frameCount < frameNum - 1)
	{
		cout << "���ڴ���ڣ�" << frameCount << "֡" << endl;
		nowFrame = videoMessage.getNowFrame();
		tracking(nowFrame, obj);
		rectangle(nowFrame, Point(obj.x, obj.y), Point(obj.x + obj.width, obj.y + obj.height), Scalar(255,0,0));
		imshow("VideoTrack", nowFrame);
		waitKey(1);
		cout << "�ڣ�" << frameCount << "֡�������" << endl;
		frameCount ++;
	}

	////---------------------------------���ݴ洢--------------------------------------//
	//restoreData();

	////---------------------------------����------------------------------------------//

}


void on_mouse(int event, int x, int y, int flags, void* param)
{		
    if( event == CV_EVENT_LBUTTONDOWN)   //����������
	{
		leftTopPoint = Point(x, y);
	}
    else if( event == CV_EVENT_LBUTTONUP )   //����������
	{		
		rightButtomPoint = Point(x, y);
	}
}
