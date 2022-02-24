#include "framework.hpp"


int main(int argc, const char** argv)
{
	NovaEngine::Engine e(argv[0]);
	return EXIT_SUCCESS;
}

#ifdef _WIN32
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    return main();
}
#endif
