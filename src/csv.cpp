
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
				column_names.push_back(token);
			}
			line_count++;
			continue;
		}
		vector<string> row_content;
		while (getline(tokenize, token, ','))
		{
			row_content.push_back(token);
		}
		column_values.push_back(row_content);
	}
}

void csvlib::show_data()
{
	for (auto name : column_names)
	{
		printf("%-10s\t", name.c_str());
	}
	printf("\n");
	for (auto values : column_values)
	{
		for (auto token : values)
		{
			printf("%-10s\t", token.c_str());
		}
		printf("\n");
	}
}







