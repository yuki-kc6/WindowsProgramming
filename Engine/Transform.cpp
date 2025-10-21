#include "Transform.h"

Transform::Transform()
	:pParent_(nullptr),
	matTranslate_ (XMMatrixIdentity()),
	matRotate_ (XMMatrixIdentity()),
	matScale_ ( XMMatrixIdentity())
{
	position_ = XMFLOAT3(0, 0, 0);
	rotate_ = XMFLOAT3(0, 0, 0);
	scale_ = XMFLOAT3(1, 1, 1);
	
}

Transform::~Transform()
{

}

void Transform::Calculation()
{
	//ˆÚ“®s—ñ
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);
	//‰ñ“]s—ñ
	XMMATRIX rotateX, rotateY, rotateZ;
	matRotate_ = XMMatrixRotationRollPitchYaw((XMConvertToRadians(rotate_.x)),
		XMConvertToRadians(rotate_.y),
		XMConvertToRadians(rotate_.z));
	//Šg‘åk¬
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
	if (pParent_ != nullptr)
	{
		return matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();
	}
	else
		return matRotate_ * matScale_ * matTranslate_;
}

XMMATRIX Transform::GetNormalMatrix()
{
	return matRotate_ * XMMatrixInverse(nullptr,matScale_);
}
