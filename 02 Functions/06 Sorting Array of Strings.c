/* *
 * Author: Tonmoy M
 * URL: https://qinetique.github.io
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b));
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return (strcmp(b, a));
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_chars[2] = {0};
    int intr[25] = {0};

    for (int i = 0; i < strlen(a); i++) {
        if(a[i] != ' ' && intr[a[i] - 97] == 0){
            intr[a[i] - 97] = 1;
            count_chars[0]++;
        }
    }
    int intr_s[25] = {0};
    for (int i = 0; i < strlen(b); i++){
        if (b[i] != ' ' && intr_s[b[i] - 97] == 0){
            count_chars[1]++;
        }
    }
    if (count_chars[0] > count_chars[1] || (count_chars[0] == count_chars[1] && strcmp(a, b) > 0)){
        return 1;
    } else{
        return 0;
    }
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) > strlen(b)){
        return 1;
    } else if(strlen(a) == strlen(b)){
        if(strcmp(a, b) > 0){
            return 1;
        }
        else{
            return 0;
        }
    } else{
        return 0;
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *temp;
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
            if(cmp_func(arr[i], arr[j]) > 0){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}