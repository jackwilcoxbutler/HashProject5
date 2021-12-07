#include<iostream>
#include<ostream>
#include"hashtable.h"
#include<string>
#include<iomanip>

using namespace std;

int main(){
  string input;
  cout << "**" << setw(20) << setfill('*') << endl;

  cout << "Welcome to the Anglo-Saxon Castle" << endl;
  cout << endl << endl;
  cout << "1) Linear Probing" << endl;
  cout << "2) Seperate Chaining" << endl;
  cout << "3) Cuckoo Hashing" << endl;
  cout << "0) Quit" << endl << endl;
  cout << "Please enter your choice: ";
  cin >> input;



  if(input == "1")
  {
    //HashTableLinearProbing table = new HashTableLinearProbing();
  }else if(input == "2")
  {
    //HashTableChaining table = new HashTableChaining();
  }else if(input == "3")
  {
    //HashTableCuckoo table = new HashTableCuckoo();
  }else
  {
    cout << "Exiting Program" << endl;
    exit(1);
  }

  if(input != "0")
  {
    while(input != "0")
    {
      cout << endl << "-----------------------" << endl;
      cout << "1) Load Table From File" << endl;
      cout << "2) Insert" << endl;
      cout << "3) Search" << endl;
      cout << "4) Delete" << endl;
      cout << "5) Print Hash Table" << endl;
      cout << "0) Quit" << endl;
      cout << "Please enter your choice : ";
      cin >> input;
      cout << endl;
      if(input == "1")
      {
        string fileIn;
        cout << "Enter input file name: ";
        cin >> fileIn;
      //table->load(fileIn);
    }else if(input == "2")
      {
        int tempVal;
        cout << "Insert (Enter Value) : ";
        cin >> tempVal;
        //table->insert(tempVal);
      }else if(input == "3")
      {
        int tempVal;
        cout << "Search (Enter Value) : ";
        cin >> tempVal;
        //table->search(tempVal);
      }else if(input == "4")
      {
        int tempVal;
        cout << "Delete (Enter Value) : ";
        cin >> tempVal;
        //table->delete(tempVal);
      }else if(input == "5")
      {
        //table->print();
      }
    }
  //delete table;
  }
}
