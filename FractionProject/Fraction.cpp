#include <iostream>
#include "Fraction.h"
void Fraction::SetNumerator(int value) { numerator = value; }
void Fraction::SetDenominator(int value) { denominator == 0 ? 1 : value; }
int Fraction::GetNumerator() const { return numerator; }
int Fraction::GetDenominator() const { return denominator; }

void Fraction::Print() const
{
    std::cout << "[" << numerator << "/" << denominator << "]";
}

Fraction Fraction::Add(const Fraction& f)
{
    Fraction res;
    res.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
    res.denominator = this->denominator * f.denominator;
    return res;
}

Fraction Fraction::Del(Fraction& f)
{
    Fraction res;
    res.numerator = this->numerator * f.denominator - this->denominator * f.numerator;
    res.denominator = this->denominator * f.denominator;
    return res;
}

Fraction Fraction::Mult(Fraction f)
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

Fraction Fraction::Div(Fraction f)
{
    Fraction res;
    res.numerator = this->numerator * f.denominator;
    res.denominator = this->denominator * f.numerator;
    return res;
}

Fraction Fraction::operator-()
{
    this->numerator = -this->numerator;
    return *this;
}

double Fraction::operator+()
{
    return (double)this->numerator / this->denominator;
}

bool Fraction::operator!()
{
    return !(this->numerator == 0);
}

Fraction Fraction::operator++()
{
    this->numerator += this->denominator;
    return *this;
    /*Fraction res(this->numerator + this->denominator, this->denominator);
    return res;*/
}

Fraction Fraction::operator++(int)
{
    Fraction res(this->numerator, this->denominator);
    this->numerator += this->denominator;
    return res;
}

Fraction::operator double()
{
    return (double)this->numerator / this->denominator;
}

//Fraction Fraction::operator+(const Fraction& f)
//{
//    /*Fraction res;
//    res.numerator = this->numerator * f.denominator + this->denominator * f.numerator;
//    res.denominator = this->denominator * f.denominator;
//    return res;*/
//
//    return this->Add(f);
//}
//
//Fraction Fraction::operator+(int n)
//{
//    Fraction res;
//    res.numerator = this->numerator + n * this->denominator;
//    res.denominator = this->denominator;
//    return res;
//}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction res;
    res.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    res.denominator = f1.denominator * f2.denominator;
    return res;

    //return f1.Add(f2);
}

Fraction operator+(const Fraction f, double n)
{
    Fraction n1;
    n1.numerator = (int)n * f.denominator;
    n1.denominator = f.denominator;
    Fraction n2;
    n2.numerator = (n - (int)n) * 100;
    n2.denominator = 100;
    n1 = n1 + n2;
    return (f + n1);
}

// non friend function overloading opertaors:
//Fraction operator*(const Fraction& f1, const Fraction& f2)
//{
//    Fraction res;
//    res.SetNumerator(f1.GetNumerator() * f2.GetDenominator());
//    res.SetDenominator(f1.GetDenominator() * f2.GetNumerator());
//    return res;
//}

bool operator>(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denominator > f2.numerator * f1.denominator;
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
    //return f1.numerator * f2.denominator <= f2.numerator * f1.denominator;
    return !(operator>(f1, f2));
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    //return f1.numerator * f2.denominator >= f2.numerator * f1.denominator;
    return !(operator<(f1, f2));
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denominator == f2.numerator* f1.denominator;
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
    //return f1.numerator * f2.denominator != f2.numerator * f1.denominator;
    return !(operator==(f1, f2));
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << "[" << f.numerator << "/" << f.denominator << "]";
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    in >> f.numerator;
    in >> f.denominator;
    return in;
}
