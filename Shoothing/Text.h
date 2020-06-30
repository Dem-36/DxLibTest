#ifndef _TEXT_H_
#define _TEXT_H_

#include"GameObject\GameObject.h"

class Text:public GameObject
{
public:
	Text(const std::string& text);
	~Text();

	void Initialize()override;
	void Update()override;
	void Draw(Renderer* renderer)override;
	void SetFontData(const std::string& fontName,int fontSize, int thick);
public:
	std::string text;
	int color;
private:
	int fontHandle;
};

#endif