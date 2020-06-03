#include"Score.h"

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
	transform.position = Vector2(500, 0);
}

void Score::Update()
{
}

void Score::Draw(Renderer* renderer)
{
	string label = "SCORE:" + to_string(score);
	renderer->DrawString(transform.position, label.c_str());
}

void Score::AddScore()
{
	score += 10;
}
