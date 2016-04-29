#include <iostream>
#include <string>
using namespace std;

void check_empty(shared_ptr<int> &p) {
  //p is used as a condition
  if (p)
    cout << "Initialized, with value of " << *p << ", use of " << p.use_count() << endl;
  else
    cout << "Not Initialized" << endl;
}

void initialize() {
  shared_ptr<int> p; //= make_shared<int>(42);
  check_empty(p);

  p = make_shared<int>(1);
  check_empty(p);

  cout <<  "---------" << endl;
  auto q(p);
  check_empty(p);
  check_empty(q);

  cout <<  "---------" << endl;
  *q = 2;

  auto &r = q;
  //print 2
  check_empty(p);
  check_empty(q);
  check_empty(r);

  cout <<  "---------" << endl;
  r = make_shared<int>(3);
  //print 2
  check_empty(p);
  //print 3
  check_empty(q);
  //print 3
  check_empty(r);

  cout <<  "---------" << endl;
  auto t = q;
  check_empty(t);
}

void process(shared_ptr<int> p) {
  cout << *p << endl;
}
void donotmix() {
  int *x(new int(42));
  process(shared_ptr<int>(x));
  cout << *x << endl;
  int j = *x;
  //delete x;
  cout << j << endl;
}

void moreoperations() {
  shared_ptr<int> p = make_shared<int>(3);
  auto q = p;
  cout << p.use_count() << endl;

  p.reset(new int(45));
  cout << *q << endl;
  //cout << q.unique() << endl;
}

void uniquept() {
  unique_ptr<int> p1(new int(42));
  p1.reset(new int(46));
  cout << *p1 << endl;

  unique_ptr<int> p2(p1.release());
  unique_ptr<int> p3;
  p3.reset(p2.release());
  cout << *p3 << endl;
}

int main(int argc, char const *argv[]) {
  //donotmix();
  //moreoperations();
  uniquept();
  return 0;
}
