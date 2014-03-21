/**
Author: Rohan D. Shah
Problem Statement (Taken From = http://www.spoj.com/problems/STPAR/ ):
For sure, the love mobiles will roll again on this summer's street parade. Each year, the organisers decide on a fixed order 
for the decorated trucks. Experience taught them to keep free a side street to be able to bring the trucks into order. 

The side street is so narrow that no two cars can pass each other. Thus, the love mobile that enters the side street last must 
necessarily leave the side street first. Because the trucks and the ravers move up closely, a truck cannot drive back and re-enter 
the side street or the approach street. 

You are given the order in which the love mobiles arrive. Write a program that decides if the love mobiles can be brought into the 
order that the organisers want them to be.

Input

There are several test cases. The first line of each test case contains a single number n, the number of love mobiles. The second 
line contains the numbers 1 to n in an arbitrary order. All the numbers are separated by single spaces. These numbers indicate the 
order in which the trucks arrive in the approach street. No more than 1000 love mobiles participate in the street parade. Input ends 
with number 0.

Output

For each test case your program has to output a line containing a single word yes if the love mobiles can be re-ordered with the help 
of the side street, and a single word no in the opposite case.

Example

Sample input:
5
5 1 2 4 3 
0

Sample output:
yes
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int no_of_elements;
	cin>>no_of_elements;
	
	while(no_of_elements>0)
	{
		queue<int> incoming;
		queue<int> outgoing;
		bool yes = true;
		
		for(int i=0 ; i<no_of_elements ; i++)
		{
			int temp;
			cin>>temp;
			incoming.push(temp);
		}
		
		stack<int> side_street;
		
		while(!incoming.empty() && yes)
		{
			int temp = incoming.front();
			incoming.pop();
			if(side_street.empty() && temp>incoming.front())
			{
				side_street.push(temp);
				continue;
			}
			if(!side_street.empty() && side_street.top() < temp)
			{
				if(side_street.top() < outgoing.back() && !outgoing.empty())
				{
					yes = false;
					continue;
				}
				else
				{					
					while(!side_street.empty() && temp > side_street.top())
					{
						outgoing.push(side_street.top());
						side_street.pop();
					}
				}
				side_street.push(temp);
				
			}
			else
			{
				if(!incoming.empty() && temp > incoming.front())
				{
					side_street.push(temp);
					continue;
				}
				if(!side_street.empty() && temp > side_street.top())
				{
					if(temp > side_street.top())
					{
						yes = false;
						continue;
					}
					else
					{
						side_street.push(temp);
					}					
				}
				else
				{
					if(!outgoing.empty() && temp < outgoing.back())
					{
						yes = false;
						continue;
					}
					outgoing.push(temp);
				}
			}			
		}
		while(!side_street.empty() && yes)
		{
			if(side_street.top() < outgoing.back())
			{
				yes = false;
				continue;
			}
			outgoing.push(side_street.top());
			side_street.pop();
		}
		if(!yes)
		{
			cout<<"no"<<endl;
			goto next_in;
		}
		else
		{
			cout<<"yes"<<endl;
			goto next_in;
		}
		next_in:
		cin>>no_of_elements;
	}
	return 0;
}
