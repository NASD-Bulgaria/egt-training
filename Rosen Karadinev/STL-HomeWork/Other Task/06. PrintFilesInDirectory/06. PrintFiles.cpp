#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

DWORD WINAPI GetAllFiles(void *args);

int main()
{
    char path[] = "C:";
    CreateThread(NULL, 0, GetAllFiles, (void *)path, 0, NULL);

    system("pause");
}

DWORD WINAPI GetAllFiles(void *args)
{
    char *tmpPath = (char *) args;
    string sPath(tmpPath);

    WIN32_FIND_DATA FindFileData;
    string sTmpPath = sPath;
    sTmpPath += "\\*.*";

    string currFile = "";

    HANDLE hFind = FindFirstFile(sTmpPath.c_str(), &FindFileData );
    if (hFind == INVALID_HANDLE_VALUE) {
        cout<< "Not a valid path\n";
        return 0;}
    else
    {
        do
        {
           //check if its a directory...
            if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ))
            {
                string filePath = FindFileData.cFileName;
                                        //ignore '.' and '..'
            	if (strcmp(".", filePath.c_str()) && strcmp("..", filePath.c_str()))
                                        {
                                              //Dont list recycle bin content...
		 if (filePath == "$RECYCLE.BIN" || filePath == "$Recycle.Bin")
                     continue;
		     sTmpPath = sPath + "\\" + filePath;
                     GetAllFiles((void *) sTmpPath.c_str());
                }
            }
            else                       //its a file...
            {
		sTmpPath = sPath + "\\";
		currFile = sTmpPath + FindFileData.cFileName;

                cout << currFile << endl << endl;
            }
        } while (FindNextFile(hFind, &FindFileData) != 0);

        FindClose(hFind);

    }

    return 0;
}
