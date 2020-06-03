#include "Renderer.h"

#define INT_CAST(x) static_cast<int>(x)

//線を描画(アンチエイリアスなし)
int Renderer::DrawLine(const Vector2 &  startPos, const Vector2& endPos, int color)
{
	return DxLib::DrawLine(INT_CAST(startPos.x), INT_CAST(startPos.y),
		INT_CAST(endPos.x), INT_CAST(endPos.y), color);
}

//線を描画(アンチエイリアスあり)
int Renderer::DrawLineAA(const Vector2& startPos, const Vector2& endPos, int color)
{
	return DxLib::DrawLineAA(startPos.x, startPos.y, endPos.x, endPos.y, color);
}

//四角形を描画(アンチエイリアスなし)
int Renderer::DrawBox(const Vector2& topLeftPos, const Vector2& bottomRightPos, int color, int fillFlag)
{
	return DxLib::DrawBox(INT_CAST(topLeftPos.x), INT_CAST(topLeftPos.y),
		INT_CAST(bottomRightPos.x), INT_CAST(bottomRightPos.y), color, fillFlag);
}

//四角形を描画(アンチエイリアスなし)
int Renderer::DrawBox(const struct Rectangle& rect, int color, int fillFlag)
{
	return DxLib::DrawBox(INT_CAST(rect.Left()), INT_CAST(rect.Top()),
		INT_CAST(rect.Right()), INT_CAST(rect.Bottom()), color, fillFlag);
}

//四角形を描画(アンチエイリアスあり)
int Renderer::DrawBoxAA(const Vector2& topLeftPos, const Vector2& bottomRightPos, int color, int fillFlag)
{
	return DxLib::DrawBoxAA(topLeftPos.x, topLeftPos.y, bottomRightPos.x, bottomRightPos.y, color, fillFlag);
}

//四角形を描画(アンチエイリアスあり)
int Renderer::DrawBoxAA(const struct Rectangle& rect, int color, int fillFlag)
{
	return DxLib::DrawBoxAA(rect.Left(), rect.Top(),
		rect.Right(), rect.Bottom(), color, fillFlag);
}

//円を描画
int Renderer::DrawCircle(const Vector2& position, int r, int color, int fillFlag)
{
	return DxLib::DrawCircle(INT_CAST(position.x), INT_CAST(position.y), r, color, fillFlag);
}

//円を描画(アンチエイリアスあり)
int Renderer::DrawCircleAA(const Vector2& position, float r, int posnum, int color, int fillFlag)
{
	return DxLib::DrawCircleAA(position.x, position.y, r, posnum, color, fillFlag);
}

//楕円を描画
int Renderer::DrawOval(const Vector2& position, const Vector2& radius_xy, int color, int fillFlag)
{
	return DxLib::DrawOval(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(radius_xy.x), INT_CAST(radius_xy.y), color, fillFlag);
}

//楕円を描画(アンチエイリアスあり)
int Renderer::DrawOvalAA(const Vector2& position, const Vector2& radius_xy, int posnum, int color, int fillFlag)
{
	return DxLib::DrawOvalAA(position.x, position.y,
		radius_xy.x, radius_xy.y, posnum, color, fillFlag);
}

//三角形を描画
int Renderer::DrawTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3, int color, int fillFlag)
{
	return DxLib::DrawTriangle(INT_CAST(v1.x), INT_CAST(v1.y),
		INT_CAST(v2.x), INT_CAST(v2.y),
		INT_CAST(v3.x), INT_CAST(v3.y), color, fillFlag);
}

//三角形を描画(アンチエイリアスあり)
int Renderer::DrawTriangleAA(const Vector2& v1, const Vector2& v2, const Vector2& v3, int color, int fillFlag)
{
	return DxLib::DrawTriangleAA(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, color, fillFlag);
}

//ピクセルを描画
int Renderer::DrawPixel(const Vector2& position, int color)
{
	return DxLib::DrawPixel(INT_CAST(position.x), INT_CAST(position.y), color);
}

//文字を描画
int Renderer::DrawString(const Vector2& position, const char* text, int color)
{
	return DxLib::DrawString(INT_CAST(position.x), INT_CAST(position.y), text, color);
}

//文字を描画 フォーマット形式
int Renderer::DrawFormatString(const Vector2& position, int color, char* formatString, ...)
{
	return DxLib::DrawFormatString(INT_CAST(position.x), INT_CAST(position.y), color, formatString);
}

//文字の描画した際の幅を取得
int Renderer::GetDrawStringWidth(const char* text, int length)
{
	return DxLib::GetDrawStringWidth(text, length);
}

//フォーマット形式で文字を描画した際の幅を取得
int Renderer::GetDrawFormatStringWidth(char* formatString, ...)
{
	return DxLib::GetDrawFormatStringWidth(formatString);
}

//フォントデータを作成する size = フォントサイズ thick = フォントの太さ
int Renderer::CreateFontToHandle(const char* fontName, int size, int thick, int fontType)
{
	return DxLib::CreateFontToHandle(fontName, size, thick, fontType);
}

//フォントデータを削除する
int Renderer::DeleteFontToHandle(int fontHandle)
{
	return DxLib::DeleteFontToHandle(fontHandle);
}

//フォントデータをもとに文字を描画する
int Renderer::DrawStringToHandle(const Vector2& position, const char* text, int color, int fontHandle)
{
	return DxLib::DrawStringToHandle(INT_CAST(position.x), INT_CAST(position.y),
		text, color, fontHandle);
}

//フォントデータをもとにフォーマット形式で文字を描画
int Renderer::DrawFormatStringToHandle(const Vector2& position, int color, int fontHandle, char* formatString, ...)
{
	return DxLib::DrawFormatStringToHandle(INT_CAST(position.x), INT_CAST(position.y), color, fontHandle, formatString);
}

//フォントデータで文字を描画した際の幅を取得
int Renderer::GetDrawStringWidthToHandle(const char* text, int length, int fontHandle)
{
	return DxLib::GetDrawStringWidthToHandle(text, length, fontHandle);
}

//フォントデータで文字を描画した際の幅を取得(フォーマット形式)
int Renderer::GetDrawFormatStringWidthToHandle(int fontHandle, char* formatString, ...)
{
	return DxLib::GetDrawFormatStringWidthToHandle(fontHandle, formatString);
}

//フォントデータの文字サイズと太さを取得。不要な場合はNULLを代入
int Renderer::GetFontStateToHandle(char* text, int* size, int* thick, int fontHandle)
{
	return DxLib::GetFontStateToHandle(text, size, thick, fontHandle);
}

//フォントデータをすべて削除する
int Renderer::InitFontToHandle(void)
{
	return DxLib::InitFontToHandle();
}

//画像の左上を起点に描画する
int Renderer::DrawGraph_TL(const Vector2& position, int handle, int transFlag)
{
	return DxLib::DrawGraph(INT_CAST(position.x), INT_CAST(position.y), handle, transFlag);
}

//画像の中心を起点に描画する
int Renderer::DrawGraph_C(const Vector2& position, const Vector2& spriteSize, int handle, int transFlag)
{
	return DxLib::DrawGraph(INT_CAST(position.x - (spriteSize.x / 2.0f)),
		INT_CAST(position.y - (spriteSize.y / 2.0f)), handle, transFlag);
}

//画像を左上を起点に左右反転して描画する
int Renderer::DrawTurnGraph_TL(const Vector2& position, int handle, int transFlag)
{
	return DxLib::DrawTurnGraph(INT_CAST(position.x), INT_CAST(position.y), handle, transFlag);
}

//画像を中心を起点に左右反転して描画する
int Renderer::DrawTurnGraph_C(const Vector2& position, const Vector2& spriteSize, int handle, int transFlag)
{
	return DxLib::DrawTurnGraph(INT_CAST(position.x - (spriteSize.x / 2.0f)),
		INT_CAST(position.y - (spriteSize.y / 2.0f)), handle, transFlag);
}

//画像を中心を起点にして描画 拡大率を指定
int Renderer::DrawScaleGraph(const Vector2& position, float scale, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		scale, 0.0, handle, transFlag, turnFlag);
}

//画像を中心を起点にして描画 角度を指定
int Renderer::DrawRotateGraph(const Vector2& position, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		1.0, angle, handle, transFlag, turnFlag);
}

//画像を中心を起点にして描画 拡大率、角度を指定
int Renderer::DrawRotaGraph(const Vector2& position, float scale, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph(INT_CAST(position.x), INT_CAST(position.y),
		scale, angle, handle, transFlag, turnFlag);
}

//画像の中心を起点に描画し、回転する点を指定する
int Renderer::DrawRotateGraph2(const Vector2& position, const Vector2& rotaPosition, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph2(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		1.0f, angle, handle, transFlag, turnFlag);
}

//画像の中心を起点に描画し、回転する点を指定する
int Renderer::DrawRotaGraph2(const Vector2& position, const Vector2& rotaPosition, float scale, float angle, int handle, int transFlag, int turnFlag)
{
	return DxLib::DrawRotaGraph2(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		scale, angle, handle, transFlag, turnFlag);
}

//画像の中心を起点に描画 XYの拡大率を指定する
int Renderer::DrawScaleGraph3(const Vector2& position, const Vector2& spriteSize, const Vector2& scale, int handle, int transFlag)
{
	return DxLib::DrawRotaGraph3(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(spriteSize.x / 2.0f), INT_CAST(spriteSize.y / 2.0f),
		scale.x, scale.y, 0.0, handle, transFlag);
}

//画像の中心を起点に描画し、回転する点を指定する
int Renderer::DrawRotaGraph3(const Vector2& position, const Vector2& rotaPosition, const Vector2& scale, float angle, int handle, int transFlag)
{
	return DxLib::DrawRotaGraph3(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rotaPosition.x), INT_CAST(rotaPosition.y),
		scale.x, scale.y, angle, handle, transFlag);
}

//描画点を指定して画像を表示する
int Renderer::DrawModiGraph(const Vector2& topLeftPos, const Vector2& topRightPos, const Vector2& bottomRightPos, const Vector2& bottomLeftPos, int handle, int transFlag)
{
	return DxLib::DrawModiGraph(INT_CAST(topLeftPos.x), INT_CAST(topLeftPos.y),
		INT_CAST(topRightPos.x), INT_CAST(topRightPos.y),
		INT_CAST(bottomRightPos.x), INT_CAST(bottomRightPos.y),
		INT_CAST(bottomLeftPos.x), INT_CAST(bottomLeftPos.y), handle, transFlag);
}

//矩形情報を指定し、その部分のみを描画する
int Renderer::DrawRectGraph(const Vector2& position,const struct Rectangle& rect, int handle, int transFlag)
{
	return DxLib::DrawRectGraph(INT_CAST(position.x), INT_CAST(position.y),
		INT_CAST(rect.x), INT_CAST(rect.y),
		INT_CAST(rect.width), INT_CAST(rect.height), handle, transFlag);
}

//画像の幅と高さを取得する 不要な場合はNULLを代入
int Renderer::GetGraphSize(int handle, int* widthBuf, int* heightBuf)
{
	return DxLib::GetGraphSize(handle, widthBuf, heightBuf);
}

//すべての画像のハンドルを削除する
int Renderer::InitGraph(void)
{
	return DxLib::InitGraph();
}

//指定した画像のハンドルを削除する
int Renderer::DeleteGraph(int handle)
{
	return DxLib::DeleteGraph(handle);
}
