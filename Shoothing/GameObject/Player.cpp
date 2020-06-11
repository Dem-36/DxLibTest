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
	transform.spriteSize = Vector2(64, 64);
	velocity = Vector2(5, 5);
	soundHandle = ResourceManager::Instance()->LoadSoundResource("laser2.mp3");
	h = ResourceManager::Instance()->LoadAminImageResource("Player.png", 54, 9, 6, 64, 64);
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
	static int i = 0;
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, h[i], TRUE, TRUE);
	renderer->DrawString(Vector2(0, 50), std::to_string(timer.GetNowTime()).c_str());
}

//ˆÚ“®
void Player::Move()
{
	velocity = Vector2::Zero();

	if (InputManager::Instance()->GetKey(KEY_INPUT_UP))
		velocity.y = -1.0f;
	if (InputManager::Instance()->GetKey(KEY_INPUT_DOWN))
		velocity.y = 1.0f;
	if (InputManager::Instance()->GetKey(KEY_INPUT_LEFT))
		velocity.x = -1.0f;
	if (InputManager::Instance()->GetKey(KEY_INPUT_RIGHT))
		velocity.x = 1.0f;

	if (velocity.x != 0 && velocity.y != 0)
		velocity.Normalize();

	transform.position += velocity * 5.0f;
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
		//hitSubject.OnNext(transform);
		//Destroy();
	}
}

IObservable<Transform>* Player::OnHit()
{
	return &hitSubject;
}
