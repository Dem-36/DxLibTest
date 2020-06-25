#include "GameSceneCanvas.h"

GameSceneCanvas::GameSceneCanvas()
{

}

void GameSceneCanvas::Initialize()
{
	score = new Score();	
	AddUIObject(score);

	energyGaugeImage = new Image("energy-bar-fill.png");
	energyGaugeBar = new Image("energy-bar.png");
	hpGaugeImage = new Image("health-bar-fill.png");
	hpGaugeBar = new Image("health-bar.png");

	Vector2 pos = energyGaugeBar->transform.spriteSize-Vector2(30.0f,0.0f);
	energyGaugeBar->transform.position = pos;
	energyGaugeImage->transform.position = pos;

	pos.x *= 2.5f;
	hpGaugeBar->transform.position = pos;
	hpGaugeImage->transform.position = pos;

	energyGaugeImage->type = ImageType::Fill_X;
	hpGaugeImage->type = ImageType::Fill_X;

	AddUIObject(energyGaugeBar);
	AddUIObject(energyGaugeImage);
	AddUIObject(hpGaugeBar);
	AddUIObject(hpGaugeImage);
}

void GameSceneCanvas::Update()
{
	BaseCanvas::Update();
}

void GameSceneCanvas::Draw(Renderer* renderer)
{
	BaseCanvas::Draw(renderer);
}

void GameSceneCanvas::Release()
{
	BaseCanvas::Release();
}