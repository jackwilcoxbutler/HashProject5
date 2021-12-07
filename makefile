blah : driver.cpp hashtable.o
	g++ -o blah driver.cpp hashtable.o
hashtable.o : hashtable.cpp hashtable.h
	g++ -c hashtable.cpp
