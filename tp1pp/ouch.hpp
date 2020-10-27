/**
 * @author Cédric B. (triozer#4242)
 */

#ifndef EXO_2_OUCH_H
#define EXO_2_OUCH_H

#include <iostream>

using namespace std;

class ouch {
private :
	long a;
public :
	ouch() { a = 0; }

	~ouch() {}

	void incr(long n) { a = a + n; }

	void print() const { cout << "a = " << a << endl; }
};

#endif