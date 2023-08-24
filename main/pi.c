#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    long long n, k;
    int thread_count;
    double factor;
    double sum = 0.0;

    thread_count = strtol(argv[1], NULL, 10);
    n = strtoll(argv[2], NULL, 10);

    #pragma omp parallel for num_threads(thread_count) reduction(+: sum)
    for (k = 0; k < n; k++) {
        factor = (k % 2 == 0) ? 1.0 : -1.0;  // Calculate factor based on value of k
        sum += factor / (2*k+1);
    }

    sum = 4.0*sum;
    printf("With n = %lld terms and %d threads,\n", n, thread_count);
    printf("   Our estimate of pi = %.14f\n", sum);
    printf("                   PI = %.14f\n", 4.0*atan(1.0));

    return 0;
}
