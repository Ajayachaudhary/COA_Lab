#include<iostream>
using namespace std;

int addb(int [],int [],int [],int);
void get_twos_complement(int [],int [],int);
int sub(int[],int[],int [],int);

int main()
{
    int n;
    cout<<"Enter no. of bits::";
    cin>>n;
    int *minude=new int[n], *subtrahend=new int[n],*diff=new int[n];
    cout<<"Enter minude number:";
    for(int i=0;i<n;i++)
    {
        cin>>minude[i];
    }
    cout<<"Enter subtrahend number:";
    for(int i=0;i<n;i++)
    {
        cin>>subtrahend[i];
    }

    int carry=sub(minude,subtrahend,diff,n); 
    cout<<"Difference is:";
    if(carry==1) //Minude is grater than subtrahend
    {
        for(int i=0;i<n;i++)
        {
            cout<<diff[i];
        }
    }
    else // Subtrahend is grater than minude
    {
        int *negatives=new int[n];
        get_twos_complement(diff,negatives,n);
        cout<<"-";
        for(int i=0;i<n;i++)
        {
            cout<<negatives[i];
        }

    }
    cout<<endl;
    return 0;
}
// Addition fucntion
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
// Two's complement fucntion
void get_twos_complement(int *subtrahend,int *twos_complement,int n)
{
    int *ones_complement=new int[n];// to get one's complement
    for(int i=0;i<n;i++)
    {
        ones_complement[i]=(subtrahend[i]==0)?1:0;
    }
    int *one=new int[n];// for 1 value uses to get two'complement 
    for(int i=0;i<n-1;i++)
    {
        one[i]=0;
    }
    one[n-1]=1;

    addb(ones_complement,one,twos_complement,n);
}
// Subtration fuction
int sub(int *minude,int*subtrahend,int*diff,int n)
{
    int *twos_complement=new int[n];
    get_twos_complement(subtrahend,twos_complement,n);
    return addb(minude,twos_complement,diff,n);
}

