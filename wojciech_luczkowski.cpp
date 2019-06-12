#include <map>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <ostream>

#include "./personContainer/person.h"
#include "./timer/timer.h"
#include "./mapFunctions/findElement.h"
#include "./mapFunctions/makeMap.h"
#include "./mapFunctions/insertElement.h"
#include "./mapFunctions/deleteElement.h"
#include "./result/result.h"
#include "./testingFunctions/testMap.h"



std::vector<person::Person> preparePeopleList( const long elementsNumber )
{
    std::vector<person::Person> peopleVector {};
    for ( int i = 0 ; i < elementsNumber ; ++i ) 
    {
        person::Person singlePerson( person::get_random_person() );
        peopleVector.push_back( singlePerson );
    }
    return peopleVector;
}

void saveResultsInFile( const ResultContainer& testsResults )
{
    std::ofstream out( "./mapscompairingresults.txt" ); 
    if (out.is_open())
  {
    for( const auto& test : testsResults.results )
    {
        out << test.containerType << ",";
        switch ( test.testType )
        {
        case TypesOfTests::makeColection :
            {
               out << "make_collection" << ","; 
            }
            break;
        case TypesOfTests::insertElement :
            {
               out << "insert_element" << ","; 
            }
            break;        
        case TypesOfTests::findElement :
            {
               out << "find_element" << ","; 
            }
            break;
        case TypesOfTests::deleteElement :
            {
               out << "delete_element" << ","; 
            }
            break;
        default:
            break;
        }
        out << test.numberElementsInContainer << ",";
        out << test.duration.count() << std::endl;
    }
  }
    out.close();
}

int main()
{
    
    ResultContainer testsResults {};  
    std::size_t maximalElementsNumber { 100000 };

    std::vector<person::Person> listOfPersons {};
    listOfPersons = preparePeopleList( maximalElementsNumber );
        
    std::vector<person::Person> smallListOfPersons {};
    smallListOfPersons = preparePeopleList( 100 );

    std::map< person::Person, long > map {};
    std::unordered_map< person::Person, long, person::PersonHash> multimap {};


    testsResults += testMapCreate( "std::map", map, listOfPersons);
    testsResults += testMapCreate( "std::multimap", multimap, listOfPersons );
    
    testsResults += testMapInsert( "std::map", map, listOfPersons, smallListOfPersons);
    testsResults += testMapInsert( "std::multimap", multimap, listOfPersons, smallListOfPersons);

    testsResults += testFindElement( "std::map", map, listOfPersons, smallListOfPersons);
    testsResults += testFindElement( "std::multimap", multimap, listOfPersons, smallListOfPersons);
    
    testsResults += testDeleteElement( "std::map", map, listOfPersons, smallListOfPersons);
    testsResults += testDeleteElement( "std::multimap", multimap, listOfPersons, smallListOfPersons);
    
    testsResults.print();
    saveResultsInFile( testsResults );
}
