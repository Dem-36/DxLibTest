#include "GameSceneCanvas.h"

GameSceneCanvas::GameSceneCanvas()
{

}

void GameSceneCanvas::Initialize()
{
	score = new Score();
	energyGaugeImage = new Image("energy-bar-fill.png");
	energyGaugeBar = new Image("energy-bar.png");
	hpGaugeImage = new Image("health-bar-fill.png");
	hpGaugeBar = new Image("health-bar.png");

	Vector2 base = energyGaugeBar->transform.spriteSize;
	Vector2 half = Vector2(energyGaugeImage->transform.spriteSize.x / 2.0f ,
		energyGaugeImage->transform.spriteSize.y / 2.0f);
	energyGaugeImage->transform.position = base - half;
	energyGaugeBar->transform.position = base;

	energyGaugeImage->type = ImageType::Fill_X;
}

void GameSceneCanvas::AddObject()
{
	AddUIObject(score);
	AddUIObject(energyGaugeBar);
	AddUIObject(energyGaugeImage);
}
