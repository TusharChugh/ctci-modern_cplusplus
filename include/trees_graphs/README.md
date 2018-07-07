# Key Points

0. There is simple_int_bst implementation and there is STL like bst implementation. Former is more suitable for the interview practice and the later is to dig deeper in the concepts and make life easier for using it while writing variety of test cases.
1. Implemented binary search tree in the bst.h. The api's are similar to std::set but it's much simpler to give an overview. Here are few key points for the implementation:  
    a. bst_node is kept public, so that it can be directly accessed.  
    b. root() give the direct access to the raw pointer to the root bst_node
    c. For range based for loop we need to implement end() (points to the element at the end of the container). end_pointer() gives the access to raw pointer. This is important to keep in mind when using this implementation.  
    d. Range based for loop in bst iterator uses inorder traversal which gives the nodes in the sorted order. ++operator on iterator gives this successor.  
    e. bst can be initialized with an initializer list.  
    f. As the access to the raw pointer. We can modify the tree outside of the bst class. This is not apt for a good bst implementation but useful to implement algorithms problems but modifying it as we like.  
    e. bst can be modified to/treated as binary trees. This is done in the solution to few problem sets here.  
2. Algorithms for node based DS like linked_lists and tree/graphs often are simpler to implement with recursion.
3. DFS can be implemented with recursively or iteratively (using stack). Intuitively recursion used stacks as well.
   