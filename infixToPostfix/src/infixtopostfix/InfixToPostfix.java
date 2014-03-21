/**
 * 
 * Problem Statement (Taken from = http://www.spoj.com/problems/ONP/ ):
 * Converting infix expressions to postfix a.k.a RPN expressions
 * 
 * Description:
 * It transforms the algebraic expression with brackets into RPN form (Reverse Polish Notation). 
 * Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). 
 * Operands: only letters: a,b,...,z. The program assumes that there is only one RPN form (no expressions like a*b*c).
 * 
 * Input
 * t [the number of expressions <= 100]
 * expression [length <= 400]
 * [other expressions]
 * Text grouped in [ ] does not appear in the input file.
 * 
 * Output
 * The expressions in RPN form, one per line.
 * 
 * Algorithm:
 * Let 's' be the stack, 'exp' be an infix expression.
 * 
 * while(till the end of the expression)
 * {
 *      if(character is an operand)
 *      store it in a postfix array 'post'
 *      else
 *      {
 *          if((the stack is empty OR the char has higher precedence than stacktop operator OR
 *              the char is '(' OR the char AND stacktop operator is '^') AND char is not ')')
 *              push the character in the stack
 *          else if(character is ')')
 *          pop all the chars from the stack until opening bracket is encountered
 *          else if(the char is of lesser or equal precedence with the stacktop operator)
 *          {
 *              1. pop all the chars from the stack untill the current char becomes of higher precedence
 *                 to the stack top operator or the stack becomes empty
 *              2. push the current char in the stack.
 *          }
 *      }
 * }
 * while(the stack is not empty)
 * pop the stack and store all the characters in the post array and print it.
 * Example
 * Input:
 * 3
 * (a+(b*c))
 * ((a+b)*(z+x))
 * ((a+t)*((b+(a+c))^(c+d)))
 * 
 * Output:
 * abc*+
 * ab+zx+*
 * at+bac++cd+^*
 */

package infixtopostfix;

import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;

/**
 *
 * @author Rohan D. Shah
 */
public class InfixToPostfix {

    /**
     * @param args the command line arguments
     */
    public static int precedence(char ch)
    {
        switch(ch){
                case '(': return 0;
                 
                case '+': return 1;
                   
                case '-': return 1;
                    
                case '*': return 2;
                    
                case '/': return 2;
                   
                case '%': return 2;
                    
                case '^': return 3;
                    
                case ')': return 4;
                                       
                default: return -1;
        }
    }
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();       
        for(int i=0 ; i<n ; i++)
        {
            Vector post = new Vector();
            Stack operators = new Stack();
            String exp = "";
            exp = sc.next();            
            char[] expArr = exp.toCharArray();           
            
            for(int j=0 ; j<expArr.length ; j++)
            {
                if(Character.isLetter(expArr[j]))
                    post.add(expArr[j]);
                else
                {
                    if((operators.isEmpty() || (precedence(expArr[j])>precedence((char) operators.peek() ))
                            || expArr[j] == '(' || ((char)operators.peek() == '^' &&  expArr[j] == '^')) && expArr[j]!=')')
                        operators.push(expArr[j]);
                    
                    else if(expArr[j] == ')')
                    {
                        while((char)operators.peek() != '(')
                        {
                           post.add(operators.pop());
                        
                        }
                        operators.pop();
                    }
                    else if(precedence(expArr[j])<=precedence((char)operators.peek()))
                    {
                        while(!operators.isEmpty() && precedence((char)operators.peek())>=expArr[j] )
                        {
                            operators.pop();
                        }
                        
                        operators.push(expArr[j]);
                    }
                }
            }
            
            while(!operators.isEmpty())
                post.add(operators.pop());
            //System.out.println("cap = "+exp.length());
            Object[] temp=post.toArray() ;
            for(int a=0 ; a<temp.length ; a++)
            {
                if(!post.elementAt(a).equals('('))
                    System.out.print(temp[a]);
            }
           
        }
    }
    
}
