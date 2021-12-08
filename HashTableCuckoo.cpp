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

    if (1==search(value))
        return 0;
    for(int i=0; i < (int)floor(m/2);i++)
    {
      int h1 = value % m;
      if(t1[h1] == 0)
      {
        t1[h1] = value;
          //cout << "insert successful " << value << endl;
        return 1;
      }
        int temp=t1[h1];
        //cout << value << " swaped with " << temp << " in array: 1, pos: " << h1<< endl;
        t1[h1] = value;
        value = temp;
      int h2 = (int)floor(value/m) % m;
      if(t2[h2] == 0)
      {
        t2[h2] = value;
          //cout << "insert successful" << value << endl;
        return 1;
      }
        temp=t2[h2];
        //cout << value << " swaped with " << temp << " in array: 2, pos: " << h2<< endl;
      t2[h2] = value;
      value = temp;
    }
    //cout<< "failed to insert "<< value << endl;
    if (0==rehash())
        cout << "**Rehash Failed! Table Not Valid!**" << endl;
        return 0;
    insert(value);
    return 1;
}

int HashTableCuckoo :: rehash(){
    //cout << "rehashing" << endl;
    if (m+3>21)
        return 0;
    int oldM=m;
    m = m+3;
    
    int * temp1;
    temp1=new int[oldM];
    for (int i=0;i<oldM;i++)
    {
        temp1[i]=t1[i];
    }
    delete [] t1;
    t1=new int[m];
    for (int i=0;i<m;i++)
        t1[i]=0;
    int * temp2;
    temp2=new int[oldM];
    for (int i=0;i<oldM;i++)
        temp2[i]=t2[i];
    delete [] t2;
    t2=new int[m];
    for (int i=0;i<m;i++)
        t2[i]=0;
    
    for (int i=0;i<oldM; i++)
    {
        if (temp1[i]!=0)
        {
            //cout << "inserting "<< temp1[i] << endl;
            if (0==insert(temp1[i]))
            {
                delete [] temp1;
                
                return 0;
            }
        }
    }
    delete [] temp1;
    for (int i=0;i<oldM; i++)
    {
        if (temp2[i]!=0)
        {
            //cout << "inserting "<< temp2[i] << endl;
            if (0==insert(temp2[i]))
            {
                delete [] temp2;
                return 0;
            }
        }
    }
    delete [] temp2;
    return 1;


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
        //cout<< ((i<10)? "[0": "[" )<<i<< "]: ";
        //cout.width(10); cout<<left << setfill(' ')<<((t1[i]!=0) ? t1[i] : NULL);
        //cout<< ((i<10)? "[0": "[")<<i<<"]: ";
        //cout.width(10); cout<<left << setfill(' ')<<((t2[i]!=0) ? t2[i] : NULL)<< endl;
        
      if(i<10)
        {cout<< "[0"<<i<<"]: ";}
      else
        {cout<< "["<<i<<"]: ";}
        
      if (t1[i]!=0)
      {cout.width(10); cout << left<< setfill(' ')<< t1[i]; }
      else
      { cout.width(10); cout << left<< setfill(' ')<< " "; }
        
      if(i<10)
        {cout<< "[0"<<i<<"]: ";}
      else
        {cout<< "["<<i<<"]: ";}
      if (t2[i]!=0)
        {cout << t2[i];}
    cout<<endl;
         
    }
    cout << endl << "***********************************" << endl;
    
}



