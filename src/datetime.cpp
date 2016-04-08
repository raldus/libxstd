/*
 *  datetime.cpp
 *
 *  18.02.2014, Fred Klaus <development@fkweb.de>
 *
 */


#include "datetime.h"

namespace xstd
{
    using std::string;

    DateTime::DateTime()
    {
        set(0);
    }

    DateTime::DateTime(time_t time)
    {
        set(time);
    }

    void DateTime::set(time_t time)
    {
        if (!time) time=::time(0);
    #ifdef _WIN32
        struct tm *tmp;
        tmp=localtime(&time); // @todo not threadsafe but localtime_r not in MinGW !! */
        mDateTime = *tmp;
    #else
        localtime_r(&time, &mDateTime); // @todo errorhandling */
    #endif
    }

    string DateTime::str(const string & temp)
    {
        const char size = 64; // @todo dont hardcode and clean this. may use 0 as str for strftime to get len*/
        char str[size];
        if (strftime(str, size, temp.c_str(), &mDateTime)) return string(str);
        else return string("");
    }

}

