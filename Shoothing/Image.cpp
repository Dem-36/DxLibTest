#include "Image.h"
#include"Utility\ResourceManager.h"
#include"DxLibExpansion.h"
#include"Utility\Rectangle.h"
#include"Math.h"

Image::Image(std::string fileName)
{
	imageHandle = ResourceManager::Instance()->LoadImageResource(fileName);
	transform.spriteSize = DxLibExpansion::GetSpriteSize(imageHandle);
	ratio = 1.0f;
}

Image::~Image()
{
}

void Image::Initialize()
{}

void Image::Update()
{}

void Image::Draw(Renderer* renderer)
{
	if (type == ImageType::Simple) {
		renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, imageHandle);
	}
	else if (type == ImageType::Fill_X) {
		ratio = Math::Clamp(ratio, 0.0f, 1.0f);
		Vector2 size = Vector2(transform.spriteSize.x * ratio, transform.spriteSize.y);
		renderer->DrawRectGraph_C(transform, struct Rectangle(Vector2(), size), imageHandle);
	}
	else if (type == ImageType::Fill_Y) {
		ratio = Math::Clamp(ratio, 0.0f, 1.0f);
		Vector2 size = Vector2(transform.spriteSize.x, transform.spriteSize.y * ratio);
		renderer->DrawRectGraph_C(transform, struct Rectangle(Vector2(), size), imageHandle);
	}
}
