#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"

//#include "Texture.h"

using namespace DirectX;

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}

struct  CONSTANT_BUFFER
{
	XMMATRIX matWVP; //world*view*projectionの行列
	XMMATRIX matNormal;
	XMMATRIX matWorld;
};

//頂点情報
struct VERTEX
{
	XMVECTOR pos;
	XMVECTOR uv;
	XMVECTOR normal;
};

class Texture;//前方宣言

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//定数バッファ

	Texture* pTexture_;
};

