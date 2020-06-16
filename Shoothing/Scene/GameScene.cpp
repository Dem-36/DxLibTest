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

	//�G�l�~�[�����ʒu�o�^
	spawner = new EnemySpawner();

	//�G�l�~�[����
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
		//�U�����q�b�g�����Ƃ��̏����o�^
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
/// �I�u�W�F�N�g��ǉ�����
/// </summary>
/// <param name="object"></param>
void GameScene::AddGameObject(GameObject* object)
{
	GameObjectManager::Instance()->AddGameObject(object);
}
