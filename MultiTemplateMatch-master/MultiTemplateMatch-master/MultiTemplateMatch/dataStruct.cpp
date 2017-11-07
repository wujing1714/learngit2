#include "dataStruct.h"
//-----------------------------------Object�ĳ�Ա����-----------------------//
//��ʼ������
Object::Object()
{
	//��ʼ����������ƫ�����ƾ���
	ShiftSimilarMat = new float*[81];
	for(int i = 0; i < 81; i ++)
	{
		ShiftSimilarMat[i] = new float[4];
	}
}
void Object::calSimilarMat(Point leftTop, Point rightButtom)
{
	tx = leftTop.x;
	ty = leftTop.y;
	sx = (float)width / (float)(templateWidth - 1);
	sy = (float)height / (float)(templateHeight - 1);
	similarMat = (Mat_<float>(2, 3) << sx, 0, tx, 0, sy, ty);
}
void Object::similarityMat2Position()
{
	x = tx;
	y = ty;
	width = sx * (templateWidth - 1);
	height = sy * (templateHeight - 1);
}
//-----------------------------------VideoMessage�ĳ�Ա����----------------//
VideoMessage::VideoMessage(string fileName)
{
	capture.open(fileName);
	if(!capture.isOpened())
	{
		cout << "����Ƶʧ��" << endl; 
	}
	capture.set( CV_CAP_PROP_POS_FRAMES,1);
	//capture.read(nowFrame);
	frameNum = capture.get(CV_CAP_PROP_FRAME_COUNT);
	rate = capture.get(CV_CAP_PROP_FPS);
}
Mat VideoMessage::getNowFrame()
{
	if(!capture.read(nowFrame))
	{
		cout << "��ȡ��Ƶʧ��" << endl;
	}
	return nowFrame;
}
int VideoMessage:: getFrameNum()
{
	return frameNum;
}