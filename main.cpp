#include <iostream>
#include <string>

int addchars(char c1, char c2, char c3);
int substractchars(char c1, char c2);
std::string addlines(std::string l1, std::string l2);
std::string subtractlines(std::string l1, std::string l2, bool setOrder = false);
std::string multiplylines(std::string l1, std::string l2);
std::string revstr(std::string l);
std::string getridoffirstzeros(std::string l);
int findchar(std::string l, char ch, int start, int end = -1);

void menu();

int main() {
	setlocale(LC_ALL, "Russian");
	menu();
	return 0;
}
void menu() {
	std::string n1, n2;
	std::cout << "Введите первое число, а потом второе:" << std::endl;
	std::getline(std::cin, n1);
	std::getline(std::cin, n2);

	std::cout << std::endl;

	std::cout << "Выберите опцию:" << std::endl;
	std::cout << "[1] - сложение" << std::endl;
	std::cout << "[2] - вычитание" << std::endl;
	std::cout << "[3] - умножение" << std::endl;
	std::cout << "Ваш выбор: ";

	int var;
	std::cin >> var;

	std::cout << std::endl;

	std::cout << "Ответ:" << std::endl;
	if (var == 1) {
		std::cout << addlines(n1, n2) << std::endl;
	}
	else if (var == 2) {
		std::string res = subtractlines(n1, n2);
		if (res == "")
			std::cout << "0" << std::endl;
		else
			std::cout << res << std::endl;
	}
	else if (var == 3) {
		std::cout << multiplylines(n1, n2) << std::endl;
	}
}
std::string multiplylines(std::string l1, std::string l2) {
	std::string res = "0";
	for (int i = 0; i < l2.size(); i++) {
		if (l2[i] == '1') {
			res = addlines(res, l1);
		}
		l1 += '0';
	}
	return res;
}
std::string subtractlines(std::string l1, std::string l2, bool setOrder) {
	if (l1 == "0" && l2 == "0") return "0";

	std::string ls1, ls2;
	ls1 = l1;
	ls2 = l2;

	l1 = revstr(l1);
	l2 = revstr(l2);

	std::string res = "";
	bool isNegative = false;

	int s1, s2, j = 0;
	s1 = l1.size();
	s2 = l2.size();

	if (setOrder) {
		for (int i = 0; j < s2; j++) {
			int r = substractchars(l1[j], l2[j]);

			if (r == 1) {
				res += '1';
			}
			else if (r == 0) {
				res += '0';
			}
			else {
				int idx = findchar(l1, '1', j);
				if (idx != -1) {
					l1[idx] = '0';
					for (int t = (idx - 1); t > j; t--) {
						l1[t] = '1';
					}
					res += '1';
				}
				else {
					res = "-" + subtractlines(ls2, ls1, true);
					return res;
				}
			}
		}
		for (int k = j; k < s1; k++) {
			res += l1[k];
		}
	}
	else if (s1 >= s2) {
		for (int i = 0; j < s2; j++) {
			int r = substractchars(l1[j], l2[j]);

			if (r == 1) {
				res += '1';
			}
			else if (r == 0) {
				res += '0';
			}
			else {
				int idx = findchar(l1, '1', j);
				if (idx != -1) {
					l1[idx] = '0';
					for (int t = (idx - 1); t > j; t--) {
						l1[t] = '1';
					}
					res += '1';
				}
				else {
					res = "-" + subtractlines(ls2, ls1, true);
					return res;
				}
			}
		}
		for (int k = j; k < s1; k++) {
			res += l1[k];
		}
	}
	else {
		isNegative = true;
		for (int i = 0; j < s1; j++) {
			int r = substractchars(l2[j], l1[j]);

			if (r == 1) {
				res += '1';
			}
			else if (r == 0) {
				res += '0';
			}
			else {
				int idx = findchar(l2, '1', j);
				l2[idx] = '0';
				for (int t = (idx - 1); t > j; t--) {
					l2[t] = '1';
				}
				res += '1';
			}
		}
		for (int k = j; k < s2; k++) {
			res += l2[k];
		}
	}

	res = revstr(res);
	res.pop_back();
	res = getridoffirstzeros(res);
	if (isNegative) res = '-' + res;
	return res;
}
std::string addlines(std::string l1, std::string l2) {
	if (l1 == "0" && l2 == "0") return "0";

	l1 = revstr(l1);
	l2 = revstr(l2);

	std::string res;
	int s1, s2, j = 0;
	s1 = l1.size();
	s2 = l2.size();

	char ost = '0';
	if (s1 >= s2) {
		for (int i = 0; j < s2; j++) {
			int r = addchars(l1[j], l2[j], ost);

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}

		}
		for (int i = j; i < s1; i++) {
			int r = addchars(l1[i], ost, '0');

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}
		}
		res += ost;
	}
	else {
		for (int i = 0; j < s1; j++) {
			int r = addchars(l1[j], l2[j], ost);

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}


		}
		for (int i = j; i < s2; i++) {
			int r = addchars(l2[i], ost, '0');

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}
		}
		res += ost;
	}

	res = revstr(res);
	res.pop_back();
	res = getridoffirstzeros(res);
	return res;
}
int addchars(char c1, char c2, char c3) {
	int res = 0;
	if (c1 == '1') res++;
	if (c2 == '1') res++;
	if (c3 == '1') res++;

	return res;
}
int substractchars(char c1, char c2) {
	if (c1 == '1' && c2 == '0') return 1;
	else if (c1 == '0' && c2 == '1') return -1;
	else return 0;
}
std::string revstr(std::string l) {
	std::string res = "";
	int s = l.size();
	for (int i = 0; i <= s; i++) {
		char cc = l[s - i];
		res += cc;
	}
	return res;
}
std::string getridoffirstzeros(std::string l) {
	std::string res;
	bool start = false;
	int s = l.size();
	for (int i = 0; i < s; i++) {
		char cc = l[i];
		if (!start && cc == '1') start = true;
		if (start) res += cc;
	}
	return res;
}
int findchar(std::string l, char ch, int start, int end) {
	int res = -1;
	if (end == -1) end = l.size();
	for (int i = start; i < end; i++) {
		if (l[i] == ch) {
			res = i;
			break;
		}
	}
	return res;
}
