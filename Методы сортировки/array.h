#pragma once
#include "init.h"
#include "sort.h"

class RandomArray { // Класс для хранения структуры массива
private:
	SortMethods* sortMethod = nullptr;
	InitTypes* initType = nullptr;

protected:
	const size_t get_numberElem() const;
	const int* get_array() const;

public:
	RandomArray(size_t numberElem = 10U, InitTypes* type = new UnorderedInitType);
	RandomArray(const RandomArray& obj);
	~RandomArray();
	void print() const;
	RandomArray* copy() const;
};
