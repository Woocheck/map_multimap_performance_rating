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
                               const std::vector<person::Person>& listOfPersons )
{
    ResultContainer result;
    
    for( std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); 
         elementsNumber *= 10 )
    {
        map.clear();
        DurationTime singleTest( container );

        singleTest.testType = TypesOfTests::makeColection;
        singleTest.containerType = container;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = makeMapOfPersons( map, listOfPersons, elementsNumber );
        result.results.push_back( singleTest );  
    }
    return result;
}

template<class Map>
ResultContainer testMapInsert( const std::string& container, Map& map,
                               const std::vector<person::Person>& listOfPersons,
                               const std::vector<person::Person>& smallListOfPersons )
{
    ResultContainer results;
    
    for( std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); 
         elementsNumber *= 10 )
    {
        map.clear();
        makeMapOfPersons( map, listOfPersons, elementsNumber );
        DurationTime singleTest( container );
        
        singleTest.testType = TypesOfTests::insertElement;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = insertElements( map, smallListOfPersons );

        results.results.push_back( singleTest );
    }
    return results;
}

template<class Map>
ResultContainer testFindElement( const std::string& container, Map& map,
                                 const std::vector<person::Person>& listOfPersons,
                                 const std::vector<person::Person>& smallListOfPersons )
{
    ResultContainer results;
    
    for( std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); 
         elementsNumber *= 10 )
    {
        map.clear();
        makeMapOfPersons( map, listOfPersons, elementsNumber );
        DurationTime singleTest( container );
        
        singleTest.testType = TypesOfTests::findElement;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = findElement( map, smallListOfPersons );

        results.results.push_back( singleTest );
    }
    return results;
}

template<class Map>
ResultContainer testDeleteElement( const std::string& container, Map& map,
                               const std::vector<person::Person>& listOfPersons,
                               const std::vector<person::Person>& smallListOfPersons )
{
    ResultContainer results;
    
    for( std::size_t elementsNumber {1}; elementsNumber <= listOfPersons.size(); 
         elementsNumber *= 10 )
    {
        map.clear();
        makeMapOfPersons( map, listOfPersons, elementsNumber );
        DurationTime singleTest( container );
        
        singleTest.testType = TypesOfTests::deleteElement;
        singleTest.numberElementsInContainer = elementsNumber;
        singleTest.duration = deleteElements( map, smallListOfPersons);

        results.results.push_back( singleTest );
    }
    return results;
}

#endif