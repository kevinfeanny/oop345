#include <algorithm>
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"
#include "Item.h"

using namespace std;
//extract function
CustomerOrder&& OrderManager::extract() {
	return std::move(vector<CustomerOrder>::back());
}
//validate order
void OrderManager::validate(const ItemManager& itemMng, std::ostream& os) {

	std::vector<CustomerOrder>::iterator iter = this->begin();
	for (; iter != this->end(); iter++) {
		for (unsigned int i = 0; i < iter->noOrders(); i++) {
			auto lamda_vaildate = [&](const Item& item) {
				return item.getName().compare((*iter)[i]);
			};

			if (std::find_if(itemMng.cbegin(), itemMng.cend(), lamda_vaildate) == itemMng.cend()) {
				os << (*iter)[i] << " is unavailable " << std::endl;
			}
		}
	}

}
//display function to prin t to the screen
void OrderManager::display(std::ostream& os) const
{
	std::vector<CustomerOrder>::const_iterator iter = this->cbegin();
	//	auto iter = this->cbegin();
	for (; iter != this->cend(); iter++) {
		iter->display(os);
	}

}