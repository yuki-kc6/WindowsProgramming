#pragma once
#include "Engine/GameObject.h"


class Fbx;
class ChildOden;
//���̏ꍇ�͌^�ƃA�h���X�����킩��΂����̂�include�����ɑO���錾�ŗǂ�
	//include�����Fbx.h�̒��g���ۂ��Ɠǂݍ��ނ��ƂɂȂ�

class Player :
    public GameObject
{
public:
	Player(GameObject* parent);
	~Player();
	//�������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	ChildOden* pRChildOden_;
	ChildOden* pLChildOden_;
	int hModel;	


};

