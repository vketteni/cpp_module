#ifndef DATA_HPP
#define DATA_HPP

# include <cstring>

class Data
{
	public:
		Data(const void *data);
		Data(const Data & other);
		Data & operator=(const Data & other);
		~Data();

		void *	getData(void) const;
		void	setData(void *data);
	private:
		Data();
		void *	_data;


};

#endif