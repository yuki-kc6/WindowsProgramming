#pragma once
#include "Engine/GameObject.h"

class TestModel :
	public GameObject
{
public:
	TestModel(GameObject* parent);
	~TestModel();
	//�������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel;


};

