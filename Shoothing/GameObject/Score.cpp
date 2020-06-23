#include"Score.h"
#include"../Utility/ResourceManager.h"

Score::Score()
{
	score = 0;
}

Score::~Score()
{
}

void Score::Initialize()
{
	score = 0;
	transform.position = Vector2(400, 0);
	handle = ResourceManager::Instance()->LoadFontResource("Orbitron", 20, 3);
}

void Score::Update()
{
}

void Score::Draw(Renderer* renderer)
{
	string label = "SCORE:" + to_string(score);
	renderer->DrawStringToHandle(transform.position, label.c_str(), GetColor(255, 255, 255), handle);
}

void Score::AddScore()
{
	score += 10;
}
