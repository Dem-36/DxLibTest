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
#include"../ScoreGem.h"

void GameScene::Initialize()
{
	canvas.Initialize();
	ObjectInitialize();
	SubjectSetting();
}

void GameScene::Update()
{
	GameObjectManager::Instance()->Update();
	GameObjectManager::Instance()->HitCheck();
	GameObjectManager::Instance()->DestroyCheck();
	canvas.Update();
}

void GameScene::Draw(Renderer* renderer)
{
	GameObjectManager::Instance()->Draw(renderer);
	canvas.Draw(renderer);
}

void GameScene::Release()
{
	GameObjectManager::Instance()->Release();
	canvas.Release();
}

void GameScene::ObjectInitialize()
{
	player = new Player();
	backGround = new BackGround("GamePlay.ogg", &player->transform);
	//ƒGƒlƒ~[¶¬ˆÊ’u“o˜^
	spawner = new EnemySpawner();
}

void GameScene::SubjectSetting()
{
	AddGameObject(backGround);
#pragma region Player
	//Subscribe“à‚ÅŠÖ”‚ð“o˜^‚·‚é
	//‚±‚±‚ÅŒ¾‚¤ŠÖ”‚Í[this](Transform`‚Ì•”•ª
	//Subscribe‚ÅŠÖ”“o˜^ -> Player“à‚ÅOnNext‚ðŒÄ‚Ô = “o˜^‚µ‚½ŠÖ”‚ðŽÀs‚Æ‚¢‚¤—¬‚ê
	player->playerAttack.OnShot()->Subscribe([this](Transform transform) {
		AddGameObject(new Bullet(&transform));
		});
	player->OnHit()->Subscribe([this](Transform transform) {
		canvas.hpGaugeImage->ratio = player->HPRatio();
		});
	player->OnDead()->Subscribe([this](Transform transform) {
		AddGameObject(new Bomb(&transform));
		backGround->StopBGM();
		SceneManager::Instance()->LoadScene(new Title());
		});
	player->OnLevelUp()->Subscribe([this](Transform transform) {
		canvas.hpGaugeImage->ratio = player->HPRatio();
		});
	AddGameObject(player);
#pragma endregion

#pragma region Enemy
	//ƒGƒlƒ~[¶¬
	spawner->OnSpawn()->Subscribe([this](SPAWN_TYPE type) {
		Enemy* enemy = nullptr;
		float r = Random::Range(0.0f, 100.0f);
		if (r <= 20.0f)
			enemy = new Enemy(new ChaseAI(player), "Enemy02.png", type, 2, 2);
		else if (r < 60.0f)
			enemy = new Enemy(new StraightAI(type), "Enemy01.png", type, 1, 1);
		else if (r <= 70.0f)
			enemy = new Enemy(new ChaseAI(player), "Enemy03.png", type, 4, 4);
		else
			enemy = new Enemy(new StraightAI(type), "Enemy04.png", type, 6, 6);

		//UŒ‚‚ªƒqƒbƒg‚µ‚½‚Æ‚«‚Ìˆ—“o˜^
		enemy->OnHit()->Subscribe([this](Transform transform) {
			AddGameObject(new Bomb(&transform));
			});
		enemy->OnDrop()->Subscribe([this](EnemyHitInfo info) {
			int exp = info.exp;
			while (0 < exp) {
				int gemExp = Random::Range(1, 4);
				ScoreGem* gem = new ScoreGem(player, &info.t, gemExp);
				gem->OnHit()->Subscribe([this](int e) {
					player->AddExp(e);
					canvas.energyGaugeImage->ratio = player->ExpRatio();
					});
				AddGameObject(gem);
				exp -= gem->GetExp();
			}
			canvas.score->AddScore();
			});
		AddGameObject(enemy);
		});
	AddGameObject(spawner);
#pragma endregion

	canvas.energyGaugeImage->ratio = player->ExpRatio();
}

/// <summary>
/// ƒIƒuƒWƒFƒNƒg‚ð’Ç‰Á‚·‚é
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GameObjectManager::Instance()->AddGameObject(object);
}
