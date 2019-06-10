#ifndef _RESULTS_H_
#define _RESULTS_H_

#include <vector>
#include <iostream>
#include <iomanip>

#include "./timer/timer.h"

struct ResultContainer
{
    std::vector<DurationTime> results;

    ResultContainer() = default;
    ResultContainer(std::vector<DurationTime>& result ): results( result ){};

    inline ResultContainer& operator+=( const ResultContainer& newResults )
    {
        for( auto result : newResults.results ) 
            results.push_back( result );
        return *this;
    }

    void print()
    {
        std::for_each( std::begin( results ), std::end( results ), [](DurationTime test )
        {
            std::cout << std::setw( 15 ) << std::left << test.containerType << " - " ;
            std::cout << std::setw( 10 ) << std::right <<test.numberElementsInContainer 
                      << " elements ";
            std::cout << " duration: " << std::setw( 12 ) << std::setprecision( 8 ) << std::fixed 
                      << test.duration.count() << " s" << std::endl;
        });
    }
};



#endif 
