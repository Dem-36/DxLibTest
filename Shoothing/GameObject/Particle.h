#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>

#define SPARK_NUM 50
class Particle :public GameObject
{
public:
	Particle(Vector2 position);
	Particle(Transform* transform);
	virtual ~Particle();

	void Initialize();
	void Update();
	void Draw(Renderer* renderer);

private:
	void CreateSpark();

private:
	typedef struct {
		bool valid;
		Vector2 position;
		Vector2 velocity;
		int gravity;
		int bright;
	}SPARK;

	SPARK spark[SPARK_NUM];
};
#endif

