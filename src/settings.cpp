/*
 *  settings.cpp
 *
 *  07.02.2014, Fred Klaus <development@fkweb.de>
 *
 */

#include "settings.h"

#include "xstd.h" // toLower & toUpper


#include <cstdlib>
#include <cctype>
#include <fstream>


namespace xstd
{

    Settings::Settings()
    {
        mMap.clear();
        mFileName.clear();
        mCase = KEEP;
    }

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
