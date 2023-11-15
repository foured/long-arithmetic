#include <iostream>
#include <string>

int addchars(char c1, char c2, char c3);
std::string addLines(std::string l1, std::string l2);

int main() {
	std::string n1, n2;
	std::getline(std::cin, n1);
	std::getline(std::cin, n2);

	std::cout << addchars('1', '0', '1');
	return 0;
}
std::string addLines(std::string l1, std::string l2) {
	int s1, s2;
	s1 = l1.size();
	s2 = l2.size();
	
	char ost = '0';
	if (s1 > s2) {
		for (int i = 0; i < s2; i++) {
			int r = addchars(l1[i], l2[i], ost);
		}
	}
}
int addchars(char c1, char c2, char c3) {
	return std::stoi(std::string{ c1 }) + std::stoi(std::string{ c2 }) + std::stoi(std::string{ c3 });
}
