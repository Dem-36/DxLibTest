#ifndef _GAMESCENECANVAS_H_
#define _GAMESCENECANVAS_H_

#include"BaseCanvas.h"
#include"Image.h"
#include"GameObject\Score.h"

class GameSceneCanvas :public BaseCanvas
{
public:
	GameSceneCanvas();

	void Initialize()override;
	void AddObject()override;
public:
	Image* energyGaugeImage;
	Image* hpGaugeImage;
	Image* energyGaugeBar;
	Image* hpGaugeBar;
	Score* score;
};
#endif

