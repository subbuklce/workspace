/*
 * conditionvariable.cpp
 *
 *  Created on: 18-Jul-2016
 *      Author: subbu
 */

#include "../include/conditionvariable.h"

condition_variable cConditionVariable::cv;
mutex cConditionVariable::mtx;
unique_lock<mutex> cConditionVariable::lck{mtx,defer_lock};

 void cConditionVariable::fun1(){

	cv.wait(lck);
	cout<<"\n this is the fun1";

}

 void cConditionVariable::fun2(){

	cv.wait(lck,[&]{this_thread::sleep_for(chrono::seconds(1));return 1;});
	cout<<"\n this is the fun2";
	cv.notify_all();

}


