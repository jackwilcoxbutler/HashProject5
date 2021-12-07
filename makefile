blah : driver.cpp hashtable.o HashTableLinearProbing.o
	g++ -o blah driver.cpp hashtable.o HashTableLinearProbing.o
HashTableLinearProbing.o : HashTableLinearProbing.cpp HashTableLinearProbing.h
	g++ -c HashTableLinearProbing.cpp
hashtable.o : hashtable.cpp hashtable.h
	g++ -c hashtable.cpp
