//Krzysztof Mielczarek, 216705
#include "Formularz1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^ > ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Wykres::Formularz1 forma;
	Application::Run(% forma);

	return 0;
}