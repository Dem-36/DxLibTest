#ifndef _BULLET_H_
#define _BULLET_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>

class Bullet :public GameObject
{
public:
	//�R���X�g���N�^
	Bullet(Transform* transform);
	//�f�X�g���N�^
	~Bullet();

	//������
	void Initialize();
	//�X�V
	void Update();
	//�`��
	void Draw(Renderer* renderer);

	void OnHitBox(GameObject* other);

private:
	Vector2 velocity;
	int handle;
};
#endif

