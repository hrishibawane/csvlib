#include "../src/csv.hpp"

int main()
{
	csvlib mycsv;
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
	vector<string> col_data = mycsv.get_column_values("Date");
	for (auto &s : col_data)
	{
		printf("%-5s ", s.c_str());
	}
}
