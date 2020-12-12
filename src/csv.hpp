
#include <iostream>
#include <string>
#include <vector>

#ifndef CSV_HPP
#define CSV_HPP

using namespace std;

class csvlib
{
private:
	vector<string> column_names;
	vector<vector<string>> column_values;

public:
	csvlib();
	~csvlib();
	void read_csv(string file_path);
	void show_data();
};

#endif
