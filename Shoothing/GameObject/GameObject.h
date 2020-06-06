#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include"Transform.h"
#include<string>
#include"../Utility/Renderer.h"

using namespace std;

//�摜���̔�����Ԃ�
#define HALF_SPRITE_X ((transform.spriteSize.x) / (2.0f))
//�摜�̍����̔�����Ԃ�
#define HALF_SPRITE_Y ((transform.spriteSize.y) / (2.0f))

class GameObject {
public:
	//�R���X�g���N�^
	GameObject():
		isDestroy(false){}

	//�f�X�g���N�^(���z�֐�)
	virtual ~GameObject() {}

	//������(�������֐�)
	virtual void Initialize() = 0;
	
	//�X�V(�������z�֐�)
	virtual void Update() = 0;

	//�`��(�������z�֐�)
	virtual void Draw(Renderer* renderer) = 0;

	//�j��(���z�֐�)
	virtual void Destroy() {
		isDestroy = true;
	}

	//�t���O�̎擾
	bool IsDestroy() {
		return isDestroy;
	}

	//��`�̃q�b�g����(���z�֐�)
	virtual void OnHitBox(GameObject* other){}

public:
	Transform transform;
	string tag;        //�^�O
private:
	//�폜�t���O
	bool isDestroy;
};

#endif