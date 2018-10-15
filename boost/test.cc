#include<iostream>

#include<boost/version.hpp>
#include<boost/config.hpp>

int main(void) {
	std::cout << BOOST_VERSION << std::endl;
	std::cout << BOOST_LIB_VERSION << std::endl;
	std::cout << BOOST_PLATFORM << std::endl;
	std::cout << BOOST_COMPILER << std::endl;
	std::cout << BOOST_STDLIB << std::endl;
}
