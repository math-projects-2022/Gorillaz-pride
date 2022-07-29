#include "equation.h"

equation::equation(int equation, double a_v, double b_v, double h_v) {

	a = a_v;
	b = b_v;
	h = h_v;
	function = equation;
	n = (b - a) / h;
	size = (int)n + 1;

	x = new double[size];

	y = new double[size];

	double temp;
	for (int i = 0; i < size; i++) {
		x[i] = a + i * h;
		y[i] = func_list[function](x[i]);
		temp = fabs((-func_list[function](x[i] - 2 * h) + 16 * func_list[function](x[i] - h) - 30 * func_list[function](x[i]) + 16 * func_list[function](x[i] + h) - func_list[function](x[i] + 2 * h)) / (12 * h * h));
		if (derivative2 < temp)
			derivative2 = temp;
	}

	


}

equation::equation(const equation& obj) {
	a = obj.a;
	b = obj.b;
	h = obj.h;
	function = obj.function;
	n = obj.n;
	size = obj.size;

	x = new double[size];
	memcpy_s(x, sizeof(double) * size, obj.x, sizeof(double) * size);

	y = new double[size];
	memcpy_s(y, sizeof(double) * size, obj.y, sizeof(double) * size);

	result_trapezoidalIntegral = obj.result_trapezoidalIntegral;

	result_centralrectanglesIntegral = new double[size];
	memcpy_s(result_centralrectanglesIntegral, sizeof(double) * size, obj.result_centralrectanglesIntegral, sizeof(double) * size);

	result_SimpsonIntegral = obj.result_SimpsonIntegral;

	error_trapezoidalIntegral = obj.error_trapezoidalIntegral;
	error_centralrectanglesIntegral = obj.error_centralrectanglesIntegral;
	
}

equation::~equation() {
	delete[] result_centralrectanglesIntegral;
	delete[] y;
	delete[] x;
	
}



/////////////////////
// Метод трапеций //
///////////////////

void equation::trapezoidalIntegral() {

	result_trapezoidalIntegral = h * (func_list[function](a) + func_list[function](b)) / 2.0;
	for (int i = 1; i <= n - 1; i++) 
		result_trapezoidalIntegral += h * func_list[function](a + h * i);

	error_trapezoidalIntegral = (((b - a) * h * h) / 12) * derivative2;
	

}


////////////////////////////////////////
// Метод центральных прямоугольников //
//////////////////////////////////////

void equation::centralrectanglesIntegral() {

	result_centralrectanglesIntegral = new double[size];
	result_centralrectanglesIntegral[0] = 0;
	for (int i = 1; i <= n; i++) {
		result_centralrectanglesIntegral[i] = result_centralrectanglesIntegral[i-1] + h*func_list[function](a + h * (i - 0.5));
	}
	error_centralrectanglesIntegral = (((b - a) * h * h) / 24) * derivative2;
	

	

}


/////////////////////
// Метод Симпсона //
///////////////////

void equation::SimpsonIntegral() {

	result_SimpsonIntegral = h * (func_list[function](a) + func_list[function](b)) / 6.0;

	for (int i = 1; i <= n; i++)
		result_SimpsonIntegral += 4.0 / 6.0 * h * func_list[function](a + h * (i - 0.5));

	for (int i = 1; i <= n - 1; i++)
		result_SimpsonIntegral +=  2.0 / 6.0 * h * func_list[function](a + h * i);

}


