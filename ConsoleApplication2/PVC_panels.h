#pragma once


#include <iostream>
#include <string>
#include "fstream"
#include <Windows.h>
#include"Cement.h"

using namespace std;

class PVC_panels : public Cement
{
public:
	PVC_panels();
	PVC_panels(const PVC_panels& temp);
	void print_information()override;
	int get_leg()const;
	void set_leg(int leg);
	PVC_panels& operator=(const PVC_panels& comp);
	void write_file(string word)override;
	void read_file(ifstream& file)override;
	void zapis()override;
protected:
	int leg;
};
