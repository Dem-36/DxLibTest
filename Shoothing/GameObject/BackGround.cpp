#include "BackGround.h"
#include"../Utility/ResourceManager.h"
#include"../Math.h"
#include"../Screen.h"

BackGround::BackGround(std::string bgmName, Transform* t_Player)
{
	transform.position = Vector2();
	transform.spriteSize = Vector2();
	bgmHandle = api.LoadSound(bgmName,SOUND_TYPE::BGM);
	this->t_Player = t_Player;
}

BackGround::~BackGround()
{
	AudioManager::Instance()->StopBGM();
}

void BackGround::Initialize()
{
	handle = ResourceManager::Instance()->LoadImageResource("5.png");
	api.PlayBGM(bgmHandle);
}

void BackGround::Update()
{
	Vector2 pos = t_Player->position;
	const Vector2 limit(WINDOW_WIDTH, WINDOW_HEIGHT);

	float tx = Math::InverseLerp(-limit.x, limit.x, pos.x);
	float ty = Math::InverseLerp(-limit.y, limit.y, pos.y);
	Vector2 m_Limit(100.0f, 80.0f);
	tx = Math::Lerp(-m_Limit.x, m_Limit.x, tx);
	ty = Math::Lerp(-m_Limit.y, m_Limit.y, ty);

	transform.position = Vector2(tx, ty);
}

void BackGround::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position + Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f),
		1.0f, 0.0f, handle);
}

void BackGround::StopBGM()
{
	api.StopBGM();
}
