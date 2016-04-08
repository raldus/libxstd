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

#include "fileinfo.h"
#include "datetime.h"

#include <iostream>

using namespace xstd;


int main(int argc, char* argv[])
{
    #ifdef _WIN32
        const char* name="c:\\boot.ini";
    #else
        const char* name="/bin/ls";
    #endif

    const int width=16;

    FileInfo fi(name);

    DateTime dta(fi.atime());
    DateTime dtc(fi.ctime());
    DateTime dtm(fi.mtime());

    std::cout.setf(std::ios::left);

    std::cout << name << '\n'<< '\n';

    std::cout.width(width);
    std::cout << "isValid: " << std::boolalpha << fi.isValid() << '\n';

    std::cout.width(width);
    std::cout << "nlinks: " << fi.nlinks() << '\n';
    std::cout.width(width);
    std::cout << "uid: " << fi.uid() << '\n';
    std::cout.width(width);
    std::cout << "gid: " << fi.gid() << '\n';
    std::cout.width(width);
    std::cout << "size: " << fi.size() << '\n';
    std::cout.width(width);
    std::cout << "atime: " << fi.atime() << "  " << dta.str() << '\n';
    std::cout.width(width);
    std::cout << "mtime: " << fi.mtime() << "  " << dtc.str() << '\n';
    std::cout.width(width);
    std::cout << "ctime: " << fi.ctime() << "  " << dtm.str() << '\n';
    std::cout.width(width);
    std::cout << "file: " << std::boolalpha << fi.isFile() << '\n';
    std::cout.width(width);
    std::cout << "dir: " << std::boolalpha << fi.isDir() << '\n';
    std::cout.width(width);
    std::cout << "link: " << std::boolalpha << fi.isLink() << std::endl;
    std::cout.width(0);

    return 0;
}
