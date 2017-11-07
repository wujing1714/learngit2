#include "addGaussian.h"
Mat addGaussian(Mat& src, Mat& seed)
{
	Mat dst = Mat(src.rows, src.cols, CV_32F);
	srand((unsigned)time(NULL));
	for(int i = 0; i < src.rows; i ++)
	{
		for(int j = 0; j < src.cols; j ++)
		{
			dst.at<float>(i, j) = src.at<float>(i, j) + seed.at<float>(i, j) * gausS();
		}
	}
	return dst;
}
double gausS()
{ 
	//������˹������DΪ������
    double sum=0; 
    for(int i = 0; i < 12; i++)
		sum += rand() / 32767.00;
	//�������rand()����Ϊ��32767����32767��2^15-1��
	//��sum��Ϊ0��1֮��ľ����������
	return sum - 6;
	//������ֵΪU����׼��ΪD�ĸ�˹�ֲ���������������
}