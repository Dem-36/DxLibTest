#include "GameObjectManager.h"
#include"../Utility/Collision.h"

void GameObjectManager::AddGameObject(GameObject* object)
{
	//objectがNULLなら追加しない
	if (object == NULL)
		return;
	object->Initialize();
	container.push_back(object);
}

void GameObjectManager::Update()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;
		(*itr)->Update();
	}
}

void GameObjectManager::Draw(Renderer* renderer)
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;
		(*itr)->Draw(renderer);
	}
}

void GameObjectManager::Release()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end();) {
		if ((*itr) != NULL) {
			delete (*itr);
			itr = container.erase(itr);
			continue;
		}
		itr++;
	}
	container.clear();
}

void GameObjectManager::HitCheck()
{
	std::list<GameObject*>::iterator itr;
	std::list<GameObject*>::iterator tgt;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		//すでに破棄済みなら処理をスキップする
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;

		for (tgt = container.begin(); tgt != container.end(); ++tgt) {

			//すでに破棄済み、もしくは
			//同一のオブジェクトなら
			if ((*tgt) == NULL ||
				(*tgt)->IsDestroy() ||
				tgt == itr)
				continue;

			if (Collision::OnHitRect(&(*itr)->transform, &(*tgt)->transform)) {
				(*itr)->OnHitBox((*tgt));
				(*tgt)->OnHitBox((*itr));
			}
		}
	}
}

void GameObjectManager::DestroyCheck()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end();) {
		if ((*itr) != NULL && (*itr)->IsDestroy()) {
			delete (*itr);
			//イテレータを削除した後、次のイテレータを取得する
			//ここで、インクリメントをするとバグになる(すでに次の値を取得しているため)
			itr = container.erase(itr);
			continue;
		}
		//破棄するフラグがtrue出ないなら次のデータにする
		itr++;
	}
}
