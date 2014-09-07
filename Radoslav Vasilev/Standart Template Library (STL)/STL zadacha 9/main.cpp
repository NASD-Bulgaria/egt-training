#include <iostream>
#include <map>
#include <vector>
using namespace std;
void vectorDisplay(vector<int>);
void mapDisplay(map<int, int>);
int main()
{
    vector <int> array;/*[9]={2, 2, 3, 3, 2, 3, 4, 3, 3}*/
    array.push_back(2);
    array.push_back(2);
    array.push_back(3);
    array.push_back(3);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(3);
    array.push_back(3);


    map<int,int> magic;
    for(size_t i = 0; i < array.size() ;i++)
    {

        if(magic.find(array[i])==magic.end())
        {
          magic.insert ( pair<int,int>(array[i],1) );
        }
        else
        {
            magic.at(array[i])++;
        }
    }

    int keyTemp =0;
    int keyCount =0;
    for ( map<int,int>::iterator it = magic.begin();it != magic.end(); ++it )
    {
        if(keyCount <it->second)
        {
            keyTemp= it->first;
            keyCount = it->second;

        }
    }

    if((unsigned)keyCount <= array.size())
    {
        cout<< keyTemp <<" -> "<< keyCount<<endl;
    }
    else
    {
        cout<< "dont have majorant number in this vector"<<endl;
    }


//    mapDisplay(magic);
    vectorDisplay(array);
    return 0;
}

void vectorDisplay(vector<int> vec)
{
    for(size_t i = 0; i < vec.size() ;i++)
    {

       cout<< vec[i]<<" ";
    }
    cout<< endl;
}

void mapDisplay(map<int,int> mapD)
{

    for ( map<int,int>::iterator it = mapD.begin();it != mapD.end(); ++it )
    {
        cout << it->first << '\t' << it->second << '\n';
    }
}

