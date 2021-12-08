#include "HashTableChaining.h"


int HashTableChaining :: load(string file){
    ifstream input(file);
    if (input.is_open())
    {
        input >> m;
        hash = new list<int>[m];
        for (int i=0;i<m;i++)
            hash[i].push_back(0);

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

void HashTableChaining :: print(){
    cout << endl << "***********************************" << endl;
    for (int i=0;i<m;i++)
    {
      if(i < 10)
        cout << "[0" << i << "]:";
      else
        cout<< "["<<i<<"]:";
        if (hash[i].front()!=0)
        {
            for (list<int>::iterator x = hash[i].begin(); x != hash[i].end(); x++)
                cout << setw(3) << setfill(' ') << *x <<  " -> ";
            cout << endl;
        }
        else
            cout<<endl;
    }
    cout << endl << "***********************************" << endl;
}

int HashTableChaining :: insert(int value){
    int mod=value%m;
    if (search(value)==1)
        return 1;
    if (hash[mod].front()==0)
    {
        hash[mod].front()=value;
        return 1;
    }
    hash[mod].push_back(value);
    return 1;
}

int HashTableChaining :: search(int value){
    int mod=value%m;
    for (list<int>::iterator x = hash[mod].begin(); x != hash[mod].end(); x++){
        if (*x == value)
            return 1;
    }
    return 0;
}

int HashTableChaining :: remove(int value){
    int mod=value%m;
    if (hash[mod].front()==hash[mod].back()==value)
    {
        hash[mod].front()=0;
        return 1;
    }
    if (1==search(value))
    {
        hash[mod].remove(value);
        return 1;
    }
    return 0;
}
