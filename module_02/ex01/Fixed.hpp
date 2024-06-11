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
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(const int& _fixedPointValue);
    float   toFloat(void) const;
    int     toInt(void) const;

};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif // FIXED_HPP
