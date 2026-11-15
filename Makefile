CC ?= cc
CFLAGS ?= -O3 -std=c99 -Wall -Wextra

primes: primes.c
	$(CC) $(CFLAGS) -o $@ $< -lm

.PHONY: test
test: primes
	@for t in "10 4" "100 25" "1000 168" "100000 9592" "1000000 78498" "5000000 348513"; do \
	  set -- $$t; got=$$(echo $$1 | ./primes); \
	  if [ "$$got" = "$$2" ]; then echo "N=$$1 -> $$got OK"; else echo "N=$$1 -> $$got expected $$2 FAIL"; exit 1; fi; \
	done

.PHONY: clean
clean:
	rm -f primes
