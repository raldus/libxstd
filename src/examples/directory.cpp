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

#include "directory.h"
#include "fileinfo.h"
#include "datetime.h"

using namespace xstd;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        const char* path="c:\\";
    #else
        const char* path="/boot/";
    #endif

    const int width=28;

    cout.setf(std::ios::left);

    Directory de(path);
    cout << "*** All Files and Folders except dotdirs unsorted:" << '\n';
    for (Directory::iterator it = de.begin(); it != de.end(); it++)
    {
        FileInfo fi(path+*it);

        if (!fi.isValid()) cout << "error" << endl;
        DateTime dta(fi.atime());
        DateTime dtc(fi.ctime());
        DateTime dtm(fi.mtime());
        cout.width(width);
        cout << *it << "  ";
        cout.width(8);
        cout << std::right << fi.size()/1024;
        cout << " kb   ";
        cout.width(12);
        cout << std::left << dta.str() << '\n';
    }
    cout << endl << de.size() << " entries.\n" << endl;

    cout << "*** All Files and Folders sorted (case sensitive) with dotdirs (Linux):" << '\n';
    de.scan(path, true);
    de.sort(true);
    for (Directory::iterator it = de.begin(); it != de.end(); it++)
    {
        FileInfo fi(path+*it);

        if (!fi.isValid()) cout << "error" << endl;
        cout.width(width);
        cout << std::left << *it << "  ";
        cout.width(8);
        cout << std::right << fi.size()/1024;
        cout << " kb   " << '\n';
    }
    cout << endl << de.size() << " entries.\n" << endl;

    cout << "*** All Files and Folders sorted (case insensitive) except dotdirs (Linux):" << '\n';
    cout << "*** - standard -" << '\n';
    de.scan(path);
    de.sort(false);
    for (Directory::iterator it = de.begin(); it != de.end(); it++)
    {
        FileInfo fi(path+*it);

        if (!fi.isValid()) cout << "error" << endl;
        cout.width(width);
        cout << std::left << *it << "  ";
        cout.width(8);
        cout << std::right << fi.size()/1024;
        cout << " kb   " << '\n';
    }
    cout << endl << de.size() << " entries.\n" << endl;

//  cout << "*** All Files and Folders except dotfiles sorted:" << endl;
//  de.scan(path);
//  for (Directory::iterator it = de.begin(); it != de.end(); it++)
//  {
//      FileInfo fi(path+*it);
//
//      if (!fi.isValid()) cout << "error" << endl;
//      cout << *it << "  " << fi.size() << endl;
//  }
//  cout << endl << de.size() << " entries.\n" << endl;

    return 0;
}
