#include "systeminfo.hpp"
#include <iostream>

int 
main( int argc, char **argv )
{
   for( int t( 0 ); t < (int) Trait::N ; t++ )
   {
      std::cout << SystemInfo::getName( (Trait) t ) << " - " << 
         SystemInfo::getSystemProperty( (Trait) t ) << "\n";
   }
   return( EXIT_FAILURE );
}
