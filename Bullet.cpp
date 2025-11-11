#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel(-1)
{
}

Bullet::Bullet()
{
}

void Bullet::Initialize()
{
	hModel = Model::Load("geppei.fbx");
	assert(hModel >= 0);
	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
	transform_.rotate_.y -= 70.0f;
}

void Bullet::Update()
{
	transform_.position_.z += 0.3;
	if (transform_.position_.z == 60)
	{
		Killme();
	}
}

void Bullet::Draw()
{
	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		Killme();
	}
}
