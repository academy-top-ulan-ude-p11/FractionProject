#pragma once
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
    void SetNumerator(int value);
    void SetDenominator(int value);
    int GetNumerator() const;
    int GetDenominator() const;

    void Print() const;
    Fraction Add(const Fraction& f);
    Fraction Del(Fraction& f);
    Fraction Mult(Fraction f);
    Fraction Div(Fraction f);

    //Fraction operator+(const Fraction& f);
    //Fraction operator+(int n);
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator+(const Fraction f, int n);
    friend Fraction operator+(int n, const Fraction f);
    friend Fraction operator+(const Fraction f, double n);
    friend Fraction operator+(double n, const Fraction f);

    friend bool operator>(const Fraction& f1, const Fraction& f2);
};

