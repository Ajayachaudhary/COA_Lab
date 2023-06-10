#include<iostream>
using namespace std;
long long decimal_to_binary(long long);

int main()
{
    long long decimal,binary;
    cout<<"Enter decimal number::";
    cin>>decimal;

    binary=decimal_to_binary(decimal);
    cout<<"Binary is:"<<binary;
    cout<<endl;
    return 0;

}

long long decimal_to_binary(long long decimal)
{
    long long weight=1,remainder,binary=0;
    while (decimal!=0)
    {
        remainder=decimal%2;
        binary+=remainder*weight;
        decimal/=2; //binary=binary/10;
        weight*=10;  //weight=weight*2;
    }
    return binary;
    
}
