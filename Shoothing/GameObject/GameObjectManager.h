#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include"GameObject.h"
#include<list>
#include"../Singleton.h"

/// <summary>
/// GameObject管理クラス(Singleton)
/// </summary>
class GameObjectManager:public Singleton<GameObjectManager>
{
public:
	//コンテナにGameObjectを格納する
	void AddGameObject(GameObject* object);

	//コンテナのInitializeを呼び出す
	//void Initialize();

	//コンテナのUpdateを呼び出す
	void Update();

	//コンテナのDrawを呼び出す
	void Draw(Renderer* renderer);

	//コンテナのGameObjectを開放する
	void Release();

	//コンテナのヒット判定を行う
	void HitCheck();

	//コンテナのGameObjectの破棄判定
	void DestroyCheck();

private:
	std::list<GameObject*> container;
};

#endif

