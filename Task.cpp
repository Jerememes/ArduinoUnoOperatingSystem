/*
*          ArduinoUnoOperatingSystem
* file     task.h
* author   Jeremy Rouillard
* Created  05-22-2022
*/


#include "Task.hpp"


template<typename T>
inline Task<T>::Task(const T& data) :data_(data)
{
	//code
}
