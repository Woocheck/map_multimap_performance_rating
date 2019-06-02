#include <map>
#include <unordered_map>
#include <map>
#include "./personContainer/person.h"
#include "./timer/timer.h"
#include "./mapFunctions/findElement.h"
#include "./mapFunctions/makeMap.h"
#include "./mapFunctions/insertElement.h"
#include "./mapFunctions/deleteElement.h"




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

int main(int argc, char ** argv)
{
   
    std::vector<person::Person> listOfPersons {};
    listOfPersons = preparePeopleList(1000);

    std::map<std::size_t, person::Person> map {};
    std::multimap<std::size_t, person::Person> multimap {};

    
    std::vector<DurationTime> testsResults;
    std::vector<long long> ids;
    
    
    std::chrono::duration<double> x = testMakeMapOfPersons(map,listOfPersons, 100);
    printMap( map );

    
}
