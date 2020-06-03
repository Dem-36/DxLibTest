#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include"GameObject.h"
#include<list>

#define GAMEOBJECT_MANAGER GameObjectManager::Instance()

/// <summary>
/// GameObject�Ǘ��N���X(Singleton)
/// </summary>
class GameObjectManager
{
private:
	//�O����C���X�^���X�������ł��Ȃ��悤�ɂ���
	GameObjectManager(){}
	GameObjectManager(const GameObjectManager&){}
public:
	//�C���X�^���X�̎擾
	static GameObjectManager* Instance();
	//�C���X�^���X�̉��
	static void DestroyInstance();

	//�R���e�i��GameObject���i�[����
	void AddGameObject(GameObject* object);

	//�R���e�i��Initialize���Ăяo��
	void Initialize();

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
	static GameObjectManager* instance;
};

#endif

