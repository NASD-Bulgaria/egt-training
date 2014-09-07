#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Type.h"
using namespace std;

enum Choices { NEW = 1, UPDATE, DELETE, DISPLAY, END };


void newRecord(fstream &);
void updateRecord(fstream &);
void deleteRecord(fstream &);
void displayRecord(fstream &);
int menu();
int getType(const char * const);
void outputLine(ostream &, const Type &);

void hardwareStore();
int main() {




    hardwareStore();


    return 0;
}



void newRecord(fstream& newFile) {
    Type type;

    int typeNumber = getType("Enter new type number");

    newFile.seekg((typeNumber - 1) * sizeof(Type));

    newFile.read(reinterpret_cast<char *>(&type), sizeof(Type));

    if (type.getTypeNumber() == 0)
    {
        char name[10];
        int counter;

        cout << "Enter type name: ";
        cin >> setw(10) >> name;
        cout << "Enter counts: ";
        cin >> counter;

        type.setTypeNumber(typeNumber);
        type.setName(name);
        type.setCounter(counter);

        newFile.seekp((typeNumber - 1) * sizeof(Type));

        newFile.write(reinterpret_cast<const char *>(&type), sizeof(Type));
    } else {
        cerr << "Type #" << typeNumber << " already contains information." << endl;
    }
}

void updateRecord(fstream& updateFile) {
    Type type;
    int count;
    int oldCount;

    int typeNumber = getType("Enter type number to update");

    updateFile.seekg((typeNumber - 1) * sizeof(Type));

    updateFile.read(reinterpret_cast<char *>(&type), sizeof(Type));

    if (type.getTypeNumber() != 0) {
        outputLine(cout, type);

        cout << "Enter (+) for added or (-) for reduced count: ";
        cin >> count;

        oldCount = type.getCounter();
        type.setCounter(oldCount + count);
        outputLine(cout, type);

        updateFile.seekp((typeNumber - 1) * sizeof(Type));
        updateFile.write(reinterpret_cast<char *>(&type), sizeof(Type));
    } else {
        cerr << "Type #" << typeNumber << " has no information." << endl;
    }
}

void deleteRecord(fstream& deleteFile) {
    Type type;
    Type blankType;
    int choce;

    int typeNumber = getType("Enter type numbet to delete");

    deleteFile.seekg((typeNumber - 1) * sizeof(Type));

    deleteFile.read(reinterpret_cast<char *>(&type), sizeof(Type));

    if (type.getTypeNumber() != 0) {
        outputLine(cout, type);

        cout << "Do you want to delete this record? (1 - Yes, 0 - No)";

        deleteFile.seekp((typeNumber - 1) * sizeof(Type));
        cin >> choce;

        while(choce < 0 || choce > 1){
            cerr << "Incorrect choice! (1 - Yes, 0 - No)";
            cin >> choce;
        }

        if (choce == 1) {
            deleteFile.write(reinterpret_cast<const char *>(&blankType), sizeof(Type));
            cout << "Type #" << typeNumber << " deleted.";
        } else {
            deleteFile.write(reinterpret_cast<char *>(&type), sizeof(Type));
            cout << "Type #" << typeNumber << " did not delete.";
        }
    } else {
        cerr << "Type #" << typeNumber << " has no information." << endl;
    }

}

void displayRecord(fstream &displayFile) {
    Type type;

    cout << setw(6) << "Number"
            << setw(16) << "Type name"
            << setw(10) << "Count" << endl;

    cout.clear();

    displayFile.seekg(0);

    while(!displayFile.eof()){
        displayFile.read(reinterpret_cast<char *>(&type), sizeof(Type));
        if (type.getTypeNumber() != 0) {
            outputLine(cout, type);
        }
    }
}

int menu()
{
    cout << "\nEnter your choice" << endl
            << NEW << " - Add a new type" << endl
            << UPDATE << " - Update an type" << endl
            << DELETE << " - Delete an type" << endl
            << DISPLAY << " - Display file" << endl
            << END << " - End program\n? ";

    int menuChoice;
    cin >> menuChoice; // input menu selection from user
    return menuChoice;
}

int getType(const char* const text) {
    int typeNumber;

    do {
        cout << text << " (1-100): ";
        cin >> typeNumber;
    } while (typeNumber < 1 || typeNumber >100);

    return typeNumber;
}

void outputLine(ostream &output, const Type &displayLine) {
    output << setw(6) << displayLine.getTypeNumber()
            << setw(16) << displayLine.getName()
            << setw(10) << displayLine.getCounter() << endl;
}
void hardwareStore()
{
    int choice;
    fstream inFile( "hardware.dat", ios::out | ios::in);

    if ( !inFile )
    {
        cerr << "File could not be opened." << endl;
        exit( EXIT_FAILURE );
    }
    while((choice = menu()) != END)
    {
        switch (choice) {
            case NEW:
                newRecord( inFile );
                break;
            case UPDATE:
                updateRecord( inFile );
                break;
            case DELETE:
                deleteRecord( inFile );
                break;
            case DISPLAY:
                displayRecord( inFile );
                break;
            default:
                cerr << "Incorrect choice!" << endl;
                break;
        }
        inFile.clear();
    }

    inFile.close();
}
