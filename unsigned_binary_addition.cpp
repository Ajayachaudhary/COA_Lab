#include<iostream>
using namespace std;

int addb(int [],int [],int [],int); // addb(int*, int*, int*, int);

int main()
{
    int n;
    cout<<"Enter no. of bits::";
    cin>>n;
    int *binary1=new int[n], *binary2=new int[n],*sum=new int[n];
    cout<<"Enter first binary number:";
    for(int i=0;i<n;i++)
    {
        cin>>binary1[i];
    }
    cout<<"Enter second binary number:";
    for(int i=0;i<n;i++)
    {
        cin>>binary2[i];
    }

    int carry=addb(binary1,binary2,sum,n); 
    cout<<"sum:";
    for(int i=0;i<n;i++)
    {
        cout<<sum[i];
    }
    cout<<endl<<"carry:"<<carry;
    return 0;
}

int addb(int *binary1,int *binary2,int *sum,int n)
{
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        sum[i]=(binary1[i]+binary2[i]+carry)%2;
        carry=(binary1[i]+binary2[i]+carry)/2; 
    }
    return carry;
}

