#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include"Transform.h"
#include<string>
#include"../Utility/Renderer.h"

using namespace std;

//画像幅の半分を返す
#define HALF_SPRITE_X ((transform.spriteSize.x) / (2.0f))
//画像の高さの半分を返す
#define HALF_SPRITE_Y ((transform.spriteSize.y) / (2.0f))

class GameObject {
public:
	//コンストラクタ
	GameObject():
		isDestroy(false){}

	//デストラクタ(仮想関数)
	virtual ~GameObject() {}

	//初期化(純粋仮関数)
	virtual void Initialize() = 0;
	
	//更新(純粋仮想関数)
	virtual void Update() = 0;

	//描画(純粋仮想関数)
	virtual void Draw(Renderer* renderer) = 0;

	//破棄(仮想関数)
	virtual void Destroy() {
		isDestroy = true;
	}

	//フラグの取得
	bool IsDestroy() {
		return isDestroy;
	}

	//矩形のヒット判定(仮想関数)
	virtual void OnHitBox(GameObject* other){}

public:
	Transform transform;
	string tag;        //タグ
private:
	//削除フラグ
	bool isDestroy;
};

#endif