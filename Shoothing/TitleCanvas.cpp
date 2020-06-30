#include "TitleCanvas.h"
#include"GameObject\Score.h"

TitleCanvas::TitleCanvas()
{
}

void TitleCanvas::Initialize()
{
	backGroundImage = new Image("TitleBack.png");
	backGroundImage->transform.position = Vector2(HALF_SPRITE_X(backGroundImage->transform), HALF_SPRITE_Y(backGroundImage->transform));
	AddUIObject(backGroundImage);
	titleText = new Text("Space Shooter");
	titleText->SetFontData("Orbitron", 70, 3);
	titleText->transform.position = Vector2(25.0f, 50.0f);
	AddUIObject(titleText);
	pressText = new Text("Press Z Key");
	pressText->SetFontData("Orbitron", 50, 3);
	pressText->transform.position = Vector2(150, 350);
	AddUIObject(pressText);
}

void TitleCanvas::Update()
{
	BaseCanvas::Update();
}

void TitleCanvas::Draw(Renderer* renderer)
{
	BaseCanvas::Draw(renderer);
}

void TitleCanvas::Release()
{
	BaseCanvas::Release();
}
