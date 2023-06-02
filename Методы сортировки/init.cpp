#include <cmath>
#include <ctime>
#include "init.h"

InitTypes::~InitTypes() {
	delete this->array;
}

const size_t InitTypes::get_numberElem() const {
	return this->numberElem;
}

const int* InitTypes::get_array() const {
	return this->array;
}

void UnorderedInitType::init(size_t arrSize) {
	this->array = new int[numberElem = arrSize];
	srand(time(NULL));
	for (int i = 0; i < numberElem; i++) {
		array[i] = rand() % 100 + 1;
	}
}

const arrayType UnorderedInitType::get_arrayType() const {
	return UNORDERED;
}

void AscendingInitType::init(size_t arrSize) {
	this->array = new int[numberElem = arrSize];
	srand(time(NULL));
	for (int i = 0; i < numberElem; i++) {
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
	for (int i = 0; i < numberElem; i++) {
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
