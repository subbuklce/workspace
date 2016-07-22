/*
 * conditionvariable.h
 *
 *  Created on: 18-Jul-2016
 *      Author: subbu
 */

#ifndef CONDITIONVARIABLE_H_
#define CONDITIONVARIABLE_H_
#include "headers.h"
#include <condition_variable>

class cConditionVariable{

	static condition_variable cv;
	static mutex mtx;
	static unique_lock<mutex> lck;
public:
	static void fun1();
	static void fun2();
};




#endif /* CONDITIONVARIABLE_H_ */
