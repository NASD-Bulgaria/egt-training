#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
   string a="wolf";
   string b = "chicken";
   string c = "snake";
   string d = "bear";
   string e = "lion";
   string f = "puma";

   vector<string> animalNames;

   animalNames.push_back(a);
   animalNames.push_back(b);
   animalNames.push_back(c);
   animalNames.push_back(d);
   animalNames.push_back(e);
   animalNames.push_back(f);

   sort(animalNames.begin(),animalNames.end() );
   for(size_t i =0;i <animalNames.size();i++)
   {
	   cout<<animalNames[i]<<endl;
   }

    return 0;
}

