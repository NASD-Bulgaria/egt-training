//============================================================================
// Name        : HomeWork04-ConditionalStatements.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

void ChangeIfFirstIsGreater(){
	int first = 0;
	int second = 0;
	cin >> first;
	cin >> second;
	cout << first << " " << second << endl;
	if (first > second) {
		int temp = first;
		first = second;
		second = temp;
	}
	cout << first << " " << second << endl;
}

void ShowSignOfProduct(){
	int first = 0;
	int second = 0;
	int third = 0;
	int counter = 0;
	if (first < 0) {
		counter++;
	}

	if (second < 0) {
		counter++;
	}

	if (third < 0) {
		counter++;
	}

	if (counter % 2 == 0) {
		cout << "The product (" << first << " * " << second << " * " << third << ") is a positive number!" << endl;
	}
	else {
		cout << "The product (" << first << " * " << second << " * " << third << ") is a negative number!" << endl;
	}
}

void FindMax(){
	int first = 0;
	int second = 0;
	int third = 0;
	int max = INT_MIN;
	cin >> first;
	cin >> second;
	cin >> third;

	if (first > second) {
		if (first > third) {
			max = first;
		}
		else {
			max = third;
		}
	}
	else if(second > third){
		max = second;
	}
	else {
		max = third;
	}

	cout << "The largest number is: " << max << endl;
}

void SortThreeIntegers() {
	double first = 0;
	double second = 0;
	double third = 0;
	double temp = 0;

	cin >> first;
	cin >> second;
	cin >> third;

	if (third > second) {
		temp = second;
		second = third;

		third = temp;
	}

	if (second > first) {
		temp = first;
		first = second;
		second = temp;
	}

	if (third > second) {
		temp = second;
		second = third;
		third = temp;
	}
	cout << first << " " << second << " " << third << endl;
}

void PrintDigitInBulagrian(){
	int digit = 0;
	cin >> digit;
	string word = "";
	switch (digit) {
		case 0:
			word = "нула";
			break;
		case 1:
			word = "едно";
			break;
		case 2:
			word = "две";
			break;
		case 3:
			word = "три";
			break;
		case 4:
			word = "четири";
			break;
		case 5:
			word = "пет";
			break;
		case 6:
			word = "шест";
			break;
		case 7:
			word = "седем";
			break;
		case 8:
			word = "осем";
			break;
		case 9:
			word = "девед";
			break;
		default:
			word = "Не е цифра";
			break;
	}

	cout << "Числото " << digit << " е " << word << endl;
}

void QuadraticEquation(){
	double a = 0;
	double b = 0;
	double c = 0;

	cout << "Enter a:" << endl;
	cin >> a;
	cout << "Enter b:" << endl;
	cin >> b;
	cout << "Enter c:" << endl;
	cin >> c;

	double x1 = 0;
	double x2 = 0;

	double discriminant = b * b - (4 * a * c);
	if (discriminant == 0) {
		x1 = (b + sqrt(discriminant)) / 2 * a;
		cout << "The quadratic equation " << a << "x^2 + " << b << "x + " << c
				<< " has one real root equal to " << x1 << endl;
	} else if (discriminant > 0) {
		x1 = (b + sqrt(discriminant)) / 2 * a;
		x2 = (b - sqrt(discriminant)) / 2 * a;
		cout << "The quadratic equation " << a << "x^2 + " << b << "x + " << c
				<< " has two real roots equal to " << x1 << " and " << x2
				<< endl;
	} else {
		cout << "The quadratic equation " << a << "x^2 + " << b << "x + " << c
				<< " has no real roots" << endl;
	}

}

void FindMaxOfFive(){
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	double e = 0;
	double max = 0;

	cout << "Enter a:" << endl;
	cin >> a;
	cout << "Enter b:" << endl;
	cin >> b;
	cout << "Enter c:" << endl;
	cin >> c;
	cout << "Enter d:" << endl;
	cin >> d;
	cout << "Enter e:" << endl;
	cin >> e;

	if (a >= b && a >= c && a >= d && a >= e) {
		max = a;
	} else if (b >= a && b >= c && b >= d && b >= e) {
		max = a;
	} else if (c >= a && c >= b && c >= d && c >= e) {
		max = a;
	} else if (d >= a && d >= b && d >= c && d >= e) {
		max = a;
	} else if (e >= a && e >= b && e >= d && e >= c) {
		max = a;
	}

	cout << "The largest number is: " << max << endl;

}

void CheckSubSumEqualsZero(){
	int a = 0;
	int b = 0;
	int c = 0;

	bool contains = false;

	if (a == -b || a == -c || c == -b) {
		contains = true;
	}

	if (contains) {
		cout << "There is a subset equal to zero" << endl;
	} else {
		cout << "There is no subset equal to zero" << endl;
	}
}

void ApplyBonusToScore(){
	int score = 0;
	cin >> score;
	bool error = false;

	switch (score) {
		case 1:
		case 2:
		case 3:
			score *= 10;
			break;
		case 4:
		case 5:
		case 6:
			score *= 100;
			break;
		case 7:
		case 8:
		case 9:
			score *=1000;
			break;
		default:
			error = true;
			break;
	}

	if (error) {
		cout << "Error" << endl;
	} else{
		cout << "The new score is: " << score << endl;
	}
}

void ConvertToBulgarian(int number){

	int units = number % 10;
	number /= 10;
	int tens = number % 10;
	int houndreds = number / 10;

	string unitStr = "";
	string tenStr = "";
	string houndredStr = "";

	switch (units) {
		case 0:
			unitStr = "";
			break;
		case 1:
			unitStr = "едно";
			break;
		case 2:
			unitStr = "две";
			break;
		case 3:
			unitStr = "три";
			break;
		case 4:
			unitStr = "четири";
			break;
		case 5:
			unitStr = "пет";
			break;
		case 6:
			unitStr = "шест";
			break;
		case 7:
			unitStr = "седем";
			break;
		case 8:
			unitStr = "осем";
			break;
		case 9:
			unitStr = "девет";
			break;
		default:
			break;
	}

	switch (tens) {
		case 0:
			tenStr = "";
			break;
		case 1:
			unitStr = "";
			switch (units) {
				case 0:
					tenStr = "десет";
					break;
				case 1:
					tenStr = "единадесет";
					break;
				case 2:
					tenStr = "дванадесет";
					break;
				case 3:
					tenStr = "тринадесет";
					break;
				case 4:
					tenStr = "четиринадесет";
					break;
				case 5:
					tenStr = "петнадесет";
					break;
				case 6:
					tenStr = "шестнадесет";
					break;
				case 7:
					tenStr = "седемнадесет";
					break;
				case 8:
					tenStr = "осемнадесет";
					break;
				case 9:
					tenStr = "деветнадесет";
					break;
				default:
					break;
			}
			units = 0;
			break;
		case 2:
			tenStr = "двадесет";
			break;
		case 3:
			tenStr = "тридесет";
			break;
		case 4:
			tenStr = "четиридесет";
			break;
		case 5:
			tenStr = "петдесет";
			break;
		case 6:
			tenStr = "шестдесет";
			break;
		case 7:
			tenStr = "седемдесет";
			break;
		case 8:
			tenStr = "осемдесет";
			break;
		case 9:
			tenStr = "деведесет";
			break;
		default:
			break;
	}

	switch (houndreds) {
		case 0:
			houndredStr = "";
			break;
		case 1:
			houndredStr = "сто";
			break;
		case 2:
			houndredStr = "двеста";
			break;
		case 3:
			houndredStr = "триста";
			break;
		case 4:
			houndredStr = "четиристотин";
			break;
		case 5:
			houndredStr = "петстотин";
			break;
		case 6:
			houndredStr = "шестстотин";
			break;
		case 7:
			houndredStr = "седемстотин";
			break;
		case 8:
			houndredStr = "осемстотин";
			break;
		case 9:
			houndredStr = "деветстотин";
			break;
		default:
			break;
	}

	string afterHoundreds = "";
	string afterTens = "";

	if (houndreds == 0) {
		afterHoundreds = "";
	} else {
		if (tens == 0) {
			afterHoundreds = "";
		} else {
			if (units == 0) {
				afterHoundreds = " и ";
			} else {
				afterHoundreds = " ";
			}
		}
	}

	if (tens == 0) {
		if (units == 0) {
			afterTens = "";
		} else {
			if (houndreds == 0) {
				afterTens = "";
			} else {
				afterTens = " и ";
			}
		}
	} else {
		if (units == 0) {
			afterTens = "";
		} else {
			afterTens = " и ";
		}
	}

	if (houndreds == 0 && tens == 0 && units == 0) {
		unitStr = "нула";
	}

	cout << houndredStr << afterHoundreds << tenStr << afterTens << unitStr << endl;
}

void SolveNumber(){
	int number = 0;
	cout << "Въведете число" << endl;
	cin >> number;
	bool negative = false;
	bool even = false;
	bool zero = false;
	if (number < 0) {
		negative = true;
	} else if (number == 0){
		zero = true;
	}

	if (number % 2 == 0) {
		even = true;
	}

	if (zero) {
		cout << "нулево ";
	} else {
		if (negative) {
			cout << "отрицателно ";
		} else {
			cout << "положително ";
		}

		if (even) {
			cout << "четно ";
		} else {
			cout << "нечетно ";
		}
	}

	cout << "число " << endl;
}

void SolveNumberOfDigits(){
	int number = 0;
	cout << "Въведете число" << endl;
	cin >> number;
	int countOfDigits = 0;
	bool even = false;

	if (number % 2 == 0) {
		even = true;
	}

	while(number != 0){
		number /= 10;
		countOfDigits++;
	}

	if (even) {
		cout << "четно ";
	} else {
		cout << "нечетно ";
	}

	switch (countOfDigits) {
		case 1:
			cout << "едноцифрено ";
			break;
		case 2:
			cout << "двуцифрено ";
			break;
		case 3:
			cout << "трицифрено ";
			break;
		default:
			break;
	}

	cout << "число"<<endl;
}

void CheckSimetricalNumber() {
	int number = 0;
	cout << "Enter a number" << endl;
	cin >> number;

	int numberOfDigits = 0;
	int f = 0;
	int e = 0;
	int d = 0;
	int c = 0;
	int b = 0;
	int a = 0;
	bool simetric = false;

	switch (numberOfDigits) {
		case 0:
			f = number % 10;
			number /= 10;
			numberOfDigits++;
			simetric = true;
			if (number == 0) {
				break;
			}
		case 1:
			e = number % 10;
			number /= 10;
			numberOfDigits++;
			if (f == e) {
				simetric = true;
			} else {
				simetric = false;
			}
			if (number == 0) {
				break;
			}
		case 2:
			d = number % 10;
			number /= 10;
			numberOfDigits++;
			if (f == d) {
				simetric = true;
			} else {
				simetric = false;
			}
			if (number == 0) {
				break;
			}
		case 3:
			c = number % 10;
			number /= 10;
			numberOfDigits++;
			if (f == c && d == e) {
				simetric = true;
			} else {
				simetric = false;
			}
			if (number == 0) {
				break;
			}
		case 4:
			b = number % 10;
			number /= 10;
			numberOfDigits++;
			if (b == f && c == e) {
				simetric = true;
			} else {
				simetric = false;
			}
			if (number == 0) {
				break;
			}
		case 5:
			a = number % 10;
			numberOfDigits++;
			if (a == f && b == e && c == d) {
				simetric = true;
			} else {
				simetric = false;
			}
			break;
		default:
			break;
	}

	cout << "The number is simetric: " << (simetric ? "true" : "false") << endl;
}

void Calculator(){
	char operation = 'a';
	double firstValue = 0;
	double secondValue = 0;
	double result = 0;
	bool validOperation = false;
	cout << "Въведете операция (+, -, *, /, %)" << endl;
	while(!validOperation){
		cin >> operation;
		switch (operation) {
			case '+':
				validOperation = true;
				break;
			case '-':
				validOperation = true;
				break;
			case '*':
				validOperation = true;
				break;
			case '/':
				validOperation = true;
				break;
			case '%':
				validOperation = true;
				break;
			default:
				cout<<"Невалидна операция! Въведете отново!"<<endl;
				validOperation = false;
				break;
		}
	}

	cout << "Въведете първата стойност" << endl;
	cin >> firstValue;
	cout << "Въведете втората стойност" << endl;
	cin >> secondValue;

	switch (operation) {
		case '+':
			result = firstValue + secondValue;
			break;
		case '-':
			result = firstValue - secondValue;
			validOperation = true;
			break;
		case '*':
			result = firstValue * secondValue;
			validOperation = true;
			break;
		case '/':
			result = firstValue / secondValue;
			validOperation = true;
			break;
		case '%':
			result = (int)firstValue % (int)secondValue;
			validOperation = true;
			break;
	}

	cout << "Резултата от операцията " << firstValue << " " << operation << " "
			<< secondValue << " = " << result << endl;
}

void Calendar(){
	int day = 0;
	int month = 0;
	int year = 0;
	int newDay = 0;
	int newMonth = 0;
	int newYear = 0;
	bool validDay = false;
	bool validMonth = false;
	bool validYear = false;
	int addedDays = 0;
	int dayPassed = 0;
	while (!validYear) {
		cout << "Enter year (1900 to 2014)" << endl;
		cin >> year;
		if (year >= 1900 && year <= 2014) {
			validYear = true;
		} else {
			cout<<"Invalid Year! ";
		}
	}
	while (!validMonth) {
		cout << "Enter month (1 to 12)" << endl;
		cin >> month;
		if (month >= 1 && month <= 12) {
			validMonth = true;
		} else {
			cout << "Invalid Month! ";
		}
	}
	while (!validDay) {
		cout << "Enter day (1 to 31)" << endl;
		cin >> day;
		if (day >= 1) {
			if (month <= 7) {
				if (month % 2 == 1 && day <= 31) {
					validDay = true;
				} else if (month % 2 == 0) {
					if (month == 2) {
						if (year % 4 == 0 && day <= 29) {
							validDay = true;
						} else if (year % 4 != 0 && day <= 28) {
							validDay = true;
						}
					} else if (day <= 30) {
						validDay = true;
					}
				}
			} else {
				if (month % 2 == 0 && day <= 31) {
					validDay = true;
				} else if (month % 2 == 0 && day <= 30) {
					validDay = true;
				}
			}
		}

		if (!validDay) {
			cout << month <<"th month does not have " << day << " days!"<<endl;
		}
	}
	cout << "Date entered: " << (day < 10 ? "0" : "") << day << "/"
			<< (month < 10 ? "0" : "") << month << "/" << year << endl;

	if (month >= 1) {
		if (month == 1) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 2) {
		if (month == 2) {
			dayPassed += day;
		} else {
			if (year % 4 == 0) {
				dayPassed += 29;
			} else {
				dayPassed += 28;
			}
		}
	}
	if (month >= 3) {
		if (month == 3) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 4) {
		if (month == 4) {
			dayPassed += day;
		} else {
			dayPassed += 30;
		}
	}
	if (month >= 5) {
		if (month == 5) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 6) {
		if (month == 6) {
			dayPassed += day;
		} else {
			dayPassed += 30;
		}
	}
	if (month >= 7) {
		if (month == 7) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 8) {
		if (month == 8) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 9) {
		if (month == 9) {
			dayPassed += day;
		} else {
			dayPassed += 30;
		}
	}
	if (month >= 10) {
		if (month == 10) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	if (month >= 11) {
		if (month == 11) {
			dayPassed += day;
		} else {
			dayPassed += 30;
		}
	}
	if (month == 12) {
		if (month == 12) {
			dayPassed += day;
		} else {
			dayPassed += 31;
		}
	}
	cout << "Enter days to add" << endl;
	cin >> addedDays;
	cout << dayPassed << endl;
}

int main() {
//	ChangeIfFirstIsGreater();
//	FindMax();
//	SortThreeIntegers();
//	PrintDigitInBulagrian();
//	QuadraticEquation();
//	FindMaxOfFive();
//	ApplyBonusToScore();
//	for (int number = 0; number < 1000; ++number) {
//		ConvertToBulgarian(number);
//	}
//
//	SolveNumber();
//	SolveNumberOfDigits();
//	CheckSimetricalNumber();
//	Calculator();
	Calendar();
	return 0;
}
