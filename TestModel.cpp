#include "TestModel.h"
#include "Engine/Model.h"

TestModel::TestModel(GameObject* parent)
	:GameObject(parent, "TestModel"),hModel(-1)
{
}

TestModel::~TestModel()
{
}

void TestModel::Initialize()
{
	hModel = Model::Load("geppei.fbx");
	assert(hModel >= 0);
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;

}

void TestModel::Update()
{
	transform_.rotate_.y += 1.0f;
}

void TestModel::Draw()
{
	
	Model::SetTransforom(hModel, transform_);
	Model::Draw(hModel);
}

void TestModel::Release()
{
	Model::Release();
}
