
#include "csv.hpp"
#include <cstdlib>
#include <climits>
#include <cstring>
#include <sstream>
#define MAX 0xFFFF

csvlib::csvlib() {}

csvlib::~csvlib() {}

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

void csvlib::show()
{
	show_data(column_values.size());
}

void csvlib::head(long int rows)
{
	show_data(rows);
}

void csvlib::tail(long int rows)
{
	show_data(-rows);
}

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

vector<string> csvlib::get_columns()
{
	return column_names;
}

vector<vector<string>> csvlib::get_rows()
{
	return column_values;
}

vector<string> csvlib::loc(long int index)
{
	return index >= column_values.size() ? vector<string>() : column_values[index];
}

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

vector<string> csvlib::unique(string col_name)
{
	vector<string> unique_data;
	unordered_set<string> ispresent; 
	long int index = column_index[col_name];
	for (long int n_row = 0; n_row < column_values.size(); n_row++)
	{
		if (ispresent.find(column_values[n_row][index]) == ispresent.end())
		{
			unique_data.push_back(column_values[n_row][index]);
			ispresent.insert(column_values[n_row][index]);
		}
	}
	return unique_data;
}