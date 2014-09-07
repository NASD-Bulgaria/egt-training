#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

void wordCreator(const int * );

int main()
{
  int number[ 7 ] ={0};


   cout << "Enter a phone number (without 1 and 0! example 234-5678) ";

   for ( int z = 0; z < 7; )
   {
      int i = cin.get();
      if ( i >= '2' && i <= '9' )
      {
         number[ z++] = i - '0';
      }

   }

   wordCreator( number );
   return 0;
}


void wordCreator( const int * number )
{

   ofstream outFile( "phone.txt" );

       vector <char> two;
       two.push_back('a');
       two.push_back('b');
       two.push_back('c');
       vector <char> three;
       three.push_back('d');
       three.push_back('e');
       three.push_back('f');
       vector <char> four;
       four.push_back('g');
       four.push_back('h');
       four.push_back('i');
       vector <char> five;
       five.push_back('j');
       five.push_back('k');
       five.push_back('l');
       vector <char> six;
       six.push_back('m');
       six.push_back('n');
       six.push_back('o');

       vector <char> seven;
       seven.push_back('p');
       seven.push_back('q');
       seven.push_back('r');
       seven.push_back('s');
       vector <char> eight;
       eight.push_back('t');
       eight.push_back('u');
       eight.push_back('v');
       vector <char> nine;
       nine.push_back('w');
       nine.push_back('x');
       nine.push_back('y');
       nine.push_back('z');
       vector< vector<char> > bukvi;
       bukvi.push_back(two);
       bukvi.push_back(three);
       bukvi.push_back(four);
       bukvi.push_back(five);
       bukvi.push_back(six);
       bukvi.push_back(seven);
       bukvi.push_back(eight);
       bukvi.push_back(nine);

   if ( !outFile )
   {
      cerr << "File phone.txt could not be opened \n";
      exit( 1 );
   }
   else
   {
       string tempStr = "0000000";
          for(size_t i =0;i<bukvi[number[0]-2].size();i++)
          {
              tempStr[0]=bukvi[number[0]-2][i];
              for(size_t i =0;i<bukvi[number[1]-2].size();i++)
              {
                 tempStr[1]=bukvi[number[1]-2][i];
                 for(size_t i =0;i<bukvi[number[2]-2].size();i++)
                 {
                     tempStr[2]=bukvi[number[2]-2][i];
                     for(size_t i =0;i<bukvi[number[3]-2].size();i++)
                     {
                         tempStr[3]=bukvi[number[3]-2][i];
                         for(size_t i =0;i<bukvi[number[4]-2].size();i++)
                         {
                             tempStr[4]=bukvi[number[4]-2][i];
                             for(size_t i =0;i<bukvi[number[5]-2].size();i++)
                             {
                                 tempStr[5]=bukvi[number[5]-2][i];
                                 for(size_t i =0;i<bukvi[number[6]-2].size();i++)
                                 {
                                     tempStr[6]=bukvi[number[6]-2][i];

                                         outFile<< tempStr;
                                         outFile<<"\n";


                                 }
                             }
                         }
                     }
                 }
              }
          }
   }

       outFile << "\nPhone number is ";

       for ( int i = 0; i < 7; i++ )
       {
          if ( i == 3 )
          {
             outFile << '-';
          }

          outFile << number[ i ];
       }
       outFile.close();

}
