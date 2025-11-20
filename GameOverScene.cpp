#include "GameOverScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Sprite.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), pSprite(nullptr)
{

}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize()
{
	pSprite = new Sprite;
	pSprite->Load("Assets/gameover.png");
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr)
			pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
	XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(0));

	pSprite->Draw(mat);
}

void GameOverScene::Release()
{
}
