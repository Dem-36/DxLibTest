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
	ObjectInitialize();
	SubjectSetting();
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

void GameScene::ObjectInitialize()
{
	player = new Player();
	backGround = new BackGround("nv_01.mp3", &player->transform);
	//�G�l�~�[�����ʒu�o�^
	spawner = new EnemySpawner();
	score = new Score();
}

void GameScene::SubjectSetting()
{
	AddGameObject(backGround);

#pragma region Player
	//Subscribe���Ŋ֐���o�^����
	//�����Ō����֐���[this](Transform�`�̕���
	//Subscribe�Ŋ֐��o�^ -> Player����OnNext���Ă� = �o�^�����֐������s�Ƃ�������
	player->OnShotButton()->Subscribe([this](Transform transform) {
		AddGameObject(new Bullet(&transform));
		});
	player->OnHit()->Subscribe([this](Transform transform) {
		AddGameObject(new Bomb(&transform));
		backGround->StopBGM();
		});
	AddGameObject(player);
#pragma endregion

#pragma region Enemy
	//�G�l�~�[����
	spawner->OnSpawn()->Subscribe([this](SPAWN_TYPE type) {
		Enemy* enemy = nullptr;
		float r = Random::Range(0.0f, 100.0f);
		if (r <= 20.0f)
			enemy = new Enemy(new ChaseAI(player), "Enemy02.png", type, 4);
		else if (r < 60.0f)
			enemy = new Enemy(new StraightAI(type), "Enemy01.png", type, 1);
		else if (r <= 70.0f)
			enemy = new Enemy(new ChaseAI(player), "Enemy03.png", type, 1);
		else
			enemy = new Enemy(new StraightAI(type), "Enemy04.png", type, 1);

		//�U�����q�b�g�����Ƃ��̏����o�^
		enemy->OnHit()->Subscribe([this](EnemyHitInfo info) {
			int exp = info.exp;
			while (0 < exp) {
				int gemExp = Random::Range(1, 4);
				ScoreGem* gem = new ScoreGem(player, &info.t, gemExp);
				gem->OnHit()->Subscribe([this](int e) {player->AddExp(e); });
				AddGameObject(gem);
				exp -= gem->GetExp();
			}
			score->AddScore();
			AddGameObject(new Bomb(&info.t));
			});
		AddGameObject(enemy);
		});
	AddGameObject(spawner);
#pragma endregion

	AddGameObject(score);
}

/// <summary>
/// �I�u�W�F�N�g��ǉ�����
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GameObjectManager::Instance()->AddGameObject(object);
}
