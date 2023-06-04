#include <cmath>
#include <ctime>
#include "init.h"

const size_t InitTypes::get_numberElem() const {
	return this->numberElem;
}

int* InitTypes::get_array() {
	return this->array;
}

void InitTypes::copy(const size_t arrSize, const int* array) {
	this->array = new int[this->numberElem = arrSize];
	for (size_t i = 0; i < numberElem; i++) {
		this->array[i] = array[i];
	}
}

InitTypes::~InitTypes() {
	delete this->array;
}

void UnorderedInitType::init(size_t arrSize) {
	this->array = new int[numberElem = arrSize];
	srand(time(NULL));
	for (size_t i = 0; i < numberElem; i++) {
		array[i] = rand() % 100 + 1;
	}
}

const arrayType UnorderedInitType::get_arrayType() const {
	return UNORDERED;
}

void AscendingInitType::init(size_t arrSize) {
	this->array = new int[numberElem = arrSize];
	srand(time(NULL));
	for (size_t i = 0; i < numberElem; i++) {
		array[i] = rand() % 100 + 1;
	}
	qsort(array, numberElem, sizeof(int),
		[](const void* left, const void* right) {
			return *(int*)left - *(int*)right;
		});
}

const arrayType AscendingInitType::get_arrayType() const {
	return ASCENDING;
}

void DescendingInitType::init(size_t arrSize) {
	this->array = new int[numberElem = arrSize];
	srand(time(NULL));
	for (size_t i = 0; i < numberElem; i++) {
		array[i] = rand() % 100 + 1;
	}
	qsort(array, numberElem, sizeof(int),
		[](const void* left, const void* right) {
			return *(int*)right - *(int*)left;
		});
}

const arrayType DescendingInitType::get_arrayType() const {
	return DESCENDING;
}
