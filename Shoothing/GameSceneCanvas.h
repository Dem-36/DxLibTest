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
	void Update()override;
	void Draw(Renderer*renderer)override;
	void Release();
public:
	Image* energyGaugeImage;
	Image* hpGaugeImage;
	Image* energyGaugeBar;
	Image* hpGaugeBar;
	Score* score;
};
#endif

