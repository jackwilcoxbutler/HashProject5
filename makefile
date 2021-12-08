blah : driver.cpp hashtable.o HashTableChaining.o HashTableLinearProbing.o HashTableCuckoo.o
	g++ -o blah driver.cpp hashtable.o HashTableChaining.o HashTableCuckoo.o HashTableLinearProbing.o
HashTableChaining.o : HashTableChaining.cpp HashTableChaining.h
	g++ -c HashTableChaining.cpp
HashTableLinearProbing.o : HashTableLinearProbing.cpp HashTableLinearProbing.h
	g++ -c HashTableLinearProbing.cpp
HashTableCuckoo.o : HashTableCuckoo.cpp HashTableCuckoo.h
	g++ -c HashTableCuckoo.cpp
hashtable.o : hashtable.cpp hashtable.h
	g++ -c hashtable.cpp
