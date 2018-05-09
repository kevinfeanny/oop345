#include "Product.h"


namespace w7 {

	Product::Product(int prodnum, double cst) {
		prodNum = prodnum;
		cost = cst;


	}
	double Product::getCharge() const { return cost; }
	void Product::display(ostream& os) const {
		os << setw(10) << right << prodNum
			<< setw(10) << right << cost << endl;

	}

	TaxableProduct::TaxableProduct(int prodnum, double cst, char tx) {
		prodNum = prodnum;
		cost = cst;
		tax = tx;

	}
	double TaxableProduct::getCharge() const {
		double tx = 1;
		if (tax == 'H') {
			tx = 1.13;

		}
		 if (tax == 'P') {
			tx = 1.08;
		}
		
		return cost * tx;

	}
	void TaxableProduct::display(ostream& os) const {
		os << setw(10) << right << prodNum << setw(10)
			<< right << cost << " ";
		if (tax == 'H') { os << setw(2) << "HST" << endl; }
		else if (tax == 'P') { os << setw(2) << "PST" << endl; }
		else { os << endl; }
	}

	ostream& operator<<(ostream& os, const iProduct& ip) {
		ip.display(os);
		return os;


	}

	iProduct* readProduct(ifstream& is) {
		int num;
		double cost;
		char tx;
		iProduct* ip;

		is >> num >> cost;
		if (is.get() != '\n') {
			is.get(tx);
			ip = new TaxableProduct(num, cost, tx);
		}else{
			ip = new Product(num, cost);
		}

		return ip;

		}







	}





















