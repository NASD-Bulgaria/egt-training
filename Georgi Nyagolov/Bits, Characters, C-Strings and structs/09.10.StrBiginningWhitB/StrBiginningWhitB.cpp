//============================================================================
// Name        : StrBiginningWhitB.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

bool conditionCheker(string &);

int main(){
	string strPtr;
    vector<string> temp;
    int count = 1;

    cout << "Enter 10 strings." << endl;

    while (count <= 10){

        cout<<"Please enter " << count << " string: ";
        getline(cin,strPtr);

        if(conditionCheker(strPtr)){
            temp.push_back(strPtr);
        }

        count++;
    }

    for(size_t i = 0; i < temp.size(); i++){
        cout << temp[i] << endl;
    }

    return 0;
}

bool conditionCheker(string &str){
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    if(cstr[0] == 'b' || (cstr[str.length()-1] == 'D' && cstr[str.length()-2] == 'E')){
        return true;
    }

    return false;
}
