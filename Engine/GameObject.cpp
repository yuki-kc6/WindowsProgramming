#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(nullptr), objectName_(name), isDead_(false)
{
	if (parent != nullptr)
	{
		transform_.pParent_ = &(parent->transform_);
	}
}

GameObject::~GameObject()
{

}

void GameObject::DrawSub()
{
	//0.自分を描画
	//1.子オブジェクトを描画　childListの各要素に対してDrawを呼ぶ

	this->Draw();

	for (auto itr = childList_.begin(); itr != childList_.end(); ++itr)
	{
		(*itr)->DrawSub();
	}


}

void GameObject::UpdateSub()
{
	this->Update();
	for (auto child : childList_)
	{
		child->UpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->isDead_)
		{
			(*itr)->ReleaseSub();
			delete (*itr);
			itr = childList_.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

void GameObject::ReleaseSub()
{
	this->Release();//自分を解放
	for (auto child : childList_)
	{
		child->ReleaseSub();
	}
	
}

void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
	transform_.position_.z = z;
}

void GameObject::Killme()
{
	isDead_ = true;
}
