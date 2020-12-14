all: build

build:
	g++ src/csv.cpp -c
	ar rcs libcsv.a csv.o
	rm /lib/libcsv.a
	rm *.o
	chmod 777 libcsv.a
	mv libcsv.a /lib/
