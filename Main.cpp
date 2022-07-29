#include "equation.h" 
#include "Main.h"




/*Пространства имен для работы с формой*/
using namespace System;
using namespace System::Windows::Forms;

/* Функция входа main() */
[STAThreadAttribute]
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); // Задаем параметры отрисовки приложения
	Application::SetCompatibleTextRenderingDefault(false); // Задаем параметры отрисовки приложения


	integraloop::Main form;
	Application::Run(% form);  // Запускаем главную форму

}
