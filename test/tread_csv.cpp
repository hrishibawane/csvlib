#include "../src/csv.hpp"

int main()
{
	csvlib mycsv;
	mycsv.read_csv("advertising.csv");
	mycsv.show_data();
}
