#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Camera.h"
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


	camPos = { 40, 10, 10, 0 };

	camTar = { 0,0,10,0 };
}

void PlayScene::Update()
{
	Camera::SetPosition(camPos);
	Camera::SetTarget(camTar);

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
