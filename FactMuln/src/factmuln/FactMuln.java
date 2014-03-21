/**
 * Problem Statement (Taken from = http://www.spoj.com/problems/FACTMULN/ ):
 * For n positive integer, let F(n) = 1! × 2! × 3! × 4! × ... × n!, product of factorial(i) for i in [1..n].
 * Let G(n) = {i in [1..n], such that n divides F(i)}. 
 * It is obvious that n belongs to G(n) that makes it a non empty set.
 * Input:
 * The first line of input contains an integer T, the number of test cases.
 * On each of the next T lines, your are given an integer n.
 * Output:
 * For each test case, you have to print min(G(n)).
 * Example:
 * Input:
 * 3
 * 4
 * 5
 * 6
 * Output:
 * 3
 * 5
 * 3
 * Explanation:
 * 
 * For test case #1:
 * F(1) = 1! = 1 , not divisible by 4
 * F(2) = 1! × 2! = 2 , not divisible by 4
 * F(3) = 1! × 2! × 3! = 12 , divisible by 4
 * F(4) = 1! × 2! × 3! × 4! = 288 , divisible by 4
 * So G(4) = {3, 4}.
 * Constraints:
 * 0 < T < 10^4
 * 0 < n < 10^8

 */

package factmuln;

import java.util.Scanner;
import java.util.Vector;

/**
 *
 * @author Rohan
 */
class FactMuln 
{
    public static long fact(int n)
    {
        if(n == 1)
            return n;
        
        return n * fact(n-1);
    }
    
    public static long factMult(int a)
    {
        if(a == 1)
            return a;
        
        return fact(a)*factMult(a-1);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        
            int cases ;
       
        Scanner sc = new Scanner(System.in);
        cases = sc.nextInt();
        
        for(int i=0 ; i<cases ; i++)
        {
            int numb = sc.nextInt();
            long[] factMultn = new long[numb+1];
            Vector min = new Vector();
            factMultn[1] = factMult(1);
            for(int j=2 ; j<=numb ; j++)
            {
                factMultn[j] = fact(j)*factMultn[j-1];
                
                if(factMultn[j]%numb == 0)
                {
                    System.out.println(j);
                    break;
                }
            }
              
        }
    }
    
}
