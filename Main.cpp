#include "equation.h" 
#include "Main.h"





using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 


	integraloop::Main form;
	Application::Run(% form);  

}
