#include"FadeManager.h"
#include"Utility/ResourceManager.h"
FadeManager::FadeManager()
	:type(FADE_TYPE::NONE), alpha(255) {
	handle = RESOURCE_MANAGER->LoadImageResource("Resource\\img\\black.png");
};

void FadeManager::FadeIn()
{
	type = FADE_TYPE::FADE_IN;
}

void FadeManager::FadeOut()
{
	type = FADE_TYPE::FADE_OUT;
}

void FadeManager::UpdateFade(Renderer* renderer)
{
	switch (type) {
	case FADE_TYPE::FADE_IN:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		renderer->DrawGraph_TL(Vector2(), handle);
		alpha += 5;
		if (alpha >= 255) {
			fadeSubject.OnNext(type);
			type = FADE_TYPE::NONE;
			alpha = 255;
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	case FADE_TYPE::FADE_OUT:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		renderer->DrawGraph_TL(Vector2(), handle);
		alpha -= 5;
		if (alpha <= 0) {
			fadeSubject.OnNext(type);
			type = FADE_TYPE::NONE;
			alpha = 0;
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	case FADE_TYPE::NONE:
		break;
	}
}

IObservable<FADE_TYPE>* FadeManager::OnFade()
{
	return &fadeSubject;
}
