#pragma once
#include<string>
#include <vector>
#include "Spirite.h"




namespace Image
{
	struct ImageData
	{
		Spirite* pSpirite_;
		std::string filename_;
	};
	int Load(std::string fileName);
	void Draw(int hModel);
	void Release();

};
