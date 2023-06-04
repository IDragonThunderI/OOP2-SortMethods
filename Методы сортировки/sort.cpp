#include <cmath>
#include "sort.h"
#include "array.h"

void SortMethods::set_array(RandomArray* randomArray) {
	this->randomArray = randomArray;
}

const size_t SortMethods::get_numberElem() const {
	return this->randomArray->get_numberElem();
}

int* SortMethods::get_array() {
	return this->randomArray->get_array();
}

SortMethods::~SortMethods() {

}

void InclusionSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();

	for (int i = 1; i < n; i++) {
		int buf = arr[i];
		int j = i - 1;

		while (buf < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = buf;
	}
}

void SelectionSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();

	for (int i = 0; i < n - 1; i++) {
		int buf = arr[i];
		int min = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < buf) {
				buf = arr[j];
				min = j;
			}
		}

		arr[min] = arr[i];
		arr[i] = buf;
	}
}

void BubbleSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();
	int buf;

	for (int i = 0; i < n - 1; i++) {
		bool isOrdered = true;

		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				buf = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = buf;
				isOrdered = false;
			}
		}

		if (isOrdered) {
			break;
		}
	}
}

void ShellSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();
	int interval_arr[100]{};
	int step = (int)(round(log(n) / log(3)) - 1);

	if (step < 1) {
		step = 1;
	}

	interval_arr[step] = 1;

	for (int k = step; k >= 1; k--) {
		interval_arr[k - 1] = 3 * interval_arr[k] + 1;
	}

	for (int s = 0; s <= step; s++) {
		int curr_interval = interval_arr[s];

		for (int j = curr_interval; j < n; j++) {
			int index = j - curr_interval;
			int buf = arr[j];

			while (index >= 0 && buf <= arr[index]) {
				arr[index + curr_interval] = arr[index];
				index -= curr_interval;
			}

			arr[index + curr_interval] = buf;
		}
	}
}

void HoarSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();

	Qsort(arr, 0, n - 1);
}

void HoarSort::Qsort(int arr[], int f, int l) {
	int first = f, last = l;
	int separator = arr[((first + last) / 2)];

	while (first <= last) {
		while (arr[first] < separator) {
			first++;
		}
		while (arr[last] > separator) {
			last--;
		}
		if (first <= last) {
			int buf = arr[first];
			arr[first] = arr[last];
			arr[last] = buf;
			first++;
			last--;
		}
	}

	if (f < last) {
		Qsort(arr, f, last);
	}
	if (first < l) {
		Qsort(arr, first, l);
	}
}

void HeapSort::sort() {
	size_t n = get_numberElem();
	int* arr = get_array();
	int L = n / 2;
	int R = n - 1;

	while (L > 0) {
		L--;
		Make_heap(arr, L, R);
	}

	while (R > 0) {
		int buf = arr[0];
		arr[0] = arr[R];
		arr[R] = buf;
		R--;
		Make_heap(arr, L, R);
	}
}

void HeapSort::Make_heap(int arr[], int L, int R)
{
	int i = L;
	int j = 2 * L + 1;
	int x = arr[L];

	if ((j < R) && (arr[j] < arr[j + 1])) {
		j++;
	}

	while ((j <= R) && (x < arr[j])) {
		int buf = arr[i];
		arr[i] = arr[j];
		arr[j] = buf;
		i = j;
		j = 2 * j + 1;
		if ((j < R) && (arr[j] < arr[j + 1])) {
			j++;
		}
	}
}
