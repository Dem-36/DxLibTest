#ifndef _BOX_H_
#define _BOX_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>

class Box:public GameObject
{
public:
	Box();
	Box(Vector2 position);
	Box(Vector2 position,Vector2 size);
	~Box();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

	void OnHitBox(GameObject* other);
};

#endif
