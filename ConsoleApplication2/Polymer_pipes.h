#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech2.h"

using namespace std;

class Polymer_pipes :public material_tech2

{

public:

	Polymer_pipes();
	Polymer_pipes(const Polymer_pipes& holod);
	void print_information()override;
	int get_kam()const;
	void set_kam(int kam);
	Polymer_pipes& operator=(const Polymer_pipes& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;

protected:

	int kam;

};