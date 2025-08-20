#include <stdio.h>
#include <stdlib.h>

int a(int n) {
    if (n == 1) {
        return 2;
    } else {
        return a(n - 1) + 3;
    }
}

int main(){
    int result = a(5);
    printf("Result: %d\n", result);
    return 0;
}
