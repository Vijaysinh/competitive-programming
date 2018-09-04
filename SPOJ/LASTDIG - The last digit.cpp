/*LASTDIG - The last digit
#number-theory #ad-hoc-1

Nestor was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives him two numbers a and b. The problem consist of finding the last digit of the potency of base a and index b. Help Nestor with his problem. You are given two integer numbers: the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the last digit of ab.
Input

The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For each test case will appear a and b separated by space.
Output

For each test case output an integer per line representing the result.
Example

Input:
2
3 10
6 2

Output:
9
6

*/


#include <cstdint>
#include <iostream>

std::int64_t modular_pow(std::int64_t base, std::int64_t exp, std::int64_t mod)
{
    std::int64_t res = 1;
    
    while(exp)
    {
        if(exp % 2)
            res = (res*base) % mod;
        
        exp >>= 1;
        base = (base*base) % mod;
    }
    
    return res;
}

int main()
{
    int tests;
    std::cin >> tests;
    
    while (tests--)
    {
        int a, b;
        std::cin >> a >> b;
        
        std::cout << modular_pow(a, b, 10) << std::endl;
    }
    
    return 0;
}
