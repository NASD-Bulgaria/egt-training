#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "Tree.h" // Tree class definition

void treeEnter(Tree<string> &);

int main()
{
   Tree< string > charTree; // create Tree of char values

   treeEnter(charTree);

   return 0;
} // end main

void treeEnter(Tree<string> &charTree)
{

	char stringExp[50];
	char *Ptr;

	cout<<"Enter the string: ";
	cin.getline(stringExp,50);

	Ptr = strtok(stringExp," ");
	while(Ptr != '\0')
	{
		string *newStringExp = new string(Ptr);
		charTree.insertNode(*newStringExp);
		Ptr = strtok(0," ");
	}

	cout<<"Preorder Traversal"<<endl;
	charTree.preOrderTraversal();

	cout<<"\nInorder traversal"<<endl;
	charTree.inOrderTraversal();

	cout<<"\nPostorder traversal"<<endl;
	charTree.postOrderTraversal();

}
