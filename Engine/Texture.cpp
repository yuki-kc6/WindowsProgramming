#include <wincodec.h>
#include "Texture.h"
#include "Direct3D.h"
#include <DirectXTex.h>

// DirectXTex�̃��C�u�����������N

#pragma comment(lib, "DirectXTex.lib")


using namespace DirectX;


Texture::Texture()
{
}

Texture::~Texture()
{
}

HRESULT Texture::Load(std::string fileName)
{
	TexMetadata metadata; //�摜�̕t�����

	ScratchImage image;   //�摜�{��

	HRESULT hr;

	//���ۂɓǂށ@�@�@�@ 
	std::wstring wfilename(fileName.begin(), fileName.end());
	hr = LoadFromWICFile(wfilename.c_str(), WIC_FLAGS::WIC_FLAGS_NONE,
							&metadata, image);
	if (FAILED(hr))
	{
		return S_FALSE;
	}

	if (FAILED(hr))

	{
		return S_FALSE;
	}

	D3D11_SAMPLER_DESC SamDesc;
	ZeroMemory(&SamDesc, sizeof(D3D11_SAMPLER_DESC));
	SamDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
	Direct3D::pDevice->CreateSamplerState(&SamDesc, &pSampler_);
	//�V�F�[�_�[���\�[�X�r���[
	D3D11_SHADER_RESOURCE_VIEW_DESC srv = {};
	srv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srv.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srv.Texture2D.MipLevels = 1;

	hr = CreateShaderResourceView(Direct3D::pDevice,
		image.GetImages(), image.GetImageCount(), metadata, &pSRV_);

	return S_OK;

}

void Texture::Release()
{
	pSampler_->Release();
	pSRV_->Release();
}
