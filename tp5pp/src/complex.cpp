#include "../headers/complex.hpp"


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