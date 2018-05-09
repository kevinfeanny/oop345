#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "Utilities.h"

using namespace std;

	size_t Task::field_width;
	//constructor
	Task::Task(const string& pRecord) {
		

		slots = 1; 
		pNextTask[passed] = nullptr;  
		pNextTask[redirect] = nullptr; 


		Utilities extract;

		size_t next_pos = 0;
		bool more = true;
		name = extract.nextToken(pRecord, next_pos, more);
		if (!more) { slots = "1"; }
		if (more) {
			slots = extract.nextToken(pRecord, next_pos, more);
		}
		if (more) {
			nextTask[passed] = extract.nextToken(pRecord, next_pos, more);
		}
		if (more) {
			nextTask[redirect] = extract.nextToken(pRecord, next_pos, more);
		}
		field_width = extract.getFieldWidth();
	
	}
	//return ammount of slots converted to integer
	unsigned int Task::getSlots() const {
		int i = stoi(slots);
		return i;
	}
	//validate function
	bool Task::validate(const Task& task) {
		if (task.name == nextTask[passed]) pNextTask[passed] = &task;
		else if (task.name == nextTask[redirect]) pNextTask[redirect] = &task;

		return (nextTask[passed].empty() || pNextTask[passed]) &&
			(nextTask[redirect].empty() || pNextTask[redirect]);

	}
	//return name
	const string& Task::getName() const {

		return name;
	}
	//display function
	void Task::display(std::ostream& os) const {
		os << "Task Name    : " << std::left << std::setw(field_width + 3) <<
			"[" + name + "]";
			
				os<< "[" << slots << "]" << std::endl;
			
		 

		if (!nextTask[passed].empty()) {
			os << " Continue to : " << std::left << std::setw(field_width + 2) <<
				"[" + nextTask[passed] + "]";
			if (pNextTask[passed] == nullptr) os << " *** to be validated ***";
			os << std::endl;
		}

		if (!nextTask[redirect].empty()) {
			os << " Redirect to : " << std::left << std::setw(field_width + 2) <<
				"[" + nextTask[redirect] + "]";
			if (pNextTask[redirect] == nullptr) os << " *** to be validated ***";
			os << std::endl;
		}
		}
	
	//return field width
	size_t Task::getFieldWidth() {
		
		return field_width;
	}
	// return true if names are the same
	bool operator==(const Task& task_a, const Task& task_b) {
		
		return task_a.getName().compare(task_b.getName()) ? 0 : 1;
	}
	//get next task function
	const Task* Task::getNextTask(Quality pValid) const {
		
		int vi;
		if (pNextTask[0] == nullptr) {
			throw string("*** Validate [" + nextTask[passed] + "]  @  [" + name + "] ***");
		}

		switch (pValid) { 
		case 1:  
			vi = passed;
			break;
		case 0:  
			vi = redirect;
			break;
		}
		return pNextTask[vi];
	}
