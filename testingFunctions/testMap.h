#ifndef _TEST_MAP_H_
#define _TEST_MAP_H_
#include <iostream>
#include <map>
#include <algorithm>
#include <typeindex>
#include <typeinfo>
#include "../personContainer/person.h"
#include "../timer/timer.h"
#include "../mapFunctions/deleteElement.h"
#include "../mapFunctions/insertElement.h"
#include "../mapFunctions/findElement.h"
#include "../mapFunctions/makeMap.h"
#include "../result.h"

template<class Map>
ResultContainer testMapCreate( const std::string& container, Map& map,
                               const std::vector<person::Person>& listOfPersons)
{
    ResultContainer results;
    
    for(std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); elementsNumber *= 10 )
    {
        map.clear();
        DurationTime singleTest( container );
        singleTest.testType = TypesOfTests::makeColection;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = makeMapOfPersons( map, listOfPersons, elementsNumber );
        
        results.results.push_back( singleTest );
        std::cout << map.size() << " - map " << std::endl;
       
    }

  

   
    return results;
}

template<class Map>
ResultContainer testMapInsert( const std::string& container, Map& map,
                               const std::vector<person::Person>& listOfPersons,
                               const std::vector<person::Person>& smallListOfPersons )
{
    ResultContainer results;
    
    for(std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); elementsNumber *= 10 )
    {
        map.clear();
        makeMapOfPersons( map, listOfPersons, elementsNumber );
        std::cout << map.size() << " - before insert " << std::endl;
        DurationTime singleTest( container );
        singleTest.testType = TypesOfTests::insertElement;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = insertElements( map, smallListOfPersons);

        results.results.push_back( singleTest );
        std::cout << map.size() << " - after " << std::endl;
    }
    return results;
}

#endif