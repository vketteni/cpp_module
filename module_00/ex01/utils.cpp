#include <iostream>
#include <string>
#include <cstdlib>

std::string truncateString(const std::string& str, std::size_t maxLength) {
    if (str.length() > maxLength) {
        return str.substr(0, maxLength) + ".";
    }
    return str;
}

bool    isAlphaNumString(std::string input) {
    if (input.length() == 0) {
        return false;
    }
    std::string::iterator it;
    it = input.begin();
    while (it != input.end()) {
        if (!(std::isalnum(*it) || std::isspace(*it))) {
            return false;
        }
        it++;
    }
    return true;
}

bool    isDigitString(std::string input) {
    if (input.length() == 0) {
        return false;
    }
    std::string::iterator it;
    it = input.begin();
    while (it != input.end()) {
        if (!(std::isdigit(*it) || std::isspace(*it))) {
            return false;
        }
        it++;
    }
    return true;
}

void	clear_screen() {
	system("clear");
}
