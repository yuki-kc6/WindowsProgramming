#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"

//#include "Texture.h"

using namespace DirectX;

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}

struct  CONSTANT_BUFFER
{
	XMMATRIX matWorld;
};

//頂点情報
struct VERTEX
{
	XMFLOAT4 pos;
	XMFLOAT2 uv;
};

class Texture;//前方宣言

class Spirite
{
public:
	Spirite();
	virtual ~Spirite();
	virtual HRESULT Initialize(const std::string fileName);
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ

	Texture* pTexture_;
};

