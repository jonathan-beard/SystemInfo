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
#include <cstdlib>
#include <cstdio>
#include <cstring>
#if __linux
#include <unistd.h>
#include <sys/sysinfo.h>
#endif

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
      return( std::to_string( val ) );
   }
   else if( trait == NumberOfProcessors ) 
   {
      return( std::to_string( get_nprocs() ) ); 
   }
   else if( ProcessorName <= trait && trait <= ProcessorFrequency )
   {
      /**
       * A bit ugly since we're processing /proc/cpuinfo
       */
      const std::string name( "model name" );
      const std::string freq( "cpu MHz" );
      FILE *fp( nullptr );
      errno = 0;
      fp = fopen( "/proc/cpuinfo", "r" );
      if( fp == nullptr )
      {
         perror( "Failed to open /proc/cpuinfo" );
         exit( EXIT_FAILURE );
      }
      const size_t buff_size( 100 );
      char  key[ buff_size ];
      char  value[ buff_size ];
      std::memset( &key, '\0', sizeof( char ) * buff_size );
      std::memset( &value, '\0', sizeof( char ) * buff_size );
      switch( trait )
      {
         case( ProcessorName ):
         {
            int count = EOF;
            while( (count = fscanf( fp, "%[^:]:%[^\n]\n", key, value ) ) != EOF )
            {
               if( count == 2 )
               {
                  if( strncmp( key, name.c_str() , name.length() - 1 ) == 0 )
                  {
                     fclose( fp );
                     return( std::string( value ) ); 
                  }
               }
            }
         }
         break;
         case( ProcessorFrequency ):
         {
            int count = EOF;
            while( (count = fscanf( fp, "%[^:]:%[^\n]\n", key, value ) ) != EOF )
            {
               if( count == 2 )
               {
                  if( strncmp( key, freq.c_str() , freq.length() - 1 ) == 0 )
                  {
                     fclose( fp );
                     errno = 0;
                     uint64_t frequency( strtof( value, (char**)NULL) * 1e6f );
                     if( errno != 0 )
                     {
                        perror( "Failed to convert frequency from /proc/cpuinfo" );
                        exit( EXIT_FAILURE );
                     }
                     return( std::to_string( frequency ) );
                  }
               }
            }


         }
         break;
         default:
            /* we'll return default zero at this point */
         break;
      }
   }
   else if( SystemName <= trait && trait <= MachineName )
   {
      /*
   SystemName,
   NodeName,
   OSRelease,
   OSVersion,
   MachineName,
      */
   }
   else if( UpTime <= trait && trait <= MemoryUnit )
   {
      /*
   UpTime,
   Loads,
   TotalMainMemory,
   FreeRam,
   SharedRam,
   BufferRam,
   TotalSwap,
   FreeSwap,
   NumberOfProcessesRunning,
   TotalHighMemory,
   FreeHighMemory,
   MemoryUnit,
       */
   }
#elif __APPLE__

#endif
   return( 0 );
}

std::string   
SystemInfo::getName( const Trait trait )
{
   static const std::string traitStrings[ Trait::N ] = {
      "LevelOneICacheSize",
      "LevelOneICacheAssociativity",
      "LevelOneICacheLineSize",
      "LevelOneDCacheSize",
      "LevelOneDCacheAssociativity",
      "LevelOneDCacheLineSize",
      "LevelTwoCacheSize",
      "LevelTwoCacheAssociativity",
      "LevelTwoCacheLineSize",
      "LevelThreeCacheSize",
      "LevelThreeCacheAssociativity",
      "LevelThreeCacheLineSize",
      "LevelFourCacheSize",
      "LevelFourCacheAssociativity",
      "LevelFourCacheLineSize",
      "NumberOfProcessors",
      "ProcessorName",
      "ProcessorFrequency",
      "SystemName",
      "NodeName",
      "OSRelease",
      "OSVersion",
      "MachineName",
      "UpTime",
      "Loads",
      "TotalMainMemory",
      "FreeRam",
      "SharedRam",
      "BufferRam",
      "TotalSwap",
      "FreeSwap",
      "NumberOfProcessesRunning",
      "TotalHighMemory",
      "FreeHighMemory",
      "MemoryUnit"
   };
   return( traitStrings[ trait ] );
}

size_t
SystemInfo::getNumTraits()
{
   return( Trait::N );
}
