#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

#include "Hardware.h"

using namespace std;

void inputData( fstream & );
void listHardwares( fstream & );
void updateRecord( fstream & );
void insertRecord( fstream & );
void deleteRecord( fstream & );
int instructions( void );

int main()
{
   int choice; 

   fstream file( "hardware.dat", ios::in | ios::out );

   void ( *functionsArray[] )( fstream & ) = { listHardwares, updateRecord, insertRecord, deleteRecord };
   
   if ( !file )
   {
	   ofstream file( "hardware.dat", ios::out);
	   Hardware blankItem;
	   for ( int i = 0; i < 100; i++ )
	   file.write( reinterpret_cast< char * >( &blankItem ), sizeof( Hardware ) );
	   cerr << "Creating File hardware.dat"<<endl<<"Restart the program...";
	   return 0;
   }

   while ( ( choice = instructions() ) != 5 )
   {
      ( *functionsArray[ choice - 1 ] )( file );
      file.clear();
   }
}

void inputData( fstream &fRef )
{
   Hardware temp;

   int number;
   string name;
   double price;
   int stock;

   cout << "Enter the part number (0 - 99, -1 to end input): ";
   cin >> number;

   if(!cin)
   {
	   cerr << "Wrong Input, Exiting Program...";
	   exit(1);
   }

   while ( number != -1 ) 
   {
	  temp.setPartNumber( number );
      cout << "Enter the Hardware name: ";
      cin.ignore();
      getline( cin, name );
      temp.setHardwareName( name );
      cout << "Enter quantity:";
      cin >> stock;

      if(!cin)
      {
   	   cerr << "Wrong Input, Exiting Program...";
   	   exit(1);
      }

      temp.setInStock( stock );
      cout << "Enter price:";
      cin >> price;

      if(!cin)
      {
   	   cerr << "Wrong Input, Exiting Program...";
   	   exit(1);
      }

      temp.setUnitPrice( price );
      
      fRef.seekp( temp.getPartNumber() * sizeof( Hardware ) );

      fRef.write( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

      cout << "Enter the part number (0 - 99, -1 to end input): ";
      cin >> number;
   }
}

int instructions()
{
   int choice;

 cout << "\nEnter a choice:\n1  List all Hardwares."
      << "\n2  Update record.\n3  Insert record."
      << "\n4  Delete record.\n5  Quit Program.\n";

   do 
   {
      cout << "? ";
      cin >> choice;

      if(!cin)
      {
   	   cerr << "Wrong Input, Exiting Program...";
   	   exit(1);
      }

   } while ( choice < 1 || choice > 5 );

   return choice;
}

void listHardwares( fstream &fRef )
{
   Hardware temp;

   cout << setw( 7 ) << "Record#" << "    " << left 
      << setw( 30 ) << "Hardware name" << left
      << setw( 13 ) << "Quantity" << left << setw( 10 ) << "Cost" << endl;

   for ( int count = 0; count < 100 && !fRef.eof(); count++ ) 
   {
      fRef.seekg( count * sizeof( Hardware ) );
      fRef.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

      if ( temp.getPartNumber() >= 0 && temp.getPartNumber() < 100 ) 
      {
         cout << fixed << showpoint;
         cout << left << setw( 7 ) << temp.getPartNumber() << "    " 
            << left << setw( 30 ) << temp.getHardwareName() << left
            << setw( 13 ) << temp.getInStock() << setprecision( 2 )
            << left << setw( 10 ) << temp.getUnitPrice() << '\n';
      }
   }
}

void updateRecord( fstream &fRef )
{
   Hardware temp;
   int part;
   string name;
   int stock;
   double price;

   cout << "Enter the part number for update: ";
   cin >> part;

   if(!cin)
   {
	   cerr << "Wrong Input, Exiting Program...";
	   exit(1);
   }

   fRef.seekg( part * sizeof( Hardware ) );

   fRef.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() != -1 ) 
   {
      cout << setw( 7 ) << "Record#" << "    " << left 
         << setw( 30 ) << "Hardware name" << left
         << setw( 13 ) << "Quantity" << setw( 10 ) << "Cost" << endl;

      cout << fixed << showpoint;
      cout << setw( 7 ) << temp.getPartNumber() << "    " 
         << left << setw( 30 ) << temp.getHardwareName()
         << left << setw( 13 ) << temp.getInStock() 
         << setprecision( 2 ) << setw( 10 ) << temp.getUnitPrice() << '\n'
         << "Enter the Hardware name: ";

      cin.ignore();
      getline( cin, name );
      temp.setHardwareName( name );

           cout << "Enter quantity:";
           cin >> stock;

           if(!cin)
           {
        	   cerr << "Wrong Input, Exiting Program...";
        	   exit(1);
           }

           temp.setInStock( stock );
           cout << "Enter price:";
           cin >> price;

           if(!cin)
           {
        	   cerr << "Wrong Input, Exiting Program...";
        	   exit(1);
           }

           temp.setUnitPrice( price );

      fRef.seekp( temp.getPartNumber() * sizeof( Hardware ) );
      fRef.write( reinterpret_cast< char * > ( &temp ), sizeof( Hardware ) );
   }
   else
      cerr << "Cannot update. The record is empty.\n";
}

void insertRecord( fstream &fRef )
{
   Hardware temp;
   int part;
   string name;
   int stock;
   double price;

   cout << "Enter the part number for insertion: ";
   cin >> part;

   if(!cin)
   {
	   cerr << "Wrong Input, Exiting Program...";
	   exit(1);
   }

   fRef.seekg( part * sizeof( Hardware ) );
   fRef.read( reinterpret_cast< char * > ( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() == -1 ) 
   {
      temp.setPartNumber( part );
      cout << "Enter the Hardware name: ";
      cin.ignore();
      getline( cin, name ); 
      temp.setHardwareName( name );

           cout << "Enter quantity:";
           cin >> stock;

           if(!cin)
           {
        	   cerr << "Wrong Input, Exiting Program...";
        	   exit(1);
           }

           temp.setInStock( stock );
           cout << "Enter price:";
           cin >> price;

           if(!cin)
           {
        	   cerr << "Wrong Input, Exiting Program...";
        	   exit(1);
           }

           temp.setUnitPrice( price );

      fRef.seekp( temp.getPartNumber() * sizeof( Hardware ) );
      fRef.write( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );
   }
   else
      cerr << "Cannot insert. The record contains information.\n";
}

void deleteRecord( fstream &fRef )
{
   Hardware blankItem;
   Hardware temp;
   int part;

   cout << "Enter the part number for deletion: ";
   cin >> part;

   if(!cin)
   {
	   cerr << "Wrong Input, Exiting Program...";
	   exit(1);
   }

   fRef.seekg( part * sizeof( Hardware ) );
   fRef.read( reinterpret_cast< char * >( &temp ), sizeof( Hardware ) );

   if ( temp.getPartNumber() != -1 ) 
   {
      fRef.seekp( part * sizeof( Hardware ) );
      fRef.write( reinterpret_cast< char * >( &blankItem ), sizeof( Hardware ) );
      cout << "Record deleted.\n";
   }
   else
      cerr << "Cannot delete. The record is empty.\n";
}
