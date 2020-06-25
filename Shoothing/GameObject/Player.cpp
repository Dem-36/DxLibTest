#include "Player.h"
#include"../Utility/InputManager.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Algorithm.h"
#include"../Screen.h"
#include"../Math.h"
#include"../DxLibExpansion.h"

Player::Player()
{
	tag = "Player";
	timer.SetLimitTime(SHOT_DELAYTIME);
	hp = MAX_HP;
}

Player::~Player()
{

}

void Player::Initialize()
{
	handle = ResourceManager::Instance()->LoadImageResource("2.png");
	soundHandle = api.LoadSound("laser2.mp3");
	transform.position = Vector2(320, 240);
	transform.spriteSize = DxLibExpansion::GetSpriteSize(handle);
	velocity = Vector2::Zero();
	expManager.Initialize(1, 16, 18);

	expManager.OnLevelUp()->Subscribe([this](char c) {
		NWayShot(30, 360.0f);
		hp = MAX_HP;
		levelUpSubject.OnNext(transform);
		});
}

void Player::Update()
{
	Move();
	Shot();
	transform.position.x = Math::Clamp(transform.position.x, HALF_SPRITE_X, WINDOW_WIDTH - HALF_SPRITE_X);
	transform.position.y = Math::Clamp(transform.position.y, HALF_SPRITE_Y, WINDOW_HEIGHT - HALF_SPRITE_Y);
}

//•`‰æ
void Player::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle, TRUE, TRUE);
	expManager.Draw(renderer);
}

//ˆÚ“®
void Player::Move()
{
	if (InputManager::Instance()->GetKey(KEY_INPUT_UP))
		transform.position += velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_DOWN))
		transform.position -= velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_LEFT))
		transform.angle -= 5.0f * Math::Deg2Rad();
	if (InputManager::Instance()->GetKey(KEY_INPUT_RIGHT))
		transform.angle += 5.0f * Math::Deg2Rad();

	velocity = Vector2(0, -5);
	velocity = Algorithm::RotationMatrix_Z(velocity, transform.angle);
}

//UŒ‚ˆ—
void Player::Shot()
{
	//’e‚ğŒ‚‚Â
	if (InputManager::Instance()->GetKey(KEY_INPUT_SPACE)) {
		timer.Update();
		if (timer.IsTime()) {
			NWayShot(3, 30.0f);
			timer.Initialize();
		}
	}
	else
		timer.Initialize();
}

void Player::NWayShot(int shotCount, float shotRange)
{
	Vector2 pos = transform.position;
	float baseAngle = transform.angle;

	if (shotCount > 1) {
		for (int i = 0; i < shotCount; i++) {
			//NWay ’e‚Ì”­ËŠp“xŒvZ
			float angle = baseAngle + (shotRange * Math::Deg2Rad()) * ((float)i / (shotCount - 1) - 0.5f);
			Transform t;
			t.position = pos;
			t.angle = angle;
			shotSubject.OnNext(t);
			api.PlaySE(soundHandle);
		}
	}
	else if (shotCount > 0) {
		shotSubject.OnNext(transform);
		api.PlaySE(soundHandle);
	}
}

/// <summary>
/// SubScribe‚ÅŠÖ”‚ğ“o˜^‚·‚é‚½‚ß
/// ’e‚ğ”­Ë‚·‚éƒ{ƒ^ƒ“‚ª‰Ÿ‚³‚ê‚Ä‚çÀs
/// </summary>
/// <returns></returns>
IObservable<Transform>* Player::OnShotButton()
{
	return &shotSubject;
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

void Player::AddExp(int exp)
{
	expManager.AddExp(exp);
}

float Player::ExpRatio() {
	return expManager.ExpRatio();
}

float Player::HPRatio() {
	return hp / MAX_HP;
}
