#include "Player.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "ChildOden.h"
#include "Engine/SphereCollider.h"
#include "Bullet.h"
#include "Engine/Camera.h"

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
	this->SetPosition(0, 0, -5.0f);
	hModel = Model::Load("oden.fbx");
	assert(hModel >= 0);
	//transform_.scale_.x = 0.7f;
	//transform_.scale_.y = 0.7f;
	//transform_.scale_.z = 0.7f;
	//子オブジェクトにChildOdenを追加
	pRChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
	
	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col); 

	camPos={ 40, 10, 10, 0 };

	camTar={ 0,0,10,0 };
}

void Player::Update()
{
	Camera::SetPosition(camPos);
	Camera::SetTarget(camTar);


	static float x = 0.0;
	float tx = sin(x) * 3.0f;
	x += 0.02f;
	//transform_.position_.x = tx;
	transform_.rotate_.y += 1.0f;
	
	if (Input::IsKey(DIK_UP))
	{
		transform_.position_.y += 0.5;
	}

	if (Input::IsKey(DIK_DOWN))
	{
		transform_.position_.y -= 0.5;
	}

	if (Input::IsKey(DIK_SPACE))
	{
		GameObject* pBullet = Instantiate<Bullet>(GetParent());
		pBullet->SetPosition(transform_.position_);
		
	}
	if (transform_.rotate_.y > 720.0f)
	{
		Killme();
	}

}

void Player::Draw()
{
	/*if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}*/
	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
	//Model::Release();
	/*if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}*/
}

void Player::OnCollision(GameObject* pTarget)
{

}
