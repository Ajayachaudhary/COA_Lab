 #include<iostream>
using namespace std;

long long addb(long long, long long);

int main()
{
    int multiplicand, mulitplier, lsb, sf=1; // sf= shfting factor
    long long ps=0;
    cout<<"Enter the multiplicand::";
    cin>>multiplicand;
    cout<<"Enter the multiplier:";
    cin>>mulitplier;

    while(mulitplier!=0)
    {
        lsb=mulitplier%10;
        if(lsb)
        {
            ps=addb(sf*(long long)multiplicand,ps); // intermediate value become long long
        }
        sf*=10;
        mulitplier/=10;
    }
    cout<<"Multiplication of two unsigned bunary number is:"<<ps<<endl;
    return 0;
}

long long addb(long long multiplicand, long long partial_sum)
{
    int carry=0;
    long long multiplication_factor=1;
    long long sum=0;
    while(multiplicand!=0 || partial_sum!=0)
    {
        sum+=((multiplicand%10+partial_sum%10+carry)%2)*multiplication_factor;
        carry=(multiplicand%10+partial_sum%10+carry)/2;
        multiplicand/=10;
        partial_sum/=10;
        multiplication_factor*=10;
    }
    sum+=carry*multiplication_factor; // to add if carry generate at MSB
    return sum;
}
