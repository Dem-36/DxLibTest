#include "Particle.h"
#include"../Utility/Random.h"
Particle::Particle(Vector2 position)
{
	transform.position = position;
}

Particle::Particle(Transform* transform)
{
	this->transform.position = transform->position;
	this->transform.angle = transform->angle;
	this->transform.spriteSize = Vector2(1, 1);
}

Particle::~Particle()
{
}

void Particle::Initialize()
{
	CreateSpark();
}

void Particle::Update()
{
	if (IsDestroy())
		return;

	int i;
	int deadNum = 0;
	for (i = 0; i < SPARK_NUM; i++) {
		if (!spark[i].valid) {
			deadNum++;
			continue;
		}

		//ˆÚ“®—Ê‚É‡‚í‚¹‚ÄˆÊ’u‚ð•ÏX
		spark[i].position += spark[i].velocity;
		//‰º‚É—Ž‚Æ‚µ‚Ä‚¢‚­
		spark[i].velocity.y += spark[i].gravity;
		//–¾‚é‚³‚ð‰º‚°‚é
		spark[i].bright -= 2;
		if (spark[i].bright <= 0)
			spark[i].valid = false;
	}

	if (deadNum >= SPARK_NUM)
		Destroy();
}

void Particle::Draw(Renderer* renderer)
{
	int i;
	for (i = 0; i < SPARK_NUM; i++) {
		if (!spark[i].valid)
			continue;
		renderer->DrawPixel(spark[i].position,
			GetColor(spark[i].bright, spark[i].bright, spark[i].bright));
	}
}

void Particle::CreateSpark()
{
	int i;
	for (i = 0; i < SPARK_NUM; i++) {
		spark[i].position = transform.position;

		spark[i].velocity = Vector2(Random::Range(-5.0f, 5.0f), Random::Range(-10.0f, 0.0f));
		spark[i].gravity = Random::Range(1.0f, 2.0f);
		spark[i].bright = 255;
		spark[i].valid = true;
	}
}
