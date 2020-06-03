#include "GameScene.h"
#include"../GameObject/GameObjectManager.h"
#include"../GameObject/Enemy.h"
#include"../GameObject/Bullet.h"
#include"../GameObject/BackGround.h"
#include"../Screen.h"
#include"../GameObject/Bomb.h"
#include"SceneManager.h"
#include"Title.h"

void GameScene::Initialize()
{
	AddGameObject(new BackGround());

	player = new Player();

	//Subscribe“à‚ÅŠÖ”‚ğ“o˜^‚·‚é
	//‚±‚±‚ÅŒ¾‚¤ŠÖ”‚Í[this](Transform`‚Ì•”•ª
	//Subscribe‚ÅŠÖ”“o˜^ -> Player“à‚ÅOnNext‚ğŒÄ‚Ô = “o˜^‚µ‚½ŠÖ”‚ğÀs‚Æ‚¢‚¤—¬‚ê
	player->OnShotButton()->Subscribe([this](Transform transform) {
		AddGameObject(new Bullet(&transform));
		});
	AddGameObject(player);

	spawner = new EnemySpawner();
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, -32.0f));
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT + 32.0f));
	spawner->AddSpawnPoint(Vector2(-32.0f, WINDOW_HEIGHT / 2.0f));
	spawner->AddSpawnPoint(Vector2(WINDOW_WIDTH + 32, WINDOW_HEIGHT / 2.0f));

	spawner->OnSpawn()->Subscribe([this](Vector2 position) {
		Enemy* enemy = new Enemy(position);
		enemy->SetTarget(player);
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
/// ƒIƒuƒWƒFƒNƒg‚ğ’Ç‰Á‚·‚é
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GAMEOBJECT_MANAGER->AddGameObject(object);
}
