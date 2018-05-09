#include <iomanip>
#include <iostream>
#include "CustomerItem.h"
#include "Item.h"

using namespace std;
//Constructor to create customeritem
CustomerItem::CustomerItem(const string& Pname) {

	name = "";
	if (!Pname.empty()) {
		name = Pname;
		}
	filled = false;
	code = 0;
}
//returns true if the names match
bool CustomerItem::asksFor(const Item& item) const { return name == item.getName() ? true : false; }
//return filled
bool CustomerItem::isFilled() const { return filled; }
//set code and filled
void CustomerItem::fill(const unsigned int fill) { code = fill; filled = true; }
//clear code set filled to false
void CustomerItem::clear() { code = 0; filled = false; }
//return name
const string& CustomerItem::getName() const { return name; }
//prnt a customeritem to the screen
void CustomerItem::display(ostream& os) const {

	if (isFilled()) { os << " + "; }
	else { os << " - "; }

	os << "[" << std::setw(CODE_WIDTH) << std::setfill('0') << std::right << code << "]  " << name << std::endl;



}