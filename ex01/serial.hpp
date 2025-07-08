#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <cstdint>

struct Data {
	int count;
	std::string verb;
	float random;
};

class Serializer {
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif