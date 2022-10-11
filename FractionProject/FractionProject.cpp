#include <iostream>
#include "Fraction.h"
using namespace std;

class B
{
public:
    void MethodB()
    {
        cout << "method B\n";
    }
};

class A
{
public:
    B MethodA()
    {
        cout << "method A\n";
        return *(new B());
    }
};

int main()
{
    Fraction 
        f1(2, 3),
        f2(4, 5),
        f3(3, 7);

    f2.Print();
    cout << "\n";
    f1.Add(f2).Div(f3).Print();
    f2 = f1.Mult(f3);
    cout << "\n";

    /*f1.Print();
    cout << "\n";
    
    f1 = f1.Add(f2);

    f1.Print();
    cout << "\n";*/
    /*f3.Print();
    cout << "\n";*/

    //f1.Add(f2).Mult(f3).Del(f1).Div(*(new Fraction(5, 8))).Print();

    //cout << sizeof(Fraction);



    // A & B classes
    /*A a;
    a.MethodA().MethodB();*/
}
