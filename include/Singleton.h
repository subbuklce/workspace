/*
 * Singleton.h
 *
 *  Created on: 14-Jul-2016
 *      Author: subbu
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include "headers.h"

class cSingleton{
public:
	static shared_ptr<cSingleton> mGetInstance();
	virtual ~cSingleton();
private:
	static std::once_flag oneflag;
	static shared_ptr<cSingleton> mInstance;
	//cSingleton()=delete;
	cSingleton(){};
	cSingleton(const cSingleton &) = delete;
	cSingleton& operator=(const cSingleton&)=delete;

};



#endif /* SINGLETON_H_ */
