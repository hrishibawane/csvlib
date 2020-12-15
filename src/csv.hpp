
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifndef CSV_HPP
#define CSV_HPP
#define DEFAULT_ROWS 10

using namespace std;

class csvlib
{
private:
	vector<string> column_names;
	vector<vector<string>> column_values;
	unordered_map<string, long int> column_index;

	void show_data(long int rows);

public:
	/*
	 * Constructor
	 */
	csvlib();

	/*
	 * Destructor
	 */
	~csvlib();

	/*
	 * Read csv file
	 */
	void read_csv(string file_path);

	/*
	 * Display csv data 
	 */
	void show();

	/*
	 * Display top n rows 
	 */
	void head(long int rows = DEFAULT_ROWS);

	/*
	 * Display bottom n rows  
	 */
	void tail(long int rows = DEFAULT_ROWS);
	vector<string> get_columns();
	vector<vector<string>> get_rows();
	vector<string> loc(long int index);
	vector<string> get_column_values(string col_name);

	/*
	 * Get all unique data from a column in order of their appearance
	 */
	vector<string> unique(string col_name);
};

#endif
