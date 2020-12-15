#include <iostream>
#include "../src/csv.hpp"

using namespace std;

int main()
{
	csvlib mycsv;
	vector<string> col_names = {"Name", "Class", "Subject", "Marks"};
	vector<vector<string>> row_values = {
		{"ABC", "10", "Math", "95"},
		{"DEF", "9", "English", "80"},
		{"PQR", "9", "History", "92"},
		{"XYZ", "10", "Geography", "98"}
	};
	string file_name = "Students.csv";
	mycsv.to_csv(col_names, row_values, file_name);
}
