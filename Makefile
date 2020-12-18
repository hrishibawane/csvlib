CXX = g++
CXXFLAGS = -g -Wall
LIBFLAGS = -lcsv
TESTFLAGS = -lcppunit
TESTM = test/test_csv.cpp
SRCM = src/csv.cpp
LIBM = libcsv.a

all: test build

test:
	$(CXX) $(CXXFLAGS) $(TESTM) -o test_csv $(LIBFLAGS) $(TESTFLAGS)

build:
	$(CXX) $(SRCM) -c
	ar rcs $(LIBM) csv.o
	rm /lib/$(LIBM)
	rm *.o
	chmod 777 $(LIBM)
	mv $(LIBM) /lib/
