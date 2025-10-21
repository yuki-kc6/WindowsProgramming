#pragma once

#include <list>
#include <string>
#include "Transform.h"


using std::string;
using std::list;


class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	virtual ~GameObject();//�f�X�g���N�^��virtual������

	virtual void Initialize() =0;
	virtual void Update() =0;
	virtual void Draw() =0;
	virtual void Release() =0;
	void DrawSub();
	void UpdateSub();
	void ReleaseSub();

	void SetPosition(XMFLOAT3 position);
	void SetPosition(float x, float y, float z);
	void Killme();

	template<typename T>
	GameObject* Instantiate(GameObject* parent)
	{
		T* obj = new T(parent);
		obj->Initialize();
		childList_.push_back(obj);
		return(obj);
	}

protected:
	list<GameObject*> childList_;
	Transform		transform_;
	GameObject* pParent_;
	string	objectName_;
private:
	bool isDead_;

};