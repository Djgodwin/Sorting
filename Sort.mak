Sort:SortEx.o Sort.o

	g++ -o Sort SortEx.o Sort.o



SortEx.o:SortEx.cpp Sort.h

	g++ -g -c SortEx.cpp



Sort.o:Sort.h Sort.cpp

	g++ -g -c Sort.cpp 
