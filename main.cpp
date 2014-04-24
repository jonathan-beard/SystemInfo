#include "systeminfo.hpp"
#include <iostream>

int 
main( int argc, char **argv )
{
   for( Trait t( LevelOneICacheSize ); t < Trait::N ; t++ )
   {
      std::cout << SystemInfo::getName( t ) << " - " << 
         SystemInfo::getSystemProperty( t ) << "\n";
   }
   return( EXIT_FAILURE );
}
