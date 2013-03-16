project4: BigNum.o project4a.o inverse.o
	g++ -o project4 BigNum.o project4a.o inverse.o

BigNum.o: BigNum.cc BigNum.h
	g++ -c BigNum.cc

inverse.o: inverse.cc
	g++ -c inverse.cc

project4a.o: project4a.cc BigNum.h
	g++ -c project4a.cc
