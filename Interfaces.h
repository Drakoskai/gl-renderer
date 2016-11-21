#pragma once

#include <windows.h>

namespace Display
{
	static const int MaxLoadString = 100;
	static const int DefaultWidth = 1280;
	static const int DefaultHeight = 720;	
	static const bool DefaultFullScreen = false;
	static const bool DefaultVsynEnabled = true;
	static const float DefaultScreenDepth = 1000.0f;
	static const float DefaultScreenNear = 0.1f;
	static const float DefaultFieldOfView = 45.0f;
	static const float DefaultAspectRatio = static_cast<float>(DefaultWidth) / static_cast<float>(DefaultHeight);
}

struct DisplayState
{
	int ScreenHeight;
	int ScreenWidth;
	bool FullScreen;
	bool VsynEnabled;
	float ScreenDepth;
	float ScreenNear;
	DisplayState()
		: ScreenHeight(Display::DefaultHeight),
		ScreenWidth(Display::DefaultWidth),
		FullScreen(Display::DefaultFullScreen),
		VsynEnabled(Display::DefaultVsynEnabled),
		ScreenDepth(Display::DefaultScreenDepth),
		ScreenNear(Display::DefaultScreenNear) { }
};

class Window
{
public:
	virtual ~Window() { }
	virtual HWND Create(const DisplayState & displayState) = 0;
};

class DrawContext
{
public:
	virtual	~DrawContext() { }
	virtual void Init() = 0;
	virtual Window* GetWindow() = 0;
	virtual void BeginScene() const = 0;
	virtual void Draw() const = 0;
	virtual void EndScene() const = 0;
};