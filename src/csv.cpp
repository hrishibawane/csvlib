
#include "csv.hpp"
#include <cstdlib>
#include <climits>
#include <cstring>
#include <sstream>
#define MAX 0xFFFF

////////////////////////////////////////////////////////////

namespace hcsv
{
	csvlib::csvlib() {}

////////////////////////////////////////////////////////////////

	csvlib::csvlib(const csvlib &_obj)
	{
		column_names = _obj.column_names;
		column_values = _obj.column_values;
		column_index = _obj.column_index;
	}

////////////////////////////////////////////////////////////////

	csvlib::~csvlib() {}

////////////////////////////////////////////////////////////////

	void csvlib::read_csv(string file_path)
	{
		const char* cfile_path = file_path.c_str();
		FILE* file_ptr = fopen(cfile_path, "r+");
		if (file_ptr == NULL)
		{
			printf("Error: Unable to open file\n");
			exit(EXIT_FAILURE);
		}

		char buffer[MAX];
		memset(buffer, 0, MAX);
		long int line_count = 1;
		while (fgets(buffer, MAX, file_ptr))
		{
			string bstr(buffer);
			stringstream tokenize(bstr);
			string token;
			if (line_count == 1)
			{
				while (getline(tokenize, token, ','))
				{
					if (token[token.length() - 1] == '\n')
					{
						token.pop_back();
					}
					column_index.insert({token, column_names.size()});
					column_names.push_back(token);
				}
				line_count++;
				continue;
			}
			vector<string> row_content;
			while (getline(tokenize, token, ','))
			{
				if (token[token.length() - 1] == '\n')
				{
					token.pop_back();
				}
				row_content.push_back(token);
			}
			column_values.push_back(row_content);
		}
	}

////////////////////////////////////////////////////////////////////

	void csvlib::show()
	{
		show_data(column_values.size());
	}

////////////////////////////////////////////////////////////////////

	void csvlib::head(long int rows)
	{
		show_data(rows);
	}

////////////////////////////////////////////////////////////////////

	void csvlib::tail(long int rows)
	{
		show_data(-rows);
	}

////////////////////////////////////////////////////////////////////

	void csvlib::show_data(long int rows)
	{
		for (auto name : column_names)
		{
			printf("%-10s\t", name.c_str());
		}
		printf("\n");

		long int limit = 0;
		if (rows >= 0)
		{
			limit = rows > column_values.size() ? column_values.size() : rows;
			for (long int n_row = 0; n_row < limit; n_row++)
			{
				vector<string> values = column_values[n_row];
				for (auto &token : values)
				{
					printf("%-10s\t", token.c_str());
				}
				printf("\n");
			}
		}
		else
		{
			limit = -rows > column_values.size() ? 0 : column_values.size() + rows;
			for (long int n_row = limit; n_row < column_values.size(); n_row++)
			{
				vector<string> values = column_values[n_row];
				for (auto &token : values)
				{
					printf("%-5s\t", token.c_str());
				}
				printf("\n");
			}
			
		}
	}

/////////////////////////////////////////////////////////////////////

	vector<string> csvlib::get_columns()
	{
		return column_names;
	}

/////////////////////////////////////////////////////////////////////

	vector<vector<string>> csvlib::get_rows()
	{
		return column_values;
	}

/////////////////////////////////////////////////////////////////////

	vector<string> csvlib::loc(long int index)
	{
		return index >= column_values.size() ? vector<string>() : column_values[index];
	}

/////////////////////////////////////////////////////////////////////

	vector<string> csvlib::get_column_values(string col_name)
	{
		vector<string> col_data;
		long int index = column_index[col_name];
		for (long int n_row = 0; n_row < column_values.size(); n_row++)
		{
			col_data.push_back(column_values[n_row][index]); 
		}
		return col_data;
	}

//////////////////////////////////////////////////////////////////////

	vector<string> csvlib::unique(string col_name)
	{
		vector<string> unique_data;
		unordered_set<string> is_present; 
		long int index = column_index[col_name];
		for (long int n_row = 0; n_row < column_values.size(); n_row++)
		{
			if (is_present.find(column_values[n_row][index]) == is_present.end())
			{
				unique_data.push_back(column_values[n_row][index]);
				is_present.insert(column_values[n_row][index]);
			}
		}
		return unique_data;
	}

///////////////////////////////////////////////////////////////////////

	void csvlib::to_csv(vector<string> col_names, vector<vector<string>> row_values, string file_name)
	{
		long int col_names_sz = col_names.size();
		long int row_values_sz = row_values.size();
		long int row_len = row_values_sz == 0 ? 0 : row_values[0].size();
		if (col_names_sz == 0 || (row_len != 0 && col_names_sz != row_len))
		{
			printf("Error: Invalid size\n");
			exit(EXIT_FAILURE);
		}

		FILE* file_ptr = fopen(file_name.c_str(), "w+");
		if (file_ptr == NULL)
		{
			printf("Error: Cannot create file\n");
			exit(EXIT_FAILURE);
		}

		long int n_col = 0;
		for (n_col = 0; n_col < col_names_sz - 1; n_col++)
		{
			fprintf(file_ptr, "%s,", col_names[n_col].c_str());
		}
		fprintf(file_ptr, "%s\n", col_names[n_col].c_str());

		long int n_row = 0;
		for (n_row = 0; n_row < row_values_sz; n_row++)
		{
			long int n_elem = 0;
			for (n_elem = 0; n_elem < row_len - 1; n_elem++)
			{
				fprintf(file_ptr, "%s,", row_values[n_row][n_elem].c_str());
			}
			fprintf(file_ptr, "%s\n", row_values[n_row][n_elem].c_str());
		}
		fclose(file_ptr);
	}

/////////////////////////////////////////////////////////////////////////

}



