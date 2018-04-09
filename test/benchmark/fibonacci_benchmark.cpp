#include <benchmark/benchmark.h>
#include <iostream>
#include "include/recursion_dp/fibonacci.h"

static void BM_simple_fib( benchmark::State& state ) {
    int result = 0;
    while ( state.KeepRunning() )
        result |= fib( 5 );
}
// Register the function as a benchmark
BENCHMARK( BM_simple_fib )->Arg( 5 )->Arg( 42 )->Arg( 87 );

BENCHMARK( BM_simple_fib )->Range( 0, 1024 );

// Define another benchmark
static void BM_StringCopy( benchmark::State& state ) {
    std::string x = "hello";
    for ( auto _ : state )
        std::string copy( x );
}
BENCHMARK( BM_StringCopy );

BENCHMARK_MAIN();