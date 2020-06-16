#include "GameScene.h"
#include"../GameObject/GameObjectManager.h"
#include"../GameObject/Enemy.h"
#include"../GameObject/Bullet.h"
#include"../GameObject/BackGround.h"
#include"../Screen.h"
#include"../GameObject/Bomb.h"
#include"SceneManager.h"
#include"Title.h"
#include"../ChaseAI.h"
#include"../StraightAI.h"
#include"../GameObject/Particle.h"

void GameScene::Initialize()
{
	player = new Player();
	backGround = new BackGround("nv_01.mp3",&player->transform);
	AddGameObject(backGround);

	//Subscribe内で関数を登録する
	//ここで言う関数は[this](Transform～の部分
	//Subscribeで関数登録 -> Player内でOnNextを呼ぶ = 登録した関数を実行という流れ
	player->OnShotButton()->Subscribe([this](Transform transform) {
		AddGameObject(new Bullet(&transform));
		});
	player->OnHit()->Subscribe([this](Transform transform) {
		AddGameObject(new Bomb(&transform));
		backGround->StopBGM();
		});
	AddGameObject(player);

	//エネミー生成位置登録
	spawner = new EnemySpawner();

	//エネミー生成
	spawner->OnSpawn()->Subscribe([this](SPAWN_TYPE type) {
		Enemy* enemy = nullptr;
		switch (Random::Range(0, 1)) {
		case 0:
			enemy = new Enemy(new ChaseAI(player),"Enemy02.png", type);
			break;
		case 1:
			enemy = new Enemy(new StraightAI(type),"Enemy01.png", type);
			break;
		}
		//Enemy* enemy = new Enemy(new StraightAI(type),type);
		//攻撃がヒットしたときの処理登録
		enemy->OnHit()->Subscribe([this](Transform transform) {
			score->AddScore();
			AddGameObject(new Bomb(&transform));
			});
		AddGameObject(enemy);
		});
	score = new Score();

	AddGameObject(score);
	AddGameObject(spawner);
}

void GameScene::Update()
{
	if (player->IsDestroy()) {
		SceneManager::Instance()->LoadScene(new Title());
	}
	GameObjectManager::Instance()->Update();
	GameObjectManager::Instance()->HitCheck();
	GameObjectManager::Instance()->DestroyCheck();
}

void GameScene::Draw(Renderer* renderer)
{
	GameObjectManager::Instance()->Draw(renderer);
}

void GameScene::Release()
{
	GameObjectManager::Instance()->Release();
}

/// <summary>
/// オブジェクトを追加する
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GameObjectManager::Instance()->AddGameObject(object);
}
