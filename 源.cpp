#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui_c.h>
#include"Kalm.h"
#include<Windows.h>
#include<iostream>
#include"putText.h"
using namespace std;
using namespace cv;
void Pos(POINT *T, HWND hwnd);
void main()
{

	namedWindow("Img", 1);
	HWND hwnd=(HWND)cvGetWindowHandle("Img");
	POINT T;
	Kalm X;
	Kalm Y;
	while (true)
	{
		Mat img = Mat(400, 800, CV_8UC3);

		Pos(&T, hwnd);
		X.kalmanFilterFun(T.x);
		Y.kalmanFilterFun(T.y);
		circle(img, Point(T.x, T.y), 30, Scalar(0, 0, 255),2);
		circle(img, Point(X.info.predictValue, Y.info.predictValue), 40, Scalar(0, 255, 0), 2);

		char buf[256];
		sprintf_s(buf, 256, "Ԥ��λ��(��Ȧ):(%3d,%3d)", int(X.info.predictValue), int(Y.info.predictValue));
		putTextZH(img, buf, Point(10, 30), Scalar(0, 0, 0),25,"����",true,false);
		sprintf_s(buf, 256, "�������˲�Ԥ��");
		putTextZH(img, buf, Point(400, 30), Scalar(0, 0, 0), 25, "����", true, false);
		sprintf_s(buf, 256, "��ǰλ��(��Ȧ):(%3d,%3d)", T.x, T.y);
		putTextZH(img, buf, Point(10, 60),Scalar(0, 0, 0), 25, "����", true, false);
		imshow("Img", img);
		waitKey(1);

	}

}

void Pos(POINT *T,HWND hwnd)
{
	RECT rect;
	POINT xy;	//λ�ñ���
	GetWindowRect(hwnd, &rect);
	GetCursorPos(&xy);
	if (xy.x - rect.left > 0 && xy.x - rect.left < (rect.right - rect.left))
	{
		T->x = xy.x - rect.left;
	}
	else T->x = 0;


	if (xy.y - rect.top > 0 && xy.y - rect.top < (rect.bottom - rect.top))
	{
		T->y = xy.y - rect.top;
	}
	else T->y = 0;

}


/*
	
	for (int i = 0; i < 20; i+=2)
	{
		A.kalmanFilterFun(i) ;
		cout << "����ֵ��" << i <<"Ԥ��ֵ��";
		cout << A.info.predictValue<< endl;
	}

*/


//����
//void CLayoutAnalysisDlg::OnBnClickedTestButton()
//{
//	Mat img = imread("D:\\test\\26.png");//����ͼ��
//	putTextZH(img, "Arial���廻...\n����ʾ!", Point(50, 50), Scalar(0, 0, 255), 30, "Arial");
//	putTextZH(img, "΢���ź����廻...\n�У�б�壬�»��ߣ���ʾ!", Point(50, 100), Scalar(0, 255, 0), 30, "΢���ź�", true, true);
//	putTextZH(img, "�������廻...\n�У�б�壬�»��ߣ���ʾ!", Point(50, 200), Scalar(128, 255, 0), 30, "����", true, true);
//
//	imshow("test", img);
//	waitKey();
//	return;
//}