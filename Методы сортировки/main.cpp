#include <iostream>
#include <functional>
#include "array.h"
#include "init.h"
#include "sort.h"

// TODO: Реализовать замер времени выполнения сортировки

int main() {
	setlocale(LC_ALL, "ru_RU");

	int arraySize;
	std::cout << "Введите размер массива: ";
	std::cin >> arraySize;
	
	RandomArray* origin = new RandomArray(arraySize);
	origin->print();

	RandomArray* temp = origin->copy();
	temp->set_SortMethod(new InclusionSort);
	std::cout << "InclusionSort:\n";
	temp->sort();
	temp->print();
	
	temp = origin->copy();
	temp->set_SortMethod(new SelectionSort);
	std::cout << "SelectionSort:\n";
	temp->sort();
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new BubbleSort);
	std::cout << "BubbleSort:\n";
	temp->sort();
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new ShellSort);
	std::cout << "ShellSort:\n";
	temp->sort();
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HoarSort);
	std::cout << "HoarSort:\n";
	temp->sort();
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HeapSort);
	std::cout << "HeapSort:\n";
	temp->sort();
	temp->print();

	delete origin;
	delete temp;

	return 0;
}
