#ifndef _BASECANVAS_H_
#define _BASECANVAS_H_

#include"GameObject\GameObject.h"
#include"GameObject\GameObjectManager.h"
#include<list>

class BaseCanvas
{
public:
	BaseCanvas() {};
	virtual ~BaseCanvas() {};

	virtual void Initialize() = 0;
	virtual void AddObject() = 0;

	void AddUIObject(GameObject* object) {
		if (object == nullptr)
			return;
		object->Initialize();
		GameObjectManager::Instance()->AddGameObject(object);
	}
};
#endif
