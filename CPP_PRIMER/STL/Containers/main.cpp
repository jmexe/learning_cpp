#include <iostream>

using namespace std;

/*
	Containers -- hash
	Default hash function by all Hashed Associated Containers
 */
void hash_practice() {
	hash<const char*> H;
	cout << "foo -> " << H("foo") << endl;
	cout << "bar -> " << H("bar") << endl;
}

int main(int argc, char const *argv[]) {
	hash_practice();
}