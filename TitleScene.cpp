#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Sprite.h"
#include "TestModel.h"
#include "Title.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),pSprite(nullptr)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	pSprite = new Sprite;
	pSprite->Load("Assets/title.png");
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
	XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(0));

	pSprite->Draw(mat);
}

void TitleScene::Release()
{
}
