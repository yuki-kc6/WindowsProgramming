#include "Transform.h"

Transform::Transform()
{
	position_ = XMFLOAT3(0, 0, 0);
	rotate_ = XMFLOAT3(0, 0, 0);
	scale_ = XMFLOAT3(1, 1, 1);
	matTranslate_ = XMMatrixIdentity();
	matRotate_ = XMMatrixIdentity();
	matScale_ = XMMatrixIdentity();
}

Transform::~Transform()
{

}

void Transform::Calculation()
{
	//à⁄ìÆçsóÒ
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);
	//âÒì]çsóÒ
	XMMATRIX rotateX, rotateY, rotateZ;
	matRotate_ = XMMatrixRotationRollPitchYaw((XMConvertToRadians(rotate_.x)),
		XMConvertToRadians(rotate_.y),
		XMConvertToRadians(rotate_.z));
	//ägëÂèkè¨
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
	//Calculation();
return matRotate_ * matScale_ * matTranslate_;
}

XMMATRIX Transform::GetNormalMatrix()
{
	return matRotate_ * XMMatrixInverse(nullptr,matScale_);
}
