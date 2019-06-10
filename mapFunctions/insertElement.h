#ifndef _INSERT_ELEMENT_H_
#define _INSERT_ELEMENT_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <random>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "makeMap.h"


template <class Map>
std::chrono::duration<double> insertElements( const Map& map, 
                              const std::vector<person::Person>& personsToinsert) 
{
    std::vector<Timer> listOfTimers;
    
    for ( int test { 0 }; test < 5 ; test++ )
    {
        Timer insertPeopleTimer( "Insert people");
        Map singleTestMap = map;
        insertPeopleTimer.start();

            for( std::size_t i {0} ; i < personsToinsert.size() ; i ++ )
            {   
                singleTestMap.insert( std::make_pair( personsToinsert.at( i ),
                                      std::rand() ) );
            }
            
        insertPeopleTimer.stop();
        listOfTimers.push_back( insertPeopleTimer );
    };

    discardExtremeValues ( listOfTimers );
    return averageTimeValue( listOfTimers );
}

#endif 
