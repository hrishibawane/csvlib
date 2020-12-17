#include "../src/csv.hpp"

int main()
{
	hcsv::csvlib mycsv;
	mycsv.read_csv("test.csv");
	printf("\nHEAD:\n");
	mycsv.head(5);
	printf("\nTAIL:\n");
	mycsv.tail(6);
	
	printf("\nCOLS:\n");
	vector<string> cols = mycsv.get_columns();
	printf("\nROWS:\n");
	vector<vector<string>> rows = mycsv.get_rows();
	printf("\nLOC:\n");
	vector<string> row_loc = mycsv.loc(13);
	printf("\nCOL_DATA:\n");
	vector<string> col_data = mycsv.get_column_values("Salary");
	printf("\nUNIQUE:\n");
	vector<string> unique_val = mycsv.unique("Location");
	for (auto &s : unique_val)
	{
		printf("%-5s, ", s.c_str());
	}

	hcsv::csvlib newobj = mycsv;
	printf("\nNew Obj HEAD:\n");
	newobj.head();
}
