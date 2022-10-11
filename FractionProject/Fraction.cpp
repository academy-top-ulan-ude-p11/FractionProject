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