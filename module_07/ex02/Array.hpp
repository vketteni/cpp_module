#ifndef ARRAY_HPP
#define ARRAY_HPP

# include "Debug.hpp"

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> & other);
		~Array();

		Array<T> &		operator=(const Array<T> & other);
		T &				operator[](unsigned int index);
		const T &		operator[](unsigned int index) const;

		unsigned int	size(void);
	private:
		T* 				_data;
		unsigned int	_size;
};

#endif

template <typename T>
inline Array<T>::Array()
{
	_size = 0;
	_data = new T[_size];
}

template <typename T>
inline Array<T>::Array(unsigned int n)
{
	_size = n;
	_data = new T[_size];
}

template <typename T>
inline Array<T>::Array(const Array<T> &other)
{
	_size = other._size;
	_data = new T[_size];
	for (int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template <typename T>
inline Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete _data;
		*this = other;
	}
	return *this;
}

template <typename T>
inline T &Array<T>::operator[](unsigned int index)
{
	if (index < _size)
		return _data[index];
	else
		throw std::exception();
}

template <typename T>
inline const T &Array<T>::operator[](unsigned int index) const
{
	return _data[index];
}

template <typename T>
inline unsigned int Array<T>::size(void)
{
	return _size;
}

template <typename T>
inline Array<T>::~Array()
{
	delete _data;
}
