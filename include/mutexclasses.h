/*
 * mutexclasses.h
 *
 *  Created on: 12-Jul-2016
 *      Author: subbu
 */

#ifndef MUTEXCLASSES_H_
#define MUTEXCLASSES_H_

#include "headers.h"

class Mutex_test{
public:
	static void func(){

		try {
			cout<<endl<<this_thread::get_id();
			ulock.try_lock_for(chrono::milliseconds(1000));
			cout<<endl<<this_thread::get_id();
			for(auto i:{1,2,3,4,5}){
				cout<<"\t Inside func method "<<i;
				//this_thread::sleep_for(chrono::seconds(1));
			}
			ulock.unlock();
		} catch (system_error &e) {
			cout<<"\n Exception: "<<e.what() <<" \t: "
					<<e.code();
			ulock.unlock();
		}
	}

	void display(){

			scope_guard t(func);
			scope_guard t1(func);



	}
private:

	static timed_mutex mtx;
	static unique_lock<timed_mutex> ulock;

};
timed_mutex Mutex_test::mtx;
unique_lock<timed_mutex> Mutex_test::ulock{mtx,defer_lock};



#endif /* MUTEXCLASSES_H_ */
