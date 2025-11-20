#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	//Playerのインスタンスを生成して、子オブジェクトに追加する
	/*Player* pPlayer = new Player(this);
	pPlayer->Initialize();
	childList_.push_back(pPlayer);*/

	Instantiate<Player>(this);
	Instantiate<Enemy>(this);


	camPos = { 40, 0, 10, 0 };

	camTar = { 0,0,10,0 };
}

void PlayScene::Update()
{
	Camera::SetPosition(camPos);
	Camera::SetTarget(camTar);

	GameObject* pPlayer = FindObject("Player");
	if (pPlayer == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr)
			pSceneManager->ChangeScene(SCENE_ID_OVER);
	}
		
	GameObject* pEnemy = FindObject("Enemy");
	if (pEnemy== nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr)
			pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
