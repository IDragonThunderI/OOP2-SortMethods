#pragma once
#include "init.h"
#include "sort.h"

class SortMethods;

class RandomArray { // Класс для хранения структуры массива
private:
	InitTypes* initType = nullptr;
	SortMethods* sortMethod = nullptr;

public:
	RandomArray(size_t numberElem = 10, InitTypes* type = new UnorderedInitType);
	RandomArray(const RandomArray& obj);
	~RandomArray();
	
	void set_SortMethod(SortMethods* sortMethod);
	const size_t get_numberElem() const;
	const int* getConst_array() const;
	int* get_array();

	/* Метод prtint() выводит на экран массив, если его размер не превышает 100
	(для предотвращения засорения окна консоли) */
	void print() const;
	RandomArray* copy() const;
	void sort();
	long long inspectSort();
};
