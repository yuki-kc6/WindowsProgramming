#include "Title.h"
#include "Engine/Image.h"

Title::Title(GameObject* parent)
	:GameObject(parent, "Title"), hImage(0)
{

}

Title::~Title()
{

}

void Title::Initialize()
{
	hImage = Image::Load("dice.png");

}

void Title::Update()
{
}

void Title::Draw()
{
	Image::Draw(hImage);
}

void Title::Release()
{
}
