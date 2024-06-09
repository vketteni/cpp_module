#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstring>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractBits = 8;

public:
    Fixed();
    Fixed(const int _fixedPointValue);
    Fixed(const float _fixedPointValue);
    Fixed(const Fixed& other);
    Fixed&  operator=(const Fixed& other);
    bool    operator>(const Fixed& other) const;
    bool    operator<(const Fixed& other) const;
    bool    operator<=(const Fixed& other) const;
    bool    operator>=(const Fixed& other) const;
    bool    operator==(const Fixed& other) const;
    bool    operator!=(const Fixed& other) const;
    Fixed   operator+(const Fixed& other) const;
    Fixed   operator-(const Fixed& other) const;
    Fixed   operator*(const Fixed& other) const;
    Fixed   operator/(const Fixed& other) const;
    Fixed   operator++(int);
    Fixed&   operator++(void);
    Fixed   operator--(int);
    Fixed&   operator--(void);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(const int& _fixedPointValue);
    float   toFloat(void) const;
    int     toInt(void) const;

    static Fixed& min(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif // FIXED_HPP