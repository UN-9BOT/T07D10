#include <stdio.h>
#include <stdlib.h>
#define MAXST 100

void input(int *, int *, int *, int *);
void crSt(int, int);
void crBu(int, int);
void crAr(int, int);
void crSe(int, int);
void inMX(int, int, int **data, int *);
void inMXst(int, int k, int data[][k], int *);
void prMX(int, int, int **data, int *);
void prMXst(int, int k, int data[][k], int *);
void minKst(int j, int k, int data[][k]);
void minK(int j, int k, int **data);
void maxCst(int j, int k, int data[][k]);
void maxC(int j, int k, int **data);

int main(void) {
    int n, j, k;
    int flag = 0;

    input(&n, &j, &k, &flag);
    if (flag == 0) {
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

void input(int *n, int *j, int *k, int *flag) {
    int trash = 0;

    printf("Enter the mode to use:\n");
    printf("1. Static (arr[n])\n");
    printf("2. Dynamic (pointers to array segments within one buffer)\n");
    printf("3. Dynamic (pointers to arrays)\n");
    printf("4. Dynamic (pointers to segments of the second array)\n");

    if (scanf("%d.%d", n, &trash) != 1 || *n <= 0 || *n > 4) {
        printf("n/a");
        *flag = 1;
    } else {
        if (scanf("%d %d.%d", j, k, &trash) != 2 || (*j <= 0 || *k <= 0) ||
            (*n == 1 && (*j > MAXST || *k > MAXST))) {
            printf("n/a");
            *flag = 1;
        }
    }
}

void crSt(int j, int k) {
    int data[MAXST][MAXST];
    int flag = 0;
    inMXst(j, k, data, &flag);
    prMXst(j, k, data, &flag);
    maxCst(j, k, data);
    minKst(j, k, data);
}

void crBu(int j, int k) {
    int **data = (int **)malloc(j * k * sizeof(int) + j * sizeof(int *));
    int *ptr = (int *)(data + j);
    int flag = 0;

    for (int tj = 0; tj < j; tj++) {
        *(data + tj) = ptr + k * tj;
    }
    inMX(j, k, data, &flag);
    prMX(j, k, data, &flag);
    maxC(j, k, data);
    minK(j, k, data);

    free(data);
}

void crAr(int j, int k) {
    int flag = 0;
    int **data = (int **)malloc(j * sizeof(int *));

    for (int tj = 0; tj < j; tj++) {
        *(data + tj) = (int *)malloc(k * sizeof(int));
    }

    inMX(j, k, data, &flag);
    prMX(j, k, data, &flag);

    maxC(j, k, data);
    minK(j, k, data);
    for (int tj = 0; tj < j; tj++) {
        free(*(data + tj));
    }
    free(data);
}

void crSe(int j, int k) {
    int **data = (int **)malloc(j * sizeof(int *));
    int *mx = (int *)malloc(j * k * sizeof(int));
    int flag = 0;

    for (int pj = 0; pj < j; pj++) {
        *(data + pj) = mx + k * pj;
    }

    inMX(j, k, data, &flag);
    prMX(j, k, data, &flag);

    maxC(j, k, data);
    minK(j, k, data);
    free(mx);
    free(data);
}

void inMX(int j, int k, int **data, int *flag) {
    int trash = 0;
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (scanf("%d.%d", (*(data + tj) + tk), &trash) != 1) {
                *flag = 1;
            }
        }
    }
}

void prMX(int j, int k, int **data, int *flag) {
    if (*flag == 0) {
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
}
void inMXst(int j, int k, int data[][k], int *flag) {
    int trash = 0;
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (scanf("%d.%d", (*(data + tj) + tk), &trash) != 1) {
                *flag = 1;
            }
        }
    }
}

void prMXst(int j, int k, int data[][k], int *flag) {
    if (*flag == 0) {
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
}

void minKst(int j, int k, int data[][k]) {
    int temp = data[0][0];
    int arr[k];
    int counter = 0;
    for (int tk = 0; tk < k; tk++) {
        for (int tj = 0; tj < j; tj++) {
            if (data[tj][tk] < temp) {
                temp = data[tj][tk];
            }
        }
        arr[counter++] = temp;
        temp = data[0][0];
    }
    for (int i = 0; i < counter - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[counter - 1]);
}

void maxCst(int j, int k, int data[][k]) {
    int temp = data[0][0];
    int arr[k];
    int counter = 0;
    printf("\n");
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (data[tj][tk] > temp) {
                temp = data[tj][tk];
            }
        }
        arr[counter++] = temp;
        temp = data[0][0];
    }
    for (int i = 0; i < counter - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[counter - 1]);
}

void minK(int j, int k, int **data) {
    int temp = data[0][0];
    int arr[k];
    int counter = 0;
    for (int tk = 0; tk < k; tk++) {
        for (int tj = 0; tj < j; tj++) {
            if (data[tj][tk] < temp) {
                temp = data[tj][tk];
            }
        }
        arr[counter++] = temp;
        temp = data[0][0];
    }
    for (int i = 0; i < counter - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[counter - 1]);
}

void maxC(int j, int k, int **data) {
    int temp = data[0][0];
    int arr[k];
    int counter = 0;
    printf("\n");
    for (int tj = 0; tj < j; tj++) {
        for (int tk = 0; tk < k; tk++) {
            if (data[tj][tk] > temp) {
                temp = data[tj][tk];
            }
        }
        arr[counter++] = temp;
        temp = data[0][0];
    }
    for (int i = 0; i < counter - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[counter - 1]);
}
