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

#include "directory.h"

#include <stddef.h>
#include <sys/types.h>
#if (MSVC)
	#include "windirent.h"
#else
	#include <dirent.h>
#endif (MSVC)


#include <algorithm>
#include <iostream>

namespace xstd
{

    Directory::Directory(const string & path, bool subdir, bool owndir)
    : std::vector<FileName>()
    {
        scan(path, subdir, owndir);
    }

    void Directory::scan(const string & path, bool subdir, bool owndir)
    {
        clear();

        DIR *dir;
        dir = opendir(path.c_str());
        if (dir == 0) return; /** @todo errorhandling !! */

        struct dirent *entry;
#if defined(_WIN32) || defined(_WIN64)
        while((entry=readdir(dir))) /**  @todo not threadsafe but readdir_r not in MinGW !! */
        {
            FileName fi(entry->d_name);
            if ((!subdir) && (fi == "..")) continue;
            if ((!owndir) && (fi == "." )) continue;
            push_back(fi);
        }
        free(entry); /** @todo this is a static portion of memory, need change ?? */
#else
        /** @todo cleanup */
        // following code is to ensure d_name is large enough.
        union
        {
            struct dirent d;
            char b[offsetof (struct dirent, d_name) + NAME_MAX + 1];
        } u;

        while (!readdir_r(dir, &u.d, &entry))
        {
            if (!entry) break;
            FileName fi(u.d.d_name);
            if ((!subdir) && (fi == "..")) continue;
            if ((!owndir) && (fi == ".")) continue;
            push_back(fi);
        }
#endif

        closedir(dir);
    }

    void Directory::sort()
    {
        std::sort(begin(), end());
    }

    void Directory::sort(bool casesensitive)
    {
        FileName::setCaseSensitiveCompare(casesensitive);
        std::sort(begin(), end());
    }

} // xstd
