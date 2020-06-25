#ifndef _RENDERER_H_
#define _RENDERER_H_

#include"DxLib.h"
#include"Vector2.h"
#include"Rectangle.h"
#include"../GameObject/Transform.h"

#define DEFAULT_COLOR GetColor(255,255,255)

//https://dxlib.xsrv.jp/dxfunc.html
//DxLib�̕`��֐��̃��b�v
class Renderer
{
public:

	//--------------------------------------------------------
	//��

	int DrawLine(const Vector2& startPos,const Vector2& endPos, int color = GetColor(255, 255, 255));
	int DrawLineAA(const Vector2& startPos,const Vector2& endPos, int color = GetColor(255, 255, 255));

	//--------------------------------------------------------
	//�l�p�`

	int DrawBox(const Vector2& topLeftPos,const Vector2& bottomRightPos,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawBox(const struct Rectangle& rect,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	int DrawBoxAA(const Vector2& topLeftPos,const Vector2& bottomRightPos,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawBoxAA(const struct Rectangle& rect,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//�~

	int DrawCircle(const Vector2& position, int r,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	//posnum = �~���`�����钸�_��
	int DrawCircleAA(const Vector2& position, float r, int posnum,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//�ȉ~

	int DrawOval(const Vector2& position, const Vector2& radius_xy,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	//posnum = �ȉ~���`�����钸�_��
	int DrawOvalAA(const Vector2& position, const Vector2& radius_xy, int posnum,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//�O�p�`

	int DrawTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);
	int DrawTriangleAA(const Vector2& v1, const Vector2& v2, const Vector2& v3,
		int color = GetColor(255, 255, 255), int fillFlag = TRUE);

	//--------------------------------------------------------
	//�s�N�Z��

	int DrawPixel(const Vector2& position, int color = GetColor(255, 255, 255));

	//--------------------------------------------------------
	//����

	int DrawString(const Vector2& position, const char* text, int color = GetColor(255, 255, 255));
	//printf�̂悤�ɏ������w��ł���
	int DrawFormatString(const Vector2& position, int color, char* formatString, ...);

	int GetDrawStringWidth(const char* text, int length);

	int GetDrawFormatStringWidth(char* formatString, ...);

	//https://dxlib.xsrv.jp/function/dxfunc_graph2.html#R17N10
	int CreateFontToHandle(const char* fontName, int size, int thick, int fontType = DX_FONTTYPE_NORMAL);

	//�t�H���g�f�[�^�̍폜
	int DeleteFontToHandle(int fontHandle);

	int DrawStringToHandle(const Vector2& position, const char* text, int color, int fontHandle);

	int DrawFormatStringToHandle(const Vector2& position, int color, int fontHandle, char* formatString, ...);

	int GetDrawStringWidthToHandle(const char* text, int length, int fontHandle);

	int GetDrawFormatStringWidthToHandle(int fontHandle, char* formatString, ...);

	//�t�H���g�̃f�[�^���擾����(�s�v�ȏꍇ��NULL�w��)
	int GetFontStateToHandle(char* text, int* size, int* thick, int fontHandle);

	int InitFontToHandle(void);

	//--------------------------------------------------------
	//�摜

	int DrawGraph_TL(const Vector2& position, int handle, int transFlag = TRUE);

	int DrawGraph_C(const Vector2& position, const Vector2& spriteSize, int handle, int transFlag = TRUE);

	int DrawTurnGraph_TL(const Vector2& position, int handle, int transFlag = TRUE);
	int DrawTurnGraph_C(const Vector2& position, const Vector2& spriteSize, int handle, int transFlag = TRUE);

	int DrawScaleGraph(const Vector2& position, float scale, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotateGraph(const Vector2& position, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotaGraph(const Vector2& position, float scale, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotateGraph2(const Vector2& position, const Vector2& rotaPosition, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawRotaGraph2(const Vector2& position, const Vector2& rotaPosition, float scale, float angle, int handle, int transFlag = TRUE, int turnFlag = FALSE);

	int DrawScaleGraph3(const Vector2& position, const Vector2& spriteSize, const Vector2& scale, int handle, int transFlag = TRUE);

	int DrawRotaGraph3(const Vector2& position, const Vector2& rotaPosition, const Vector2& scale, float angle, int handle, int transFlag = TRUE);

	int DrawModiGraph(const Vector2& topLeftPos, const Vector2& topRightPos, const Vector2& bottomRightPos, const Vector2& bottomLeftPos, int handle, int transFlag = TRUE);

	int DrawRectGraph(const Vector2& position,const struct Rectangle& rect, int handle, int transFlag = TRUE);

	int DrawRectGraph_C(const Transform& transform,const struct Rectangle& rect, int handle, int transFlag = TRUE);

	int GetGraphSize(int handle, int* widthBuf, int* heightBuf);

	int InitGraph(void);

	int DeleteGraph(int handle);

	//--------------------------------------------------------
};

#endif