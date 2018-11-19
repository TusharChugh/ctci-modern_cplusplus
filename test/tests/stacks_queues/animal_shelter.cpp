#include <stacks_queues/animal_shelter.h>
#include <gtest/gtest.h>

TEST( ANIMAL_SHELTER, POP_ORDER_BASED ) {
    algorithm::animal_queue input_queue;
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 1" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 1" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 2" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 3" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 2" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 3" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 4" ) );

    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 1" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 1" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 2" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 3" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 2" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 3" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 4" );
}

TEST( ANIMAL_SHELTER, POP_DOGS_FIRST_THEN_CATS ) {
    algorithm::animal_queue input_queue;
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 1" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 1" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 2" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 3" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 2" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 3" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 4" ) );

    ASSERT_EQ( input_queue.pop_dog()->name(), "DOG 1" );
    ASSERT_EQ( input_queue.pop_dog()->name(), "DOG 2" );
    ASSERT_EQ( input_queue.pop_dog()->name(), "DOG 3" );
    ASSERT_EQ( input_queue.pop_dog()->name(), "DOG 4" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 1" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 2" );
    ASSERT_EQ( input_queue.pop_any()->name(), "CAT 3" );
}

TEST( ANIMAL_SHELTER, POP_CATS_FIRST_THEN_DOGS ) {
    algorithm::animal_queue input_queue;
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 1" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 1" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 2" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 3" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 2" ) );
    input_queue.push( std::make_unique<algorithm::cat>( "CAT 3" ) );
    input_queue.push( std::make_unique<algorithm::dog>( "DOG 4" ) );

    ASSERT_EQ( input_queue.pop_cat()->name(), "CAT 1" );
    ASSERT_EQ( input_queue.pop_cat()->name(), "CAT 2" );
    ASSERT_EQ( input_queue.pop_cat()->name(), "CAT 3" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 1" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 2" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 3" );
    ASSERT_EQ( input_queue.pop_any()->name(), "DOG 4" );
}
