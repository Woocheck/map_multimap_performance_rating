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
std::chrono::duration<double> insertElements( Map& map, const std::vector<person::Person>& personsToinsert ) 
{
    std::vector<Timer> listOfTimers;
    for(auto person : personsToinsert)
    {   
        Timer insertPeopleTimer( "Insert people id: " + person.first );
        insertPeopleTimer.start();

        map.insert( std::pair<std::size_t, person::Person>(  , person ));

        insertPeopleTimer.stop();
        listOfTimers.push_back( insertPeopleTimer );
    }
    
    sortTimers ( listOfTimers );
    return averageTimeValue( listOfTimers );
}

#endif 
