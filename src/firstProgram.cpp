//============================================================================
// Name        : firstProgram.cpp
// Author      : Subrahmanyam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../include/Ctest.h"
#include "../include/mutexclasses.h"
#include "../include/deadlocksimulation.h"
#include "../include/Singleton.h"
#include "../include/conditionvariable.h"
#include "../include/scheduler.h"
#include "../include/packaged_task_file.h"

int main(){

	try {
		Mutex_test obj;
		//obj.display();
		cDeadLockSimulation obj1;
		//obj1.display();


		//shared_ptr<cSingleton> ptr = cSingleton::mGetInstance();

		//cConditionVariable obj;
		//scope_guard t1(cConditionVariable::fun1),t2(cConditionVariable::fun2);

/*
		cMachine machine;
		machine.push_scheduler();
		machine.pop_sheduler();
*/
cThreadLess theadlessobj ;
theadlessobj.timeslot();
	} catch (system_error & e) {
		cout<<e.what()<<e.code();
	}




	return 0;
}
