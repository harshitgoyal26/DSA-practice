#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

class Polynomial
{
    int *degCoeff ;
    int capacity ;

    public:

    Polynomial()
    {
        degCoeff = new int[5] () ;
        capacity = 5;
    }

    Polynomial(Polynomial const &d)
    {
        this -> degCoeff = new int[d.capacity] ();
        for(int i = 0 ; i<capacity ; i++)
        {
            this -> degCoeff[i] = d.degCoeff[i];
        }
        this -> capacity = d.capacity ;
    }

    void operator=(Polynomial const &d)
    {
        this -> capacity = d.capacity ;
        this -> degCoeff = new int[capacity] () ;
        for(int i = 0 ; i<capacity ; i++)
        {
            this -> degCoeff[i] = d.degCoeff[i];
        }
        this -> capacity = d.capacity ;
    }

    void print() const
    {
        for(int i = capacity-1 ; i>=0 ; i--)
        {
            if(degCoeff[i] > 0)
            {
                if(i==0)
                {
                    cout<<"+ "<<degCoeff[i]<<"  ";
                }
                else if(i==1)
                {
                    cout<<"+ "<<degCoeff[i]<<"x ";
                }
                else
                {
                    cout<<"+ "<<degCoeff[i]<<"x^"<<i<<" ";
                }
            }
            else if(degCoeff[i] <0)
            {
                if(i==0)
                {
                    cout<<""<<degCoeff[i]<<"  ";
                }
                else if(i==1)
                {
                    cout<<""<<degCoeff[i]<<"x ";
                }
                else
                {
                    cout<<""<<degCoeff[i]<<"x^"<<i<<" ";
                }
            }
        }
        cout<<endl;
    }

    void setCoeff(int i , int coeff)
    {
        if(i<capacity)
        {
            degCoeff[i] = coeff;
        }
        else
        {
            if(i >= capacity)
            {
                int *newData = new int[2*capacity] ();
                for(int j = 0 ; j< capacity ; j++)
                {
                   newData[j] = degCoeff[j];
                }

                delete [] degCoeff ;
                degCoeff = newData ;
                capacity = 2*capacity ;

                degCoeff[i] = coeff;
            }
        }
    }

    Polynomial operator+(Polynomial &p2) 
    {
        Polynomial Pnew;
        int x = max(this -> capacity , p2.capacity) ;
        int y = min(this -> capacity , p2.capacity) ;
        Pnew.capacity = x;
        Pnew.degCoeff = new int[x] ()  ;
        int n;

        for(int i = 0 ; i < y ; i++)
        {
            n = this -> degCoeff[i] + p2.degCoeff[i];
            Pnew.degCoeff[i] = n;
            // Pnew.print();
        }

        for(int i = y ; i<x ; i++)
        {
            if(this -> capacity == x)
            {
                n = this -> degCoeff[i];
                Pnew.degCoeff[i] = n;
            }
            else
            {
                n = p2.degCoeff[i];
                Pnew.degCoeff[i] = n;
            }
            
        }

        return Pnew;
    }


    Polynomial operator-(Polynomial &p2) 
    {
        Polynomial Pnew;
        int x = max(this -> capacity , p2.capacity) ;
        int y = min(this -> capacity , p2.capacity) ;
        Pnew.capacity = x;
        Pnew.degCoeff = new int[x] ()  ;
        int n;

        for(int i = 0 ; i < y ; i++)
        {
            n = this -> degCoeff[i] - p2.degCoeff[i];
            Pnew.degCoeff[i] = n;
            // Pnew.print();
        }

        for(int i = y ; i<x ; i++)
        {
            if(this -> capacity == x)
            {
                n = this -> degCoeff[i];
                Pnew.degCoeff[i] = n;
            }
            else
            {
                n = p2.degCoeff[i];
                Pnew.degCoeff[i] = -1*n;
            }
            
        }

        return Pnew;
    }


};


int main()
{
    Polynomial p1;
    p1.setCoeff(4 , 3);
    p1.setCoeff(3 , -2);
    p1.setCoeff(1 , 1);
    p1.setCoeff(0 , 1);
    p1.setCoeff(5 , 7);
    p1.setCoeff(6 , 5);
    p1.setCoeff(7 , 3);
    p1.print();

    Polynomial p2 ;
    Polynomial p3 ;
    p2 = p1 ;

    p1.setCoeff(8 , 3);
    p1.setCoeff(9 , 3);
    p1.setCoeff(10 , 3);
    p1.setCoeff(11 , 3);
    p1.print();
    p2.print() ;

    p3 = p1 + p2;
    p3.print();

    Polynomial p4;

    p4= p3 - p2 ; 
    p4.print() ;


    return 0;
}

