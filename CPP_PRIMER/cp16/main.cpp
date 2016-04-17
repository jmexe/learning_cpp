#include <iostream>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main(int argc, char const *argv[]) {
	cout << compare(4, 5) << endl;
	cout << compare("avx", "abc") << endl;
}