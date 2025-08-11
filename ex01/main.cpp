#include "serial.hpp"
#include <iostream>

int main() {
	Serializer s;

	// 1) Stack‐allocated Data
	Data d;
	Data* p1 = &d;
	uintptr_t raw1 = s.serialize(p1);
	Data* r1 = s.deserialize(raw1);

	std::cout << "Stack object test\n";
	std::cout << "  Original pointer:    " << p1 << "\n";
	std::cout << "  Serialized value:    " << raw1 << "\n";
	std::cout << "  Deserialized pointer:" << r1 << "\n";
	std::cout << "  Result: "
				<< (r1 == p1 ? "MATCH\n" : "MISMATCH\n");

	// 2) Heap‐allocated Data
	Data* p2 = new Data();
	uintptr_t raw2 = s.serialize(p2);
	Data* r2 = s.deserialize(raw2);

	std::cout << "\nHeap object test\n";
	std::cout << "  Original pointer:    " << p2 << "\n";
	std::cout << "  Serialized value:    " << raw2 << "\n";
	std::cout << "  Deserialized pointer:" << r2 << "\n";
	std::cout << "  Result: "
				<< (r2 == p2 ? "MATCH\n" : "MISMATCH\n");

	delete p2;

	// 3) Null pointer
	Data* p3 = 0;
	uintptr_t raw3 = s.serialize(p3);
	Data* r3 = s.deserialize(raw3);

	std::cout << "\nNull pointer test\n";
	std::cout << "  Original pointer:    " << p3 << "\n";
	std::cout << "  Serialized value:    " << raw3 << "\n";
	std::cout << "  Deserialized pointer:" << r3 << "\n";
	std::cout << "  Result: "
				<< (r3 == p3 ? "MATCH\n" : "MISMATCH\n");

	return 0;
}
