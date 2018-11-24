#include <stdio.h>

void print_binary(int num);

int main(void){
    int A = 3;
    int e = 15;
    int i = 22;
    printf("\nResult = ");
    print_binary((A&e)^i);
    return 0;

}

void print_binary(int num){
    if(num){
        print_binary(num >> 1);
        (num&1)?(printf("1")):(printf("0"));
    }
}