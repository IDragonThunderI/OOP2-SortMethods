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
	
	/*================================ НЕУПОРЯДОЧЕННЫЙ МАССИВ ================================*/
	std::cout << "\n================================ Сортировка неупорядоченного массива: ================================\n\n";

	RandomArray* origin = new RandomArray(arraySize);
	origin->print(); /* Метод prtint() выводит на экран массив, если его размер не превышает 100
	(для предотвращения засорения окна консоли) */

	RandomArray* temp = origin->copy();
	temp->set_SortMethod(new InclusionSort);
	std::cout << "InclusionSort:\n";
	long long elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();
	
	temp = origin->copy();
	temp->set_SortMethod(new SelectionSort);
	std::cout << "SelectionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new BubbleSort);
	std::cout << "BubbleSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new ShellSort);
	std::cout << "ShellSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HoarSort);
	std::cout << "HoarSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HeapSort);
	std::cout << "HeapSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	/*================================ МАССИВ УПОРЯДОЧЕННЫЙ ПО ВОЗРАСТАНИЮ ================================*/
	std::cout << "\n================================ Сортировка массива, упорядоченного по возрастанию: ================================\n\n";

	origin = new RandomArray(arraySize, new AscendingInitType);
	origin->print();

	temp = origin->copy();
	temp->set_SortMethod(new InclusionSort);
	std::cout << "InclusionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new SelectionSort);
	std::cout << "SelectionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new BubbleSort);
	std::cout << "BubbleSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new ShellSort);
	std::cout << "ShellSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HoarSort);
	std::cout << "HoarSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HeapSort);
	std::cout << "HeapSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	/*================================ МАССИВ УПОРЯДОЧЕННЫЙ ПО УБЫВАНИЮ ================================*/
	std::cout << "\n================================ Сортировка массива, упорядоченного по убыванию: ================================\n\n";

	origin = new RandomArray(arraySize, new DescendingInitType);
	origin->print();

	temp = origin->copy();
	temp->set_SortMethod(new InclusionSort);
	std::cout << "InclusionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new SelectionSort);
	std::cout << "SelectionSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new BubbleSort);
	std::cout << "BubbleSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new ShellSort);
	std::cout << "ShellSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HoarSort);
	std::cout << "HoarSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	temp = origin->copy();
	temp->set_SortMethod(new HeapSort);
	std::cout << "HeapSort:\n";
	elapsedTime = temp->inspectSort();
	std::cout << "Затраченное время: " << std::setprecision(3) << (double)elapsedTime / 1000.0 << " с. (" << elapsedTime << " мс.)\n";
	temp->print();

	delete origin;
	delete temp;

	return 0;
}
