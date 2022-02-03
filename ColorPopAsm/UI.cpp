#include <Windows.h>

#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {

#ifdef CONSOLE
	BOOL chk = AllocConsole();
	if (chk) freopen("CONOUT$", "w", stdout);
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ColorPopAsm::UI form;
	Application::Run(% form);
}