#include <iostream>
#include <iomanip>

using namespace std;

#include "Gradebook.h"

GradeBook::GradeBook(string name, const int gradesArray[][tests])
{
	setCourseName(name);

	//copy grades from gradesArray to grades data member
	for(int student = 0; student < students; student++)
	{
		for(int test = 0; test < tests; test++)
		{
			grades[student][test] = gradesArray[student][test];
		}
	}
}

void GradeBook::setCourseName(string name)
{
	courseName = name;
}

string GradeBook::getCourseName()
{
	return courseName;
}

void GradeBook::displayMessage()
{
	cout << "Wellcome to the grade book for\n" << getCourseName() << "!"
			<< endl;
}

void GradeBook::processGrades()
{
	outputGrades();

	// call functions getMinimum and getMaximum
	cout << "\nLowest grade in the grade book is " << getMinimum()
		<< "\nHighest grade in the grade book is " << getMaximum() << endl;

	outputBarChart();
}

int GradeBook::getMinimum()
{
	int lowGrade = 100;

	for(int student = 0; student < students; student++)
	{
		for(int test = 0; test < tests; test++)
		{
			if(grades[student][test] < lowGrade)
			{
				lowGrade = grades[student][test];
			}
		}
	}

	return lowGrade;
}

int GradeBook::getMaximum()
{
	int highGrade = 0;

	for(int student = 0; student < students; student++)
	{
		for(int test = 0; test < tests; test++)
		{
			if(grades[student][test] > highGrade)
			{
				highGrade = grades[student][test];
			}
		}
	}

	return highGrade;
}

double GradeBook::getAverage( const int setOfGrades[], const int grades )
{
   int total = 0; // initialize total

   // sum grades in array
   for ( int grade = 0; grade < grades; grade++ )
      total += setOfGrades[ grade ];

   // return average of grades
   return static_cast< double >( total ) / grades;
} // end function getAverage

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
   cout << "\nOverall grade distribution:" << endl;

   // stores frequency of grades in each range of 10 grades
   const int frequencySize = 11;
   int frequency[ frequencySize ] = { 0 };

   // for each grade, increment the appropriate frequency
   for ( int student = 0; student < students; student++ )

      for ( int test = 0; test < tests; test++ )
         ++frequency[ grades[ student ][ test ] / 10 ];

   // for each grade frequency, print bar in chart
   for ( int count = 0; count < frequencySize; count++ )
   {
      // output bar label ("0-9:", ..., "90-99:", "100:" )
      if ( count == 0 )
         cout << "  0-9: ";
      else if ( count == 10 )
         cout << "  100: ";
      else
         cout << count * 10 << "-" << ( count * 10 ) + 9 << ": ";

      // print bar of asterisks
      for ( int stars = 0; stars < frequency[ count ]; stars++ )
         cout << '*';

      cout << endl; // start a new line of output
   } // end outer for
} // end function outputBarChart

void GradeBook::outputGrades()
{
   cout << "\nThe grades are:\n\n";
   cout << "            "; // align column heads

   // create a column heading for each of the tests
   for ( int test = 0; test < tests; test++ )
      cout << "Test " << test + 1 << "  ";

   cout << "Average" << endl; // student average column heading

   // create rows/columns of text representing array grades
   for ( int student = 0; student < students; student++ )
   {
      cout << "Student " << setw( 2 ) << student + 1;

      // output student's grades
      for ( int test = 0; test < tests; test++ )
         cout << setw( 8 ) << grades[ student ][ test ];

      // call member function getAverage to calculate student's average;
      // pass row of grades and the value of tests as the arguments
      double average = getAverage( grades[ student ], tests );
      cout << setw( 9 ) << setprecision( 2 ) << fixed << average << endl;
   } // end outer for
} // end function outputGrades
