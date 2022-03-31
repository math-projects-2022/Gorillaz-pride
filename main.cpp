///////////////////////////
// Подключение библиотек //
//////////////////////////

#define _USE_MATH_DEFINES
#include <math.h>   
#include <ctime>  
#include <fstream>
#include <iomanip>
using namespace std;
#include <iostream>
#include "main.h"

int main() {
	setlocale(LC_ALL, "");

	////////////////////////////////////////////////////////////////////////////////
	// Открываем файлы для записи результата и промежуточных значений вычислений //
	//////////////////////////////////////////////////////////////////////////////

	ofstream write_file("data.tsv");
	ofstream write_integral("intermediate.tsv");

	double a, b;
	double h;
	

	h = 0.1; // Устанавливаем точность вычислений (чем меньше, тем лучше)

	/*
	
	Запрашивашиваем границы в пределах ожидаемых значений, так как границы общие для всех восьми функций, некоторые интегралы могут не посчитаться,
	или посчитаться, но выйти за максимальное или минималное значение long double от ±2.23 x 10^-308 до ±1.80 x 10^308
	
	
	*/
	cout << "Введите границы интегрирования" << endl;
	cout << "Нижняя (a): " << endl;
	cin >> a;
	cout << "Верхняя (b): " << endl;
	cin >> b;


	double n = (b - a) / h; // задаем число разбиений

	const int f_num = 8;

	///////////////////////////////////////////////////////////////////
	//																 //
	// Объявляем массив из 8 функций которые нужно проинтегрировать: //
	//	1) y=sin(x)													 //
	//  2) y=cos(x)													 //
	//	3) y=2*x²													 //
	//	4) y=x                                                       //
	//	5) y=5ᵡ                                                      //
	//	6) y=1/5²+x²                                                 //
	//	7) y=eᵡ                                                      //
	//	8) y=(x+2)³													 //					
	//  															 //
	///////////////////////////////////////////////////////////////////

	double (*func[f_num])(double) = { 
		sin, 
		cos,
		function_0,
		function_1,
		function_2,
		function_3, 
		function_4,
		function_5 
	};

	/* Записываем в файл параметры интегрирования */
	write_file << a << '\t';
	write_file << b << '\t';
	write_file << h << '\n';

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//																								//
	// Записываем время начала и завершения выполнения алгорима. Переберая в цикле массив функций,	//
	// вызываем функции вычисления интеграла в соотвестветствии с методом.							//
	// Используемые методы:																			//
	// 1) Метод трапеций																			//
	// 2) Центральных прямоугольников																//
	// 3) Метод Симпсона																			//
	//																								//
	// Записываем полученные результаты в файл data.tsv 											//
	// 																								//
	//////////////////////////////////////////////////////////////////////////////////////////////////

	clock_t start, end;
	start = clock();
	for (int i = 0; i < f_num; i++) {

			write_file << trapezoidalIntegral(a, b, h, n, func[i]) << '\t';
			write_file << centralrectanglesIntegral(a, b, h, n, func[i], write_integral) << '\t';
			write_file << SimpsonIntegral(a, b, h, n, func[i]) << '\n';

		
	}

	end = clock();

	/*
	
	Выводим информацию о времени выполнения алгорима и о файле отчета
	Закрываем потоки ввода файлов
	Запускаем скрипт рендеринга отчета
	*/

	cout << '|' << setw(10) << "Время интегрирования (с.)" << setw(2) << ':'
		<< setw(10) << (end - start) / 1000.0 << setw(5) << '|' << endl << endl;

	cout << setw(10) << "Отчет записан в" << setw(2) << ':' << setw(10) << " отчет.xlsx" << endl << endl;
	write_file.close();
	write_integral.close();

	system("python report.py");
	system("pause");
	return 0;
	
}

/////////////
// y=2*x² //
///////////

double function_0(double x){

	return (2.0 * (x * x));

}

//////////
// y=x //
////////

double function_1(double x){

	return x;

}

///////////
// y=5ᵡ //
/////////

double function_2(double x) {
 
	return pow(5.0, x);

}

/////////////////
//  y=1/5²+x² //
///////////////

double function_3(double x) {

	return (1 / (5.0*5.0 + x*x));

}

///////////
// y=eᵡ //
/////////

double function_4(double x) {

	return pow(M_E, x);

}

///////////////
// y=(x+2)³ //
/////////////

double function_5(double x) {

	return ((x + 2.0)* (x + 2.0)* (x + 2.0));
}


/////////////////////
// Метод трапеций //
///////////////////

long double trapezoidalIntegral(double a, double b, double h, double n, double(*f)(double)) {
	long double result = 0.0;
	
	result = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++) {
		result = result + h * f(a + h * i);
	
	}

	return round(result* 1000000)/ 1000000;


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//									  Метод центральных прямоугольников										   //
// Записываем в файл intermediate.tsv промежуточные результаты вычислений интегралов, для построения графиков //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

long double centralrectanglesIntegral(double a, double b, double h, double n, double(*f)(double), ofstream& write_integral) {
	
	long double result = 0.0;
	
		for (int j = 1; j <= n; j++) {
		
			result = result + h * f(a + h * (j - 0.5));
			write_integral << round(result * 1000000) / 1000000 << '\t';
		
		}
	
	write_integral << endl;

	return round(result * 1000000) / 1000000;

}

/////////////////////
// Метод Симпсона //
///////////////////

long double SimpsonIntegral(double a, double b, double h, double n, double(*f)(double)) {
	long double result = h * (f(a) + f(b)) / 6.0;
	
	for (int i = 1; i <= n; i++)
		result = result + 4.0 / 6.0 * h * f(a + h * (i - 0.5));

	for (int i = 1; i <= n - 1; i++) 
		result = result + 2.0 / 6.0 * h * f(a + h * i);
	
	
	

	return round(result * 1000000) / 1000000;

}