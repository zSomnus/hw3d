#include "App.h"
#include <sstream>
#include <iomanip>

App::App() : wnd(800, 600, "Main Window")
{

}

int App::Update()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			// If return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	/*const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());*/

	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestTriangle(timer.Peek());
	wnd.Gfx().EndFrame();
}
