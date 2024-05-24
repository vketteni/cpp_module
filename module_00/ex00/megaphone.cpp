#include <iostream>
#include <string>
#include <cctype>
#include <string.h>

void    capitalize(std::string& str)
{
    std::string::size_type i;
    
    i = 0;
    while (i < str.size())
    {
        str[i] = toupper(static_cast<unsigned char>(str[i]));
        i++;
    }
}
int	main(int argc, char **argv)
{
    int         i;
    std::string argument;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc) {
        argument = argv[i];
        capitalize(argument);
        std::cout << argument << " " << std::flush;
        i++;
    }
    std::cout << std::endl;
    return 0;
}