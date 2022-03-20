#include <iostream>
#include <math.h>
#include "main.h"
#include <thread>    

using namespace std;
int main() {
	setlocale(LC_ALL, "");
	double a, b;
	double h;
	cout << "¬ведите границы интегрировани€" << endl;
	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;

	cout << "¬ведите шаг интегрировани€" << endl;
	cout << "h: " << std::endl;
	cin >> h;

	double n = (b - a) / h;

	 thread first(trapezoidalIntegral, a, b, h, n);
	 thread second(centralrectanglesIntegral, a, b, h, n);
	 thread third(SimpsonIntegral, a, b, h, n);
	 first.join();
	 second.join();
	 third.join();
	
	return 0;
}

double f(double x) {

	return sin(x);

}

void trapezoidalIntegral(double a, double b, double h, double n) {
	double result = 0.0;
	result = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++)
		result = result + h * f(a + h * i);
	cout << "I1 = " << result << endl;


}

void centralrectanglesIntegral(double a, double b, double h, double n) {
	
	double result = 0.0;
	for (int i = 1; i <= n; i++)
		result = result + h * f(a + h * (i - 0.5));
	cout << "I2 = " << result << "\n";

}

void forSimpsonIntegral(double result, double a, double b, double h, double n) {
	for (int i = 1; i <= n - 1; i++)
		result = result + 2.0 / 6.0 * h * f(a + h * i);
	cout << "I3 = " << result << "\n";
}

void SimpsonIntegral(double a, double b, double h, double n) {
	double result = h * (f(a) + f(b)) / 6.0;
	for (int i = 1; i <= n; i++)
		result = result + 4.0 / 6.0 * h * f(a + h * (i - 0.5));
	std::thread t1([&]()
		{
			for (int i = 1; i <= n - 1; i++)
				result = result + 2.0 / 6.0 * h * f(a + h * i);
		});
	t1.join();
	cout << "I3 = " << result << "\n";

}