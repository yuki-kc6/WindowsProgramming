#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"

//#include "Texture.h"

using namespace DirectX;

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}

struct  CONSTANT_BUFFER
{
	XMMATRIX matWVP; //world*view*projection�̍s��
	XMMATRIX matNormal;
	XMMATRIX matWorld;
};

//���_���
struct VERTEX
{
	XMVECTOR pos;
	XMVECTOR uv;
	XMVECTOR normal;
};

class Texture;//�O���錾

class Quad
{
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�萔�o�b�t�@

	Texture* pTexture_;
};

