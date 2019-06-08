#ifndef _INSETR_ELEMENT_H_
#define _INSETR_ELEMENT_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <random>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "makeMap.h"
#include "insertElement.h"


template <class Map>
std::chrono::duration<double> findElement( const Map& map, 
                                              const std::vector<person::Person>& personsToifind,
                                              const std::size_t elementsNumber ) 
{
    std::vector<Timer> listOfTimers;
    
    Map MapWithElementsToFind = map;
    for( std::size_t i {0} ; i < personsToifind.size() ; i ++ )
            {   
                    MapWithElementsToFind.insert( std::make_pair( personsToifind.at( i ) ,
                                                  std::rand() ) );
            };
    
    for ( int test { 0 }; test < 5 ; test++ )
    {
        Timer insertPeopleTimer( "Find people");
        Map singleTestMap = MapWithElementsToFind;
        insertPeopleTimer.start();

            for( std::size_t i {0} ; i < personsToifind.size() ; i ++ )
            {   
                    singleTestMap.find( personsToifind.at( i ) );
            }

        insertPeopleTimer.stop();

        listOfTimers.push_back( insertPeopleTimer );
    };
    discardExtremeValues ( listOfTimers );
    
    return averageTimeValue( listOfTimers );
}


#endif 