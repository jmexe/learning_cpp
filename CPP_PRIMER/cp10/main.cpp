#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void find_practice() {
	vector<string> strs = {"abc", "test", "know"};
	auto result = find(strs.cbegin(), strs.cend(), "abc");
	cout << *result << endl;
}

void accumulate_practice() {
	vector<int> vec = {1, 2, 3};
	int result = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << result << endl;
	vector<string> v = {"abv", "qerw"};
	cout << accumulate(v.cbegin(), v.cend(), string("")) << endl;
}

void equal_practice() {
	vector<int> arr1 = {1, 2, 3};
	vector<int> arr2 = {1, 2, 3, 1};
	vector<int> arr3 = {3, 1, 2};
	vector<int> arr4 = {1, 2, 3};

	cout << equal(arr2.begin(), arr2.end(), arr1.cbegin()) << endl;
}

void fill_practice() {
	vector<int> v = {1, 2, 3, 4};
	fill(v.begin(), v.end(), 0);
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << endl;

	fill_n(v.begin(), 3, -1);
	for (auto &i : v) {
		cout << i << " ";
	}
	cout << endl;

}

void back_inserter_practice() {
	vector<int> v = {1, 2, 3};
	auto it = back_inserter(v);

	fill_n(back_inserter(v), 3, -1);

	*it = 100;

	for (auto &i : v) {
		cout << i << " ";
	}

	cout << endl;
}

void eliminating_practice() {
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	for (auto it = words.begin(); it != words.end(); it++) {
		cout << *it++ << endl;
	}
}

void reverse_itr_practice() {
	vector<string> words = {"a", "b", "c"};
	for (auto itr = words.rbegin(); itr != words.crend(); itr++) {
		cout << *itr << " ";
	}	
	cout << endl;
}

int main(int argc, char const *argv[])
{
	//find_practice();
	//accumulate_practice();
	//equal_practice();
	//fill_practice();
	//back_inserter_practice();
	//eliminating_practice();
	reverse_itr_practice();
	return 0;
}