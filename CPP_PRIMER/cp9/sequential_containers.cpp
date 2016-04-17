#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
using namespace std;

void iterator_practice() {
	forward_list<string> fL {"Jack", "Rose", "Slow", "Fxxk"};
	list<string> sL {"Jack", "Rose", "Slow", "Fxxk"};
	deque<string> dL {"Jack", "Rose", "Slow", "Fxxk"};
	vector<string> vL {"Jack", "Rose", "Slow", "Fxxk"};

	auto fentry = fL.begin();
	auto sentry = sL.begin();
	auto dentry = sL.begin();
	auto ventry = vL.begin();

	cout << "forward_list----" << endl;
	cout << *fentry++ << endl;
	//cout << *entry-- << endl; // Does not support --
	while (fentry != fL.end()) {
		cout << *fentry++ << endl;
	}

	cout << "list ----" << endl;
	cout << *sentry++ << endl;
	cout << *sentry-- << endl;
	while (sentry != sL.end())
		cout << *sentry++ << endl;

	/*
	cout << "deque-----" << endl;
	cout << *dentry++ << endl;
	cout << *dentry-- << endl;
	while (dentry != dL.end())
		cout << *dentry++ << endl;
	*/

	cout << "vector-----" << endl;
	cout << *ventry++ << endl;
	cout << *ventry-- << endl;
	while (ventry != vL.end())
		cout << *ventry++ << endl;

	cout << "Size ----" << endl;
	size_t vSize = vL.size();
	cout << vSize << endl;
	size_t sSize = sL.size();
	cout << sSize << endl;
	size_t dSize  = dL.size();
	cout << dSize << endl;
	/*
	size_t fSize = fL.size();
	cout << vSize << endl;
	*/
}

void vector_practice() {
	vector<string> names {"Jack", "Rose", "Slow", "FXXK"};

	auto entry = names.begin();

	while (entry != names.end()) {
		cout << *entry++ << endl;
	}

}

void print_vector(vector<int> &vec) {
	auto it = vec.begin();
	while (it != vec.cend()) {
		cout << *it++ << " ";
	}
	cout << endl;
}

void print_forward_list(forward_list<int> &list) {
	auto it = list.begin();
	while (it != list.cend()) {
		cout << *it++ << " ";
	}
	cout << endl;
}

void print_list(list<int> &list) {
	auto it = list.begin();
	while (it != list.cend()) {
		cout << *it++ << " ";
	}
	cout << endl;
}

void print_deque(deque<int> &list) {
	auto it = list.begin();
	while (it != list.cend()) {
		cout << *it++ << " ";
	}
	cout << endl;
}

void init_practice() {
	//array
	array<int, 5> arr1 = {1, 2, 3, 4, 5};
	int digs[5] = {1, 2, 3, 4, 5};
	//int digs2[5] = digs; //Illegal
	//array<int, 5> arr2 = digs;
	array<int, 5> arr2 = arr1;



	//
}

vector<int> create_vector(int size) {
	vector<int> arr;

	int i = 0;
	while (i++ < size) {
		arr.push_back(i);
	}

	return arr;
}


void create_and_insert() {
	deque<int> deq = {1, 2, 3};
	deq.push_back(4);
	deq.push_front(0);

	deq.insert(deq.begin() + 2, 0);
	deq.erase(deq.begin() + 1, deq.begin() + 3);

	print_deque(deq);

	//list support push_back and push_front
	list<int> list = {1, 2, 3};
	list.push_back(4);
	list.push_front(9);
	//Insert a range
	list.insert(list.end(), 10, 0);

	print_list(list);

	vector<int> vec = {1, 2, 3};
	vec.push_back(4);
	//vec.push_front(1); //Illegal
	//No push_front, but we can insert before begin()
	vec.insert(vec.begin(), 5);
	print_vector(vec);

	forward_list<int> flist = {1, 2, 3};
	flist.push_front(0);

	//flist.insert(flist.end(), 199); //
	//flist.push_back(9);
	print_forward_list(flist);

	string s = "test";
	s.push_back('D');
	//s.push_front('A');
	cout << s << endl;
}


void resize_and_validate() {
	//vector
	vector<int> vec = {1, 2, 3, 4, 5};
	auto it = vec.begin();

	cout << *it++ << endl;
	cout << *it++ << endl;
	cout << *it++ << endl;
	cout << *it++ << endl;

	vec.resize(3);
	print_vector(vec);

	cout << *(it - 1) << endl;

	vec.insert(vec.begin(), 3, -1);
	print_vector(vec);
	cout << *(it - 3) << endl;
}

void play_with_string() {
	string s = "test";
	cout << s.size() << endl;
} 



int main(int argc, char const *argv[])
{
	play_with_string();
	return 0;
}
