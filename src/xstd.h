/*
 *  xstd.h
 *
 *  17.02.2014, Fred Klaus <development@fkweb.de>
 *
 */

#ifndef XSTD_H_
#define XSTD_H_

#include <string>

namespace xstd
{
    using std::string;

    const string & toLower(string & str); /// converts a [std::string] to lower Case
    const string & toUpper(string & str); /// converts a [std::string] to upper Case

} /* namespace xstd */

#endif /* XSTD_H_ */
