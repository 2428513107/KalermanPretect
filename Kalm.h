#pragma once
typedef struct {
	float filterValue;//�˲����ֵ
	float kalmanGain;//Kalamn����
	float A;//״̬����
	float H;//�۲����
	float Q;//״̬����ķ���
	float R;//�۲����ķ���
	float P;//Ԥ�����
	float B;
	float u;
	float predictValue;
}KalmanInfo;
class Kalm
{
public:
	void kalmanFilterFun(float new_value);
	void initKalmanFilter(KalmanInfo *info);
	Kalm();
	KalmanInfo info;
};

