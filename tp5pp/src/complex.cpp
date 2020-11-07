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

Complex operator + (Complex& Complex1, Complex& Complex2) {
	double real = Complex1._real() + Complex2._real();
	double imag = Complex1._imag() + Complex2._imag();

	Complex tmp(real, imag);
	return tmp;
}

Complex operator - (Complex& Complex1, Complex& Complex2){
	double real = Complex1._real() - Complex2._real();
	double imag = Complex1._imag() - Complex2._imag();

	Complex tmp(real, imag);
	return tmp;
}

Complex operator * (Complex& Complex1, Complex& Complex2){
	double real = (Complex1._real() * Complex2._real()) - (Complex1._imag() * Complex2._imag());
	double imag = (Complex1._real() * Complex2._imag()) + (Complex1._imag() * Complex2._real());

	Complex tmp(real, imag);
	return tmp;
}

Complex operator / (Complex& Complex1, Complex& Complex2){
	Complex conjugate2(Complex2._real(), -Complex2._imag());
	Complex num = Complex1 * conjugate2;
	Complex denom = Complex2 * conjugate2;

	Complex tmp(num._real()/denom._real(), num._imag()/denom._real());
	return tmp;
}

void Complex::print() {
	if (this->_imag() < 0.0) {
		cout << this->_real() << "-" << -this->_imag() << "i" << endl;
	} else {
		cout << this->_real() << "+" << this->_imag() << "i" << endl;
	}
}