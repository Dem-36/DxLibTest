#include"Score.h"
#include"../Utility/ResourceManager.h"

int Score::maxScore = 0;

Score::Score()
{
	score = 0;
}

Score::~Score()
{
	if (maxScore <= score)
		maxScore = score;
}

void Score::Initialize()
{
	score = 0;
	transform.position = Vector2(450, 10);
	handle = ResourceManager::Instance()->LoadFontResource("Orbitron", 18, 3);
}

void Score::Update()
{
}

void Score::Draw(Renderer* renderer)
{
	string hiScoreLabel = "HISCORE:" + to_string(maxScore);
	renderer->DrawStringToHandle(transform.position, hiScoreLabel.c_str(), GetColor(255, 255, 255), handle);
	string label = "SCORE:" + to_string(score);
	renderer->DrawStringToHandle(transform.position + Vector2(0, 20), label.c_str(), GetColor(255, 255, 255), handle);
}

void Score::AddScore()
{
	score += 10;
}
