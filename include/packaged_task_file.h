/*
 * packaged_task_file.h
 *
 *  Created on: 20-Jul-2016
 *      Author: subbu
 */

#ifndef PACKAGED_TASK_FILE_H_
#define PACKAGED_TASK_FILE_H_
#include "headers.h"
#include <future>
#include <chrono>
using get_time = chrono::steady_clock;
using millisecond = chrono::milliseconds;

class cThreadLess{
public:
	static bool fun1(int data){
		//cout<<" \n Thread id :"<<this_thread::get_id()<<"\t :"<<data;
		this_thread::sleep_for(millisecond(1));
		return true;
	}

	void timeslot(){
		auto start = get_time::now();
		for(auto i:{1,2,3,4,5,6}){
			auto val = async( launch::async, fun1 , i);
			auto val1 = async(launch::async, fun1 , i);
			cout<<endl<<val.get() <<val1.get();
		}
		auto diff = get_time::now() - start;
		cout<<"\n Time took is :"<< chrono::duration_cast<millisecond>(diff).count();
	}

};


#endif /* PACKAGED_TASK_FILE_H_ */
