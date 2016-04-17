#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void map_practice() {
	map<string, size_t> word_count;
	vector<string> vec = {"qwerty", "123", "adf"};
	for (auto it = vec.begin(); it != vec.cend(); it++) {
		word_count[*it] = (*it).size();
	}

	for (const auto &w : word_count) {
		cout << w.first << "'s length is " << w.second << endl;
	}

	map<string, int> excludes = {{"Ming", 1},
									{"Yiqi", 2},
									{"Test", 4}};

	for (const auto &w : excludes) {
		cout << w.first << " " << w.second << endl;
	}
}

void set_practice() {
	set<string> test = {"ABC", "avc", "abc"};
	string word;
	while (cin >> word)
		if (test.find(word) != test.end())
			cout << "found!" << endl;
}

void ordered_container_practice() {
	set<int> arr = {3, 7, 1, 5, 2, 5};
	for (const auto &w : arr) {
		cout << w << endl;
	}
}

void multi_set_practice() {
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 10; i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());

	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;
}

bool compareIsbn(const string s1, const string s2) {
	return s1.size() > s2.size();
}

void self_defined_compare_multiset_practice() {
	multiset<string, decltype(compareIsbn)*> bookstore(compareIsbn);
	bookstore.insert("abc");
	bookstore.insert("abc");
	bookstore.insert("ab");
	bookstore.insert("abcd");
	for(const auto &it : bookstore) {
		cout << it << endl;
	}
}

pair<string, int> create_pair(vector<string> &v) {
	if (!v.empty()) 
		return {v.back(), v.back().size()};
	else
		return pair<string, int>();
}

void pair_practice() {
	vector<string> v = {"abc"};
	auto p = create_pair(v);
	cout << p.first << endl;
}

void test_return_from_insert() {
	map<string, size_t> word_count;
	string word;
	int cnt(0);

	while(cin >> word && ++cnt < 10) {
		auto ret = word_count.insert({word, 1});

		if (!ret.second)
			++ret.first->second;
	}

	for (const auto p : word_count) {
		cout << p.first << " " << p.second << endl; 
	}
}

int main(int argc, char const *argv[])
{
	cout << "Practice for Chapter 11" << endl;
	//map_practice();
	//set_practice();
	//multi_set_practice();
	
	//ordered_container_practice();
	//self_defined_compare_multiset_practice();
	//pair_practice();
	test_return_from_insert();
	return 0;
}