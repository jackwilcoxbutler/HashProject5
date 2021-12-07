blah : driver.cpp hashtable.o HashTableChaining.o HashTableLinearProbing.o
	g++ -o blah driver.cpp hashtable.o HashTableChaining.o HashTableLinearProbing.o
HashTableChaining.o : HashTableChaining.cpp HashTableChaining.h
	g++ -c HashTableChaining.cpp
HashTableLinearProbing.o : HashTableLinearProbing.cpp HashTableLinearProbing.h
	g++ -c HashTableLinearProbing.cpp
hashtable.o : hashtable.cpp hashtable.h
	g++ -c hashtable.cpp
