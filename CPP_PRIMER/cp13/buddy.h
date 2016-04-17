#ifndef __MJ_CP13_BUDDY_H
#define __MJ_CP13_BUDDY_H
#include <iostream>

class Buddy {
public:
	static int cnt;
	static int appeared;
	std::string name;
	
	Buddy(std::string name);
	Buddy(const Buddy& buddy);

	Buddy& operator=(const Buddy&);
	~Buddy();
};


#endif