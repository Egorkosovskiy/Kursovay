#pragma once


#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

using namespace std;

class Exception {

public:

	Exception()

	{

		oshibka = "Îøèáêà";

	}

	Exception(const string oshibka)

	{

		this->oshibka = oshibka;

	}

	const string get_error() const

	{

		return oshibka;

	}

private:

	string oshibka;

};