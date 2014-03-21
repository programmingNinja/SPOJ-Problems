/*
Author: Rohan D. Shah
Problem Statement (Taken from = http://www.spoj.com/problems/AVERAGE/ )
Description

Given a list of numbers, compute the median and the mean.
Median - When the list is sorted, the median is the middle number. If the length of the list is even, the median is halfway 
between the two middle numbers.
Mean - The arithmetic mean is the sum divided by the length of the list.
Input

The first line is the N, the length of the list of numbers (1 <= N <= 100). The next N lines are integers between 1 and 1000 inclusive.
Output

On the first line, print the median. On the second line, print the mean. Your answer must be accurate within three decimal places.
Input	Input
5
1
2
3
4
5
4
3
11
4
3
Output	Output
3
3
3.5
5.25

*/

#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int elements;
	cin>>elements;
	float median;
	float mean;
	int sum = 0;
	int *arr = new int[elements];
	
	for(int i=0;i<elements;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr, arr + elements);
	if(elements%2 == 0)
	{
		int m = elements/2 - 1;
		int n = elements/2 ;
		
		median = (float)(arr[m] + arr[n])/2;
	}
	else
	{
		median = arr[elements/2];
	}
	mean = (float)sum/elements;
	
	cout<<median<<endl<<mean;
}
