#ifndef _BULLET_H_
#define _BULLET_H_

#include"DxLib.h"
#include"GameObject.h"
#include<math.h>

class Bullet :public GameObject
{
public:
	//コンストラクタ
	Bullet(Transform* transform);
	//デストラクタ
	~Bullet();

	//初期化
	void Initialize();
	//更新
	void Update();
	//描画
	void Draw(Renderer* renderer);

	void OnHitBox(GameObject* other);

private:
	Vector2 velocity;
	int handle;
};
#endif

