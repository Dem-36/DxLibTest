#include "Player.h"
#include"../Utility/InputManager.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Algorithm.h"
#include"../Screen.h"

Player::Player()
{
	tag = "Player";
}

Player::~Player()
{

}

void Player::Initialize()
{
	transform.position = Vector2(320, 240);
	transform.spriteSize = Vector2(64, 64);
	velocity = Vector2(5, 5);
	soundHandle = RESOURCE_MANAGER->LoadSoundResource("laser2.mp3");
	h = RESOURCE_MANAGER->LoadAminImageResource("Player.png", 54, 9, 6, 64, 64);
	waitFrame = 0;
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
}

//ˆÚ“®
void Player::Move()
{
	velocity = Vector2::Zero();

	if (INPUT_MANAGER->GetKey(KEY_INPUT_UP))
		velocity.y = -1.0f;
	if (INPUT_MANAGER->GetKey(KEY_INPUT_DOWN))
		velocity.y = 1.0f;
	if (INPUT_MANAGER->GetKey(KEY_INPUT_LEFT))
		velocity.x = -1.0f;
	if (INPUT_MANAGER->GetKey(KEY_INPUT_RIGHT))
		velocity.x = 1.0f;

	if (velocity.x != 0 && velocity.y != 0)
		velocity.Normalize();

	transform.position += velocity * 5.0f;
}

//UŒ‚ˆ—
void Player::Shot()
{
	//’e‚ğŒ‚‚Â
	if (INPUT_MANAGER->GetKey(KEY_INPUT_SPACE)) {
		if (waitFrame == 0) {
			shotSubject.OnNext(transform);
			PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);
			waitFrame = 1;
		}
		waitFrame++;
		if (waitFrame > SHOT_DELAYFRAME)
			waitFrame = 0;
	}
	else
		waitFrame = 0;
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
