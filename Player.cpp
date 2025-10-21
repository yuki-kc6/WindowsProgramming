#include "Player.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"
#include "ChildOden.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pFbx_(nullptr),hModel(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//pFbx_ = new Fbx();
	////pFBX_がnullptrじゃなかったら。
	////のチェック入れた方がいい
	//pFbx_->Load("oden.fbx");

	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	//子オブジェクトにChildOdenを追加
	pRChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
	hModel = Model::Load("oden.fbx");

}

void Player::Update()
{
	transform_.rotate_.y += 1.0f;
	if (transform_.rotate_.y > 720.0f)
	{
		Killme();
	}
}

void Player::Draw()
{
	if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}
	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
	Model::Release();
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
