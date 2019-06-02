#ifndef _INSETR_ELEMENT_H_
#define _INSETR_ELEMENT_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "makeMap.h"


template <class Map>
std::chrono::duration<double> findElement( Map& map, std::chrono::duration<double>& duration, 
                          std::vector<long long> ids)
{
    std::vector<Timer> listOfTimers;
    for(auto id : ids)
    {   
        Timer findForPeopleTimer( "Find people id: " + id );
        findForPeopleTimer.start();

        map.find( id );

        findForPeopleTimer.stop();
        listOfTimers.push_back( findForPeopleTimer );
    }
    
    sortTimers ( listOfTimers );
    return averageTimeValue( listOfTimers );
}


#endif 