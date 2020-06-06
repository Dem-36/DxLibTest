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
#include"../GameObject/Particle.h"

void GameScene::Initialize()
{
	AddGameObject(new BackGround());

	player = new Player();

	//Subscribe内で関数を登録する
	//ここで言う関数は[this](Transform～の部分
	//Subscribeで関数登録 -> Player内でOnNextを呼ぶ = 登録した関数を実行という流れ
	player->OnShotButton()->Subscribe([this](Transform transform) {
		AddGameObject(new Bullet(&transform));
		});
	AddGameObject(player);

	//エネミー生成位置登録
	spawner = new EnemySpawner();
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, -32.0f));
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT + 32.0f));
	spawner->AddSpawnPoint(Vector2(-32.0f, WINDOW_HEIGHT / 2.0f));
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH + 32, WINDOW_HEIGHT / 2.0f));

	//エネミー生成
	spawner->OnSpawn()->Subscribe([this](Vector2 position) {
		Enemy* enemy = new Enemy(new ChaseAI(player),position);
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
	//if (INPUT_MANAGER->GetKeyDown(KEY_INPUT_Z)) {
	//	SceneManager::Instance()->LoadScene(new Title());
	//}
	GAMEOBJECT_MANAGER->Update();
	GAMEOBJECT_MANAGER->HitCheck();
	GAMEOBJECT_MANAGER->DestroyCheck();
}

void GameScene::Draw(Renderer* renderer)
{
	GAMEOBJECT_MANAGER->Draw(renderer);
}

void GameScene::Release()
{
	GAMEOBJECT_MANAGER->Release();
}

/// <summary>
/// オブジェクトを追加する
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GAMEOBJECT_MANAGER->AddGameObject(object);
}
