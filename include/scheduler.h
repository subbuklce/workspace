/*
 * scheduler.h
 *
 *  Created on: 18-Jul-2016
 *      Author: subbu
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "headers.h"
#include <condition_variable>
#include <list>

static int count =0;

void fun(){
	while(count < 1){
		cout<<"\n fun called "<<count;;
		this_thread::sleep_for(chrono::seconds(2));
	}
};


class cScheduler{
	list<thread> q;
	mutex mtx;
	condition_variable cv;
	//unique_ptr<mutex> lck{lck,defer_lcok};

public:
	void put(thread &&t){
		lock_guard<mutex> l{mtx};
		// cv.wait(l);
		q.push_back(move(t));
		cv.notify_one();


	}
	void get(thread &t, chrono::steady_clock::duration d){
		unique_lock<mutex> lck{mtx};
		bool not_empty = cv.wait_for(lck,d,[this]{ return !q.empty();});
		if(not_empty){
			t =move(q.front());
			cout<<"\n Reached get method with thread id:"<<t.get_id();

			q.pop_front();
		}
		else{
			cout<<"\n Timed out";


		}
	}
};

class cMachine{
	cScheduler obj;
public:
	void push_scheduler(){

		thread t(fun);
		obj.put(move(t));
		//this_thread::sleep_for(chrono::milliseconds(2));

		cout<<"\n End of push scheduler";
	};
	void pop_sheduler(){
		try {

			scope_guard t;
			obj.get(ref(t),chrono::seconds(1));
			print(ref(t));

			this_thread::sleep_for(chrono::seconds(2));

			//t.detach();

			cout<<"\n End of Pop scheduler";


		} catch (system_error & e) {
			cout<<e.what()<<" \t "<<e.code();
		}
	}


	void print(thread &t){
		cout<<"\n thread id is "<<t.get_id();
	}
};


#endif /* SCHEDULER_H_ */
