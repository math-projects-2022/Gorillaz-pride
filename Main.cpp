#include "equation.h" 
#include "Main.h"





using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); // Çàäàåì ïàðàìåòðû îòðèñîâêè ïðèëîæåíèÿ
	Application::SetCompatibleTextRenderingDefault(false); // Çàäàåì ïàðàìåòðû îòðèñîâêè ïðèëîæåíèÿ


	integraloop::Main form;
	Application::Run(% form);  // Çàïóñêàåì ãëàâíóþ ôîðìó

}
