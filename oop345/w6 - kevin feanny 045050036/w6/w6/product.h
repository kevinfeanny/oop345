#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
//Kevin feanny w6
// Workshop 6 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

namespace w7 {
	//base class
	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	class Product :public iProduct {
		int prodNum;
		double cost;
	public:
		//constructor 
		Product(int, double);
		//helper function returning cost
		double getCharge() const;
		//display function to print to screen variables
		void display(ostream& os) const;

	};
	class TaxableProduct :public iProduct {
		int prodNum;
		double cost;
		char tax;
	public:
		//constructor
		TaxableProduct(int, double, char);
		//helper function to calculate cost + tax 
		double getCharge() const;
		//display function to print to screen variables
		void display(ostream&) const;




	};




	//function to print either a taxable product or a product with no tax to the screen
	std::ostream& operator<<(std::ostream&, const iProduct&);
	//function to read from a text file a list of products their cost and if they're taxable
	iProduct* readProduct(std::ifstream&);

}

#endif
