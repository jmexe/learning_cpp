#include "buddy.h"
using namespace std;

int Buddy::cnt = 0;
int Buddy::appeared = 0;

Buddy::Buddy(string tn): name(tn) {
	cnt++;
	appeared++;
}

Buddy::Buddy(const Buddy& buddy) : name(buddy.name) {
	cnt++;
	appeared++;
}

Buddy& Buddy::operator=(const Buddy& buddy){
	name = buddy.name;
	cnt++;
	appeared++;
	return *this;
}

Buddy::~Buddy() {
	cnt--;
}