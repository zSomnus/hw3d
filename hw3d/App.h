#pragma once
#include "Window.h"
#include "MyTimer.h"

class App
{
public:
	App();
	// Master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};