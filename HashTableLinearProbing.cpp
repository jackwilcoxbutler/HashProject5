#include "HashTableLinearProbing.h"


int HashTableLinearProbing :: load(string file){
    ifstream input(file);
    if (input.is_open())
    {
        input >> m;
        hash = new int[m];
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

void HashTableLinearProbing :: print(){
    cout << endl << "***********************************" << endl;
    for (int i=0;i<m;i++)
    {
        cout<< "["<<i<<"]: ";
        if (hash[i]!=0)
        {    cout<< hash[i]<<endl; }
        else
            cout<<endl;
    }
    cout << endl << "***********************************" << endl;
}

int HashTableLinearProbing :: insert(int value){
    int mod=value%m;
    if (search(value)==1)
        return 1;
    for (int i=0;i<m;i++)
    {
        if (hash[(mod+i)%m]==0)
        {
            hash[(mod+i)%m]=value;
            return 1;
        }
    }
    return 0;
}

int HashTableLinearProbing :: search(int value){
    for (int i=0;i<m;i++)
    {
        if (hash[i]==value)
            return 1;
    }
    return 0;
}

int HashTableLinearProbing :: remove(int value){
    for (int i=0;i<m;i++)
    {
        if (hash[i]==value)
        {
            hash[i]=0;
            return 1;
        }
    }
    return 0;
}
