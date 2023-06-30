#include<iostream>
using namespace std;

void addb(int [],int[],int [],int ,int,int );

int main()
{

    int n,m,i;
    cout<<"Enter number of bits of multiplicand:";
    cin>>n;
    cout<<"Enter number of bits of mutiplier:";
    cin>>m;
    int a=(n>m)?n:m;
    int o=2*a;
    int *sum = new int [o];
        for(i=0; i<o; i++)
        {
            sum[i]=0;
        }
    
    int *multiplicand = new int [n];
    int *multiplier = new int [m];
    // input multiplicand
    cout<<"Enter multiplicand:";
    for(i=0; i<n; i++)
    {
        cin>>multiplicand[i];
    }
    //input mutliplier
    cout<<"Enter multiplier:";
    for(i=0; i<m; i++)
    {
        cin>>multiplier[i];
    }

    addb(multiplicand,multiplier,sum,n,m,a);// calling function
    
    // display result
    cout<<"Multiplication of Binary number is:";
    for(i=0; i<o; i++)
    {
        cout<<sum[i];
    }
    cout<<endl;
    //deallocate memory
    delete [] sum;
    delete [] multiplicand;
    delete [] multiplier;
    return 0;
        
}

void addb(int *multiplicand, int *multiplier, int *result,int n,int m, int c)
{
    int i,j,k,l,temp,a,b=0;
    a=c*2;

    int *multiplicand1 = new int[a];
    for(i=0; i<a; i++) // zero-padding or zero-extension
    {
        if(i<(a-n))
        {
            multiplicand1[i]=0;
        }
        else
        {
            multiplicand1[i]=multiplicand[b];
            b++;
        }
    }

    
    for(i=m-1; i>=0; i--)
    {
        for(k=0; k<1; k++)// shifting value backward by 1 step
            {
                 for(l=0; l<a-1; l++)
                    {
                      result[l] = result[l+1];
                    }
                    result[a-1] = 0;
            }
        if(multiplier[i] == 1)
        {
            int carry=0;
            for(j=a-1; j>=0; j--)
            {
                 temp = multiplicand1[j]+result[j]+carry;
                 result[j] = temp%2;
                 carry = temp/2;
            }
        }
    }
}