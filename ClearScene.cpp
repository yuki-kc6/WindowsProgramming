#include "ClearScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Sprite.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"),pSprite(nullptr)
{

}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	pSprite = new Sprite;
	pSprite->Load("Assets/clear.png");
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
	XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(0));

	pSprite->Draw(mat);
}

void ClearScene::Release()
{
}
