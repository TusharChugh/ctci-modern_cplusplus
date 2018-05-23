#pragma once

#include <vector>

namespace algorithm {
    long long int fib_recurssive( int n) {
        if (n <= 1) return n;
        return fib_recurssive(n - 1) + fib_recurssive(n - 2);
    }

    long long int fib_memoize_full(int n, std::vector<long long int>& mem);

    long long int fib_memoize_full( int n) {
        std::vector<long long int> mem(n + 1);
        return fib_memoize_full(n, mem);
    }

    long long int fib_memoize_full(int n, std::vector<long long int>& mem) {
        if(n < 1) return 0;
        if(n == 1) return 1;

        if(mem.at(n) == 0)
            mem.at(n) = fib_memoize_full(n - 1, mem) + fib_memoize_full(n - 2, mem);
        return mem.at(n);
    }



    long long int fib_memoize_iterative(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;

        long long int first = 0;
        long long int second = 1;

        for(int i = 2; i <= n; ++i) {
            auto sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
}

