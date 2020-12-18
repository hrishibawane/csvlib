#include "../src/csv.hpp"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>

using namespace std;
using namespace CppUnit;
using namespace hcsv;

class test_csv : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(test_csv);
	CPPUNIT_TEST(test_get_columns);
	CPPUNIT_TEST(test_get_rows);
	CPPUNIT_TEST(test_loc);
	CPPUNIT_TEST_SUITE_END();

private:
	csvlib* m_obj;

public:
	void setUp();
	void tearDown();

protected:
	void test_get_columns();
	void test_get_rows();
	void test_loc();
};

void test_csv::setUp()
{
	m_obj = new csvlib();
}

void test_csv::tearDown()
{
	delete m_obj;
}

void test_csv::test_get_columns()
{
	vector<string> col_names = {"Name", "Age", "Location", "Occupation", "Salary"};
	m_obj->read_csv("test.csv");
	CPPUNIT_ASSERT(m_obj->get_columns() == col_names);
}

void test_csv::test_get_rows()
{
	vector<vector<string>> row_val = {
		{"ABC", "23", "Pune", "SDE", "60000"},
		{"XYZ", "50", "Mumbai", "Manager", "130000"},
		{"PQR", "35", "Hyderabad", "Clerk", "30000"},
		{"Wolf Gupta", "12", "San Hose", "SDE", "100000000"}
	};
	m_obj->read_csv("test.csv");
	CPPUNIT_ASSERT(m_obj->get_rows() == row_val);
}

void test_csv::test_loc()
{
	vector<string> row = {"PQR", "35", "Hyderabad", "Clerk", "30000"};
	m_obj->read_csv("test.csv");
	CPPUNIT_ASSERT(m_obj->loc(2) == row);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_csv);

int main()
{
	CPPUNIT_NS::TestResult testresult;

	CPPUNIT_NS::TestResultCollector collectedres;
	testresult.addListener(&collectedres);

	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);

	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedres, std::cerr);
	compileroutputter.write();
	return collectedres.wasSuccessful() ? 0 : 1;
}




