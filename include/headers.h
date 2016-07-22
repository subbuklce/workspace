/*
 * headers.h
 *
 *  Created on: 08-Jul-2016
 *      Author: subbu
 */

#ifndef HEADERS_H_
#define HEADERS_H_

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include<memory>
using namespace std;

struct scope_guard:thread{
	using thread::thread;
	~scope_guard(){
		if(joinable())
			join();
	}
};


#endif /* HEADERS_H_ */
