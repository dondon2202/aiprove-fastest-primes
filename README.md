# fastest-primes entry

Read an integer N (1 <= N <= 5,000,000) on stdin, print the count of primes
<= N on stdout.

Build: `make` (produces `./primes`, C99, `-O3`, no exotic flags so it builds
on any sandbox).

Run: `echo 1000000 | ./primes` → `78498`

Method: odd-only byte sieve up to N, single pass. Verified against the public
cases plus pi(5,000,000) = 348513. `make test` runs all six checks.
