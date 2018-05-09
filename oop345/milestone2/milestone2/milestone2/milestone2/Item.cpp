#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

using namespace std;

size_t Item::field_width = 0;
//create am item
Item::Item(const string& record) {

	code = 1;

	size_t next_pos = 0;
	bool more = true;
	Utilities u;
	size_t pos = 0;
	name = u.nextToken(record, pos, more);

	if (field_width < u.getFieldWidth()) {
		field_width = u.getFieldWidth();
	}
	try {
		if (more) { filler = u.nextToken(record, pos, more); }
		if (more) { remover = u.nextToken(record, pos, more); }
		if (more) { code = stoi(u.nextToken(record, pos, more)); }
		if (more) { description = u.nextToken(record, pos, more); }
	}
	catch (...) {
		throw string(record + " <-- *** no token found before the delimiter ***");
	}
	if (name.empty() || filler.empty() || remover.empty()) {
		throw string("***No Token found before the delimiter ***");



	}
}
//check if its empty
bool Item::empty() const {
	bool i;
	if (name == "") {
		i = true;
	}
	else {
		i = false;
	}
	return i;
}
//operator to adda  item toa list
Item& Item::operator++(int n) {

	Item temp = *this;
	code++;
	return temp;
}
//return code
unsigned int Item::getCode() const { return code; }
//return name
const string& Item::getName() const { return name; }
//return filler
const string& Item::getFiller() const { return filler; }
//return remover
const string& Item::getRemover() const { return remover; }
//print an item on screen
void Item::display(std::ostream& os, bool more) const {
	
	os << std::setfill(' ');
	os << std::setw(field_width) << std::left << name << "[" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "] From " <<
		std::setw(field_width) << std::left << std::setfill(' ') << filler << " To " << remover << std::endl <<
		std::setw(field_width + CODE_WIDTH + 3) << std::right << ": " << description << std::endl;


}