#ifndef _PLAYERMOVE_H_
#define _PLAYERMOVE_H_

#include"GameObject\GameObject.h"

/// <summary>
/// �v���C���[�ړ��p�X�N���v�g
/// </summary>
class PlayerMove {
public:
	PlayerMove() = default;
	~PlayerMove() = default;

	//Player�̓��� velocity�͌����Ă�������̃x�N�g��
	void Move(Transform& player,const Vector2 velocity);
private:
	Vector2 velocity;
};

#endif