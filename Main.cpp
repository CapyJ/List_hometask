#include <iostream>
#include "List.h"
#include <list>

using namespace std;

int main() {

	List<int> l1;
	l1.AddLast(12);
	l1.AddLast(14);
	l1.AddLast(16);
	l1.AddFirst(99);
	l1.Print();
	cout<<l1.GetSize()<<endl;

	list<int> i12;
	i12.pop_back();

	/*list<int> l2;
	l2.push_back(19);
	l2.push_back(21);
	l2.push_front(22);

	auto b = l2.begin();
	auto e = l2.end();

	l2.insert(b, 135);
	cout << l2.size() << endl;

	while (b != e) {

		cout << *b << " | ";

		b++;
	}

	cout << endl;*/


	system("pause");
	return 0;
}