#pragma once
#include <iostream>

int fib( int n ) {
    // std::cout << "called with N = " << n << std::endl;
    if ( n <= 1 ) return n;
    return fib( n - 1 ) + fib( n - 2 );
}
