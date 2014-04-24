/**
 * systeminfo.cpp - 
 * @author: Jonathan Beard
 * @version: Wed Apr 23 15:32:06 2014
 * 
 * Copyright 2014 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <unistd.h>
#include "systeminfo.hpp"

std::string
SystemInfo::getSystemProperty( const Trait trait )
{
#if __linux
   if( trait < 15 )
   {
      errno = 0;
      long val( 0 );
      switch( trait )
      {
         case( LevelOneICacheSize ):
         {
            if( (val = sysconf( _SC_LEVEL1_ICACHE_SIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelOneICacheAssociativity ):
         {
            if( (val = sysconf( _SC_LEVEL1_ICACHE_ASSOC ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelOneICacheLineSize ):
         {
            if( (val = sysconf( _SC_LEVEL1_ICACHE_LINESIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelOneDCacheSize ):
         {
            if( (val = sysconf( _SC_LEVEL1_DCACHE_SIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelOneDCacheAssociativity ):
         {
            if( (val = sysconf( _SC_LEVEL1_DCACHE_ASSOC ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelOneDCacheLineSize ):
         {
            if( (val = sysconf( _SC_LEVEL1_DCACHE_LINESIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelTwoCacheSize ):
         {
            if( (val = sysconf( _SC_LEVEL2_CACHE_SIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelTwoCacheAssociativity ):
         {
            if( (val = sysconf( _SC_LEVEL2_CACHE_ASSOC ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelTwoCacheLineSize ):
         {
            if( (val = sysconf( _SC_LEVEL2_CACHE_LINESIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelThreeCacheSize ):
         {
            if( (val = sysconf( _SC_LEVEL3_CACHE_SIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelThreeCacheAssociativity ):
         {
            if( (val = sysconf( _SC_LEVEL3_CACHE_ASSOC ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelThreeCacheLineSize ):
         {
            if( (val = sysconf( _SC_LEVEL3_CACHE_LINESIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelFourCacheSize ):
         {
            if( (val = sysconf( _SC_LEVEL4_CACHE_SIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelFourCacheAssociativity ):
         {
            if( (val = sysconf( _SC_LEVEL4_CACHE_ASSOC ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         case( LevelFourCacheLineSize ):
         {
            if( (val = sysconf( _SC_LEVEL4_CACHE_LINESIZE ) ) == -1 )
            {
               perror( "Failed to get config info" );
               val = -1;
            }
         }
         break;
         default:
            break;
      }
   }
#elif __APPLE__

#endif
}
