#include <iostream>
#include <chrono>
#include <iomanip>
#include "array.h"
#include "init.h"
#include "sort.h"

int main() {
	setlocale(LC_ALL, "ru_RU");

	int arraySize;
	std::cout << std::fixed << "Введите размер массива: ";
	std::cin >> arraySize;
	
	RandomArray* origin = new RandomArray(arraySize);

	

	RandomArray* temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new InclusionSort);
	std::cout << "InclusionSort:\n";
	long long elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();
	
	temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new SelectionSort);
	std::cout << "SelectionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";

	temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new BubbleSort);
	std::cout << "BubbleSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new ShellSort);
	std::cout << "ShellSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";

	temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new HoarSort);
	std::cout << "HoarSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->print();
	temp->set_SortMethod(new HeapSort);
	std::cout << "HeapSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";

	delete origin;
	delete temp;

	return 0;
}
