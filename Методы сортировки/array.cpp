#include <iostream>
#include "array.h"

const size_t RandomArray::get_numberElem() const {
	return this->initType->get_numberElem();
}

const int* RandomArray::get_array() const {
	return this->initType->get_array();
}

RandomArray::RandomArray(size_t numberElem, InitTypes* type) {
	this->initType = type;
	this->initType->init(numberElem);
}

RandomArray::RandomArray(const RandomArray& obj) {
	switch (obj.initType->get_arrayType()) {
	case UNORDERED:
		this->initType = new UnorderedInitType;
		break;
	case ASCENDING:
		this->initType = new AscendingInitType;
		break;
	case DESCENDING:
		this->initType = new DescendingInitType;
		break;
	}
	this->initType->init(obj.get_numberElem());
}

RandomArray::~RandomArray() {
	delete this->sortMethod;
	delete this->initType;
}

void RandomArray::print() const {
	int n = this->get_numberElem();
	const int* arr = this->get_array();
	if (n <= 100)
	{
		std::cout << "RandomArray = { ";
		for (int i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "}\n\n";
	}
}

RandomArray* RandomArray::copy() const {
	return new RandomArray(*this);
}

void RandomArray::set_SortMethod(SortMethods* sortMethod) {
	if (this->sortMethod != nullptr) {
		delete this->sortMethod;
	}
	this->sortMethod = sortMethod;
	this->sortMethod->set_array(this);
}
