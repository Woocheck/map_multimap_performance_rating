#ifndef _DELETE_ELEMENT_H_
#define _DELETE_ELEMENT_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "makeMap.h"

template <class Map>
std::chrono::duration<double> deleteElements( const Map& map, 
                                              const std::vector<person::Person>& personsToDelete) 
{
    std::vector<Timer> listOfTimers;
    
    Map MapWithElementsToDelete = map;
    for( std::size_t i { 0 } ; i < personsToDelete.size() ; i ++ )
            {   
                    MapWithElementsToDelete.insert( std::make_pair( personsToDelete.at( i ) ,
                                                  std::rand() ) );
            };
    
    for ( int test { 0 }; test < 5 ; test++ )
    {
        Timer insertPeopleTimer( "Find people");
        Map singleTestMap = MapWithElementsToDelete;
        insertPeopleTimer.start();

            for( std::size_t i {0} ; i < personsToDelete.size() ; i ++ )
            {   
                    singleTestMap.erase( personsToDelete.at( i ) );
            }

        insertPeopleTimer.stop();
        listOfTimers.push_back( insertPeopleTimer );
    };

    discardExtremeValues ( listOfTimers );
    return averageTimeValue( listOfTimers );
}

#endif