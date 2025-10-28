#pragma once
#include "Engine/GameObject.h"

class TestModel :
	public GameObject
{
public:
	TestModel(GameObject* parent);
	~TestModel();
	//純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel;


};

