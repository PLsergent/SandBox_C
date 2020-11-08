#include "../headers/complex.hpp"


Complex::Complex() {
	cout << "Default constructor running..."; 
	real = 0;
	imag = 0;
	cout << "done" << endl;
}

Complex::Complex(const Complex& complex) {
	cout << "Copy constructor running..."; 
	real = complex.real;
	imag = complex.imag;
	cout << "done" << endl;
}

Complex::Complex(double real_ = 0, double imag_ = 0 ) {
	cout << "Basic constructor running..."; 
	real = real_;
	imag = imag_;
	cout << "done" << endl; 
}

Complex operator + (Complex& complex1, Complex& complex2) {
	double real = complex1.real + complex2.real;
	double imag = complex1.imag + complex2.imag;

	Complex tmp(real, imag);
	return tmp;
}

Complex operator - (Complex& complex1, Complex& complex2){
	double real = complex1.real - complex2.real;
	double imag = complex1.imag - complex2.imag;

	Complex tmp(real, imag);
	return tmp;
}

Complex operator * (Complex& complex1, Complex& complex2){
	double real = (complex1.real * complex2.real) - (complex1.imag * complex2.imag);
	double imag = (complex1.real * complex2.imag) + (complex1.imag * complex2.real);

	Complex tmp(real, imag);
	return tmp;
}

Complex operator / (Complex& complex1, Complex& complex2){
	Complex conjugate2(complex2.real, -complex2.imag);
	Complex num = complex1 * conjugate2;
	Complex denom = complex2 * conjugate2;

	Complex tmp(num.real/denom.real, num.imag/denom.real);
	return tmp;
}

ostream& operator << (ostream& out, Complex& complex) {
	out << complex.real;
	complex.imag < 0.0 ?
		out << " - " << -complex.imag << "i" << endl :
			out << " + " << complex.imag << "i" << endl;
	return out;
}

istream& operator >> (istream &in,  Complex& complex) {
    cout << "Enter Real Part : "; 
    in >> complex.real; 
    cout << "Enter Imaginary Part : "; 
    in >> complex.imag; 
    return in; 
}

/* Complex& Complex::operator = (Complex& complex) {
	real = complex.real;
	imag = complex.imag;

	return *this;
} */

void Complex::print() {
	cout << this->_real();
	if (this->_imag() < 0.0) {
		cout << "-" << -this->_imag() << "i" << endl;
	} else {
		cout << "+" << this->_imag() << "i" << endl;
	}
}