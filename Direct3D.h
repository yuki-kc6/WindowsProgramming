#pragma once
#include <Windows.h>
#include<d3d11.h>
#include <assert.h>

//リンカ
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
	//externはどこかに実際の定義（宣言）があるという意味
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;

	HRESULT InitShader();
	HRESULT InitShader3D();//3D用
	HRESULT InitShader2D();//2D用

	void SetShader(SHADER_TYPE type);


	HRESULT Initialize(int winW, int winH, HWND hWind);
	

	void BeginDraw();

	void EndDraw();
	
	void Release();
}
