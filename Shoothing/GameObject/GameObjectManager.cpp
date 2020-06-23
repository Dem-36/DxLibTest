#include "GameObjectManager.h"
#include"../Utility/Collision.h"

void GameObjectManager::AddGameObject(GameObject* object)
{
	//object��NULL�Ȃ�ǉ����Ȃ�
	if (object == NULL)
		return;
	object->Initialize();
	container.push_back(object);
}

void GameObjectManager::Update()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;
		(*itr)->Update();
	}
}

void GameObjectManager::Draw(Renderer* renderer)
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;
		(*itr)->Draw(renderer);
	}
}

void GameObjectManager::Release()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end();) {
		if ((*itr) != NULL) {
			delete (*itr);
			itr = container.erase(itr);
			continue;
		}
		itr++;
	}
	container.clear();
}

void GameObjectManager::HitCheck()
{
	std::list<GameObject*>::iterator itr;
	std::list<GameObject*>::iterator tgt;
	for (itr = container.begin(); itr != container.end(); ++itr) {
		//���łɔj���ς݂Ȃ珈�����X�L�b�v����
		if ((*itr) == NULL ||
			(*itr)->IsDestroy())
			continue;

		for (tgt = container.begin(); tgt != container.end(); ++tgt) {

			//���łɔj���ς݁A��������
			//����̃I�u�W�F�N�g�Ȃ�
			if ((*tgt) == NULL ||
				(*tgt)->IsDestroy() ||
				tgt == itr)
				continue;

			if (Collision::OnHitRect(&(*itr)->transform, &(*tgt)->transform)) {
				(*itr)->OnHitBox((*tgt));
				(*tgt)->OnHitBox((*itr));
			}
		}
	}
}

void GameObjectManager::DestroyCheck()
{
	std::list<GameObject*>::iterator itr;
	for (itr = container.begin(); itr != container.end();) {
		if ((*itr) != NULL && (*itr)->IsDestroy()) {
			delete (*itr);
			//�C�e���[�^���폜������A���̃C�e���[�^���擾����
			//�����ŁA�C���N�������g������ƃo�O�ɂȂ�(���łɎ��̒l���擾���Ă��邽��)
			itr = container.erase(itr);
			continue;
		}
		//�j������t���O��true�o�Ȃ��Ȃ玟�̃f�[�^�ɂ���
		itr++;
	}
}
