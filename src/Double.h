#pragma once
#include <iostream>
#include <cstdint>
#include <cassert>
#include <cmath> 

class Double
{
private:
	std::int16_t m_beforeDot; // integer part
	std::int8_t m_afterDot;  // fractional part
	static constexpr int fractionCapacity = 100;
public:
	Double(std::int16_t beforeDot = 0, std::int8_t afterDot = 0);
	Double(double dValue);	

	operator double() const;	

	friend bool operator == (const Double& d1, const Double& d2);

	friend std::ostream& operator << (std::ostream& out, const Double& d);
	friend std::istream& operator >> (std::istream& in, Double& d);

	friend Double operator + (const Double& d1, const Double& d2);

	Double& operator -();
};