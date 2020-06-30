#include "Player.h"
#include"../Utility/InputManager.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Algorithm.h"
#include"../Screen.h"
#include"../DxLibExpansion.h"

Player::Player()
	:playerAttack(this)
{
	tag = "Player";
	hp = MAX_HP;
}

Player::~Player()
{

}

void Player::Initialize()
{
	handle = ResourceManager::Instance()->LoadImageResource("Player.png");
	transform.position = Vector2(320, 240);
	transform.spriteSize = DxLibExpansion::GetSpriteSize(handle);
	expManager.Initialize(1, 16, 18);
	parameter.Initialize(1, 4, 0.35f, 0.2f, 50.0f, 150.0f);
	playerAttack.UpdateInterval(parameter.shotInterval);

	expManager.OnLevelUp()->Subscribe([this](char c) {
		playerAttack.NWayShot(30, 360);
		hp = MAX_HP;
		parameter.UpdateParameter(expManager.GetLevel());
		playerAttack.UpdateInterval(parameter.shotInterval);
		levelUpSubject.OnNext(transform);
		});
}

void Player::Update()
{
	playerMove.Move(transform, Vector2(0.0f, -5.0f));
	playerAttack.Shot(parameter.shotCount, 15);
	transform.position.x = Math::Clamp(transform.position.x, HALF_SPRITE_X(transform), WINDOW_WIDTH - HALF_SPRITE_X(transform));
	transform.position.y = Math::Clamp(transform.position.y, HALF_SPRITE_Y(transform), WINDOW_HEIGHT - HALF_SPRITE_Y(transform));
}

//•`‰æ
void Player::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle, TRUE, TRUE);
	expManager.Draw(renderer);
}

void Player::OnHitBox(GameObject* other)
{
	//“G‚ÆÚG
	if (other->tag == "Enemy") {
		hp--;
		hitSubject.OnNext(transform);
		if (hp <= 0) {
			deadSubject.OnNext(transform);
			Destroy();
		}
	}
}

IObservable<Transform>* Player::OnHit()
{
	return &hitSubject;
}

IObservable<Transform>* Player::OnDead()
{
	return &deadSubject;
}

IObservable<Transform>* Player::OnLevelUp()
{
	return &levelUpSubject;
}

float Player::HPRatio() {
	return hp / MAX_HP;
}

float Player::DrawDist()const
{
	return parameter.drawGem;
}
