#include<iostream>
using namespace std; 
int add (int [], int [], int [], int);
void shift_left(int *,int *, int);
void get_twoscomplement(int [], int [],int);

int main()
{
    int n;
    cout<<"Enter the number of bits::";
    cin>>n;

    int *dividend = new int[n];
    int *divisor  = new int[n+1];
    int *A = new int[n+1];
    int *divisor_twoscomplement = new int[n+1];

    cout<<"Enter the Dividend::";
    for(int i=0; i<n; i++)
    {
        cin>>dividend[i];
    } 
    cout<<"Enter the Divisor::";
    for(int i=0; i<=n; i++)
    {
        cin>>divisor[i];
        A[i]=0;
    }

    get_twoscomplement(divisor, divisor_twoscomplement, n+1);

    int count = n;

    for(int i=count; i>0; i--)
    {
        shift_left(A, dividend, n); // shift one position left
        add(A, divisor_twoscomplement, A, n+1);
        if(A[0]==1)
        {
            dividend[n-1]=0;
            add(A,divisor,A,n+1);
        }
        else
        {
            dividend[n-1]=1;
        }
    }
    
    cout<<"The quotient is:";
    for(int i=0; i<n; i++)
    {
        cout<<dividend[i];
    }
    cout<<endl<<"The remainder is::";
    for(int i=0; i<=n; i++)
    {
        cout<<A[i];
    }
    cout<<endl;
    return 0;
}
//Two's complement

void get_twoscomplement(int *divisor, int *complement_result, int n)
{
    int *onescomplement = new int[n];
    for(int i=0; i<n; i++) // one's complement
    {
        onescomplement[i]=(divisor[i]==0)?1:0;
    }
    int *one = new int[n];
    for(int i=0; i<n-1; i++)
    {
        one[i]=0;
    }
    one[n-1]=1;  // 1 value for adding to get two's complement
    add(onescomplement, one, complement_result, n);
}

//Adding 

int add(int *binary1,int *binary2,int *sum,int n)
{
    int carry=0,temp;
    for(int i=n-1;i>=0;i--)
    {
        temp =(binary1[i]+binary2[i]+carry);
        sum[i]=temp%2;
        carry=temp/2; 
    }
    return carry;
}

// Shifting left one position 

void shift_left(int *A, int *dividend, int n)
{
    for(int i=0; i<n; i++)
    {
        A[i] = A[i+1];
    }
    A[n] = dividend[0];
    for(int i=0; i<n-1; i++)
    {
        dividend[i] = dividend[i+1];
    }
}
