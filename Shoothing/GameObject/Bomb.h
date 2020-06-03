#ifndef _BOMB_H_
#define _BOMB_H_

#include"GameObject.h"

class Bomb:public GameObject
{
public:
	Bomb(Transform* transform);
	~Bomb();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

private:
	int handle[8];
	int snd;
	int index;

};
#endif

