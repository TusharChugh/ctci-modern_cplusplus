# Stacks and Queues

## Key Points:
1. Stack and queue are the adaptors to the [sequence containers](http://en.cppreference.com/w/cpp/concept/SequenceContainer). See the adaptor pattern. 
2. Both stack and queue take container as the template arguments. Default container is ```std::deque<T>```
```
template<
    class T,
    class Container = std::deque<T>
> class queue;
```
3. Containers must provide following functions for stack (in addition to being a sequence container) :
```
back()
push_back()
pop_back()
```
The standard containers ```std::vector```, ```std::deque``` and ```std::list``` satisfy these requirements.

4. Containers must provide following functions for queue (in addition to being a sequence container) :
```
back()
front()
push_back()
pop_front()
```
The standard containers ```std::deque``` and ```std::list``` satisfy these requirements.

5. Iterators are not implemented with noth the data structures as we don't have a way to iterator over the elements

6. As iterators can't be implemented with both (no begin() and end() functions), we cannot use ```for_each``` and std::algorithms like ```std::sort```, ```std::reverse``` and more. 

7. Calling ```front()``` or ```back()``` on an empty container is undefined.