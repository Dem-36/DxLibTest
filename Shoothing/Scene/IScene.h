#ifndef _ISCENE_H_
#define _ISCENE_H_

#include"../Utility/Renderer.h"
#include"../Utility/InputManager.h"

//シーンインターフェース
class IScene {
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw(Renderer* renderer) = 0;
	virtual void Release() = 0;
};

#endif