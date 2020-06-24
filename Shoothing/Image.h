#ifndef _IMAGE_H_
#define _IMAGE_H_

#include"GameObject\GameObject.h"
#include"Utility\Renderer.h"
#include<string>

enum class ImageType {
	Simple,
	Fill_X,
	Fill_Y
};
class Image :public GameObject
{
public:
	Image(std::string fileName);
	~Image();

	void Initialize()override;
	void Update()override;
	void Draw(Renderer* renderer)override;
public:
	float ratio;
	ImageType type = ImageType::Simple;
private:
	int imageHandle;
};
#endif
