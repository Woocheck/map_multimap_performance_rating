#ifndef _RESULTS_H_
#define _RESULTS_H_

#include <vector>
#include <iostream>
#include "./timer/timer.h"

struct ResultContainer
{
    std::vector<DurationTime> results;

    inline ResultContainer& operator+=( const ResultContainer& newResults)
    {
        for( auto result : newResults.results ) 
            results.push_back( result );
        return *this;
    }
    ResultContainer() = default;
    ResultContainer(std::vector<DurationTime>& result ): results( result ){};

    void print()
    {
        std::for_each(std::begin( results ), std::end( results ), [](DurationTime test){
            std::cout << test.containerType << " - " ;
            std::cout << test.numberElementsInContainer << " elements ";
            std::cout << " duration: " << test.duration.count() << std::endl;
        });
    }
};



#endif 
