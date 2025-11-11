#pragma once
#include "Engine/GameObject.h"
class Bullet :
    public GameObject
{
public:
	Bullet(GameObject* parent);
	Bullet();
	//純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
private:
	int hModel;


};

