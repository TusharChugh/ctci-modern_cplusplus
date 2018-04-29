# Stacks and Queues

## Key Points:
1. Stack and queue are the adaptors to the [sequence containers]. (http://en.cppreference.com/w/cpp/concept/SequenceContainer) See the adaptor pattern. 
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