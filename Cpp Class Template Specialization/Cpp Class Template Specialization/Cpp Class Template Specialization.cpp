/*
You are given a main function which reads the enumeration values for two different types as input, then prints out the corresponding enumeration names.
Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown.
*/

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
#include <string_view>

template<>
struct Traits<Fruit> {
	static std::string_view name(int index) {
		switch (static_cast<Fruit>(index)) {
		case Fruit::apple: return "apple"; break;
		case Fruit::orange: return "orange"; break;
		case Fruit::pear: return "pear"; break;
		default: return "unknown";
		}
	}
};

template<>
struct Traits<Color> {
	static std::string_view name(int index) {
		switch (static_cast<Color>(index)) {
		case Color::red: return "red"; break;
		case Color::green: return "green"; break;
		case Color::orange: return "orange"; break;
		default: return "unknown";
		}
	}
};

int main()
{
	int t = 0; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}