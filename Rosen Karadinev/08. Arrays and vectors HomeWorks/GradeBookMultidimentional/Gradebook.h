
#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_

#endif /* GRADEBOOK_H_ */

#include <string>

using namespace std;

class GradeBook
{
	public:
		const static int students = 10;
		const static int tests = 3;

		GradeBook(string, const int[][tests]);

		void setCourseName(string);
		string getCourseName();
		void displayMessage();
		void processGrades();
		int getMinimum();
		int getMaximum();
		double getAverage(const int[], const int);
		void outputBarChart();
		void outputGrades();

	private:
		string courseName;
		int grades[students][tests];
};
