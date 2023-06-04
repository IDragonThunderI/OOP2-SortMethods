﻿#pragma once
#include "array.h"

class RandomArray;

class SortMethods { // Общий интерфейс для всех методов сортировки
protected:
	RandomArray* randomArray = nullptr;

public:
	void set_array(RandomArray* randomArray);
	const size_t get_numberElem() const;
	int* get_array();

	virtual ~SortMethods();
	
	virtual void sort() = 0;
};

class InclusionSort : public SortMethods {
	void sort() override;
};

class SelectionSort : public SortMethods {
	void sort() override;
};

class BubbleSort : public SortMethods {
	void sort() override;
};

class ShellSort : public SortMethods {
	void sort() override;
};

class HoarSort : public SortMethods {
	void sort() override;

	// Подпрограмма для рекурсивной сортировки Хоара
	void Qsort(int arr[], int f, int l);
};

class HeapSort : public SortMethods {
	void sort() override;

	// Подпрограмма для рекурсивной пирамидальной сортировки
	void Make_heap(int arr[], int L, int R);
};
