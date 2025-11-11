#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


class Enemy :
	public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	//純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
private:
	Fbx* pFbx;
	int hModel;


};

