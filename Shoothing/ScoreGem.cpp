#include "ScoreGem.h"
#include"Easing.h"
#include"Utility\Random.h"
#include"Math.h"
#include"Utility\Algorithm.h"
#include"Screen.h"
#include"DxLibExpansion.h"
#include"Utility\ResourceManager.h"

ScoreGem::ScoreGem(GameObject* player,const Transform* transform, int exp)
	:player(player), m_exp(exp)
{
	this->transform.position = transform->position;
	std::string name = "gem-" + std::to_string(exp) + ".png";
	int handle = ResourceManager::Instance()->LoadImageResource(name);
	Vector2 size = DxLibExpansion::GetSpriteSize(handle);
	this->transform.spriteSize = Vector2(size.x / 4, size.y);
	anim.SetAnim(name, 4, 4, 1, this->transform.spriteSize.x,this->transform.spriteSize.y, 0.2f);
	anim.SetLoopFlag(true);
}

void ScoreGem::Initialize()
{
	transform.angle = Random::Range(0.0f, 360.0f) * Math::Deg2Rad();
	velocity = Vector2(1, 0);
	velocity = Algorithm::RotationMatrix_Z(velocity, transform.angle);
	speed = Random::Range(5.0f, 10.0f);
}

void ScoreGem::Update()
{

	float dist = Vector2::Distance(transform.position, player->transform.position);
	if (dist < 100.0f) {
		Vector2 direction = player->transform.position - transform.position;
		direction.Normalize();
		transform.position += direction * 8.0f;
		return;
	}

	time.Update();
	transform.position += velocity * speed;
	speed = Easing::QuadraticOut(time.GetNowTime(), time.GetLimitTime(), speed, 0.0f);

	transform.position.x = Math::Clamp(transform.position.x, 0.0f, WINDOW_WIDTH + HALF_SPRITE_X);
	transform.position.y = Math::Clamp(transform.position.y, 0.0f, WINDOW_HEIGHT + HALF_SPRITE_Y);
}

void ScoreGem::Draw(Renderer* renderer)
{
	renderer->DrawGraph_C(transform.position,
		transform.spriteSize, anim.GetAnimHandle());

	anim.Update();
}

void ScoreGem::OnHitBox(GameObject* other)
{
	if (other->tag == "Player") {
		hitSubject.OnNext(m_exp);
		Destroy();
	}
}

int ScoreGem::GetExp() const noexcept
{
	return m_exp;
}

IObservable<int>* ScoreGem::OnHit()
{
	return &hitSubject;
}
