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
	//�G�l�~�[�����ʒu�o�^
	spawner = new EnemySpawner();
}

void GameScene::SubjectSetting()
{
	AddGameObject(backGround);
#pragma region Player
	//Subscribe���Ŋ֐���o�^����
	//�����Ō����֐���[this](Transform�`�̕���
	//Subscribe�Ŋ֐��o�^ -> Player����OnNext���Ă� = �o�^�����֐������s�Ƃ�������
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
	//�G�l�~�[����
	spawner->OnSpawn()->Subscribe([this](char c) {

		float diff = (float)(player->expManager.GetLevel()) / (float)(MAX_LEVEL);
		Enemy* enemy = spawner->Spawn(player, diff);

		//�U�����q�b�g�����Ƃ��̏����o�^
		enemy->OnHit()->Subscribe([this](Transform transform) {
			AddGameObject(new Bomb(&transform));
			});
		enemy->OnDrop()->Subscribe([this](EnemyHitInfo info) {
			int exp = info.exp;
			while (0 < exp) {
				int gemExp = Random::Range(1, (int)Math::Clamp(exp + 1,1,4));
				ScoreGem* gem = new ScoreGem(player, &info.t, gemExp);
				gem->OnHit()->Subscribe([this](int e) {
					player->expManager.AddExp(e);
					canvas.energyGaugeImage->ratio = player->expManager.ExpRatio();
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

	canvas.energyGaugeImage->ratio = player->expManager.ExpRatio();
}

/// <summary>
/// �I�u�W�F�N�g��ǉ�����
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GameObjectManager::Instance()->AddGameObject(object);
}
