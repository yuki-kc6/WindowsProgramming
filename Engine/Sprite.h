#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include <d3d11.h>
#include <string>
using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWorld; //ワールド行列
};

struct VERTEX
{
	XMFLOAT4 pos;	//位置
	XMFLOAT2 uv;	//UV座標
};

//前方宣言
class Texture;//Textureクラスってのがどこかにあってだなぁ宣言

class Sprite
{
public:
	Sprite();
	~Sprite();
	HRESULT Load(std::string fileName);
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();

	void InitVertex();
	void InitIndex();
	void InitConstantBuffer();

protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ
	Texture* pTexture_;	//テクスチャ
};