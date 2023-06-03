#include "sort.h"
#include "array.h"

void InclusionSort::sort() {
	for (int i = 1; i < n; i++) {
		int buf = B[i];
		int j = i - 1;

		while (buf < B[j] && j >= 0) {
			B[j + 1] = B[j];
			j--;
		}

		B[j + 1] = buf;
	}
}

void SelectionSort::sort() {

}

void BubbleSort::sort() {

}

void ShellSort::sort() {

}

void HoarSort::sort() {

}

void HeapSort::sort() {

}

void SortMethods::set_array(RandomArray* array) {
	this->array = array;
}
