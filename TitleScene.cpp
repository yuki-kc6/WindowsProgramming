#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "TestModel.h"
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene")
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Instantiate<TestModel>(this);
}

void TitleScene::Update()  
{  
   if (Input::IsKeyDown(DIK_SPACE))  
   {  
	   SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	   if (pSceneManager != nullptr)
	   pSceneManager->ChangeScene(SCENE_ID_PLAY);
   }
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
