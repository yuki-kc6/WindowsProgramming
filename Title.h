#pragma once
#include "Engine/GameObject.h"


class Title :
    public GameObject
{
public:
	Title(GameObject* parent);
	~Title();
	//純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hImage;

};

