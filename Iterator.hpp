/*
 ArduinoUnoOperatingSystem

 file     Iterator.h
 author   Jeremy Rouillard
 Created  05-22-2022
*/

#pragma once

#include "Task.hpp"
#include "gsl/gsl_assert"
#include "gsl/span"

template<typename T>
class Iterator
{
public:
	Iterator(Task<T>* position);

	void goForward();
	void goBackward();

	T& operator*();
	bool operator==(const Iterator<T>& it) const = default;
	Iterator& operator++ ();
	Iterator& operator-- ();


private:
	Task<T>* position_;
	friend class LinkedTaskList<T>;
};

