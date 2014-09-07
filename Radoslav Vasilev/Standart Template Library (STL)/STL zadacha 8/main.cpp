#include <iostream>
#include <map>
#include <vector>
using namespace std;
void vectorDisplay(vector<int>);
void mapDisplay(map<int, int>);
int main()
{
    vector <int> array;/*[11]={4,2,2,5,2,3,2,3,1,5,2}*/
    array.push_back(4);
    array.push_back(2);
    array.push_back(2);
    array.push_back(5);
    array.push_back(2);
    array.push_back(3);
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(5);
    array.push_back(2);


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


    for(size_t i = 0; i < array.size() ;i++)
    {

        if(magic.find(array[i])->second % 2!= 0)
        {
          array.erase(array.begin()+i);
          i--;
        }

    }
    mapDisplay(magic);
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
