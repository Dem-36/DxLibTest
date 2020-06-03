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
///// ‰Šú‰»
///// </summary>
//void GameMain::Initialize() {
//
//	AddGameObject(new BackGround());
//
//	player = new Player();
//
//	//Subscribe“à‚ÅŠÖ”‚ğ“o˜^‚·‚é
//	//‚±‚±‚ÅŒ¾‚¤ŠÖ”‚Í[this](Transform`‚Ì•”•ª
//	//Subscribe‚ÅŠÖ”“o˜^ -> Player“à‚ÅOnNext‚ğŒÄ‚Ô = “o˜^‚µ‚½ŠÖ”‚ğÀs‚Æ‚¢‚¤—¬‚ê
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
///// XV
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
///// ‰ğ•úˆ—
///// </summary>
//void GameMain::Release() {
//	GAMEOBJECT_MANAGER->Release();
//}
//
///// <summary>
///// ƒIƒuƒWƒFƒNƒg‚ğ’Ç‰Á‚·‚é
///// </summary>
///// <param name="object"></param>
//void GameMain::AddGameObject(GameObject* object)
//{
//	GAMEOBJECT_MANAGER->AddGameObject(object);
//}
