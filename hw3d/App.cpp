#include "App.h"
#include <sstream>
#include <iomanip>

App::App() : wnd(800, 300, "Main Window")
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
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}
