#ifndef _Sale_H_
#define _Sale_H_

#include "Product.h"
#include <vector>


namespace w7 {
	class Sale {
		//list of products taxable or not
		vector<iProduct*> iProd;
		//pointer variable to temporarily hold a product before its added to the list
		iProduct* ipr;
	public:
		//constructor to build the list
		Sale(const char*);
		//function to display the list
		void display(ostream&);
		};






}





#endif // !_Sales_

