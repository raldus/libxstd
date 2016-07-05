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

#include "settings.h"
#include "xstd.h" // toLower & toUpper

#include <cstdlib>
#include <cctype>
#include <fstream>

namespace xstd
{

    Settings::Settings(Case cas)
    {
        mMap.clear();
        mFileName.clear();
        mCase = cas;
    }

    Settings::~Settings() {};

    int Settings::load(const string & filename)
    {
        mFileName = filename;
        ifstream inFile(filename.c_str(), std::istream::in);

        mMap.clear();

        string strLine, strKey, strValue;
        string::iterator itLine;

        bool bKey = true;
        bool bBlanks = false;

        while (getline(inFile, strLine)) // TODO Errorhandling
        {
            if (strLine.find('=') == strLine.npos) continue;

            strKey.clear();
            strValue.clear();

            bKey = true;
            bBlanks = false;

            for (itLine = strLine.begin(); itLine != strLine.end(); itLine++)
            {
                if (!bKey && (*itLine == '"'))
                {
                    if (!bBlanks) bBlanks = true; else bBlanks = false;
                    continue;
                }
                if (!bBlanks && isspace(*itLine)) continue;
                if (*itLine == '#') break;
                if (*itLine == '=')
                {
                    bKey = false;
                    continue;
                }

                bKey ? strKey.push_back(*itLine) : strValue.push_back(*itLine);
            }

            if (strValue.empty()) continue;

            switch (mCase)
            {
                case KEEP:  mMap[strKey]          =         strValue;  break;
                case UPPER: mMap[toUpper(strKey)] = toUpper(strValue); break;
                case LOWER: mMap[toLower(strKey)] = toLower(strValue); break;
                default: break;
            }

        }

        inFile.close();

        return 0;
    }

    int Settings::getInt(const string& key)
    {
        return atoi(mMap[key].c_str());
    }

    float Settings::getFloat(const string& key)
    {
        return atof(mMap[key].c_str());
    }

    const string & Settings::getString(const string & key)
    {
        return mMap[key];
    }

    const string & Settings::getStringU(const string & key)
    {
        return toUpper(mMap[key]);
    }

    const string & Settings::getStringL(const string & key)
    {
        return toLower(mMap[key]);
    }

} // xstd
