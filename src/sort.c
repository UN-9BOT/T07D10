#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

void nsort(int *, int, int);
void input(int *, int *, int *);
void output(int *, int *);

int main(void) {
    int flag;
    int n;
    int *data;
    data = (int *)malloc(sizeof(int) * NMAX);

    flag = n = 0;
    input(data, &flag, &n);
    if (flag == 1) {
        printf("n/a");
    } else {
        nsort(data, 0, n - 1);
        output(data, &n);
    }
    free(data);
    return (0);
}

void input(int *data, int *flag, int *n) {
    int k;
    if (scanf("%d.%d", n, &k) != 1 || *n > NMAX || *n <= 0) {
        *flag = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d.%d", (data + i), &k) != 1) {
                *flag = 1;
            }
        }
    }
}

void nsort(int *data, int low, int high) {
    int i = low;   // left
    int j = high;  // right;
    int y = 0;
    int z = *(data + (low + high) / 2);

    while (i <= j) {
        while (*(data + i) < z) {
            i++;
        }
        while (*(data + j) > z) {
            j--;
        }
        if (i <= j) {
            y = *(data + i);
            *(data + i) = *(data + j);
            *(data + j) = y;
            i++;
            j--;
        }
    }

    if (low < j) {
        nsort(data, low, j);
    }
    if (i < high) {
        nsort(data, i, high);
    }
}

void output(int *data, int *n) {
    for (int i = 0; i < *n - 1; i++) {
        printf("%d ", *(data + i));
    }
    printf("%d", *(data + *n - 1));
}
