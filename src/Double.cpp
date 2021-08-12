#include "Double.h"

Double::Double(std::int16_t beforeDot, std::int8_t afterDot)
	: m_beforeDot(beforeDot), m_afterDot(afterDot)
{
	assert(abs(m_afterDot) < fractionCapacity);

	// signes of both parts has to be same
	if (m_beforeDot < 0.0 || m_afterDot < 0.0)
	{
		if (m_beforeDot > 0.0)
			m_beforeDot = -m_beforeDot;
		if (m_afterDot > 0.0)
			m_afterDot = -m_afterDot;
	}
}

Double::Double(double dValue)
{
	m_beforeDot = static_cast<std::int16_t>(dValue); // discard fractional part

	// using round() avoids overflow
	m_afterDot = static_cast<std::int8_t>(round((dValue - m_beforeDot) * fractionCapacity));

}

Double::operator double() const
{
	return m_beforeDot + static_cast<double>(m_afterDot) / fractionCapacity;
}

bool operator==(const Double& d1, const Double& d2)
{
	return (d1.m_beforeDot == d2.m_beforeDot && d1.m_afterDot == d2.m_afterDot);
}

std::ostream& operator<<(std::ostream& out, const Double& d)
{
	out << static_cast<double>(d);
	return out;
}

std::istream& operator>>(std::istream& in, Double& d)
{
	double _d;
	in >> _d;
	d = Double(_d);
	return in;
}

Double operator+(const Double& d1, const Double& d2)
{
	return Double(static_cast<double>(d1) + static_cast<double>(d2));
}

Double& Double::operator-()
{
	m_afterDot = -m_afterDot;
	m_beforeDot = -m_beforeDot;
	return *this;
}
