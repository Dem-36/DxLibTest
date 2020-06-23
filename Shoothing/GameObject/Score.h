#ifndef _SCORE_H_
#define _SCORE_H_

#include"GameObject.h"

class Score :public GameObject {
public:
	Score();
	~Score();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);
	void AddScore();
private:
	int score;
	int handle;
};

#endif