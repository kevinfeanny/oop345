#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>



using namespace std;

namespace w5 {


	class Message {

				
		string user;
		string reply;
		string tweet;


	public:

		Message(ifstream& in, char c);
		bool empty() const;
		void display(ostream&) const;





	};
}
#endif