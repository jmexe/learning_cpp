#include <iostream>
#include "buddy.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Buddy bd1 = Buddy("Ming");
	Buddy bd2 = Buddy("Yiqi");

	Buddy bd3 = Buddy(bd1);
	Buddy bd4 = bd2;

	Buddy* p4 = new Buddy(bd4);

	cout << bd1.name << endl;
	cout << bd2.name << endl;
	cout << bd3.name << endl;
	cout << bd4.name << endl;

	cout << "Buddies:" << Buddy::cnt << endl;
	cout << "Buddies in history:" << Buddy::appeared << endl;

	delete p4;

	cout << "Buddies:" << Buddy::cnt << endl;
	cout << "Buddies in history:" << Buddy::appeared << endl;

	return 0;
}
