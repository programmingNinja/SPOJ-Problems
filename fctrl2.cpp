/**
Author: Rohan D. Shah
Problem Statement (taken from = http://www.spoj.com/problems/FCTRL2/):
You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output

For each integer n given at input, display a line with the value of n!

Example

Sample input:
4
1
2
5
3
Sample output:

1
2
120
6

*/

#include <iostream>
using namespace std;
int main()
{
	
    int t;
    int a[200]; 
    int n,i,j,temp,m,x;

    cin>>t;
    while(t--)
    {
       cin>>n;
       a[0]=1;  
       m=1;    

       temp = 0; //Initializes carry variable to 0.
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp; 
               a[j]=x%10; 
               temp = x/10; 
            }
             while(temp>0) 
             { 
               a[m]=temp%10;
               temp = temp/10;
               m++; 
             }
      }
              for(i=m-1;i>=0;i--) //printing answer
             cout<<a[i];
             cout<<endl;
    }
    return 0;

}

