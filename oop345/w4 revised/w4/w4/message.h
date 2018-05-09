#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>



using namespace std;

namespace w5 {


	class Message {

				
		string user;
		string reply;
		string tweet;


	public:
		//constructor safe state
		Message();
		//construcor to build message
		Message(ifstream& in, char c);
		//check if ts in a safe state
		bool empty() const;
		//display
		void display(ostream&) const;





	};
}
#endif