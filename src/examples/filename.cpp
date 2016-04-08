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

#include "filename.h"

#include <iostream>

using namespace xstd;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        FileName fn1("c:\\winnt\\win.1.ini");
    #else
        FileName fn1("/usr/bin/test.1.tst");
    #endif

    FileName fn=fn1; // copytest

    cout << "filename: " << fn << endl;
    cout << "qualified: " << fn.qualified() << endl;
    cout << "base+ext: " << fn.base() << endl;
    cout << "base-ext: " << fn.base(false) << endl;
    cout << "path: " << fn.path() << endl;
    cout << "relpath: " << fn.relpath() << endl;
    cout << "ext+dot: " << fn.ext() << endl;
    cout << "ext-dot: " << fn.ext(false) << endl;

    cout << "\n--------------------\n" << endl;

    fn.setBase("changed");
    fn.setExt("cgd");
    #ifdef _WIN32
        fn.setPath("\\1\\2\\3\\");
    #else
        fn.setPath("/1/2/3/");
    #endif

    cout << "filename: " << fn << endl;
    cout << "qualified: " << fn.qualified() << endl;
    cout << "base+ext: " << fn.base() << endl;
    cout << "base-ext: " << fn.base(false) << endl;
    cout << "path: " << fn.path() << endl;
    cout << "relpath: " << fn.relpath() << endl;
    cout << "ext+dot: " << fn.ext() << endl;
    cout << "ext-dot: " << fn.ext(false) << endl;

    cout << "\n--------------------\n" << endl;

    #ifdef _WIN32
        FileName fn2("c:\\winnt\\win");
    #else
        FileName fn2("/usr/bin/test");
    #endif
    cout << "filename: " << fn2 << endl;
    cout << "qualified: " << fn2.qualified() << endl;
    cout << "base+ext: " << fn2.base() << endl;
    cout << "base-ext: " << fn2.base(false) << endl;
    cout << "path: " << fn2.path() << endl;
    cout << "relpath: " << fn2.relpath() << endl;
    cout << "ext+dot: " << fn2.ext() << endl;
    cout << "ext-dot: " << fn2.ext(false) << endl;

    cout << "\n--------------------\n" << endl;

    #ifdef _WIN32
        FileName fn3("c:\\.winnt\\.win.1.ini");
    #else
        FileName fn3("/.usr/bin/.test.1.tst");
    #endif

    cout << "filename: " << fn3 << endl;
    cout << "qualified: " << fn3.qualified() << endl;
    cout << "base+ext: " << fn3.base() << endl;
    cout << "base-ext: " << fn3.base(false) << endl;
    cout << "path: " << fn3.path() << endl;
    cout << "relpath: " << fn3.relpath() << endl;
    cout << "ext+dot: " << fn3.ext() << endl;
    cout << "ext-dot: " << fn3.ext(false) << endl;

    cout << "\n--------------------\n" << endl;

    #ifdef _WIN32
        FileName fn4("c:\\.winnt\\.win");
    #else
        FileName fn4("/usr/.bin/.test");
    #endif

    cout << "filename: " << fn4 << endl;
    cout << "qualified: " << fn4.qualified() << endl;
    cout << "base+ext: " << fn4.base() << endl;
    cout << "base-ext: " << fn4.base(false) << endl;
    cout << "path: " << fn4.path() << endl;
    cout << "relpath: " << fn4.relpath() << endl;
    cout << "ext+dot: " << fn4.ext() << endl;
    cout << "ext-dot: " << fn4.ext(false) << endl;

    return 0;
}
