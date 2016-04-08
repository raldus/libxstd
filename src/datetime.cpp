/***************************************************************************
 *   Copyright (C) by Fred Klaus                                           *
 *       development@fkweb.de                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

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

