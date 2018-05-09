#include "notifications.h"


namespace w5 {


	Notifications::Notifications() : msg(nullptr), m(0) {

		msg = new Message[SIZE];

	}

	Notifications::Notifications(const Notifications& notifications) : msg(new Message[10]), m(notifications.m) {
		for (int i = 0; i < m; i++) {
			msg[i] = notifications.msg[i];
		}



	}
	Notifications& Notifications::operator=(const Notifications& notifications) {

		if (this != &notifications) {
			if (!msg) {
				msg = new Message[SIZE];
				m = notifications.m;
				for (int i = 0; i < m; i++) {
					msg[i] = notifications.msg[i];
				}
			}
		}
		return *this;
	}
	Notifications::Notifications(Notifications&& notifications) :msg(notifications.msg), m(notifications.m) {
		notifications.msg = nullptr;
		notifications.m = 0;
	

	}
	Notifications&& Notifications::operator=(Notifications&& notifications) {

		if (this != &notifications) {
			m = notifications.m;
			if (msg) {
				delete[] msg;
				msg = notifications.msg;
				m = notifications.m;

				notifications.m = 0;
				notifications.msg = nullptr;
			}
		}
		return move(*this);


	}
	Notifications::~Notifications() {

		delete[] msg;

	}
	void Notifications::operator+=(const Message& message) {
		
		if (m < SIZE) {
			msg[m++] = message;
		}

		

		
	}
	void Notifications::display(std::ostream& os) const {
		
		for (int i = 0; i < m; i++) {
			msg[i].display(os);
		}


	}



}