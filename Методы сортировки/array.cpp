#include <iostream>
#include <chrono>
#include "array.h"
#include "init.h"
#include "sort.h"

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
	this->initType->copy(obj.get_numberElem(), obj.getConst_array());
	this->sortMethod = obj.sortMethod;
}

RandomArray::~RandomArray() {
	delete this->sortMethod;
	delete this->initType;
}

void RandomArray::set_SortMethod(SortMethods* sortMethod) {
	if (this->sortMethod != nullptr) {
		delete this->sortMethod;
	}
	this->sortMethod = sortMethod;
	this->sortMethod->set_array(this);
}

const size_t RandomArray::get_numberElem() const {
	return this->initType->get_numberElem();
}

const int* RandomArray::getConst_array() const {
	return this->initType->get_array();
}

int* RandomArray::get_array() {
	return this->initType->get_array();
}

void RandomArray::print() const {
	size_t n = this->get_numberElem();
	const int* arr = this->getConst_array();

	if (n <= 100) {
		std::cout << "RandomArray = { ";
		for (size_t i = 0; i < n; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "}\n\n";
	}
}

RandomArray* RandomArray::copy() const {
	return new RandomArray(*this);
}

void RandomArray::sort() {
	if (this->sortMethod == nullptr) {
		this->set_SortMethod(new HoarSort);
	}
	this->sortMethod->sort();
}

long long RandomArray::inspectSort() {
	if (this->sortMethod == nullptr) {
		std::cerr << "Не выбран метод сортировки для исследования!\n";
		return -1;
	}
	auto begin = std::chrono::steady_clock::now();
	this->sortMethod->sort();
	auto end = std::chrono::steady_clock::now();

	return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}
