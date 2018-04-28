#pragma once

#include <deque>

namespace algorithm {
template<typename T, typename Container = std::deque<T>> class stack {
public:
    using container_type  = Container;
    using value_type      = typename Container::value_type;
    using size_type       = typename Container::size_type;
    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;

    // Constructors
    explicit stack( const Container& cont ) : container( cont ) {}

    explicit stack( Container&& cont = Container() ) : container( std::move( cont ) ) {}

    stack( const stack& other ) : container( other.container ) {}

    stack( stack&& other ) : container( std::move( other.container ) ) {}

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
        return container.push_back( value );
    }

    inline void push( value_type&& value ) {
        container.push_back( std::move( value ) );
    }

    inline void pop() {
        container.pop_back();
    }

    void swap( stack& other ) noexcept {
        using std::swap;
        swap( container, other.container );
    }

protected:
    Container container;
};

template<class T, class Container>
bool operator==( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container == rhs.container;
}

template<class T, class Container>
bool operator!=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container != rhs.container;
}

template<class T, class Container>
bool operator<( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container < rhs.container;
}

template<class T, class Container>
bool operator<=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container <= rhs.container;
}

template<class T, class Container>
bool operator>( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container > rhs.container;
}

template<class T, class Container>
bool operator>=( const stack<T, Container>& lhs, const stack<T, Container>& rhs ) {
    return lhs.container >= rhs.container;
}

template<class T, class Container>
void swap( stack<T, Container>& lhs, stack<T, Container>& rhs ) noexcept {
    lhs.swap( rhs );
}
} // namespace algorithm