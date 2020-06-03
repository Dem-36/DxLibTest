#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include"DxLib.h"
#include"../GameObject/GameObject.h"
#include"../GameObject/Player.h"
#include"../GameObject/EnemySpawner.h"
#include"../GameObject/Score.h"
#include"IScene.h"

//ゲームプレイシーン
class GameScene:public IScene
{
public:
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void Release();

private:
	void AddGameObject(GameObject* object);
private:
	Player* player;
	EnemySpawner* spawner;
	Score* score;
};
#endif

