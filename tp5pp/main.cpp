#include "./headers/public_or_private.hpp"
#include "./headers/complex.hpp"


int main () {
    cout << "======= THEME 1 PUBLIC OR PRIVATE ? =======" << endl;

    Base base;
    Derived derived;
    Unrelated unrelated;

    // cout << base.default_attribute << endl; Doesn't compile because by default attributes are private

    cout << "Base default_attribute : " << base.get_default_attribute() << endl;
    cout << "Base private_int : " << base.get_private_int() << endl;
    cout << "Base protected_int : " << base.get_protected_int() << endl;
    cout << "Base public_int : " << base.get_public_int() << endl;

    cout << endl;

    cout << "Derived default_attribute : " << derived._default() << endl;
    cout << "Derived private_int : " << derived._private() << endl;
    cout << "Derived protected_int : " << derived._protected() << endl;
    cout << "Derived public_int : " << derived._public() << endl;

    cout << endl;
    
    cout << "Unrelated default_attribute : " << unrelated._default() << endl;
    cout << "Unrelated private_int : " << unrelated._private() << endl;
    cout << "Unrelated protected_int : " << unrelated._protected() << endl;
    cout << "Unrelated public_int : " << unrelated._public() << endl;

    // By default attributes are private
    cout << "===========================================" << endl;

    cout << "================= COMPLEX =================" << endl;

    Complex c1(3, 2);
    Complex c2(4, -3);
    Complex c3;
    
    cout << "Complex 1 : ";
    c1.print();
    cout << "Complex 2 : ";
    c2.print();
    cout << endl;

    cout << "Sum > " << endl;
    c3 = c1 + c2;
    c3.print();
    cout << endl;

    cout << "Difference > " << endl;
    c3 = c1 - c2;
    c3.print();
    cout << endl;

    cout << "Product > " << endl;
    c3 = c1 * c2;
    c3.print();
    cout << endl;

    cout << "Division > " << endl;
    c3 = c1 / c2;
    c3.print();
    cout << endl;

    // ===========================================
}