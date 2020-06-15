#ifndef _MATH_H_
#define _MATH_H_

//�~����
#define PI 3.14159265359f

class Math
{
public:
	//Degree����Radian�ɕϊ�
	static float Deg2Rad();
	//Radian����Degree�ɕϊ�
	static float Rad2Deg();
	//������̕\��
	static float Infinity();
	//���̖�����̕\��
	static float NegativeInfinity();
public:
	//��Βl�̎擾
	static float Abs(float f);
	//�A�[�N�R�T�C��(r = ���W�A��)
	static float Acos(float r);
	//�A�[�N�T�C��(r = ���W�A��)
	static float Asin(float r);
	//�A�[�N�^���W�F���g(r = ���W�A��)
	static float Atan(float r);
	//Tan��y/x�ɂȂ�p�x�����W�A���ŕԂ�
	static float Atan2(float y, float x);
	//f�ȏ�̍ŏ��̐�����Ԃ�(�������ʐ؂�グ)
	static float Ceil(float f);
	//f�ȏ�̍ŏ��̐�����Ԃ�(�������ʐ؂�グ)
	static int CeilToInt(float f);
	//n��min����max�ɐ�������
	static float Clamp(float n, float min, float max);
	//n��0����1�ɐ�������
	static float Clamp01(float n);
	//�R�T�C��(r = ���W�A��)
	static float Cos(float r);
	//f�ȏ�̍ŏ��̐�����Ԃ�(�������ʐ؂�̂�)
	static float Floor(float f);
	//f�ȏ�̍ŏ��̐�����Ԃ�(�������ʐ؂�̂�)
	static int FloorToInt(float f);
	//���`�⊮
	static float Lerp(float a, float b, float t);
	//a,b���ׁA�傫������Ԃ�
	static float Max(float a, float b);
	//a,b���ׁA����������Ԃ�
	static float Min(float a, float b);
	//current����target�܂ŁAmaxDelta�̃X�s�[�h�ňړ�����
	static float MoveTowards(float current, float target, float maxDelta);
	//f��p��̒l��Ԃ�
	static float Pow(float f, float p);
	//�T�C��(r = ���W�A��)
	static float Sin(float r);
	//from��to�̊ԂŐ��������X���[�W���O�ŕ⊮����
	static float SmoothStep(float from,float to,float t);
	//f�̕�������Ԃ�
	static float Sqrt(float f);
	//�^���W�F���g(r = ���W�A��)
	static float Tan(float r);
};
#endif

