#include "initialize.h"
void initialize(Object& obj, VideoMessage& videoMessage, Mat& Frame, Point leftTop, Point rightButtom, int tW, int tH, int tN, Mat& seed)
{
	cout << "4.1 ��ʼ������" << endl;
	//------------------------------Ŀ��λ�ó�ʼ��-----------------------------//
	obj.x = leftTop.x;
	obj.y = leftTop.y;
	//------------------------------Ŀ���С��ʼ��-----------------------------//
	obj.width = rightButtom.x - leftTop.x;
	obj.height = rightButtom.y - leftTop.y;
	//------------------------------��ʼ��ģ���С-----------------------------//
	obj.templateWidth = tW;
	obj.templateHeight = tH;
	obj.templateNum = tN;
	//------------------------------��ʼ��������-------------------------------//
	obj.calSimilarMat(leftTop, rightButtom);
	cout << obj.similarMat.at<float>(0, 0) << endl;
	//------------------------------ģ���ʼ��---------------------------------//
	obj.templateFeature = new Mat[obj.templateNum];
	//namedWindow("test");
	obj.templateFeature[0] = Mat(obj.templateHeight, obj.templateWidth, CV_8UC1);
	getFeature(Frame, obj.templateFeature[0], obj.similarMat);
	/*for(int i = 0; i < obj.templateFeature[0].rows; i ++)
	{
		for(int j = 0; j < obj.templateFeature[0].cols; j ++)
		{
			cout << (int)obj.templateFeature[0].at<uchar>(i, j) << "\t";
		}
		cout << endl;
	}
	imshow("test", obj.templateFeature[0]);
	cvWaitKey(0);*/
	//char outfilename[200] = {0};
	for(int i = 1; i < obj.templateNum; i ++)
	{
		//�Ӹ�˹����
		Mat similarMatAddGaussian = addGaussian(obj.similarMat, seed);
		//Ϊģ������ڴ�
		obj.templateFeature[i] = Mat(obj.templateHeight, obj.templateWidth, CV_8UC1);
		getFeature(Frame, obj.templateFeature[i], similarMatAddGaussian);
		/*imshow("test", obj.templateFeature[i]);
		sprintf(outfilename,"C:\\Users\\wulala1119\\Documents\\visual studio 2012\\Projects\\MultiTemplateMatch\\template\\template_%02d.jpg",i);
		imwrite(outfilename, obj.templateFeature[i]);
		cvWaitKey(0);*/
	}
	//------------------------------��ʼ������---------------------------------//
	cout << "4.2 ��ʼ������" << endl;
}

