#pragma once
#include <iostream>

#include <string>

#include "fstream"

#include <Windows.h>

#include"material_tech2.h"

using namespace std;

class Steel_piles :public material_tech2

{

public:

	Steel_piles();
	Steel_piles(const Steel_piles& temp);
	void print_information()override;
	string get_kickbacks()const;
	void set_kickbacks(string kickbacks);
	Steel_piles& operator=(const Steel_piles& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;

protected:

	string kickbacks;

}; 
