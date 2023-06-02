#pragma once

enum arrayType {
	UNORDERED = 0,
	ASCENDING,
	DESCENDING
};

class InitTypes { // Класс для хранения типов инициализации массива
protected:
	int* array = nullptr;
	size_t numberElem = 0U;

public:
	virtual ~InitTypes();
	virtual void init(size_t) = 0;
	virtual const arrayType get_arrayType() const = 0;
	const size_t get_numberElem() const;
	const int* get_array() const;
};

class UnorderedInitType : public InitTypes { // Класс для инициализации неупорядоченного массива
public:
	void init(size_t) override;
	const arrayType get_arrayType() const override;
};

class AscendingInitType : public InitTypes { // Класс для инициализации массива, упорядоченного по возрастанию
public:
	void init(size_t) override;
	const arrayType get_arrayType() const override;
};

class DescendingInitType : public InitTypes { // Класс для инициализации массива, упорядоченного по убыванию
public:
	void init(size_t) override;
	const arrayType get_arrayType() const override;
};
