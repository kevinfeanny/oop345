#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Item.h"
#include "Utilities.h"

using namespace std;

size_t CustomerOrder::field_width;
//constructor to create a customerorder 
CustomerOrder::CustomerOrder(const std::string& precord)
	: name(""), product(""), order(nullptr), nOrders(0) {
	size_t position = 0;
	bool more = true;

	Utilities u;
	name = u.nextToken(precord, position, more);
	if (!name.empty()) {
		if (more) {
			product = u.nextToken(precord, position, more);
		}

		std::vector<std::string> input;
		while (more) {
			std::string t = u.nextToken(precord, position, more);
			if (t.size() > 0) {
				input.push_back(t);
			}
		}

		nOrders = input.size();
		order = new CustomerItem[nOrders];
		for (int i = 0; i < nOrders; i++) {
			order[i] = CustomerItem(input[i]);
		}

		field_width = u.getFieldWidth();
	}
}
//forbidden copy constuctor
CustomerOrder::CustomerOrder(const CustomerOrder& n)
{
	

	throw std::string("the copy constructor should never be called");


}
//move constuctor
CustomerOrder::CustomerOrder(CustomerOrder&& n) NOEXCEPT
{
	order = nullptr;
	*this = std::move(n);
}
//move operator constuctor
CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& n) NOEXCEPT
{
	if (this != &n)
	{
		if (order)
			delete[] order;

		name = n.name;
		product = n.product;
		nOrders = n.nOrders;
		order = n.order;
		
		n.name.clear();
		n.product.clear();
		n.nOrders = 0;
		n.order = nullptr;
	}

	return std::move(*this);
}
//destructor
CustomerOrder::~CustomerOrder() {
	
	delete[] order;
}
// return numbe rof orders norders
unsigned int CustomerOrder::noOrders() const { return nOrders; }
//operator [] overload to see if the name exists then returns name
const string& CustomerOrder::operator[](unsigned int i) const {
	try {
		string Cname;
		Cname = order[i].getName();

	}
	catch (...) {

	}
	return name;


}
//Add item to customer order
void CustomerOrder::fill(Item& item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].asksFor(item)) {
			order[i].fill(item.getCode());
			item++;
		}
	}
}
//remove item from  customer order
void CustomerOrder::remove(Item& item) {

	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			nOrders--;
		}
	}



}
//if order is empty return true
bool CustomerOrder::empty() const { return (order == nullptr) ? true : false; }
//display customer order to the screen
void CustomerOrder::display(ostream& os) const {

	os << std::setw(field_width) << std::setfill(' ') << std::left << name << " :  " << product << std::endl;
	for (unsigned int i = 0; i < nOrders; i++) {
		order[i].display(os);
	}



}
