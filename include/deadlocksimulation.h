/*
 * deadlocksimulation.h
 *
 *  Created on: 12-Jul-2016
 *      Author: subbu
 */

#ifndef DEADLOCKSIMULATION_H_
#define DEADLOCKSIMULATION_H_

#include "headers.h"

class cDeadLockSimulation{
	static mutex m1,m2;
	static unique_lock<mutex> lck1,lck2;

public:
	static void func(mutex & in1,mutex & in2){

		try {
			unique_lock<mutex> lck1 {in1};
			cout<<this_thread::get_id();
			this_thread::sleep_for(chrono::milliseconds(100));
			unique_lock<mutex> lck2 {in2};
			cout<<"\n this is great"<<this_thread::get_id();
			lck1.unlock();
			lck2.unlock();
		} catch (system_error & e) {
			cout<<e.what()<<e.code();
		}
	}
	void display(){
		cout<<"\n dispaly module";
		thread t1{func,ref(m1),ref(m2)};
		thread t2{func,ref(m1),ref(m2)};
	}
};

mutex cDeadLockSimulation::m1;
mutex cDeadLockSimulation::m2;
unique_lock<mutex> cDeadLockSimulation::lck1;
unique_lock<mutex> cDeadLockSimulation::lck2;

#endif /* DEADLOCKSIMULATION_H_ */
