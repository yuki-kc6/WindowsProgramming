#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene")
{

}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr)
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
