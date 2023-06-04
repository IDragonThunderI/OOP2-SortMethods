#pragma once

enum arrayType {
	UNORDERED = 0,
	ASCENDING,
	DESCENDING
};

class InitTypes { // Общий интерфейс для всех типов инициализации массива
protected:
	int* array = nullptr;
	size_t numberElem = 0;

public:
	const size_t get_numberElem() const;
	int* get_array();
	void copy(const size_t arrSize, const int* array);

	virtual ~InitTypes();

	virtual void init(size_t numberELem) = 0;
	virtual const arrayType get_arrayType() const = 0;
};

class UnorderedInitType : public InitTypes { // Класс для инициализации неупорядоченного массива
public:
	void init(size_t numberElem) override;
	const arrayType get_arrayType() const override;
};

class AscendingInitType : public InitTypes { // Класс для инициализации массива, упорядоченного по возрастанию
public:
	void init(size_t numberElem) override;
	const arrayType get_arrayType() const override;
};

class DescendingInitType : public InitTypes { // Класс для инициализации массива, упорядоченного по убыванию
public:
	void init(size_t numberElem) override;
	const arrayType get_arrayType() const override;
};
