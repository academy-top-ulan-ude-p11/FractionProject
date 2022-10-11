#include <iostream>

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





class Fraction
{
    int numerator;
    int denominator;
public:
    //Fraction() : numerator{ 0 }, denominator{ 1 } {}
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{ numerator }, denominator{ denominator } 
    {
        if (denominator == 0)
            denominator = 1;
    }
    void SetNumerator(int value) { numerator = value; }
    void SetDenominator(int value) { denominator == 0 ? 1 : value; }
    int GetNumerator() const { return numerator; }
    int GetDenominator() const { return denominator; }

    void Print() const
    {
        cout << "[" << numerator << "/" << denominator << "]";
    }

    Fraction Add(const Fraction& f)
    {
        Fraction res;
        res.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
        res.denominator = this->denominator * f.denominator;
        return res;
    }

    Fraction Del(Fraction& f)
    {
        Fraction res;
        res.numerator = this->numerator * f.denominator - this->denominator * f.numerator;
        res.denominator = this->denominator * f.denominator;
        return res;
    }

    Fraction Mult(Fraction f)
    {
        //1
        Fraction res;
        res.numerator = this->numerator * f.numerator;
        res.denominator = this->denominator * f.denominator;
        return res;

        //2
        /*Fraction res(this->numerator * f.numerator, this->denominator * f.denominator);
        return res;*/

        //3
        //return *(new Fraction(this->numerator * f.numerator, this->denominator * f.denominator));
    }

    Fraction Div(Fraction f)
    {
        Fraction res;
        res.numerator = this->numerator * f.denominator;
        res.denominator = this->denominator * f.numerator;
        return res;
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
