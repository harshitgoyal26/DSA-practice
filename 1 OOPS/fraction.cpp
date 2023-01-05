#include<iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

    public:
    
    Fraction(int numerator , int denominator)
    {
        this -> numerator = numerator ;
        this -> denominator = denominator ;
    }

    void print() const
    {
        cout<< this -> numerator <<" / "<< this -> denominator <<endl;

    }

    void simplify()
    {
        int gcd =1;
        int j = min(numerator , denominator);

        for(int i=1 ; i<=j ;i++)
        {
            if(numerator%i==0 && denominator%i ==0)
            {
                gcd = i ;
            }
        }

        numerator = numerator / gcd ;
        denominator = denominator / gcd ;
    }

    Fraction add(Fraction f2) const
    {
        int lcm = denominator * f2.denominator ;
        int x = lcm / denominator ;
        int y = lcm / f2.denominator ;

        int num = x * numerator + (y * f2.numerator);
        //this -> numerator = num ;
        //this -> denominator = lcm;

        Fraction fnew(num , lcm) ; 
        fnew.simplify() ;
        return fnew;
    }

    Fraction operator+(Fraction f2) const
    {
        int lcm = denominator * f2.denominator ;
        int x = lcm / denominator ;
        int y = lcm / f2.denominator ;

        int num = x * numerator + (y * f2.numerator);
        //this -> numerator = num ;
        //this -> denominator = lcm;

        Fraction fnew(num , lcm) ; 
        fnew.simplify() ;
        return fnew;
    }

    Fraction multiply(Fraction f2) const
    {

        int n = numerator * f2.numerator ;
        int d = denominator * f2.denominator ;

        Fraction fnew(n , d);
        fnew.simplify();

        return fnew ;
    }
    
    Fraction operator*(Fraction f2) const
    {

        int n = numerator * f2.numerator ;
        int d = denominator * f2.denominator ;

        Fraction fnew(n , d);
        fnew.simplify();

        return fnew ;
    }

    bool operator==(Fraction f2) const
    {
        return(numerator == f2.numerator && denominator == f2.denominator);
    }

    Fraction& operator++()
    {
        numerator = numerator + denominator ; 
        simplify() ;

        return *this ;
    }

    Fraction operator++(int)
    {
        Fraction fnew(numerator , denominator) ;
        numerator = numerator + denominator ;

        simplify();
        fnew.simplify();

        return fnew ;
    }

    Fraction& operator+=(Fraction f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator ;
        int y = lcm / f2.denominator ;

        int num = x* numerator + (y * f2.numerator) ;
        numerator = num ;
        denominator = lcm ;
        simplify();

        return *this ;
    }



};


int main()
{
    Fraction f1(10 , 2);
    Fraction f2(15 , 4);

    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2 ;

    Fraction f5 = f1.multiply(f2);
    Fraction f6 = f1 * f2 ;
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();
    f6.print();

    if(f1 == f2 )
    {
        cout<<"Equal !"<<endl;
    }
    else
    {
        cout<<"Not equal"<<endl;
    }

    ++f1 ;
    f1.print();
    Fraction y = ++f1;
    y.print();
    f1.print();


    cout<<"Post increment starts here"<<endl;

    f1++ ;
    f1.print();
    y = f1++ ;
    y.print() ;
    f1.print() ;

    Fraction f7(5 , 8) ;
    Fraction f8(3 , 7) ;

    f7 += f8 ;
    f7.print() ;
    f8.print() ;


    return 0;
}