#include "framework.hpp"

int entry(int argc, const char** argv)
{
	NovaEngine::Engine e("test :D");
	return EXIT_SUCCESS;
}

#ifdef _WIN32
#ifndef _USE_OLD_IOSTREAMS
using namespace std;
#endif
// maximum mumber of lines the output console should have
static const WORD MAX_CONSOLE_LINES = 500;

void redirectIOToConsole()
{
	// allocate a console for this app
	AllocConsole();

	FILE* fp = nullptr;
	freopen_s(&fp, "CONIN$", "r", stdin);
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	redirectIOToConsole();

	return entry(0, nullptr);
}
#else
int main(int argc, const char** argv)
{
	return entry(argc, argv);
}
#endif
