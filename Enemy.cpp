#include "Enemy.h"
#include "Engine/SphereCollider.h"


Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), pFbx(nullptr)
{
}

Enemy::~Enemy()
{
}

void
Enemy::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("oden.fbx");
	transform_.position_ = { 0.0f,0.0f,50.0f };

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);

}

void Enemy::Update()
{
	//transform_.rotate_.y += 1.0f;
	/*if (transform_.rotate_.y > 720.0f)
	{
		Killme();
	}*/

}

void Enemy::Draw()
{
	pFbx->Draw(transform_);
}

void Enemy::Release()
{
}
