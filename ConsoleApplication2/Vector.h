	#pragma once



#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include "material.h"

#include "Exception.h"

using namespace std;

template <class T>

class Vector

{

private:

	T* mas;

public:

	int i;

	Vector(int i) {

		this->i = i;

		mas = new T[i];

	}

	Vector(const Vector<T>& other) {

		i = other.i;

		mas = new T[i];

	}

	void Plus(T&& elem, int j) {

		mas[j] = elem;

		cout << endl;

	}

	T& operator()(int number)

	{

		if (number < 0 || number >= i)throw Exception("Выход за границы массива");

		return mas[number];

	}

	void sort(bool(*cmp)(const T& a, const T& b)) {

		if (i == 0) throw Exception("Объектов нет");

		for (int j = 0; j < i - 1; j++)

			for (int k = i - 1; k > j; k--)

				if (sort_price(mas[k], mas[k - 1])) swap(mas[k], mas[k - 1]);

	}

	int length() const {

		return i;

	}

	void clear() {

		for (int j = 0; j < i; j++)

			mas[j] = 0;

		i = 0;

	}

	void print() {

		if (i == 0) throw Exception("Объектов нет");

		for (int j = 0; j < i; j++)

			mas[j]->print_information();

	}

	template<class C>

	T* Search(C value, bool(*finder)(C value, const T& comp)) {

		if (i == 0) throw Exception("Объектов нет");

		for (int j = 0; j < i; j++)

			if (FindByName(value, mas[j])) return &mas[j];

		return nullptr;

	}
private:
	T** material;
};
