#pragma once
#include "Engine/GameObject.h"


class Fbx;
class ChildOden;
//この場合は型とアドレスだけわかればいいのでincludeせずに前方宣言で良い
	//includeするとFbx.hの中身を丸ごと読み込むことになる

class Player :
    public GameObject
{
public:
	Player(GameObject* parent);
	~Player();
	//純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
private:
	Fbx* pFbx_;
	ChildOden* pRChildOden_;
	ChildOden* pLChildOden_;
	int hModel;	
	XMVECTOR camPos;
	XMVECTOR camTar;

};

