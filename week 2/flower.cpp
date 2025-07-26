#include<iostream>

int mutliplyByAddition(int a, int b)
{
    int prod = 0;
    for (int i = 0; i < b; i++)
        prod += a;
    
    return prod;
}

int main()
{
    int a = 5, b = 3;
    int result = mutliplyByAddition(a, b);
    return result; // Should return 15
}