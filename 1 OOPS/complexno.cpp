#include<iostream>
using namespace std;

class complex {
    int real , img ;
    public:
    

    complex()
    {
        real = 0 ;
        img = 0 ;
    }

    complex(int r , int i)
    {
        real = r;
        img = i;
    }

    void display()
    {
        if(img < 0)
        {
            if(img==-1)
            {
                cout<<real<<" - i"<<endl;
            }
            else
            cout<<real<<" - i"<<img*-1<<endl;
        }
        else if(img==0)
        {
            cout<<real<<endl;
        }
        else
        {
            if(img==1)
            {
                cout<<real<<" + i"<<endl;
            }
            else
            {
                cout<<real<<" + i"<<img<<endl;
            }
        }

    }

    void plus(complex c2)
    {
        this -> real = this -> real + c2.real ;
        this -> img = this -> img + c2.img ;
    }

    void multiply(complex c2)
    {
        this -> real = (this -> real) * (c2.real) - (this -> img) * (c2.img) ;
        this -> img  = (this -> real) * (c2.img) + (c2.real) * (this -> img) ;
    }

};



int main()
{
    int real1 , img1 , real2 , img2 , choice;

    cin>> real1 >> img1 ;
    cin>> real2 >> img2 ;

    cout<<"Enter a choice"<<endl;
    cin>>choice;

    complex c1(real1 , img1);
    complex c2(real2 , img2);

    c1.display() ;
    c2.display() ;

    if(choice == 1)
    {
        c1.plus(c2);
        c1.display();
    }
    else
    {
        c1.multiply(c2);
        c1.display();
        
    }


    return 0;
}