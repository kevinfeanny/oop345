
#include "Sale.h"


namespace w7 {

	Sale::Sale(const char* name) {
		ifstream is(name);
		while (is.good()) {
			ipr = readProduct(is);
			iProd.push_back(ipr);
			}

	}
	void Sale::display(ostream& os) {
		double sum = 0, dummy;
		os << setw(10) << right << "Product No     " << setw(10)
			<< right << "Cost Taxable \n";
		os << fixed << setprecision(2);
		//iterator to access and print the list and tally up the charge
		for (auto p : iProd) {

			os << *p;
			 sum += p->getCharge();
			

		}
		os << setw(10) << right << "Total" << setw(10) << sum;



	}



}