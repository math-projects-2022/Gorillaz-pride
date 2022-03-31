#pragma once

long double trapezoidalIntegral(double, double, double, double, double(*)(double));
long double centralrectanglesIntegral(double, double, double, double, double(*)(double), ofstream&);
long double SimpsonIntegral(double, double, double, double, double(*)(double));

double function_0(double);

double function_1(double);

double function_2(double);

double function_3(double);

double function_4(double);

double function_5(double);