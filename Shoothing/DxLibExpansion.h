#ifndef _DXLIBEXPANSION_H_
#define _DXLIBEXPANSION_H_

#include<DxLib.h>
#include"Utility\Vector2.h"

class DxLibExpansion {
public:
	static Vector2 GetSpriteSize(const int handle) {
		int x, y;
		GetGraphSize(handle, &x, &y);
		return Vector2(x, y);
	}
};

#endif