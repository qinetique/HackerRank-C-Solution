/* *
 * Author: Tonmoy M
 * URL: https://qinetique.github.io
 * */

#include <stdio.h>

int main(){
    char s[100];
    scanf("%[^\n]%*c", &s);

    printf("Hello, World!\n");
    printf("%s", s);

    return 0;
}