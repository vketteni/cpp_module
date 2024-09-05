#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <string>
# include <iostream>

template <typename T>
inline void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
inline const T& max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

template <typename T>
inline const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

#endif

