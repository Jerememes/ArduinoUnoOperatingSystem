/*
*          ArduinoUnoOperatingSystem
* file     task.h
* author   Jeremy Rouillard
* Created  05-22-2022
*/


#pragma once
#include <gsl/pointers>


template<typename T> class LinkedTaskList;
template<typename T> class Iterator;
template<typename T>
class Task
{
public:
	Task(const T& data);

private:
	Task* next_ = borders_;
	Task* previous_ = borders_;
	T     data_;

	inline static constexpr Task* borders_ = nullptr;
	
	friend class LinkedTaskList<T>;
	friend class Iterator<T>;
};

