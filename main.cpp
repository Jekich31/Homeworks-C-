#include <iostream>
#include "home.h"
using namespace std;
class Test {
public:
	int value;

	Test(int v) : value(v) {
		cout << "Created: " << value << endl;
	}

	~Test() {
		cout << "Destroyed: " << value << endl;
	}

	void show() {
		cout << "Value: " << value << endl;
	}
};

int main() {

	cout << "UniquePtr Test " << endl;

	UniquePtr<Test> up1(new Test(10));
	up1->show();

	UniquePtr<Test> up2 = std::move(up1);

	if (!up1.get()) {
		cout << "up1 is empty\n";
	}

	up2->show();

	cout << "\nSharedPtr Test " << endl;

	SharedPtr<Test> sp1(new Test(20));
	{
		SharedPtr<Test> sp2 = sp1;
		cout << "Count: " << sp1.use_count() << endl;

		{
			SharedPtr<Test> sp3 = sp2;
			cout << "Count: " << sp1.use_count() << endl;
		}

		cout << "After sp3: " << sp1.use_count() << endl;
	}

	cout << "After sp2: " << sp1.use_count() << endl;
}