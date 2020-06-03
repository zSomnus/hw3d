#pragma once
#include "Window.h"
#include "MyTimer.h"

class App
{
public:
	App();
	// Master frame / message loop
	int Update();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
};