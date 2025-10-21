#include "ChildOden.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"
ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent, "Player"), pFbx_(nullptr), hModel(-1)
{
}

ChildOden::~ChildOden()
{

}

void ChildOden::Initialize()
{

	//pFbx_ = new Fbx();
	//pFBX_がnullptrじゃなかったら。
	//のチェック入れた方がいい
	//pFbx_->Load("oden.fbx");
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;
	transform_.scale_.z = 0.3f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
	hModel = Model::Load("oden.fbx");
	assert(hModel >= 0);
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.5;
}

void ChildOden::Draw()
{
	/*if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}*/
	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void ChildOden::Release()
{
	Model::Release();
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
