#include <iostream>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :
				bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; };
	virtual double net_price(size_t n) const
				{ return n * price; }
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

/*
class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :
				Quote(book, p), min_qty(qty), discount(disc) {};
	double net_price(size_t) const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;

};
*/

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double p, size_t qty, double disc) :
				Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(size_t) const = 0;
protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc) :
						Disc_quote(book, price, qty, disc) {}
	double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}




double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

int main(int argc, char const *argv[]) {
	//Disc_quote discounted;
	Bulk_quote bk = Bulk_quote("1020-123", 20, 15, 0.1);
	Quote qt = Quote("1020-345", 20);
	print_total(cout, qt, 20);
	print_total(cout, bk, 20);
}
