#include "equation.h"

double F0(double x) {

	return sin(x);

}

double F1(double x) {

	return cos(x);

}
/////////////
// y=2*x² //
///////////

double F2(double x) {

	return (2.0 * (x * x));

}

//////////
// y=x //
////////

double F3(double x) {

	return x;

}

///////////
// y=5ᵡ //
/////////

double F4(double x) {

	return pow(5.0, x);

}

/////////////////
//  y=1/5²+x² //
///////////////

double F5(double x) {

	return (1 / (5.0 * 5.0 + x * x));

}

///////////
// y=eᵡ //
/////////

double F6(double x) {

	return pow(M_E, x);

}

///////////////
// y=(x+2)³ //
/////////////

double F7(double x) {

	return ((x + 2.0) * (x + 2.0) * (x + 2.0));
}