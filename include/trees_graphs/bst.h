/**
 * @brief Simple templatized bst implementation
 * TODO: const_pointer, destructor
 * References
 * 1. Leak-Freedum in C++... By default - HERB SUTTER
 * 2. LLVM STL set implementation
 * @file bst.h
 * @author Tushar Chugh
 */

#pragma once

#include <memory>

#include <iostream>

namespace algorithm {
template <typename T> class bst_node {
public:
    using value_type       = T;
    using node_pointer     = typename std::unique_ptr<bst_node>;
    using node_raw_pointer = bst_node*;
    using const_reference  = const T&;

    explicit bst_node( const value_type& value = value_type{} )
        : value_{value}, left_{nullptr}, right_{nullptr}, parent_{nullptr} {}

    explicit bst_node( const value_type& value, node_raw_pointer parent )
        : value_{value}, left_{nullptr}, right_{nullptr}, parent_{parent} {}

    ~bst_node() = default;

    value_type value_;
    node_pointer left_;
    node_pointer right_;
    node_raw_pointer parent_;
};

template <typename bst_node_t>
class bst_iterator : public std::iterator<const std::bidirectional_iterator_tag, bst_node_t*> {
private:
    using node_pointer = typename bst_node_t::node_raw_pointer;

    node_pointer tree_min( node_pointer x ) noexcept {
        while ( x->left_ != nullptr ) {
            x = ( x->left_ ).get();
        }
        return x;
    }

    node_pointer tree_max( node_pointer x ) noexcept {
        while ( x->right_ != nullptr ) {
            x = ( x->right_ ).get();
        }
        return x;
    }

    bool is_left_child( node_pointer x ) noexcept {
        return ( x == ( ( x->parent_ )->left_ ).get() );
    }

    node_pointer tree_next( node_pointer x ) noexcept {
        if ( ( x->right_ ) != nullptr ) return tree_min( ( x->right_ ).get() );
        while ( !is_left_child( x ) )
            x = ( x->parent_ );
        return ( x->parent_ );
    }

public:
    using value_type        = typename bst_node_t::value_type;
    using iterator_category = const std::bidirectional_iterator_tag;
    using const_reference   = typename bst_node_t::const_reference;

    template <typename value_type> friend class bst;

    const_reference operator*() const {
        return pointee_->value_;
    }

    bst_iterator& operator++() {
        pointee_ = tree_next( pointee_ );
        return *this;
    }

    bst_iterator operator++( int ) {
        auto temp = *this;
        ++( *this );
        return temp;
    }

    bool operator!=( const bst_iterator& rhs ) {
        return pointee_ != rhs.pointee_;
    }

    ~bst_iterator() = default;

private:
    node_pointer pointee_;

    explicit bst_iterator( const node_pointer& pointee = nullptr ) : pointee_( pointee ) {}
};

template <typename Key> class bst {
public:
    using value_type      = Key;
    using pointer         = typename std::unique_ptr<Key>;
    using const_pointer   = const std::unique_ptr<Key>;
    using reference       = Key&;
    using const_reference = const Key&;
    using size_type       = std::size_t;
    using node_type       = bst_node<Key>;
    using const_node_type = const bst_node<Key>;
    using node_pointer    = typename node_type::node_pointer;
    using iterator        = bst_iterator<node_type>;
    using const_iterator  = bst_iterator<const_node_type>;
    // using node_const_pointer = typename const node_pointer;

private:
    using node_raw_pointer = typename node_type::node_raw_pointer;

public:
    bst() : root_{std::make_unique<node_type>( value_type{} )}, end_( root_.get() ), size_{0} {}

    bool insert( const value_type& value ) {
        return insert_iterative( value );
    }

    bool insert( value_type&& value ) {
        return insert_iterative( std::forward<value_type>( value ) );
    }

    const_reference find( const_reference key );

    size_type erase( const_reference key );

    size_type size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    iterator begin() noexcept {
        return make_iterator( tree_min( root_.get() ) );
    }

    iterator end() noexcept {
        return make_iterator( end_ );
    }

    ~bst() = default;

private:
    node_pointer root_;
    node_raw_pointer end_;
    size_type size_;

    iterator make_iterator( node_raw_pointer input ) noexcept {
        return bst_iterator<node_type>( input );
    }

    const_iterator make_iterator( const node_raw_pointer input ) const noexcept {
        return bst_iterator<node_type>( input );
    }

    bool insert_iterative( const value_type& value ) {
        if ( root_ == nullptr ) {
            root_ = std::make_unique<node_type>( value );
            ++size_;
            return true;
        }

        auto current_node = root_.get();
        auto parent       = current_node;

        while ( current_node != nullptr ) {
            parent = current_node;
            if ( value < current_node->value_ )
                current_node = ( current_node->left_ ).get();
            else if ( value > current_node->value_ )
                current_node = ( current_node->right_ ).get();
            else
                return false;
        }

        if ( value < parent->value_ )
            current_node->left_ = std::make_unique<node_type>( value );
        else
            current_node->right_ = std::make_unique<node_type>( value );
        return true;
    }

    bool insert_iterative( value_type&& value ) {
        auto current_node = root_.get();
        if ( current_node == end_ ) {
            auto new_root    = std::make_unique<node_type>( std::forward<value_type>( value ) );
            new_root->right_ = std::move( root_ );
            root_            = std::move( new_root );
            ++size_;
            return true;
        }

        auto parent = current_node;

        while ( current_node != nullptr && current_node != end_ ) {
            parent = current_node;
            if ( value < current_node->value_ )
                current_node = ( current_node->left_ ).get();
            else if ( value > current_node->value_ )
                current_node = ( current_node->right_ ).get();
            else
                return false;
        }

        if ( value < parent->value_ ) {
            parent->left_ =
                std::make_unique<node_type>( std::forward<value_type>( value ), parent );
        }

        else {
            if ( current_node == end_ ) {
                auto new_node =
                    std::make_unique<node_type>( std::forward<value_type>( value ), parent );
                new_node->right_ = std::move( parent->right_ );
                parent->right_   = std::move( new_node );
                end_             = ( ( parent->right_ )->right_ ).get();
            }

            else {
                parent->right_ =
                    std::make_unique<node_type>( std::forward<value_type>( value ), parent );
            }
        }

        ++size_;
        return true;
    }

    node_raw_pointer tree_min( node_raw_pointer x ) noexcept {
        while ( x->left_ != nullptr ) {
            x = ( x->left_ ).get();
        }
        return x;
    }

    node_raw_pointer tree_max( node_raw_pointer x ) noexcept {
        while ( x->right_ != nullptr ) {
            x = ( x->right_ ).get();
        }
        return x;
    }

    // void release_subtree( node_pointer n ) {
    //     while ( n->left_ || n->right_ ) {
    //         auto left =
    //     }
    // }
};
} // namespace algorithm