#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "TestModel.h"
#include "Title.h"
#include "Engine/Spirite.h"
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
	sp = new Spirite;
	sp->Initialize();
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
