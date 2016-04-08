/*
 *  xstd.cpp
 *
 *  17.02.2014, Fred Klaus <development@fkweb.de>
 *
 */

#include "xstd.h"

#include <cctype>

namespace xstd
{

    using std::string;

    const string & toLower(string & str)
    {
        for (string::size_type i = 0; i < str.size(); i++)
            str[i] = tolower(str[i]);
        return str;
    }

    const string & toUpper(string & str)
    {
        for (string::size_type i = 0; i < str.size(); i++)
            str[i] = toupper(str[i]);
        return str;
    }

} /* namespace xstd */
