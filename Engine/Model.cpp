#include "Model.h"
#include "Direct3D.h"

namespace Model
{
	std::vector<ModelData*> modelList;
}


int Model::Load(std::string fileName)
{
	ModelData* pModelData = new ModelData;
	pModelData->filename_ = fileName;
	pModelData->pFbx_ = nullptr;

	for (auto& itr: modelList)
	{
		if (itr->filename_ == fileName) 
		{
			pModelData->pFbx_ = itr->pFbx_;
			break;
		}

	}
	if (pModelData->pFbx_ == nullptr)
	{
		pModelData->pFbx_ = new Fbx;
		pModelData->pFbx_->Load(fileName.c_str());
	}
	modelList.push_back(pModelData);
	return((int)(modelList.size() - 1));

}

void Model::SetTransforom(int hModel, Transform transform)
{
	modelList[hModel]->transform_=transform;	

}

void Model::Draw(int hModel)
{
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}

void Model::Release()
{

	bool isReffered=false;//�Q�Ƃ���Ă��邩�ǂ���
	for (int i = 0; i < modelList.size();i++)
	{
		for (int j = i + 1; j < modelList.size(); j++)
		{
			if (modelList[i]->pFbx_ == modelList[j]->pFbx_)
			{
				isReffered = true;
				break;
			}
		}
		if (isReffered == false)
		{
			SAFE_DELETE(modelList[i]->pFbx_);
		}
	}
	modelList.clear();//�z�����ɂ���i�O�̂��߁j


}
