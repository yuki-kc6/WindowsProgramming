#pragma once
#include<string>
#include <vector>
#include "Sprite.h"




namespace Image
{
	struct ImageData
	{
		Sprite* pSpirite_;
		std::string filename_;
	};
	int Load(std::string fileName);
	void Draw(int hModel);
	void Release();
};


