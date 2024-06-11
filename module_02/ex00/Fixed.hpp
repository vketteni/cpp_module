#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstring>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractBits = 8;

public:
    Fixed();
    Fixed(int _fixedPointValue);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int                 getRawBits() const;
    void                setRawBits(const int& _fixedPointValue);
};

#endif // FIXED_HPP
