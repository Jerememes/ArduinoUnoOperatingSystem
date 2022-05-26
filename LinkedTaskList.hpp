/*
*          ArduinoUnoOperatingSystem
* file     LinkedTaskList.h
* author   Jeremy Rouillard
* Created  05-22-2022
*/

#pragma once

#include "Iterator.hpp"
#include "gsl/gsl_assert"

template<typename T> class Iterator;
template<typename T>
class LinkedTaskList
{
public:
	LinkedTaskList();
	~LinkedTaskList();

	bool        isEmpty() const;
	unsigned    size() const;

	Iterator<T> begin();
	Iterator<T> end();
	
	void        push_back(const T& item);
	Iterator<T> insert(Iterator<T> it, 
					   const T&    item);
	Iterator<T> erase(Iterator<T> it);


private:
	gsl::owner<Task<T>*> head_;
	Task<T>* tail_;
	unsigned size_;
	friend class Iterator<T>;
};
