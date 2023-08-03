/* *
 * Author: Tonmoy M
 * URL: https://qinetique.github.io
 * */

#include <stdio.h>

int max_of_four(int a, int b, int c, int d){
    int solution;
    a = a > b ? a : b;
    c = c > d ? c : d;
    solution = a > c ? a : c;
    return solution;
}

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int solution  = max_of_four(a, b, c, d);
    printf("%d", solution);

    return 0;
}