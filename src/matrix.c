#include <stdio.h>
#include <stdlib.h>

void input(int *, int *, int *);
void menu(void);
void crSt(int, int, int);
void crBu(int, int, int);
void crAr(int, int, int);
void crSe(int, int, int);
/* void prData(int *, int, int, int); */

int main(void) {
    int n, j, k;
    menu();
    input(&n, &j, &k);
}

void menu(void) {
    printf("Enter the mode to use:\n");
    printf("1. Static (arr[n])\n");
    printf("2. Dynamic (pointers to array segments within one buffer)\n");
    printf("3. Dynamic (pointers to arrays)\n");
    printf("4. Dynamic (pointers to segments of the second array)\n");
}
    
void input(int *n , int *j, int *k) {
    int trash = 0;

    if (scanf("%d.%d", n, &trash) != 1) {
        printf("n/a");
    } else {
        if (scanf("%d %d.%d", j, k, &trash) != 2) {
            printf("n/a");
        } else {
            switch (*n) {
                case (1) :
                    crSt(*n, *j, *k);
                    break;
                case (2) :
                    crBu(*n, *j, *k);
                    break;
                case (3) :
                    crAr(*n, *j, *k);
                    break;
                case (4) :
                    crSe(*n, *j, *k);
                    break;
            }
        }
    }
}

void crSt(int n, int j, int k) {
    int data[j*k];
    for i
}
