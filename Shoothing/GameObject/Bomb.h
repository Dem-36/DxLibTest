#ifndef _BOMB_H_
#define _BOMB_H_

#include"GameObject.h"
#include"../Animation.h"

class Bomb:public GameObject
{
public:
	Bomb(const Transform* transform);
	~Bomb();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

private:
	int snd;
	Animation anim;

};
#endif

