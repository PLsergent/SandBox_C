#include "./headers/public_or_private.hpp"
#include "./headers/complex.hpp"
#include "./headers/X.hpp"
#include "./headers/Y.hpp"
#include "./headers/D.hpp"
#include "./headers/2D_array.hpp"


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

    Complex c4(c1);
    
    cout << "Complex 1 : ";
    c1.print();
    cout << "Complex 2 : ";
    c2.print();
    cout << endl;

    cout << "Sum + " << endl;
    c3 = c1 + c2;
    c3.print();
    cout << endl;

    cout << "Difference - " << endl;
    c3 = c1 - c2;
    c3.print();
    cout << endl;

    cout << "Product * " << endl;
    c3 = c1 * c2;
    c3.print();
    cout << endl;

    cout << "Division / " << endl;
    c3 = c1 / c2;
    c3.print();
    cout << endl;

    cout << "===========================================" << endl;

    cout << "================= CLASS X =================" << endl;

    X a;
    a.print();

    X b(a); // Copy constructor called
    b.print();

    a.set_value_at(1, 3);
    a.print(); // a array updated
    b.print(); // b array unchanged
    cout << "===========================================" << endl;

    cout << "================= CLASS Y =================" << endl;

    Y e;
    e.print();

    Y f(e); // Copy constructor called
    f.print();

    e.set_value_at(1, 3);
    e.print(); // e array updated
    f.print(); // f array unchanged
    cout << "===========================================" << endl;

    cout << "================= CLASS D =================" << endl;

    char string1[] = "str1";
    char string2[] = "str2";
    D str1(string1);
    D str2(string2);

    D *pt_str1 = &str1;
    D *pt_str2 = &str2;

    str1.D::~D();
    str2.D::~D();

    // Even if the destructors are called explicitly they will be called automaticaly when out of scope
    // So there is the same amount of destructor and constructor called when the destructor are not called explicitly

    cout << "===========================================" << endl;
    
    cout << "================ 2D ARRAY =================" << endl;

    T dyn_arr(2, 2);
    // The constuctors of O are called before the constructor of T
    // Same for the destuctors

    cout << "===========================================" << endl;
    return 0;
}