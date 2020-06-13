#include "Player.h"
#include"../Utility/InputManager.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Algorithm.h"
#include"../Screen.h"

Player::Player()
{
	tag = "Player";
	timer.SetLimitTime(SHOT_DELAYTIME);
}

Player::~Player()
{

}

void Player::Initialize()
{
	transform.position = Vector2(320, 240);
	transform.spriteSize = Vector2(38, 32);
	velocity = Vector2::Zero();
	soundHandle = ResourceManager::Instance()->LoadSoundResource("laser2.mp3");
	handle = ResourceManager::Instance()->LoadImageResource("2.png");
}

void Player::Update()
{
	Move();
	Shot();
	transform.position.x = Algorithm::Clamp(transform.position.x, HALF_SPRITE_X, WINDOW_WIDTH - HALF_SPRITE_X);
	transform.position.y = Algorithm::Clamp(transform.position.y, HALF_SPRITE_Y, WINDOW_HEIGHT - HALF_SPRITE_Y);
}

//•`‰æ
void Player::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle, TRUE, TRUE);
	renderer->DrawString(Vector2(0, 50), std::to_string(timer.GetNowTime()).c_str());
}

//ˆÚ“®
void Player::Move()
{
	if (InputManager::Instance()->GetKey(KEY_INPUT_UP))
		transform.position += velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_DOWN))
		transform.position -= velocity;
	if (InputManager::Instance()->GetKey(KEY_INPUT_LEFT))
		transform.angle -= ToRadian(5);
	if (InputManager::Instance()->GetKey(KEY_INPUT_RIGHT))
		transform.angle += ToRadian(5);

	//if (velocity.x != 0 && velocity.y != 0)
	//	velocity.Normalize();

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
			shotSubject.OnNext(transform);
			PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);
			timer.Initialize();
		}
	}
	else
		timer.Initialize();
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
		hitSubject.OnNext(transform);
		Destroy();
	}
}

IObservable<Transform>* Player::OnHit()
{
	return &hitSubject;
}
