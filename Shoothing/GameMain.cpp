//#include "GameMain.h"
//#include"InputManager.h"
//#include"GameObjectManager.h"
//#include"ResourceManager.h"
//#include"Enemy.h"
//#include"Bullet.h"
//#include"Particle.h"
//#include"BackGround.h"
//#include"Screen.h"
//
///// <summary>
///// 初期化
///// </summary>
//void GameMain::Initialize() {
//
//	AddGameObject(new BackGround());
//
//	player = new Player();
//
//	//Subscribe内で関数を登録する
//	//ここで言う関数は[this](Transform〜の部分
//	//Subscribeで関数登録 -> Player内でOnNextを呼ぶ = 登録した関数を実行という流れ
//	player->OnShotButton()->Subscribe([this](Transform transform) {
//		AddGameObject(new Bullet(&transform));
//		});
//	AddGameObject(player);
//
//	spawner = new EnemySpawner();
//	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, -32.0f));
//	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT + 32.0f));
//	spawner->AddSpawnPoint(Vector2(-32.0f, WINDOW_HEIGHT / 2.0f));
//	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH + 32, WINDOW_HEIGHT / 2.0f));
//
//	spawner->OnSpawn()->Subscribe([this](Vector2 position) {
//		Enemy* enemy = new Enemy(position);
//		enemy->SetTarget(player);
//		enemy->OnHit()->Subscribe([this](Transform transform) {
//			score->AddScore();
//			AddGameObject(new Particle(&transform));
//			});
//
//		AddGameObject(enemy);
//		});
//	score = new Score();
//
//	AddGameObject(score);
//	AddGameObject(spawner);
//}
//
///// <summary>
///// 更新
///// </summary>
//void GameMain::Update() {
//	INPUT_MANAGER->UpdateKey();
//
//	GAMEOBJECT_MANAGER->Update();
//	GAMEOBJECT_MANAGER->Draw(&renderer);
//	GAMEOBJECT_MANAGER->HitCheck();
//
//	GAMEOBJECT_MANAGER->DestroyCheck();
//}
//
///// <summary>
///// 解放処理
///// </summary>
//void GameMain::Release() {
//	GAMEOBJECT_MANAGER->Release();
//}
//
///// <summary>
///// オブジェクトを追加する
///// </summary>
///// <param name="object"></param>
//void GameMain::AddGameObject(GameObject* object)
//{
//	GAMEOBJECT_MANAGER->AddGameObject(object);
//}
