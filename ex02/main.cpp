#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <exception>
#include <cstdlib>

Base *generate(void)
{
	std::srand(time(0));
	int seed = std::rand() % 3;
	if (seed == 0)
		return new A();
	else if (seed == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "A\n"; return; }
	catch (std::exception &e) { (void)e; }
	try { (void)dynamic_cast<B&>(p); std::cout << "B\n"; return; }
	catch (std::exception &e) { (void)e; }
	try { (void)dynamic_cast<C&>(p); std::cout << "C\n"; return; }
	catch (std::exception &e) { (void)e; }
	std::cout << "Unknown\n";
}

int	main(void)
{
	std::srand(std::time(0));
	for (int cur = 0; cur < 5; cur++)
	{
		Base *randBase = generate();
		identify(randBase);
		identify(*randBase);
		delete randBase;
	}
	return 0;
}
