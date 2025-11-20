#include "Enemy.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), pFbx(nullptr),hModel(0)
{
}

Enemy::~Enemy()
{
}

void
Enemy::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("mikan.fbx");
	transform_.position_ = { 0.0f,0.0f,30.0f };

	SphereCollider* col = new SphereCollider(1.0f);
	AddCollider(col);

}

void Enemy::Update()
{
	static float y = 1.0;
	float ty = cos(y) * 5.0f;
	y += 0.02f;
	transform_.position_.y = ty;

	transform_.rotate_.y += 1.0f;

}

void Enemy::Draw()
{
	pFbx->Draw(transform_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		Killme();
	}
}
