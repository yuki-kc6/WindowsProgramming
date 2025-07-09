#pragma once
#include "Quad.h"
class Dice :
    public Quad
{
	Dice();
	~Dice();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};

