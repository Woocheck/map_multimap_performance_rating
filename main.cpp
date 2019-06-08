#include <map>
#include <unordered_map>
#include <map>
#include "./personContainer/person.h"
#include "./timer/timer.h"
#include "./mapFunctions/findElement.h"
#include "./mapFunctions/makeMap.h"
#include "./mapFunctions/insertElement.h"
#include "./mapFunctions/deleteElement.h"
#include "./result.h"
#include "./testingFunctions/testMap.h"



std::vector<person::Person> preparePeopleList( const long elementsNumber)
{
    std::vector<person::Person> peopleVector {};
    for ( int i = 0 ; i < elementsNumber ; ++i ) 
    {
        person::Person singlePerson( person::get_random_person() );
        peopleVector.push_back( singlePerson );
    }
    return peopleVector;
}



int main(int argc, char ** argv)
{
    
    ResultContainer testsResults {};  
    std::size_t maximalElementsNumber { 1000 };

    std::vector<person::Person> listOfPersons {};
    listOfPersons = preparePeopleList( maximalElementsNumber );
    std::map< person::Person, long > map {};
    std::unordered_multimap< person::Person, long, person::PersonHash> multimap {};
    
    std::vector<person::Person> smallListOfPersons {};
    smallListOfPersons = preparePeopleList(100);


    testsResults += testMapCreate( "std::map", map, listOfPersons);
    testsResults += testMapCreate( "std::multimap", multimap, listOfPersons );
    
    testsResults += testMapInsert( "std::map", map, listOfPersons, smallListOfPersons);
    testsResults += testMapInsert( "std::multimap", multimap, listOfPersons, smallListOfPersons);

    testsResults += testFindElement( "std::map", map, listOfPersons, smallListOfPersons);
    testsResults += testFindElement( "std::multimap", multimap, listOfPersons, smallListOfPersons);
   
    testsResults.print();
}
