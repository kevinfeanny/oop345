#include <vector>
#include "Item.h"
#include "ItemManager.h"

using namespace std;
//display function to print to the screen
void ItemManager::display(ostream& os, bool full) const  {

	for (size_t i = 0; i < vector<Item>::size(); i++) {

		vector<Item>::at(i).display(os, full);

	}


}