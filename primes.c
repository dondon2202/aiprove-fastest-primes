/* Fastest correct prime counter: read N on stdin, print pi(N).
 * Odd-only byte sieve, O2-friendly. N up to 5,000,000. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    long n;
    if (scanf("%ld", &n) != 1) return 1;
    if (n < 2) { printf("0\n"); return 0; }
    /* sieve over odd numbers only: index i represents 2*i+3 */
    long m = (n - 1) / 2; /* count of odds in [3, n] */
    unsigned char *is_comp = (unsigned char *)calloc((size_t)m, 1);
    if (!is_comp) return 1;
    long sq = (long)sqrt((double)n);
    for (long i = 0; 2 * i + 3 <= sq; i++) {
        if (!is_comp[i]) {
            long p = 2 * i + 3;
            long start = (p * p - 3) / 2;
            for (long j = start; j < m; j += p) is_comp[j] = 1;
        }
    }
    long count = 1; /* prime 2 */
    for (long i = 0; i < m; i++) if (!is_comp[i]) count++;
    printf("%ld\n", count);
    free(is_comp);
    return 0;
}
