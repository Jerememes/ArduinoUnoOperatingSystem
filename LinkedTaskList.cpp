/*
 ArduinoUnoOperatingSystem

 file     LinkedTaskList.cpp
 author   Jeremy Rouillard
 Created  05-22-2022
*/


#include "LinkedTaskList.hpp"


template<typename T>
LinkedTaskList<T>::LinkedTaskList() : head_(Task<T>::borders_),
									  size_(0),
									  tail_(Task<T>::borders_)
{
	//code
}


template<typename T>
LinkedTaskList<T>::~LinkedTaskList()
{
	while (head_ != tail_)
	{
		auto temp = head_;
		head_ = head_->next_;
		delete temp;
	}
	delete tail_;
}


template<typename T>
bool LinkedTaskList<T>::isEmpty() const
{
	return size_ == 0;
}


template<typename T>
unsigned LinkedTaskList<T>::size() const
{
	return size_;
}


template<typename T>
Iterator<T> LinkedTaskList<T>::begin()
{
	return { to_address(head_) };
}


template<typename T>
Iterator<T> LinkedTaskList<T>::end()
{
	return { to_address(tail_->suivant_) };
}


template<typename T>
void LinkedTaskList<T>::push_back(const T& item)
{
	Task<T>* newItem = new Task(item);

	if (isEmpty())
	{
		gsl::owner<Task<T>*> owner = newItem;
		head_ = owner;
	}
	else
	{
		tail_->next_ = newItem;
		newItem->previous_ = tail_;
	}
	tail_ = newItem;
	size_++;
}


template<typename T>
Iterator<T> LinkedTaskList<T>::insert(Iterator<T> it, const T& item)
{
	if (it.position_ == Task<T>::borders_)
	{
		push_back(item);
		return Iterator(tail_);
	}

	Task<T>* newTask = new Task<T>(item);
	Task<T>* after = it.position_;
	Task<T>* before = after->previous_;
	newTask->next_ = after;
	newTask->previous_ = before;
	after->previous_ = newTask;

	if (before == Task<T>::apresDernier_)
	{
		gsl::owner<Task<T>*> owner = newTask;
		head_ = owner;
	}
	else
		before->next_ = newTask;

	size_++;

	return Iterator(newTask);
}


template<typename T>
Iterator<T> LinkedTaskList<T>::erase(Iterator<T> it)
{
	Task<T>* after = it.position_->next_;
	Task<T>* before = it.position_->previous_;

	if (head_ == it)
	{
		gsl::owner<Task<T>*> owner = after;
		head_ = owner;
	}
	else
	{
		before->next_ = after;
		after->previous_ = before;
	}
	delete it.position_;

	size_--;

	return Iterator(after);
}

