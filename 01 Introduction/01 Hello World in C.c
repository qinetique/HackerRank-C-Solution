#include <stdio.h>

/*
 * Author: Tonmoy M
 * URL: https://github.com/qinetique
 * */

int main(){
    char s[100];
    scanf("%[^\n]%*c", &s);

    printf("Hello, World!\n");
    printf("%s", s);

    return 0;
}