#include <stdio.h>
#include <stdlib.h>
#define MAXST 100

void input();
void menu(void);
void crSt(int, int);
void crBu(int, int);
void crAr(int, int);
void crSe(int, int);
void maxJ(int **, int, int);
void minK(int j, int k, int data[][k]);
void maxC(int j, int k, int data[][k]);

int main(void) {
    menu();
    input();
}

void menu(void) {
    printf("Enter the mode to use:\n");
    printf("1. Static (arr[n])\n");
    printf("2. Dynamic (pointers to array segments within one buffer)\n");
    printf("3. Dynamic (pointers to arrays)\n");
    printf("4. Dynamic (pointers to segments of the second array)\n");
}

void input() {
    int n, j, k;
    int trash = 0;

    if (scanf("%d.%d", &n, &trash) != 1 || n <= 0 || n > 4) {
        printf("n/a");
    } else {
        if (scanf("%d %d.%d", &j, &k, &trash) != 2 || (j <= 0 || k <= 0) ||
            (n == 1 && (j > MAXST || k > MAXST))) {
            printf("n/a");
        } else {
            switch (n) {
                case (1):
                    crSt(j, k);
                    break;
                case (2):
                    crBu(j, k);
                    break;
                case (3):
                    crAr(j, k);
                    break;
                case (4):
                    crSe(j, k);
                    break;
            }
        }
    }
}

void crSt(int j, int k) {
    int data[j][k];
    int flag = 0, trash = 0;
    for (int tj = 0; tj < j && flag == 0; tj++) {
        for (int tk = 0; tk < k && flag == 0; tk++) {
            if (scanf("%d.%d", (*(data + tj) + tk), &trash) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int tj = 0; tj < j; tj++) {
            for (int tk = 0; tk < k; tk++) {
                printf("%d", *(*(data + tj) + tk));
                if (tk != k - 1) {
                    printf(" ");
                }
                if (tk == k - 1 && tj != j - 1) {
                    printf("\n");
                }
            }
        }
    } else {
        printf("n/a");
    }
    maxC(j, k, data);
    minK(j, k, data);
}

void crBu(int j, int k) {
    int **mx = (int **)malloc(j * k * sizeof(int) + j * sizeof(int *));
    int *ptr = (int *)(mx + j);
    int trash = 0;
    int flag = 0;

    for (int tj = 0; tj < j; tj++) {
        *(mx + tj) = ptr + k * tj;
    }
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (scanf("%d.%d", (*(mx + tj) + tk), &trash) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int tj = 0; tj < j; tj++) {
            for (int tk = 0; tk < k; tk++) {
                printf("%d", *(*(mx + tj) + tk));
                if (tk != k - 1) {
                    printf(" ");
                }
                if (tk == k - 1 && tj != j - 1) {
                    printf("\n");
                }
            }
        }
    } else {
        printf("n/a");
    }
    free(mx);
}

void crAr(int j, int k) {
    int flag = 0, trash = 0;
    int **data = (int **)malloc(j * sizeof(int *));

    for (int tj = 0; tj < j; tj++) {
        *(data + tj) = (int *)malloc(k * sizeof(int));
    }

    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (scanf("%d.%d", (*(data + tj) + tk), &trash) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int tj = 0; tj < j; tj++) {
            for (int tk = 0; tk < k; tk++) {
                printf("%d", *(*(data + tj) + tk));
                if (tk != k - 1) {
                    printf(" ");
                }
                if (tk == k - 1 && tj != j - 1) {
                    printf("\n");
                }
            }
        }
    } else {
        printf("n/a");
    }

    for (int tj = 0; tj < j; tj++) {
        free(*(data + tj));
    }
    free(data);
}

void crSe(int j, int k) {
    int **pArr = (int **)malloc(j * sizeof(int *));
    int *mx = (int *)malloc(j * k * sizeof(int));
    int flag = 0, trash = 0;

    for (int pj = 0; pj < j; pj++) {
        *(pArr + pj) = mx + k * pj;
    }

    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (scanf("%d.%d", (*(pArr + tj) + tk), &trash) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int tj = 0; tj < j; tj++) {
            for (int tk = 0; tk < k; tk++) {
                printf("%d", *(*(pArr + tj) + tk));
                if (tk != k - 1) {
                    printf(" ");
                }
                if (tk == k - 1 && tj != j - 1) {
                    printf("\n");
                }
            }
        }
    } else {
        printf("n/a");
    }

    free(mx);
    free(pArr);
}

void minK(int j, int k, int data[][k]) {
    int temp = data[0][0];
    for (int tk = 0; tk < k; tk++) {
        for (int tj = 0; tj < j; tj++) {
            if (data[tj][tk] < temp) {
                temp = data[tj][tk];
            }
        }
        printf("\n%d\n", temp);
        temp = data[0][0];
    }
}

void maxC(int j, int k, int data[][k]) {
    int temp = data[0][0];
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (data[tj][tk] > temp) {
                temp = data[tj][tk];
            }
        }
        printf("\n%d\n", temp);
        temp = data[0][0];
    }
}
