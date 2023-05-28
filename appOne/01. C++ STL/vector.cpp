// std::list demo
// by Eduardo Corpe�o

#include <iostream>
#include <list>

using namespace std;

void print(const list<int>& my_list) {
	cout << "list content: {  ";
	for (const int& num : my_list)
		cout << num << " ";
	cout << "}\n\n";
}

int main() {
	list<int> numbers;
	int value = 0;
	cout << "pusint back ..\n";
	while (value >= 0) {
		cout << "enter value: \n";
		cin >> value;
		if (value >= 0)
			numbers.push_back(value);
	}
	
	print(numbers);

	value = 0;
	cout << "pusing front..\n";
	while (value >= 0) {
		cout << "enter value: \n";
		cin >> value;
		if (value >= 0)
			numbers.push_front(value);
	}

	print(numbers);

	

	return 0;
}

