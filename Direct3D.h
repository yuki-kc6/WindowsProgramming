#pragma once
#include <Windows.h>
#include<d3d11.h>
#include <assert.h>

//リンカ
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

namespace Direct3D
{
	//externはどこかに実際の定義（宣言）があるという意味
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;

	HRESULT InitShader();

	HRESULT Initialize(int winW, int winH, HWND hWind);

	void BeginDraw();

	void EndDraw();
	
	void Release();
}
