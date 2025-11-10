#include "Enemy.h"
#include "Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("geppei.fbx");
	assert(hModel >= 0);
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;

}

void Enemy::Update()
{
	transform_.rotate_.y += 1.0f;
	if (transform_.rotate_.y > 720.0f)
	{
		Killme();
	}

}

void Enemy::Draw()
{

	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
	Model::Release();
}
