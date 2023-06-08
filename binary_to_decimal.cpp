#include<iostream>
using namespace std;
long long binary_to_decimal(long long);

int main()
{
    long long decimal,binary;
    cout<<"Enter binary number::";
    cin>>binary;

    decimal=binary_to_decimal(binary);
    cout<<"Decimal of binary is:"<<decimal;
    cout<<endl;
    return 0;

}

long long binary_to_decimal(long long binary)
{
    long long weight=1,remainder,decimal=0;
    while (binary!=0)
    {
        remainder=binary%10;
        decimal+=remainder*weight;
        binary/=10; //binary=binary/10;
        weight*=2;  //weight=weight*2;
    }
    return decimal;
    
}




