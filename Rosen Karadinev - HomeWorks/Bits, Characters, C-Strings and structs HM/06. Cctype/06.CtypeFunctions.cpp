#include <iostream>
#include <cctype>
using namespace std;

int main()
{

	cout << "According to isdigit:\n"
	      << ( isdigit( '8' ) ? "8 is a" : "8 is not a" ) << " digit\n"
	      << ( isdigit( '#' ) ? "# is a" : "# is not a" ) << " digit\n";

	   cout << "\nAccording to isalpha:\n"
	      << ( isalpha( 'A' ) ? "A is a" : "A is not a" ) << " letter\n"
	      << ( isalpha( 'b' ) ? "b is a" : "b is not a" ) << " letter\n"
	      << ( isalpha( '&' ) ? "& is a" : "& is not a" ) << " letter\n"
	      << ( isalpha( '4' ) ? "4 is a" : "4 is not a" ) << " letter\n";

	   cout << "\nAccording to isalnum:\n"
	      << ( isalnum( 'A' ) ? "A is a" : "A is not a" )
	      << " digit or a letter\n"
	      << ( isalnum( '8' ) ? "8 is a" : "8 is not a" )
	      << " digit or a letter\n"
	      << ( isalnum( '#' ) ? "# is a" : "# is not a" )
	      << " digit or a letter\n";

	   cout << "\nAccording to isxdigit:\n"
	      << ( isxdigit( 'F' ) ? "F is a" : "F is not a" )
	      << " hexadecimal digit\n"
	      << ( isxdigit( 'J' ) ? "J is a" : "J is not a" )
	      << " hexadecimal digit\n"
	      << ( isxdigit( '7' ) ? "7 is a" : "7 is not a" )
	      << " hexadecimal digit\n"
	      << ( isxdigit( '$' ) ? "$ is a" : "$ is not a" )
	      << " hexadecimal digit\n"
	      << ( isxdigit( 'f' ) ? "f is a" : "f is not a" )
	      << " hexadecimal digit" << endl;

	   cout << "According to islower:\n"
	         << ( islower( 'p' ) ? "p is a" : "p is not a" )
	         << " lowercase letter\n"
	         << ( islower( 'P' ) ? "P is a" : "P is not a" )
	         << " lowercase letter\n"
	         << ( islower( '5' ) ? "5 is a" : "5 is not a" )
	         << " lowercase letter\n"
	         << ( islower( '!' ) ? "! is a" : "! is not a" )
	         << " lowercase letter\n";

	      cout << "\nAccording to isupper:\n"
	         << ( isupper( 'D' ) ? "D is an" : "D is not an" )
	         << " uppercase letter\n"
	         << ( isupper( 'd' ) ? "d is an" : "d is not an" )
	         << " uppercase letter\n"
	         << ( isupper( '8' ) ? "8 is an" : "8 is not an" )
	         << " uppercase letter\n"
	         << ( isupper('$') ? "$ is an" : "$ is not an" )
	         << " uppercase letter\n";

	      cout << "\nu converted to uppercase is "
	         << static_cast< char >( toupper( 'u' ) )
	         << "\n7 converted to uppercase is "
	         << static_cast< char >( toupper( '7' ) )
	         << "\n$ converted to uppercase is "
	         << static_cast< char >( toupper( '$' ) )
	         << "\nL converted to lowercase is "
	         << static_cast< char >( tolower( 'L' ) ) << endl;

	      cout << "According to isspace:\nNewline "
	            << ( isspace( '\n' ) ? "is a" : "is not a" )
	            << " whitespace character\nHorizontal tab "
	            << ( isspace( '\t' ) ? "is a" : "is not a" )
	            << " whitespace character\n"
	            << ( isspace( '%' ) ? "% is a" : "% is not a" )
	            << " whitespace character\n";

	      cout << "\nAccording to iscntrl:\nNewline "
	            << ( iscntrl( '\n' ) ? "is a" : "is not a" )
	            << " control character\n"
	            << ( iscntrl( '$' ) ? "$ is a" : "$ is not a" )
	            << " control character\n";

	       cout << "\nAccording to ispunct:\n"
	            << ( ispunct( ';' ) ? "; is a" : "; is not a" )
	            << " punctuation character\n"
	            << ( ispunct( 'Y' ) ? "Y is a" : "Y is not a" )
	            << " punctuation character\n"
	            << ( ispunct('#') ? "# is a" : "# is not a" )
	            << " punctuation character\n";

	         cout << "\nAccording to isprint:\n"
	            << ( isprint( '$' ) ? "$ is a" : "$ is not a" )
	            << " printing character\nAlert "
	            << ( isprint( '\a' ) ? "is a" : "is not a" )
	            << " printing character\nSpace "
	            << ( isprint( ' ' ) ? "is a" : "is not a" )
	            << " printing character\n";

	         cout << "\nAccording to isgraph:\n"
	            << ( isgraph( 'Q' ) ? "Q is a" : "Q is not a" )
	            << " printing character other than a space\nSpace "
	            << ( isgraph(' ') ? "is a" : "is not a" )
	            << " printing character other than a space" << endl;
	return 0;
}
