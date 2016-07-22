/*

 * Singleton.cpp
 *
 *  Created on: 14-Jul-2016
 *      Author: subbu
 */

#include "../include/Singleton.h"


shared_ptr<cSingleton> cSingleton::mInstance;
std::once_flag cSingleton::oneflag;

shared_ptr<cSingleton> cSingleton::mGetInstance(){

	call_once(oneflag,
			[&]{
		this_thread::sleep_for(chrono::nanoseconds(1));
		mInstance.reset(new cSingleton);
		cout<<"\n address is "<<mInstance.get();
	}
	);


	return mInstance;
}

cSingleton::~cSingleton(){
	cout<<"\n SIngleton Destructor.";
}

