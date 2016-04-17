#include <iostream>
#include <vector>
using namespace std;

struct OPTest {
	int val;
	OPTest(int arg) {val = arg;}
};

struct Human {
	int gender;
	int age;
	int id;
	string name;

	Human(int g_val, int a_val, int i_val, string n_val) : gender(g_val), age(a_val), id(i_val), name(n_val) {}

	int operator==(Human& h2) {
		if (this->id == h2.id) {
			return 1;
		}
		return 0;
	}

	int operator>(Human& h2) {
		return this->age > h2.age;
	}

	int operator<(Human& h2) {
		return this->age < h2.age;
	}
};


struct HMVector {
	vector<int> vec;

	HMVector operator+(int a) {
		this->vec.push_back(a);
		return *this;
	}

	HMVector operator+(HMVector vec2) {
		for (auto &itr : vec2.vec) {
			this->vec.push_back(itr);
		}
		return *this;
	}

	void operator+=(int a) {
		this->vec.push_back(a);
	}

	void operator+=(HMVector vec2) {
		for (auto &itr : vec2.vec) {
			vec.push_back(itr);
		}
	}

	void print() {
		for (auto& itr : this->vec) {
			cout << itr << " ";
		}
		cout << endl;
	}
};



class StrVec {
public:
	std::string& operator[](std::size_t n)
		{return elements[n];}
	const std::string& operator[](std::size_t n) const
		{return elements[n];}
private:
	std::string *elements;
};

int operator%(OPTest op1, OPTest op2) {
	cout << op1.val + op2.val << endl;
	return op1.val + op2.val;
}

int main(int argc, char const *argv[])
{
	/*
	OPTest op1 = OPTest(4);
	OPTest op2 = OPTest(2);

	op1 % op2;

	cout << 5%3 << endl;
	*/
	/*
	Human h1 = Human(1, 34, 10034, "John");
	Human h2 = Human(1, 35, 10035, "Jack");
	Human h3 = Human(0, 21, 10034, "Fake John");

	cout << (h1 == h3) << endl;
	cout << (h1 > h3) << endl;
	*/
	/*
	HMVector obj1;
	obj1 += 4;
	obj1 = obj1 + 5;
	obj1.print();

	HMVector obj2;
	obj2 += 1;
	obj2 = obj2 + 2;
	obj2.print();

	obj1 += obj2;
	obj1.print();
	*/



	return 0;
}
