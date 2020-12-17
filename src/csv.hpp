
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifndef CSV_HPP
#define CSV_HPP
#define DEFAULT_ROWS 10

using namespace std;

namespace hcsv
{
	class csvlib
	{
	private:
		vector<string> column_names;
		vector<vector<string>> column_values;
		unordered_map<string, long int> column_index;

		void show_data(long int rows);

	public:
		/*
		 * Constructors
		 */
		csvlib();

		csvlib(const csvlib &obj);

		/*
		 * Destructor
		 */
		~csvlib();

		/*
		 * Read csv file
		 * @param file_path: path to the csv file.
		 */
		void read_csv(string file_path);

		/*
		 * Display csv data.
		 */
		void show();

		/*
		 * Display first N rows
		 * @param rows: no. of rows to be printed.
		 */
		void head(long int rows = DEFAULT_ROWS);

		/*
		 * Display bottom n rows
		 * @param rows: no. of rows to be printed.
		 */
		void tail(long int rows = DEFAULT_ROWS);

		/*
		 * Get column names
		 * returns vector of column names.
		 */
		vector<string> get_columns();

		/*
		 * Get rows of the csv data
		 * returns vector of rows where each row is a vector of values.
		 */
		vector<vector<string>> get_rows();

		/*
		 * Get row at specific location
		 * @param index: index of the row
		 * returns vector of row values at location index.
		 */
		vector<string> loc(long int index);

		/*
		 * Get all values of a specific column
		 * @param col_name: name of the column
		 * returns vector of values pertaining to column col_name
		 */
		vector<string> get_column_values(string col_name);

		/*
		 * Get all unique values from a column in order of their appearance
		 * @param col_name: name of the column
		 * returns vector of unique values of column col_name
		 */
		vector<string> unique(string col_name);

		/*
		 * Create a csv file from given data
		 * @param col_names: vector of column names
		 * @param row_values: vector of rows where each row is a vector of values
		 * @param file_name: name of the csv file to be created
		 */
		void to_csv(vector<string> col_names, vector<vector<string>> row_values, string file_name);
	};
}

#endif
