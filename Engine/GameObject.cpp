#include "GameObject.h"
#include "SphereCollider.h"
#include "Windows.h"
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
	transform_.Calculation();
	this->Update();


	RoundRobin(GetRootJob());
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

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr)
	{
		return this;//rootjobだよ
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
		return this;//自分が探されていたオブジェクト
	}
	else
	{
		for (auto child : childList_)
		{
			GameObject* result = child->FindChildObject(name);
			if (result != nullptr)
			{
				return result;//見つかった
			}
		}
		return nullptr;//見つからなかった
	}
}

GameObject* GameObject::FindObject(const string& name)
{
	GameObject* rootJob = GetRootJob();
	GameObject* result = rootJob->FindChildObject(name);
	return result;
}

void GameObject::AddColider(SphereCollider* pCollider)
{
	pCollider_ = pCollider;
}

void GameObject::Collision(GameObject* pTarget)
{
	//this->pCollider_とpTarget->pCollider_はぶつかってる？
	// 閾値＝お互いの半径＋半径
	float thisR = this->pCollider_->GetRadius();
	float tgtR = pTarget->pCollider_->GetRadius();
	float thre = (thisR + tgtR)* (thisR + tgtR);
	//2つのコライダーの距離計算をする
	XMFLOAT3 thisP = this->transform_.position_;
	XMFLOAT3 tgtP = pTarget->transform_.position_;
	float dist = (thisP.x - tgtP.x) * (thisP.x - tgtP.x) +
				 (thisP.y - tgtP.y) * (thisP.y - tgtP.y) +
				 (thisP.z - tgtP.z) * (thisP.z - tgtP.z);
		
	//コライダー同士が交差していたら
	if (dist <= thre) {
		//処理をする
		MessageBoxA(0, "ぼん", "Collider", MB_OK);
	}
	
}

void GameObject::RoundRobin(GameObject* pTarget)
{
	//自分にコライダーがなかったらreturn
	if (pCollider_ == nullptr)
		return;
	//自分とターゲット自体のコライダーが当たり判定
	if(pTarget->pCollider_!=nullptr)
	Collision(pTarget);
	//再帰的な奴で、ターゲットの子オブジェクトに当たり判定していく
	for (auto itr : pTarget->childList_)
		RoundRobin(itr);
		
}
