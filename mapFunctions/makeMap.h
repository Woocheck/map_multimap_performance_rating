#ifndef _MAKE_MAP_H_
#define _MAKE_MAP_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../personContainer/person.h"
#include "../timer/timer.h"


void sortTimers( std::vector<Timer>& listOfTimers )
{
    std::sort( listOfTimers.begin(), listOfTimers.end() );
    listOfTimers.erase( listOfTimers.begin() );
    if( !listOfTimers.empty() )listOfTimers.pop_back();
}

std::chrono::duration<double> averageTimeValue( std::vector<Timer>& listOfTimers )
{
    std::chrono::duration<double> sumTimeValue {};
    for( auto timer : listOfTimers ) sumTimeValue += timer.getDuration();

    sumTimeValue /= listOfTimers.size();
    return sumTimeValue;
}

template <class Map>
std::chrono::duration<double> testMakeMapOfPersons( Map& map, 
                              const std::vector<person::Person>& listOfPersons,  
                              long long recordsNumber )
{
    std::vector<Timer> listOfTimers;
    Timer makeMapTimer;
    int keySeed {0};

    makeMapTimer.start();

        for( auto person : listOfPersons )
        {   
            map[ keySeed * 10 ] = person;
            keySeed++;
        }
    
    makeMapTimer.stop();
    listOfTimers.push_back( makeMapTimer );
    
    sortTimers( listOfTimers );
    return averageTimeValue( listOfTimers );
}



#endif 
