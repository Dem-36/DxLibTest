#ifndef _PLAYERMOVE_H_
#define _PLAYERMOVE_H_

#include"GameObject\GameObject.h"

/// <summary>
/// プレイヤー移動用スクリプト
/// </summary>
class PlayerMove {
public:
	PlayerMove() = default;
	~PlayerMove() = default;

	//Playerの動き velocityは向いている向きのベクトル
	void Move(Transform& player,const Vector2 velocity);
private:
	Vector2 velocity;
};

#endif