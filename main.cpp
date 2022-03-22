#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "main.h"
#include <thread>    
#include <ctime>  
#include <fstream>
#include <iomanip>


using namespace std;

int main() {
	setlocale(LC_ALL, "");
	ofstream write_file("data.tsv");

	double a, b;
	double h;
	long double integral[3];

	//a = -25;
	//b = 50;
	h = 0.1;
	cout << "Введите границы интегрирования" << endl;
	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;

//	cout << "Введите шаг интегрирования" << endl;
	//cout << "h: " << std::endl;
	//cin >> h; 

	double n = (b - a) / h;

	const int f_num = 8;
	double (*func[f_num])(double) = { sin, cos, function_0, function_1, function_2,  function_3, function_4, function_5 };

	unsigned int s = thread::hardware_concurrency();
	cout << endl << s << " параллельных потоков поддерживается." << endl << endl;

	write_file << a << '\t';
	write_file << b << '\t';
	write_file << h << '\n';

	clock_t start, end;
	start = clock();
		for (int i = 0; i < f_num ; i++) {
			//trapezoidalIntegral(a, b, h, n, func[i], integral);
			//centralrectanglesIntegral( a, b, h, n, func[i], integral);
			//SimpsonIntegral( a, b, h, n, func[i], integral);
			thread first(trapezoidalIntegral, a, b, h, n, func[i], integral);
			thread second(centralrectanglesIntegral, a, b, h, n, func[i], integral);
			thread third(SimpsonIntegral, a, b, h, n, func[i], integral);
			first.join();
			second.join();
			third.join();
			write_file << integral[0] << '\t';
			write_file << integral[1] << '\t';
			write_file << integral[2] << '\n';

		}

		end = clock();
	
	
	cout << '|' << setw(10) << "Время интегрирования (с.)" << setw(2) << ':'
		<< setw(10) << (end-start) / 1000.0 << setw(5) << '|' << endl << endl;

	cout << setw(10) << "Отчет записан в" << setw(2) << ':' << setw(10) << " отчет.xlsx"  << endl << endl;
	write_file.close();

	system("python report.py");
	system("pause");
	return 0;
	
}

double function_0(double x){

	return (2.0 * (x * x));

}

double function_1(double x){

	return x;

}

double function_2(double x) {
 
	return pow(5.0, x);

}

double function_3(double x) {

	return (1 / (5.0*5.0 + x*x));

}

double function_4(double x) {
	return pow(M_E, x);
}

double function_5(double x) {
	//return pow((x+2), 3);
	return ((x + 2.0)* (x + 2.0)* (x + 2.0));
}

void trapezoidalIntegral(double a, double b, double h, double n, double(*f)(double), long double integral[]) {
	long double result = 0.0;
	
	result = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++)
		result = result + h * f(a + h * i);

	integral[0] = result;


}

void centralrectanglesIntegral(double a, double b, double h, double n, double(*f)(double), long double integral[]) {
	
	long double result = 0.0;

	for (int i = 1; i <= n; i++)
		result = result + h * f(a + h * (i - 0.5));
	integral[1] = result;

}



void SimpsonIntegral(double a, double b, double h, double n, double(*f)(double), long double integral[]) {
	long double result = h * (f(a) + f(b)) / 6.0;
	
	for (int i = 1; i <= n; i++)
				result = result + 4.0 / 6.0 * h * f(a + h * (i - 0.5));

	for (int i = 1; i <= n - 1; i++)
				result = result + 2.0 / 6.0 * h * f(a + h * i);
	

	
	integral[2] = result;

}