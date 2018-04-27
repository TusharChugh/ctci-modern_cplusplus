#pragma once

#include <deque>

namespace algorithm {
    template<
            typename T,
            typename Container = std::deque<T>
    > class stack {
    public:
        using container_type = Container;
        using value_type = typename Container::value_type;
        using size_type = typename Container::size_type;
        using reference = typename Container::reference;
        using const_reference = typename Container::const_reference;

        //Constructors
        explicit stack( const Container& cont ) : container(cont) {}

        explicit stack( Container&& cont = Container() ) : container(cont) { }

        stack( const stack& other );

        stack( stack&& other ) {

        }

        /**
         * Destructs the container adaptor.
         * The destructors of the elements are called and the used storage is deallocated.
         * Note, that if the elements are pointers, the pointed-to objects are not destroyed.
         */
        ~stack() = default;

        inline reference top() {
            return container.back();
        }

        inline const_reference top() const {
            return container.back();
        }

        inline bool empty() const {
            return container.empty();
        }

        inline size_type size() const {
            return container.size();
        }

        inline void push( const value_type& value ) {
            return container.push_back(value);
        }

        inline void push( value_type&& value ) {
            return container.push_back(std::move(value));
        }

        inline void pop() {
            return container.pop_back();
        }

    protected:
        Container container;

    };
}