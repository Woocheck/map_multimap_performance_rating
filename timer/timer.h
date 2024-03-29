#ifndef __TIMER_H
#define __TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <typeindex>
#include <typeinfo>

enum class TypesOfTests { makeColection, insertElement, findElement, deleteElement };

struct DurationTime
{
    std::string containerType;
    TypesOfTests testType {};
    long numberElementsInContainer {};
    std::chrono::duration<double> duration;
    DurationTime() = default;
    DurationTime( std::string type ): containerType( type ) {};   
};
class Timer
{
    private:
        std::string id;
        std::chrono::time_point<std::chrono::steady_clock> timerStart;
        std::chrono::time_point<std::chrono::steady_clock> timerStop;
        std::chrono::duration<double> duration;

    public:
        Timer() = default;
        Timer( const std::string& s ): id( s ){};

        void start()
        {
            timerStart = ( std::chrono::steady_clock::now() );
        }

        void stop()
        {
            timerStop = ( std::chrono::steady_clock::now()) ;
            duration = timerStop - timerStart;
        }

        std::chrono::duration<double> getDuration() const
        {
            return duration;
        }

        bool operator<(const Timer& compared ) const
        {
        return ( duration < compared.getDuration() );
        }
};

#endif
