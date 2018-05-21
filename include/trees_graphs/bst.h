/**
 * @brief Simple templatized bst implementation
 * Happiness is a tree with a unique pointer
 * TODO: -- operator, erase, emplace
 * References
 * 1. Leak-Freedom in C++... By default - HERB SUTTER
 * 2. LLVM STL set implementation
 * 3. Only implemented const_iterator with iterator alias (this choice limits the use of std::copy
 * for initializer_list and copy constructor)
 * we can use pointer as the template argument in order to support iterator and const_iterator
 * 4. Default destructor would take H (height of tree) space on the stack. This is not a effective
 * way, use the suggestion from Herb Sutter's cppconn talk
 * @file bst.h
 * @author Tushar Chugh
 */

#pragma once

#include <memory>

namespace algorithm {

/**
 * @brief bst node used by binary search tree (bst)
 *
 * @tparam T typename of type T
 */
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

/**
 * @brief iterator for the bst
 *
 * @tparam bst_node_t node of type bst
 */
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

    node_pointer successor( node_pointer x ) noexcept {
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
        pointee_ = successor( pointee_ );
        return *this;
    }

    bst_iterator operator++( int ) {
        auto temp = *this;
        ++( *this );
        return temp;
    }

    friend bool operator!=( const bst_iterator& lhs, const bst_iterator& rhs ) {
        return lhs.pointee_ != rhs.pointee_;
    }

    friend bool operator==( const bst_iterator& lhs, const bst_iterator& rhs ) {
        return !( lhs != rhs );
    }

    ~bst_iterator() = default;

private:
    node_pointer pointee_;

    explicit bst_iterator( const node_pointer& pointee = nullptr ) : pointee_( pointee ) {}
};

/**
 * @brief implementation of the bst
 *
 * @tparam Key Key
 */
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
    using node_raw_pointer = typename node_type::node_raw_pointer;

public:
    bst() : root_{std::make_unique<node_type>( value_type{} )}, end_( root_.get() ), size_{0} {}

    bst( const bst& other )
        : root_{std::make_unique<node_type>( value_type{} )}, end_( root_.get() ), size_{0} {
        copy_bst( other );
    }

    bst( bst&& other ) noexcept
        : root_{std::move( other.root_ )}, end_( other.end_ ), size_{other.size_} {
        other.root_ = nullptr;
        other.end_  = nullptr;
        other.size_ = 0;
    }

    bst( std::initializer_list<value_type> init )
        : root_{std::make_unique<node_type>( value_type{} )}, end_( root_.get() ), size_{0} {
        for ( const auto& in : init )
            insert( in );
    }

    std::pair<iterator, bool> insert( const value_type& value ) {
        return insert_iterative( value );
    }

    std::pair<iterator, bool> insert( value_type&& value ) {
        return insert_iterative( std::forward<value_type>( value ) );
    }

    iterator find( const_reference key ) {
        return search_value( key );
    }

    iterator erase( iterator pos ) {
        return erase_value( pos );
    }

    // size_type erase( const_reference key ) {
    //     erase( find( key ) );
    //     return size_;
    // }

    size_type size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    iterator begin() const noexcept {
        return make_iterator( tree_min( root_.get() ) );
    }

    iterator end() const noexcept {
        return make_iterator( end_ );
    }

    bst& operator=( const bst& other ) {
        root_ = std::make_unique<node_type>( value_type{} );
        end_  = root_.get();
        size_ = 0;
        copy_bst( other );
    }

    bst& operator=( bst&& other ) {
        root_       = std::make_unique<node_type>( value_type{} );
        end_        = root_.get();
        size_       = 0;
        other.root_ = nullptr;
        other.end_  = nullptr;
        other.size_ = 0;
    }

    node_raw_pointer root() const noexcept {
        return root_.get();
    }

    node_raw_pointer end_pointer() const noexcept {
        return end_;
    }

    ~bst() = default;

private:
    node_pointer root_;
    node_raw_pointer end_;
    size_type size_;

    iterator make_iterator( node_raw_pointer input ) const noexcept {
        return bst_iterator<node_type>( input );
    }

    std::pair<iterator, bool> insert_iterative( const value_type& value ) {
        auto current_node = root_.get();
        if ( current_node == end_ ) {
            auto new_root    = std::make_unique<node_type>( value );
            new_root->right_ = std::move( root_ );
            root_            = std::move( new_root );
            ++size_;
            return std::make_pair<iterator, bool>( make_iterator( root_.get() ), true );
        }

        auto parent = current_node;

        while ( current_node != nullptr && current_node != end_ ) {
            parent = current_node;
            if ( value < current_node->value_ )
                current_node = ( current_node->left_ ).get();
            else if ( value > current_node->value_ )
                current_node = ( current_node->right_ ).get();
            else
                return std::make_pair<iterator, bool>( make_iterator( current_node ), false );
            ;
        }
        ++size_;

        if ( value < parent->value_ ) {
            parent->left_ = std::make_unique<node_type>( value, parent );
            return std::make_pair<iterator, bool>( make_iterator( parent->left_.get() ), true );
        }

        else {
            if ( current_node == end_ ) {
                auto new_node    = std::make_unique<node_type>( value, parent );
                new_node->right_ = std::move( parent->right_ );
                parent->right_   = std::move( new_node );
                end_             = ( ( parent->right_ )->right_ ).get();
            }

            else {
                parent->right_ = std::make_unique<node_type>( value, parent );
            }
            return std::make_pair<iterator, bool>( make_iterator( parent->right_.get() ), true );
        }
    }

    std::pair<iterator, bool> insert_iterative( value_type&& value ) {
        auto current_node = root_.get();
        if ( current_node == end_ ) {
            auto new_root    = std::make_unique<node_type>( std::forward<value_type>( value ) );
            new_root->right_ = std::move( root_ );
            root_            = std::move( new_root );
            ++size_;
            return std::make_pair<iterator, bool>( make_iterator( root_.get() ), true );
        }

        auto parent = current_node;

        while ( current_node != nullptr && current_node != end_ ) {
            parent = current_node;
            if ( value < current_node->value_ )
                current_node = ( current_node->left_ ).get();
            else if ( value > current_node->value_ )
                current_node = ( current_node->right_ ).get();
            else
                return std::make_pair<iterator, bool>( make_iterator( current_node ), false );
            ;
        }
        ++size_;

        if ( value < parent->value_ ) {
            parent->left_ =
                std::make_unique<node_type>( std::forward<value_type>( value ), parent );
            return std::make_pair<iterator, bool>( make_iterator( parent->left_.get() ), true );
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
            return std::make_pair<iterator, bool>( make_iterator( parent->right_.get() ), true );
        }
    }

    node_raw_pointer tree_min( node_raw_pointer x ) const noexcept {
        while ( x->left_ != nullptr ) {
            x = ( x->left_ ).get();
        }
        return x;
    }

    node_raw_pointer tree_max( node_raw_pointer x ) const noexcept {
        while ( x->right_ != nullptr ) {
            x = ( x->right_ ).get();
        }
        return x;
    }

    iterator search_value( const_reference value ) const noexcept {
        auto current_node = root_.get();
        while ( current_node != nullptr && current_node != end_ ) {
            if ( current_node->value_ == value )
                return make_iterator( current_node );
            else if ( value < current_node->value_ )
                current_node = ( current_node->left_ ).get();
            else if ( value > current_node->value_ )
                current_node = ( current_node->right_ ).get();
        }
        return make_iterator( end_ );
    }

    void copy_bst( const bst& other ) {
        for ( const auto& ot : other )
            insert( ot );
    }

    // void release_subtree( node_pointer n ) {
    //     while ( n->left_ || n->right_ ) {
    //         auto left =
    //     }
    // }
};
} // namespace algorithm

/**
 * @brief erase the value at the given position
 * Maintain invariant for the parent (left->parent == this && right->parent == this)
 * @param pos position of the value to be erased
 * @return iterator iterator to the node replacing the pos (can be used with foreach)
 */
// iterator erase_value( iterator pos ) {
//     // case 0: handles end node or empty bst
//     if ( pos == end() ) return end();
//     --size_;
//     auto node        = pos.pointee_;
//     auto node_parent = node->parent_;

//     // case 1: Both left and right are nullptr. Parent invariant is maintained
//     if ( node->left_ == nullptr && node->right_ == nullptr ) {
//         if ( pos.is_left_child( node ) )
//             ( node_parent->left_ ).reset();
//         else
//             ( node_parent->right_ ).reset();
//     }

//     // case 2: has one child. Manually maintain the parent invariant
//     else if ( node->left_ == nullptr ) {
//         if ( node == root_.get() ) {
//             root_          = std::move( node->right_ );
//             root_->parent_ = nullptr;
//             return begin();
//         } else if ( pos.is_left_child( node ) ) {
//             ( node->right_ )->parent_ = node_parent;
//             node_parent->left_        = std::move( node->right_ );
//             return make_iterator( node_parent->left_ );
//         } else {
//             ( node->right_ )->parent_ = node_parent;
//             node_parent->right_       = std::move( node->right_ );
//             return make_iterator( node_parent->right_ );
//         }
//     }

//     else if ( node->right_ == nullptr || node->right_ == end_ ) {
//         if ( node == root_.get() ) {
//             root_          = std::move( node->left_ );
//             root_->parent_ = nullptr;
//             return begin();
//         } else if ( pos.is_left_child( node ) ) {
//             ( node->left_ )->parent_ = node_parent;
//             node_parent->left_       = std::move( node->left_ );
//             return make_iterator( node_parent->left_ );
//         } else {
//             ( node->left_ )->parent_ = node_parent;
//             node_parent->right_      = std::move( node->left_ );
//             return make_iterator( node_parent->left_ );
//         }
//     }

//     // case 3: has two left child. NOTE: successor is definitely in the right sub-tree
//     else {
//         auto successor = pos.successor( node );
//         if ( node == root.get() ) {

//         } else {
//             ( ( successor->parent_ )->left_ ).release();
//             ( successor->parent_ )->left_ = std::move( successor->right_ );

//             successor->right_ = std::move( node->right_ );
//             successor->left_  = std::move( node->left_ );
//         }
//     }
// }