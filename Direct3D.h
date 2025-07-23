#pragma once
#include <Windows.h>
#include<d3d11.h>
#include <assert.h>

//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

enum SHADER_TYPE
{
	SHADER_3D,
	SHADER_2D,
	SHADER_MAX
};

namespace Direct3D
{
	//extern�͂ǂ����Ɏ��ۂ̒�`�i�錾�j������Ƃ����Ӗ�
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;

	HRESULT InitShader();
	HRESULT InitShader3D();//3D�p
	HRESULT InitShader2D();//2D�p

	void SetShader(SHADER_TYPE type);


	HRESULT Initialize(int winW, int winH, HWND hWind);
	

	void BeginDraw();

	void EndDraw();
	
	void Release();
}
