#include "Input.h"


//namespace�̋�Ԃ̓O���[�o���ɂȂ��Ă���B���O����邩��c����Input�����Ă���
namespace Input
{
	//�L�[�{�[�h�C���v�b�g
	LPDIRECTINPUT8  pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256] = { 0 };
	//�}�E�X�C���v�b�g
	LPDIRECTINPUTDEVICE8 pMouseDevice = nullptr;
	DIMOUSESTATE mouseState;//�}�E�X�̏��
	DIMOUSESTATE prevMouseState;
	XMVECTOR mouseposition;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

		//�}�E�X
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);
		pMouseDevice->SetDataFormat(&c_dfDIMouse);
		pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	}
	
	void Update()
	{
		memcpy(prevKeyState, keyState, sizeof(keyState));
		for (auto i = 0; i < 256; i++)
		{
			prevKeyState[i] = keyState[i];
		}
		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);

		//�}�E�X�̏�Ԃ̕ۑ�
		pMouseDevice->Acquire();
		memcpy(&prevMouseState, &mouseState, sizeof(mouseState));
		pMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
		

	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 128)
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		//�������A�O�񉟂�
		if (!IsKey(keyCode) && (prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//�������A�O�񉟂��Ă��Ȃ�
		if (IsKey(keyCode) && !(prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	XMVECTOR GetMousePosition()
	{
		return mouseposition;
	}

	void SetMousePosition(int x, int y)
	{
		mouseposition = { (float)x,(float)y,0.0f,1.0f };
	}

	bool IsMouseButton(int btnCode)
	{
		if (mouseState.rgbButtons[btnCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonUp(int btnCode)
	{
		if (!IsMouseButton(btnCode) && prevMouseState.rgbButtons[btnCode] & 0x80)
		{
			return true;
		}

		return false;
	}

	bool IsMouseButtonDown(int btnCode)
	{
		if (IsMouseButton(btnCode) && !prevMouseState.rgbButtons[btnCode]&0x80)
		{
			return true;
		}

		return false;

	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
		//SAFE_RELEASE(pKeyDevice);
	}
}