#ifndef TRACKING_H
#define TRACKING_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "dataStruct.h"
#include "getFeature.h"
using namespace cv;

//-------------------------------------------ģ��ƥ�����-------------------------------//
//��������ʱ�ĸ������ӵ�ƫ�Ʋ���
#define SX_SHIFT 0.5
#define SY_SHIFT 0.5
#define TX_SHIFT 1
#define TY_SHIFT 1
//����������������������
#define SHIFT_NUM 81
//�ֿ���
#define X_NUM 4
#define Y_NUM 4
//�ж��ڵ����ƶ���ֵ
#define OCCLUSION_THRESHOLD 0.6
//ģ��������ƶ���ֵ
#define UPDATE_THRESHOLD 0.5
void tracking(Mat &src, Object& obj);
void calShiftSimilarMat(float ** ShiftSimilarMat, Mat& similarMat);
#endif