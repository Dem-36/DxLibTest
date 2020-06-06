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
	velocity = Vector2(5, 0);
	soundHandle = RESOURCE_MANAGER->LoadSoundResource("laser2.mp3");
	h = RESOURCE_MANAGER->LoadAminImageResource("Player.png", 54, 9, 6, 64, 64);
	waitFrame = 0;
}

void Player::Update()
{
	Move();

	Shot();

	transform.position.x = Algorithm::Clamp(transform.position.x, 0.0f, WINDOW_WIDTH);
	transform.position.y = Algorithm::Clamp(transform.position.y, 0.0f, WINDOW_HEIGHT);

	//はじめ、画像自体が右を向いているため？
	Vector2 moveVel(3, 0);
	//Z軸方向に回転する行列
	velocity = Algorithm::RotationMatrix_Z(moveVel, transform.angle);
}

void Player::Draw(Renderer* renderer)
{
	static int i =0;
		renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, h[i], TRUE, TRUE);
}

void Player::Move()
{
	if (INPUT_MANAGER->GetKey(KEY_INPUT_UP))
		transform.position += velocity;
	if (INPUT_MANAGER->GetKey(KEY_INPUT_DOWN))
		transform.position -= velocity;
	if (INPUT_MANAGER->GetKey(KEY_INPUT_LEFT))
		transform.angle -= ToRadian(4);
	if (INPUT_MANAGER->GetKey(KEY_INPUT_RIGHT))
		transform.angle += ToRadian(4);
}

void Player::Shot()
{
	//弾を撃つ
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
/// SubScribeで関数を登録するため
/// 弾を発射するボタンが押されてら実行
/// </summary>
/// <returns></returns>
IObservable<Transform>* Player::OnShotButton()
{
	return &shotSubject;
}
