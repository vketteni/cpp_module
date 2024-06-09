#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _fixedPointValue(num << _fractBits) {
    std::cout << "Parameterized constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fixedPointValue(roundf(num * (1 << _fractBits)))
{
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


float Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractBits));
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}


bool Fixed::operator>(const Fixed &other) const
{
    if (this->_fixedPointValue > other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->_fixedPointValue < other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->_fixedPointValue  <= other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->_fixedPointValue >= other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->_fixedPointValue == other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->_fixedPointValue != other._fixedPointValue) {
        return true;
    }
    else {
        return false;
    }
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed sum;
    sum.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return sum;
}

Fixed Fixed::operator-(const Fixed &other)  const
{
    Fixed diff;
    diff.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return diff;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed prod;
    prod.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractBits);
    return prod;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed quot;
    quot.setRawBits(this->_fixedPointValue / other._fixedPointValue);
    return quot;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
	_fixedPointValue += 1; //(1 << _fractBits);
    return temp;
}

Fixed& Fixed::operator++(void)
{
	_fixedPointValue += 1; //(1 << _fractBits);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
	_fixedPointValue -= 1; //(1 << _fractBits);
    return temp;
}

Fixed& Fixed::operator--(void)
{
	_fixedPointValue -= 1; //(1 << _fractBits);
    return *this;
}


Fixed &Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2) {
        return num1;
    }
    else {
        return num2;
    }
}

const Fixed &Fixed::min(const Fixed& num1, const Fixed& num2) 
{
	if (num1 < num2) {
        return num1;
    }
    else {
        return num2;
    }
}

Fixed &Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2) {
        return num1;
    }
    else {
        return num2;
    }
}

const Fixed &Fixed::max(const Fixed& num1, const Fixed& num2) 
{
	if (num1 > num2) {
        return num1;
    }
    else {
        return num2;
    }
}