#pragma once
#include "Engine/GameObject.h"

class Fbx;

class ChildOden:
	public GameObject
{
public:
	ChildOden(GameObject* parent);
	~ChildOden();
	//�������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	int hModel;
};

