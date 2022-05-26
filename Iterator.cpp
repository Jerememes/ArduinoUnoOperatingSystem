/*
 ArduinoUnoOperatingSystem

 file     Iterator.cpp
 author   Jeremy Rouillard
 Created  05-22-2022
*/


#include "Iterator.hpp"


template<typename T>
Iterator<T>::Iterator(Task<T>* position) : position_(position)

{
	Task<T>* position = Task<T>::borders_;
}


template<typename T>
void Iterator<T>::goForward()
{
	Expects(position_ != nullptr);
	position_ = position_->next_;
}


template<typename T>
void Iterator<T>::goBackward()
{
	Expects(position_ != nullptr);
	position_ = position_->previous_;
}


template<typename T>
inline T& Iterator<T>::operator*()
{
	return position_->data_;
}


template<typename T>
inline Iterator<T>& Iterator<T>::operator++()
{
	Expects(position_ != Task<T>::borders_);
	goForward();
	return *this;
}


template<typename T>
inline Iterator<T>& Iterator<T>::operator--()
{
	Expects(position_ != Task<T>::borders_);
	goBackward();
	return *this;
}