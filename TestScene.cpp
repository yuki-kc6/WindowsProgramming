#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "TestModel.h"
TestScene::TestScene(GameObject* parent)
	:GameObject(parent,"TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	Instantiate<TestModel>(this);
}

void TestScene::Update()  
{  

	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
   if (Input::IsKeyDown(DIK_SPACE))  
   {  
	   
	   if (pSceneManager != nullptr)
	   pSceneManager->ChangeScene(SCENE_ID_PLAY);
   }
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
