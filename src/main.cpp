#include "Double.h"

int main()
{
	Double a(7, 33);
	std::cout << a << '\n';

	std::cout << Double(0.75) + Double(1.23) << '\n';
	std::cout << Double(0.75) + Double(1.50) << '\n';
	std::cout << Double(-0.75) + Double(-1.23) << '\n';
	std::cout << Double(-0.75) + Double(-1.50) << '\n';
	std::cout << Double(0.75) + Double(-1.23) << '\n';
	std::cout << Double(0.75) + Double(-1.50) << '\n';
	std::cout << Double(-0.75) + Double(1.23) << '\n';
	std::cout << Double(-0.75) + Double(1.50) << '\n';

	return 0;
}
