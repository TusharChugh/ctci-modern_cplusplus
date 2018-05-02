/**
 * @brief Animal Shelter
 * An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out"
 * basis. People must adopt either the "oldest" (based on arrival time) of all animals at the
 * shelter, or they can select whether they would prefer a dog or a  cat (and will receive the
 * oldest animal of that type). They cannot select which specific animal they would like. Create the
 * data structures to maintain  this system and implement operations such as enqueue, dequeueAny,
 * dequeueDog, and dequeueCat. You may use the built-in LinkedList data structure.
 *
 * @file animal_shelter.h
 * @author Tushar Chugh
 */
#pragma once

#include <memory>
#include <queue>
#include <string>

namespace algorithm {
class animal {
public:
    animal()          = default;
    virtual ~animal() = default;

    void set_order( size_t order ) noexcept {
        order_ = order;
    }

    inline size_t get_order() const noexcept {
        return order_;
    }

    bool operator<( const animal& other ) {
        return order_ < other.order_;
    }

    std::string name() {
        return name_;
    }

protected:
    std::string name_;

    animal( const std::string& name ) : name_( name ), order_( 0 ) {}

    animal( std::string&& name ) : name_( std::move( name ) ), order_( 0 ) {}

private:
    size_t order_;
};

class dog : public animal {
public:
    dog( const std::string& name ) : animal( name ) {}
    dog( std::string&& name ) : animal( std::move( name ) ) {}
    ~dog() = default;
};

class cat : public animal {
public:
    cat( const std::string& name ) : animal( name ) {}
    cat( std::string&& name ) : animal( std::move( name ) ) {}
    ~cat() = default;
};

class animal_queue {
public:
    animal_queue()  = default;
    ~animal_queue() = default;

    void push( std::unique_ptr<animal> input_animal ) {
        auto input_animal_ptr = input_animal.get();
        input_animal->set_order( order_++ );
        if ( auto input_dog = dynamic_cast<dog*>( input_animal_ptr ) )
            dogs_.push( std::unique_ptr<dog>( std::move( input_dog ) ) );
        else if ( auto input_cat = dynamic_cast<cat*>( input_animal_ptr ) )
            cats_.push( std::unique_ptr<cat>( std::move( input_cat ) ) );
        else {
            input_animal.release();
            std::__throw_invalid_argument( "Only dogs and cats are accepted in the animal_queue" );
        }
        input_animal.release();
    }

    // void push( std::unique_ptr<animal>&& input_animal ) {
    //     auto input_animal_local = std::move( input_animal );
    //     auto input_animal_ptr   = input_animal_local.get();
    //     input_animal->set_order( order_++ );
    //     if ( auto input_dog = dynamic_cast<dog*>( input_animal_ptr ) )
    //         dogs_.push( std::unique_ptr<dog>( std::move( input_dog ) ) );
    //     else if ( auto input_cat = dynamic_cast<cat*>( input_animal_ptr ) )
    //         cats_.push( std::unique_ptr<cat>( std::move( input_cat ) ) );
    //     else {
    //         input_animal.release();
    //         std::__throw_invalid_argument( "Only dogs and cats are accepted in the animal_queue"
    //         );
    //     }
    //     input_animal.release();
    // }

    std::unique_ptr<animal> pop_any() {
        if ( dogs_.empty() ) return pop_cat();
        if ( cats_.empty() ) return pop_dog();
        if ( *dogs_.front() < *cats_.front() ) return pop_dog();
        return pop_cat();
    }

    std::unique_ptr<dog> pop_dog() {
        auto temp = std::move( dogs_.front() );
        dogs_.pop();
        return temp;
    }

    std::unique_ptr<cat> pop_cat() {
        auto temp = std::move( cats_.front() );
        cats_.pop();
        return temp;
    }

    bool empty() {
        return dogs_.empty() + cats_.empty();
    }

    size_t size() {
        return dogs_.size() + cats_.size();
    }

private:
    std::queue<std::unique_ptr<dog>> dogs_;
    std::queue<std::unique_ptr<cat>> cats_;
    size_t order_ = 0;
};

} // namespace algorithm
