#include "Array.hpp"
#include "Iter.hpp"

template <typename T>
void print(T &value) {
    std::cout << value << std::endl;
}

int	main(void)
{
	header("Simple Type (int)");
	Array<int> * arr_ptr = new Array<int>(5);
	Array<int> arr = *arr_ptr;
	debug(arr[0]);

	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i;
	iter(arr, arr.size(), print<int>);
	newLine()

	header("Index out of bounds");
	try
	{
		arr[6] = 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete arr_ptr;
	newLine()

	header("Complex Type (std::string)");
	Array<std::string> * strarr_ptr = new Array<std::string>(5);
	Array<std::string> strarr = *strarr_ptr;
	debug(strarr[0]);

	for (unsigned int i = 0; i < strarr.size(); ++i)
	{
		strarr[i] = std::string("  hello");
		strarr[i][0] = '0' + i;
	}
	iter(strarr, strarr.size(), print<std::string>);
	delete strarr_ptr;
	newLine()

	// header("Read only");
	// const Array<int> arr_const = (const Array<int>)arr;
	// arr_const[0] = 42;
}