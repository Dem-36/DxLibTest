#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include"GameObject.h"
#include<list>
#include"../Singleton.h"

/// <summary>
/// GameObject�Ǘ��N���X(Singleton)
/// </summary>
class GameObjectManager:public Singleton<GameObjectManager>
{
public:
	//�R���e�i��GameObject���i�[����
	void AddGameObject(GameObject* object);

	//�R���e�i��Initialize���Ăяo��
	//void Initialize();

	//�R���e�i��Update���Ăяo��
	void Update();

	//�R���e�i��Draw���Ăяo��
	void Draw(Renderer* renderer);

	//�R���e�i��GameObject���J������
	void Release();

	//�R���e�i�̃q�b�g������s��
	void HitCheck();

	//�R���e�i��GameObject�̔j������
	void DestroyCheck();

private:
	std::list<GameObject*> container;
};

#endif

