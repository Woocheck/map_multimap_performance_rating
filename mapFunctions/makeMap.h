#ifndef _MAKE_MAP_H_
#define _MAKE_MAP_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iterator>
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
std::chrono::duration<double> makeMapOfPersons( Map& map, 
                              const std::vector<person::Person>& listOfPersons,  
                              long long recordsNumber , int keySeed = 0 )
{
    std::vector<Timer> listOfTimers;
    Timer makeMapTimer;

    makeMapTimer.start();

        for( auto person : listOfPersons )
        {   
            map.insert( std::make_pair( keySeed * 10 , person ) );
            keySeed++;
        }
    
    makeMapTimer.stop();
    listOfTimers.push_back( makeMapTimer );
    
    sortTimers( listOfTimers );
    return averageTimeValue( listOfTimers );
}

template<class Map>
void printMap( const Map& mapToPrint )
{
    for(auto person : mapToPrint)
        {
            std::cout << person.first << " - " << person.second.name << " ";
            std::cout << person.second.surname << " age: " << person.second.age;
            std::cout << " " << person.second.city << " PESEL: " << person.second.pesel << std::endl;
        }
}


#endif 
