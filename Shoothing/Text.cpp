#include "Text.h"
#include"Utility\ResourceManager.h"

Text::Text(const std::string& text)
	:fontHandle(0), color(GetColor(255, 255, 255)), text(text)
{

}

Text::~Text()
{
}

void Text::Initialize()
{
}

void Text::Update()
{
}

void Text::Draw(Renderer* renderer)
{
	renderer->DrawStringToHandle(transform.position, text.c_str(), color,fontHandle);
}

void Text::SetFontData(const std::string& fontName, int fontSize, int thick)
{
	fontHandle = ResourceManager::Instance()->LoadFontResource(fontName, fontSize, thick);
}
