#pragma once

class SortMethods { // Класс для хранения методов сортировки
protected:
	RandomArray* array = nullptr;
public:
	virtual void sort() = 0;
	void set_array(RandomArray* array);
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
};

class HeapSort : public SortMethods {
	void sort() override;
};
