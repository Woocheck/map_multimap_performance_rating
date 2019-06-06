#ifndef _INSERT_ELEMENT_H_
#define _INSERT_ELEMENT_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "makeMap.h"

template <class Map>
std::chrono::duration<double> insertElements( Map& map, 
                                              const std::vector<person::Person>& personsToinsert ) 
{
    std::vector<Timer> listOfTimers;
    std::size_t i {1};
    for(auto person : personsToinsert)
    {   
        i++;
        if( map.count( i ) > 0 ) i++;
        Timer insertPeopleTimer( "Insert people id: " + i);
        insertPeopleTimer.start();

        map.insert( std::pair<std::size_t, person::Person>( map.size()/2 + i, person ));

        insertPeopleTimer.stop();
        listOfTimers.push_back( insertPeopleTimer );
    }
    
    sortTimers ( listOfTimers );
    return averageTimeValue( listOfTimers );
}

#endif 
