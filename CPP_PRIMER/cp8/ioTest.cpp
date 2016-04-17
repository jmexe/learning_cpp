#include <iostream> // Read from and Write to a stream
#include <fstream>	// Read & Write named files
#include <sstream>	// Read & Write in-memory string
#include <vector>
using namespace std;
using std::vector;
struct PersonInfo
{
	string name;
	vector<string> phones;
};

void string_istream() {
	string line, word;
	vector<PersonInfo> people;
	int cnt = 3;

	while (getline(cin, line) && cnt-- > 0) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word) 
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto &entry : people) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else 
				formatted << "" << format(nums);
		}

		if (badNums.str().empty()) 
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name << "invalid number(s)" << badNums.str() << endl;
	}
}


int main(int argc, char const *argv[])
{
	string_istream();
	return 0;
}