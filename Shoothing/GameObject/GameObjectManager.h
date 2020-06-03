#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_

#include"GameObject.h"
#include<list>

#define GAMEOBJECT_MANAGER GameObjectManager::Instance()

/// <summary>
/// GameObject管理クラス(Singleton)
/// </summary>
class GameObjectManager
{
private:
	//外からインスタンスが生成できないようにする
	GameObjectManager(){}
	GameObjectManager(const GameObjectManager&){}
public:
	//インスタンスの取得
	static GameObjectManager* Instance();
	//インスタンスの解放
	static void DestroyInstance();

	//コンテナにGameObjectを格納する
	void AddGameObject(GameObject* object);

	//コンテナのInitializeを呼び出す
	void Initialize();

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
	static GameObjectManager* instance;
};

#endif

