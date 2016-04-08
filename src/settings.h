/*
 *  settings.h
 *
 *  07.02.2014, Fred Klaus <development@fkweb.de>
 *
 */

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

} /* namespace xstd */

#endif /* SETTINGS_H_ */
