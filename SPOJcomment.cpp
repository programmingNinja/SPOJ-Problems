#include<iostream>
#include<string>
using namespace std;

/**
Author: Rohan D. Shah
Problem Statement (Taken From = http://www.spoj.com/problems/COMMENTS/ ) :

Description

Everyone knows that lots and lots of comments make for great code.
Well...actually that's not true.
In any case, we are going to count comments in programs written in a new language: C' (pronounced C prime).
In this language, comments take two forms.
Type-1: Beginning with two slashes (//), and ending with a new line, or end-of-file.
Type-2: Beginning with a slash and asterisk (/*), and ending with an asterisk and a slash (*\/). 
Comments are found by starting at the beginning of the program and moving forward. An opening comment token can be anywhere except 
inside another comment. Once a comment begins, it is terminated only by the ending sequence for that same type.
For instance,
//* *\/ hello
is a single type-1 comment, since it began with // and it can only end with a new line or end-of-file.
Likewise,
/** a
	// b
*\/ c
is a single type-2 comment, since it began with /* and can only end with *\/.
Given source code, how many comments of each type are present?
Input

Source code consisting of at most 5000 characters. The code will be legal according to the rules earlier (i.e. it will not have unclosed 
comments).
Output

The number of type-1 comments and the number of type-2 comments. Separate these answers by whitespace.
Input
//* *\/ hello
Output
1 0
Input
/**
 * @return whether program halts
 *\/
int doesItHalt(void (*program)()) {
	return 1; //remember: big picture perspective
}
Output
1 1
Input
int f(int a, int *b) {
	char *t = "//yeah, this isn't C";
	return a /*b *\/*//*c
	;
}
Output
2 1
 */
int main() {

    string input;
    string line;

    int comment1 = 0;   // number of single line comments
    int comment2 = 0;   // number of multi line comments

    // Read lines until end of file (EOF).
    // If typing with the keyboard, type Ctrl+Z and Enter for EOF.
    while (!cin.eof()) {
        getline(cin, line);
        input += line + '\n';
    }

    for(int i = 0; i < input.length() - 1; i++) {

        // Single line comment
        if (input[i] == '/' && input[i + 1] == '/') {
    		comment1++;
    		i += 2;
    		while(i < input.length() && input[i] != '\n')
                i++;
        }
        // Multi line comment
    	else if(input[i] == '/' && input[i + 1] == '*') {
            comment2++;
            i += 2;
            while (input[i] != '*' || input[i + 1] != '/')
                i++;
            i++;
    	}
    }

    cout << comment1 << " " << comment2;
    return 0;
}
