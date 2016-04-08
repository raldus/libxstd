/***************************************************************************
 *   Copyright (C) 2005 by Fred Klaus                                      *
 *   frednet@web.de                                                        *
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

#include <iostream>

#include <directory.h>
#include <fileinfo.h>
#include <datetime.h>

using namespace xstd;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    DateTime dt; // sets automatically the current time

    cout << "current time:" << "\n\n";
    cout << "timestring:" << dt.str() << "\n\n";

    cout << "day: " << dt.day() << "\n";
    cout << "month: " << dt.month() << "\n";
    cout << "year: " << dt.year() << "\n\n";

    cout << "hour: " << dt.hour() << "\n";
    cout << "minute: " << dt.min() << "\n";
    cout << "seconds: " << dt.sec() << "\n\n";

    return 0;
}
