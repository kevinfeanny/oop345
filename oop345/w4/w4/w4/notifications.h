#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "message.h"


namespace w5 {




	class Notifications {


		vector<Message> msg;

	public:

		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;




	};
}
#endif