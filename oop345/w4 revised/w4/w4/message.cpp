#include "message.h"
namespace w5 {

	Message::Message() {}
	Message::Message(ifstream& in, char c) {

		string line, dummy;
		getline(in, line, c);
		istringstream is(line);

		if (user.empty()) {
			is >> user;
			if ((int)user.find('@') > 0) {
				user.clear();
			}
			
		}
		if (reply.empty()) {
			is >> reply;
			
			if ((int) reply.find('@') < 0) {
				is.seekg(0, ios::beg);
				is >> dummy;
				getline(is, tweet);
				reply.clear();
			}
			
				
			
		}
		if (tweet.empty()) {
			getline(is, tweet);
		}
		is.clear();

		}


	bool Message::empty() const {

		return user.empty() || tweet.empty();


	}

	void Message::display(ostream& os) const {


		os << "Message" << endl;
		    os << "User  : " << user << endl;
		if (!reply.empty()) {

			os << "Reply : "  ;
			for (int i = 1; reply[i] != '\0'; i++) {
				os << reply[i];
			}
			os << endl;

		}
		    os << "Tweet :" << tweet << endl;
		os << endl;







	}





}