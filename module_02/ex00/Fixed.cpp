#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int _fixedPointValue) : _fixedPointValue(_fixedPointValue << _fractBits) {
    std::cout << "Parameterized constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this == &other) {
        return *this;
    }
    this->_fixedPointValue = other._fixedPointValue;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    // TODO: Clean up any allocated resources
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;

    return _fixedPointValue;
}

void Fixed::setRawBits(const int& _fixedPointValue) {
    std::cout << "setRawBits member function called" << std::endl;

    this->_fixedPointValue = _fixedPointValue;
}
