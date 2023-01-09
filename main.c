#include <stdio.h>
#include <stdlib.h>

int factorial(int);
double power(double, int);
void array_sort(int*, int);
void array_display(int*, int);

int main() {
    double a, sum=0;
    int N;
    do {
        printf("Enter N\n");
        scanf("%d", &N);
        printf("Enter a\n");
        scanf("%lf", &a);
    } while(N<0);
    for(int n=0; n<=N; n++)
        sum += power (-1, n) * power (a, n) / factorial (n);
    do {
        printf("Enter N\n");
        scanf("%d", &N);
    } while(N<=1);
    int A[N];
    for (int i=0; i<N; i++)
        A[i] = 1 + rand()%(N-1);
    array_display(&A[0], N);
    array_sort(&A[0], N);
    array_display(&A[0], N);
    printf("\nSum = %lf\n", sum);
    return 0;
}

int factorial(int N) {
    int value = 1;
    for(int i = 2; i <= N; i++)
        value *= i;
    return value;
}

double power(double a, int N) {
    double value=1;
    if(N==0)
        return 1;
    for(int i=0; i<=N; i++)
        value*=a;
    if(N%2==0 && N>=2 && a<0 || N==1 && a<0)
        value = -value;
    return value;
}

void array_display(int* A, int N) {
    printf("\n");
    for (int i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void array_sort(int* A, int N) {
    for (int i=0; i<N; i++)
        for (int j=1, temp; j<N; j++)
            if (A[j]>A[j-1])
                temp = A[j-1], A[j-1] = A[j], A[j] = temp;

}
