/*
Example SFINAE macros and their usage
https://ideone.com/5fVNhX
*/

#include <iostream>
#include <type_traits>


#define IS_SAME(T,U) std::is_same<T,U>::value
#define IS_ARITHMETIC(T) std::is_arithmetic<T>::value
#define ENABLE_IF(V) typename std::enable_if<V,bool>::type = true


template <typename T, ENABLE_IF(IS_SAME(T,int) && IS_ARITHMETIC(T))>
T foo(T input) 
{
	return input + 20;
}

template <typename T, ENABLE_IF(!IS_ARITHMETIC(T))>
T foo(T input)
{
	return input;
}

template <typename T, ENABLE_IF(IS_SAME(T,double))>
T foo(T input)
{
	return input * 1000;
}

int main() 
{
	std::cout << foo(0.45) << std::endl;
	std::cout << foo(3) << std::endl;
	std::cout << foo("sasdasd") << std::endl;
	// std::cout << foo(true) << std::endl; <-- no template for bool, instant compiler error, nice!
	return 0;
}