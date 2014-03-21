/*
Author: Rohan D. Shah
Problem Statement (Taken From = http://www.spoj.com/problems/MONEYS/ )
Description

Given a whole number of US dollars, what combination of $1, $5, $20, and $100 bills sum to that amount? Choose the combination 
that minimizes the total number of bills. For example, $10 may be composed of
ten $1 bills
one $5 and five $1 bills
two $5 bills
The fewest bills are the two $5 bills.
Input

An integer number of dollars, from 0 to 1200 inclusive.
Output

The numbers of bills, in the following order: $100, $20, $5, and $1. Separate the numbers by whitespace.
Input		Input
10			334
Output		Output
0 0 2 0		3 1 2 4

*/

#include<iostream>
using namespace std;

int main()
{
	int input;
	int hundred=0;
	int twenty=0;
	int five=0;
	int one=0;
	cin>>input;
	
	if(input>=100)
	{
		hundred = input/100;
		input = input%100;
	}
	if(input>=20)
	{
		twenty = input/20;
		input = input%20;	
	}
	if(input>=5)
	{
		five = input/5;
		input = input%5;
	}
	if(input >=1) 
	one = input;
	
	cout<<hundred<<" "<<twenty<<" "<<five<<" "<<one;
	return 0;
}
