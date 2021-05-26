#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"Cement.h"

using namespace std;

class Bitumen :public Cement

{

public:

	Bitumen();

	Bitumen(const Bitumen& temp);

	void print_information()override;

	string get_softness()const;

	void set_softness(string softness);

	Bitumen& operator=(const Bitumen& comp);

	void write_file(string word)override;

	void read_file(ifstream& file)override;

	void zapis()override;

protected:

	string softness;

};