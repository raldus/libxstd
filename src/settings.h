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

#ifndef SETTINGS_H_
#define SETTINGS_H_


#include <string>
#include <map>


namespace xstd
{
    using std::string;
    using std::ifstream;
    using std::map;

    /// File IO and Key/Value Handling of a Settings File
    /** handles all operations with Settings  */
    class Settings
    {
    public:
        enum Case {KEEP = 0, UPPER = 1, LOWER = 2};

        Settings(); /// Standard Constructor
        Settings(Case cas = KEEP); /// Constructor to select Upper-/Lower Case Sorage in Settings::map

        virtual ~Settings();

        int load(const string & filename);

        int            getInt     (const string & key);
        float          getFloat   (const string & key);
        const string & getString  (const string & key);
        const string & getStringU (const string & key);
        const string & getStringL (const string & key);

    private:
        string mFileName;

        map<string, string> mMap;

        Case mCase;
    };

} // xstd

#endif /* SETTINGS_H_ */
