#include "notifications.h"


namespace w5 {


	Notifications::Notifications() {

		msg.clear();

	}

	Notifications::Notifications(const Notifications& notifications) {

		msg = notifications.msg;



	}
	Notifications& Notifications::operator=(const Notifications& notifications) {
		if (this != &notifications) {
			msg = notifications.msg;

		}


		return *this;
	}
	Notifications::Notifications(Notifications&& notifications) {

		msg = notifications.msg;
		notifications.msg.clear();
	

	}
	Notifications&& Notifications::operator=(Notifications&& notifications) {

		if (this != &notifications) {
			msg = move(notifications.msg);


		}

		return move(*this);


	}
	Notifications::~Notifications() {

		msg.clear();

	}
	void Notifications::operator+=(const Message& message) {
		
		msg.push_back(message);

		

		
	}
	void Notifications::display(std::ostream& os) const {
		
		for (auto message = msg.begin(); message != msg.end(); ++message) {
			message->display(os);


		}


	}



}