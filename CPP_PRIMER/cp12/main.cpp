#include "StrBlob.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  StrBlob sb({"abc", "123", "test"});

  cout << sb.front() << sb.back() << endl;
}
