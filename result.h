#ifndef _RESULTS_H_
#define _RESULTS_H_

#include <vector>
#include "./timer/timer.h"

struct ResultContainer
{
    std::vector<DurationTime> results;

    inline ResultContainer& operator+=( const ResultContainer& newResults)
    {
        for( auto result : newResults.results ) results.push_back( result );
        //results.emplace( results.end(), newResults.results.begin(), newResults.results.end() );
    }
    ResultContainer() = default;
    ResultContainer(std::vector<DurationTime>& result ): results( result ){};
};

#endif 
