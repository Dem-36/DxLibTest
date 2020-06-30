#ifndef _TITLECANVAS_H_
#define _TITLECANVAS_H_

#include"Text.h"
#include"Image.h"
#include"BaseCanvas.h"

class TitleCanvas:public BaseCanvas
{
public:
	TitleCanvas();

	void Initialize()override;
	void Update()override;
	void Draw(Renderer* renderer)override;
	void Release();
public:
	Text* titleText;
	Text* pressText;
	Image* backGroundImage;
};
#endif
