#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include"DxLib.h"
#include"../GameObject/GameObject.h"
#include"../GameObject/Player.h"
#include"../GameObject/BackGround.h"
#include"../GameObject/EnemySpawner.h"
#include"IScene.h"
#include"../GameSceneCanvas.h"

//ゲームプレイシーン
class GameScene:public IScene
{
public:
	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void Release();

private:
	void ObjectInitialize();
	void SubjectSetting();
	void AddGameObject(GameObject* object);
private:
	Player* player;
	BackGround* backGround;
	EnemySpawner* spawner;
	GameSceneCanvas canvas;
};
#endif

