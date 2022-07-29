
#define _USE_MATH_DEFINES
#define FUNCTIONS 8

#include <math.h>
#include <memory.h>

/////////////////////////////
// Задаем шаблоны функций //	
///////////////////////////

double F0(double);
double F1(double);
double F2(double);
double F3(double);
double F4(double);
double F5(double);
double F6(double);
double F7(double);


////////////////////////////////
// Объявляем класс уравнений //	
//////////////////////////////

class equation {

private:

	double a = 0;
	double b = 0;
	double h = 0;
	double n = 0;
	int function;
	double derivative2 = 0;

	/* Задаем массив указателей на функции */

	double (*func_list[FUNCTIONS])(double) = {
	  F0,
	  F1,
	  F2,
	  F3,
	  F4,
	  F5,
	  F6,
	  F7

	};



public:

	int size = 0;
	double* x = nullptr;
	double* y;
	double result_trapezoidalIntegral = 0;
	double* result_centralrectanglesIntegral = nullptr;
	double result_SimpsonIntegral = 0;
	
	double error_trapezoidalIntegral = 0;
	double error_centralrectanglesIntegral = 0;

	equation(int, double, double, double);
	equation(const equation&);
	~equation();

	void trapezoidalIntegral();
	void centralrectanglesIntegral();
	void SimpsonIntegral();
	
};


