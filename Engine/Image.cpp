#include "Image.h"
#include "Direct3D.h"

namespace Image
{
	std::vector<ImageData*> imageList;
}


int Image::Load(std::string fileName)
{
	ImageData* pImageData = new ImageData;
	pImageData->filename_ = fileName;
	pImageData->pSpirite_ = nullptr;

	for (auto& itr : imageList)
	{
		if (itr->filename_ == fileName)
		{
			pImageData->pSpirite_ = itr->pSpirite_;
			break;
		}
	}
	if (pImageData->pSpirite_ == nullptr)
	{
		pImageData->pSpirite_ = new Spirite;
		pImageData->pSpirite_->Initialize(fileName);
	}
	imageList.push_back(pImageData);
	return (int)(imageList.size() - 1);
}

void Image::Draw(int hModel)
{
	XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(0));
	imageList[hModel]->pSpirite_->Draw(mat);
}

void Image::Release()
{
	bool isReffered = false;//参照されているかどうか
	for (int i = 0; i < imageList.size(); i++)
	{
		isReffered == false;
		for (int j = i + 1; j < imageList.size(); j++)
		{
			if (imageList[i]->pSpirite_ == imageList[j]->pSpirite_)
			{
				isReffered = true;
				break;
			}
		}
		if (isReffered == false)
		{
			SAFE_DELETE(imageList[i]->pSpirite_);
		}

	}
	imageList.clear();//配列を空にする（念のため）

}
