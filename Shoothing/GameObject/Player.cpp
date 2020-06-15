#include "Player.h"
#include"../Utility/InputManager.h"
#include"../Utility/ResourceManager.h"
#include"../Utility/Algorithm.h"
#include"../Screen.h"
#include"../Math.h"

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
	transform.position.x = Math::Clamp(transform.position.x, HALF_SPRITE_X, WINDOW_WIDTH - HALF_SPRITE_X);
	transform.position.y = Math::Clamp(transform.position.y, HALF_SPRITE_Y, WINDOW_HEIGHT - HALF_SPRITE_Y);
}

//描画
void Player::Draw(Renderer* renderer)
{
	renderer->DrawRotaGraph(transform.position, 1.0f, transform.angle, handle, TRUE, TRUE);
	renderer->DrawString(Vector2(0, 50), std::to_string(timer.GetNowTime()).c_str());
}

//移動
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

//攻撃処理
void Player::Shot()
{
	//弾を撃つ
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
/// SubScribeで関数を登録するため
/// 弾を発射するボタンが押されてら実行
/// </summary>
/// <returns></returns>
IObservable<Transform>* Player::OnShotButton()
{
	return &shotSubject;
}

void Player::OnHitBox(GameObject* other)
{
	//敵と接触
	if (other->tag == "Enemy") {
		hitSubject.OnNext(transform);
		Destroy();
	}
}

IObservable<Transform>* Player::OnHit()
{
	return &hitSubject;
}
