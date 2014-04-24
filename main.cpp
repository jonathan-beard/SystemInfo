#include "systeminfo.hpp"
#include <iostream>

int 
main( int argc, char **argv )
{
   std::cout << SystemInfo::getSystemProperty( LevelOneICacheSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelOneICacheAssociativity ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelOneICacheLineSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelOneDCacheSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelOneDCacheAssociativity ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelOneDCacheLineSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelTwoCacheSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelTwoCacheAssociativity ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelTwoCacheLineSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelThreeCacheSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelThreeCacheAssociativity ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelThreeCacheLineSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelFourCacheSize ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelFourCacheAssociativity ) << "\n";
   std::cout << SystemInfo::getSystemProperty( LevelFourCacheLineSize ) << "\n";

   std::cout << "ProcNumInfo:\n";
   std::cout << SystemInfo::getSystemProperty( NumberOfProcessors ) << "\n"; 

   std::cout << "/proc/cpuinfo Information: \n";
   std::cout << SystemInfo::getSystemProperty( ProcessorName ) << "\n";
   std::cout << SystemInfo::getSystemProperty( ProcessorFrequency ) << "\n";
   return( EXIT_FAILURE );
}
