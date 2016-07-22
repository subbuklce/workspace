/*
 * Ctest.h
 *
 *  Created on: 08-Jul-2016
 *      Author: subbu
 */

#ifndef CTEST_H_
#define CTEST_H_
#include "headers.h"
class Ctest{
private:
	mutex obj;
public:
	void myfunction(){
		for(auto &x: {1,2,3,4,5} ){
			obj.lock();
			cout<<x<<" firstone "<<this_thread::get_id()<<endl;
			obj.unlock();
		}

	}
	void myfunction1(){
		for(auto x: {1,2,3,4,5} ){
			obj.lock();
			cout<<x<<" secondone "<<this_thread::get_id()<<endl;
			obj.unlock();
		}



	}
	void myfunction2(){
		for(auto x: {1,2,3,4,5} ){
			obj.lock();
			cout<<x<<" ThirdOne "<<this_thread::get_id()<<endl;
			obj.unlock();
		}


	}

};


#endif /* CTEST_H_ */
