#include"HashTableCuckoo.h"

int HashTableCuckoo :: load(string file){
  ifstream input(file);
  if(input.is_open())
  {
    input >> m;
    t1 = new int[m];
    t2 = new int[m];
    int itemsInFile;
    input >> itemsInFile;
    for (int i=0;i<itemsInFile;i++)
    {
        int toInsert;
        input >> toInsert;
        if (0==insert(toInsert))
            return 0;
    }
    return 1;
  }
  return 0;
}

int HashTableCuckoo :: insert(int value){

    for(int i=0; i < 1;i++)
    {
      int h1 = value % m;
      if(t1[h1] == 0)
      {
        t1[h1] = value;
        return 1;
      }
      t1[h1] = value;
      value = t1[h1];
      int h2 = (int)floor(value/m) % m;
      if(t2[h2] == 0)
      {
        t2[h2] = value;
        return 1;
      }
      t2[h2] = value;
      value = t2[h2];
    }
    //rehash;
    //insert(x);
    return 0;
}

void HashTableCuckoo :: rehash(){
  return;
  //rehash increases m by 3
  //check if less than 21
  //insert values from old table
}

int HashTableCuckoo :: search(int value){
    for (int i=0;i<m;i++)
    {
        if (t1[i]==value or t2[i]==value)
            return 1;
    }
    return 0;
}

int HashTableCuckoo :: remove(int value){
    for (int i=0;i<m;i++)
    {
        if (t1[i]==value)
        {
            t1[i]=0;
            return 1;
        }else if(t2[i]==value)
        {
          t2[i] = 0;
          return 1;
        }
    }
    return 0;
}

void HashTableCuckoo :: print(){
    cout << endl << "***********************************" << endl;
    for (int i=0;i<m;i++)
    {
      if(i<10)
        {cout<< "[0"<<i<<"]: ";}
      else
        {cout<< "["<<i<<"]: ";}
      if (t1[i]!=0)
        {cout<< setw(10) << setfill(' ') << t1[i];}
      else
        {cout << setw(10) << setfill(' ');}
      if(i<10)
        {cout<< "[0"<<i<<"]: ";}
      else
        {cout<< "["<<i<<"]: ";}
      if (t2[i]!=0)
        {cout<< setw(10) << setfill(' ') << t2[i];}
      else
        {cout << setw(10) << setfill(' ');}
            cout<<endl;
    }
    cout << endl << "***********************************" << endl;
}
