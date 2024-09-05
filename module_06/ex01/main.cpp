#include "Serializer.hpp"
#include <string>

int	main(void)
{
	std::string raw = "hello world";
	Data my_data((void *)raw.c_str());
	debug((char *)my_data.getData());
	uintptr_t serialized = Serializer::serialize(&my_data);
	Data *unserialized = Serializer::deserialize(serialized);

	debug((char *)unserialized->getData());
}