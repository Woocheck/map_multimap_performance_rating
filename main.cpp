#include <map>
#include <unordered_map>
#include <map>
#include "./personContainer/person.h"
#include "./timer/timer.h"


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
   {
        std::vector<person::Person> listOfPersons {};
        listOfPersons = preparePeopleList(1000);
        
        for(auto person : listOfPersons)
        {
            std::cout << person << std::endl;
        }
    }
    {
    
    }
}
