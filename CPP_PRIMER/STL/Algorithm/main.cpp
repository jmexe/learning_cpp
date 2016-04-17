#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <functional>
using namespace std;

/*
	Algorithm -- for_each 
 */
template<class T> struct print : public unary_function<T, void> 
{
	print(ostream& out) : os(out), count(0) {}
	void operator() (T x) {os << x << ' ';  ++count;}
	ostream &os;
	int count;
};


void simple_itr() {
	//for_each
	int A[] = {1, 4, 2, 8, 5, 7};
	const int N = sizeof(A) / sizeof(int);

	print<int> P = for_each(A, A + N, print<int>(cout));
	cout << endl << P.count << " objects printed." << endl;
}

/*
	Algorithm -- find
 */
void find_practice() {
	list<int> L = {1, 3, 5, 7};
	auto itr = find(L.begin(), L.end(), 5);
	assert(2 + 1 == 4);
	assert(itr == L.end() || *itr == 5);
}

/*
	Algorithm -- find_if
	TODO -- bind2nd
 */
void find_if_practice() {
	list<int> L = {1, 3, 5, 7};
	auto itr = find_if(L.begin(), L.end(), 
						bind2nd(greater<int>(), 0));

	assert(*(itr) > 0);
}

/*
	Algorithm -- adjacent_find
	https://www.sgi.com/tech/stl/adjacent_find.html
 */
void adjacent_find_practice() {
	int A[] = {1, 2, 3, 4, 6, 5, 7, 8};
	const int N = sizeof(A) / sizeof(int);
	const int *p = adjacent_find(A, A + N, greater<int>());

	cout << "Element " << p - A << " is out of order: "
		<< *p << " > " << *(p + 1) << "." << endl;
}

/*
	Algorithm -- find_first_of
 */
void find_first_of_practice() {
	const char* WS = "\t\n ";
	const int n_WS = strlen(WS);

	char* s1 = "This sentence contains five words.";
	char* s2 = "OneWord";

	char* end1 = find_first_of(s1, s1 + strlen(s1), WS, WS + n_WS);
	char* end2 = find_first_of(s2, s2 + strlen(s2), WS, WS + n_WS);

	printf("First word of s1: %.*s\n", end1 - s1, s1); 
  	printf("First word of s2: %.*s\n", end2 - s2, s2);
}

/*
	Algorithm -- count
 */
void count_practice() {
	int A[] = {2, 0, 4, 6, 0, 3, 1, -7};
	const int N = sizeof(A) / sizeof(int);

	cout << "Number of zeros: "
		 << count(A, A + N, 0)
		 << endl;
}

/*
	Algorithm -- count_if
	TODO - compose1 bugs
 */
void count_if_practice() {
	int A[] = {2, 0, 4, 6, 0, 3, 1, -7};
	const int N = sizeof(A) / sizeof(int);
	/*
	cout << "Number of even elements: " 
		 << count_if(A, A + N,
		 			compose1(bind2nd(equal_to<int>(), 0),
		 					 bind2nd(modulus<int>(), 2)))
		 << endl;
	*/
}

/*
	Algorithm - mismatch
 */
void mismatch_practice() {
	int A1[] = { 3, 1, 4, 1, 5, 9, 3 };
	int A2[] = { 3, 1, 4, 2, 8, 5, 7 };
	const int N = sizeof(A1) / sizeof(int);

	pair<int*, int*> result = mismatch(A1, A1 + N, A2);
	cout << "The first mismatch is in position " << result.first - A1 << endl;
	cout << "Values are : " << *(result.first) << ", " << *(result.second) << endl;
}

/*
	Predefined function objects -- plus 
 */


/*
	Own functor
 */
template<class T> struct own_functor : public unary_function<T, void> 
{
	own_functor(ostream& out) : os(out), count(0) {}
	void operator() (T x) {os << "current val:" << x << ", be called " << count++ << " times" << endl;}

	ostream &os;
	int count;
};

/*
	Algorithm -- equal
 */
void equal_practice() {
	int A1[] = {3, 1, 4, 1, 5, 9, 3};
	int A2[] = {3, 1, 4, 2, 8, 5, 7};

	const int N = sizeof(A1) / sizeof(int);

	cout << "Result of comparison: " << equal(A1, A1 + N, A2) << endl;
}

/*
	Algorithm -- search
 */
void search_practice() {
	const char S1[] = "Hello, world!";
	const char S2[] = "world";

	const int N1 = sizeof(S1) - 1;
	const int N2 = sizeof(S2) - 1;

	const char* p = search(S1, S1 + N1, S2, S2 + N2);
	printf("Found subsequence \"%s\" at character %d of sequence \"%s\".\n", S2, p - S1, S1);
}

void search_n_practice() {
	const int N = 10;
  	int A[N] = {1, 2, 1, 1, 3, -3, 1, 1, 1, 1};
}

int main(int argc, char const *argv[]) {

	//simple_itr();
	//find_practice();
	//find_if_practice();
	//adjacent_find_practice();
	// find_first_of_practice();
	// count_practice();
	//count_if_practice();

	// own_functor<int> P(cout);
	// P(4);
	//mismatch_practice(); 
	//equal_practice();
	search_practice();	
	return 0;
}

