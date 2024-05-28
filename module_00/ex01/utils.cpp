#include <iostream>
#include <string>
#include <cstdlib>

std::string truncateString(const std::string& str, std::size_t maxLength) {
    if (str.length() > maxLength) {
        return str.substr(0, maxLength) + ".";
    }
    return str;
}

void	clear_screen() {
	system("clear");
}
