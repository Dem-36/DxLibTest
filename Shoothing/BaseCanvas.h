#ifndef _BASECANVAS_H_
#define _BASECANVAS_H_

#include"GameObject\GameObject.h"
#include"Utility\Renderer.h"
#include<list>

class BaseCanvas
{
public:
	BaseCanvas() {};
	virtual ~BaseCanvas() {};

	virtual void Initialize() = 0;

	virtual void Update() {
		std::list<GameObject*>::iterator itr;
		for (itr = uiContainer.begin(); itr != uiContainer.end(); ++itr) {
			if ((*itr) == NULL ||
				(*itr)->IsDestroy())
				continue;
			(*itr)->Update();
		}
	}

	virtual void Draw(Renderer* renderer) {
		std::list<GameObject*>::iterator itr;
		for (itr = uiContainer.begin(); itr != uiContainer.end(); ++itr) {
			if ((*itr) == NULL ||
				(*itr)->IsDestroy())
				continue;
			(*itr)->Draw(renderer);
		}
	}

	virtual void Release() {
		std::list<GameObject*>::iterator itr;
		for (itr = uiContainer.begin(); itr != uiContainer.end();) {
			if ((*itr) != NULL) {
				delete (*itr);
				itr = uiContainer.erase(itr);
				continue;
			}
			itr++;
		}
		uiContainer.clear();
	}

	void AddUIObject(GameObject* object) {
		if (object == nullptr)
			return;
		object->Initialize();
		uiContainer.push_back(object);
	}
protected:
	std::list<GameObject*> uiContainer;
};
#endif
