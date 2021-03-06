#include "framework.hpp"

int entry(int argc, const char** argv)
{
	NovaEngine::Engine e("test :D");

	return EXIT_SUCCESS;
}

#ifdef _WIN32
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	if (AllocConsole())
	{
		FILE* fp = nullptr;
		freopen_s(&fp, "CONIN$", "r", stdin);
		freopen_s(&fp, "CONOUT$", "w", stdout);
		freopen_s(&fp, "CONOUT$", "w", stderr);
	}

	return entry(0, nullptr);
}
#else
int main(int argc, const char** argv)
{
	return entry(argc, argv);
}
#endif
