#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "message.h"

#define SIZE 10

namespace w5 {




	class Notifications {


		Message* msg;
		int m;

	public:
		//constructor
		Notifications();
		//copy constructor
		Notifications(const Notifications&);
		//operator overload for copy constructor
		Notifications& operator=(const Notifications&);
		//move constructor
		Notifications(Notifications&&);
		//move overloaded operator
		Notifications&& operator=(Notifications&&);
		//destructor
		~Notifications();
		//operator to add messages
		void operator+=(const Message& msg);
		//display
		void display(std::ostream& os) const;




	};
}
#endif