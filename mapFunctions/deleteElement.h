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
std::chrono::duration<double> deleteElements( Map& map, const Map& personsToDelete ) 
{
    std::vector<Timer> listOfTimers;
    for(auto person : personsToDelete)
    {   
        Timer deletePeopleTimer( "Delete people id: " + person.first );
        deletePeopleTimer.start();

        map.erase( person.first );

        deletePeopleTimer.stop();
        listOfTimers.push_back( deletePeopleTimer );
    }
    
    sortTimers ( listOfTimers );
    return averageTimeValue( listOfTimers );
}

#endif