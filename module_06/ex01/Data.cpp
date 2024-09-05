#include "Data.hpp"

Data::Data() : _data(0)
{
}

Data::Data(const void *data)
{
	_data = new char[100];
	std::memcpy(_data, data, 100);
}

Data::Data(const Data &other)
{
	if (other._data)
	{
		_data = new char[100];
		std::memcpy(_data, other._data, 100);
	}
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		delete[] static_cast<char *>(_data);
		_data = 0;
		if (other._data)
		{
			_data = new char[100];
			std::memcpy(_data, other._data, 100);
		}
	}
	return *this;
}

Data::~Data()
{
	delete[] static_cast<char*>(_data);
}

void *Data::getData(void) const
{
	return _data;
}

void Data::setData(void *data)
{
	delete[] static_cast<char*>(_data);
	_data = data;
}
