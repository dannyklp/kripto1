#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <locale>
using namespace std;

class MyTransform {
private :
   int shift ;
public :
   MyTransform( int s ) : shift( s ) { }

  char operator( )( char c ) {
      if ( isspace( c ) )
	 return ' ' ;
      else {
			static std::string letters( "abcdefghijklmnopqrstuvwxyz" ) ;
		std::string::size_type found = letters.find(tolower( c )) ;
			int shiftedpos = ( static_cast<int>( found ) + shift ) % 26 ;
		if ( shiftedpos < 0 )
			shiftedpos = 26 + shiftedpos ;
	char shifted = letters[shiftedpos] ;
			return shifted ;
      }
  }
} ;

int main( ) {

	setlocale(0, "Rus");
   std::string input ;
   std::cout << "введите путь к файлу: " ;
   getline( std::cin , input ) ;
   ifstream file;
   file.open(input, ios::in);
   if (!file.is_open()) {
	   cout << "файл не найден";
	   system("pause");
	   return -1;
   }
   string source, buf;
   while (getline(file, buf))
   {
	   source += buf;
   }
   file.close();

   std::cout << "введите сдвиг: " ;
   int myshift = 0 ;
   std::cin >> myshift ;
   std::cout << "источник:" << source << std::endl ;
   std::transform (source.begin( ) , source.end( ) , source.begin( ) ,
	 MyTransform( myshift ) ) ;
	
   std::cout << "зашифровано: " ;
   std::cout << source << std::endl ;
   myshift *= -1 ; 
   std::transform (source.begin( ) , source.end( ) , source.begin( ) ,
	 MyTransform( myshift ) ) ;
   std::cout << "расшифровано: " ;
   std::cout << source << std::endl ;
   system("pause");
   return 0 ;
}
