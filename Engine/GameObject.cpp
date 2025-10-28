#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name), isDead_(false)
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
	//0.������`��
	//1.�q�I�u�W�F�N�g��`��@childList�̊e�v�f�ɑ΂���Draw���Ă�

	this->Draw();

	for (auto itr = childList_.begin(); itr != childList_.end(); ++itr)
	{
		(*itr)->DrawSub();
	}


}

void GameObject::UpdateSub()
{
	transform_.Calculation();
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
	this->Release();//���������
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

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr)
	{
		return this;//rootjob����
	}
	else
	{
		return pParent_->GetRootJob();
	}
}

GameObject* GameObject::FindChildObject(const string& name)
{
	if (this->objectName_ == name)
	{
		return this;//�������T����Ă����I�u�W�F�N�g
	}
	else
	{
		for (auto child : childList_)
		{
			GameObject* result = child->FindChildObject(name);
			if (result != nullptr)
			{
				return result;//��������
			}
		}
		return nullptr;//������Ȃ�����
	}
}

GameObject* GameObject::FindObject(const string& name)
{
	GameObject* rootJob = GetRootJob();
	GameObject* result = rootJob->FindChildObject(name);
	return result;
}
