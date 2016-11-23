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

#ifndef DATETIME_H_
#define DATETIME_H_

#include <ctime>
#include <string>

namespace xstd
{
    using std::string;

    //! Date- and Timehandling.
    //! Covers Time and Date and reformating of them.
    //! \n\n<B>Example:</B>\n @include "datetime.cpp"
    //! @author Fred Klaus */
    class DateTime
    {

    public:
        DateTime();   /**< Constructor. Because null-time does not exist DateTime is set to current time */
        DateTime(time_t time);                      /**< Constuctor. @param time = time value. */
        DateTime(char day, int month, char year) {} /**< Constuctor. @param time = time value. */
        ~DateTime() {}                              /**< Standard Destructor. Does nothing */

        void set(time_t time);

        /** This is the number of full seconds since the top of the
            minute (normally in the range `0' through `59', but the
            actual upper limit is `60', to allow for leap seconds if leap
            second support is available */
        int sec() const {return mDateTime.tm_sec;}
        /** This is the number of full minutes since the top of the hour
            (in the range `0' through `59'). */
        int min() const {return mDateTime.tm_min;}
        /** This is the number of full hours past midnight (in the range
            `0' through `23').*/
        int hour() const {return mDateTime.tm_hour;}
        /** This is the ordinal day of the month (in the range `1'
            through `31').  Watch out for this one!  As the only ordinal
            number in the structure, it is inconsistent with the rest of
            the structure. */
        int day() const {return mDateTime.tm_mday;}
        /** This is the number of full calendar months since the
            beginning of the year + 1  (in the range `1' through `12'). */
        int month() const {return mDateTime.tm_mon+1;}
        /** This is the number of full calendar years. */
        int year() const {return mDateTime.tm_year+1900;}

        /** This is the number of full days since Sunday (in the range
           `0' through `6'). */
        int weekday() const {return mDateTime.tm_wday;}
        /** This is the number of full days since the beginning of the
           year (in the range `0' through `365'). */
        int yearday() const {return mDateTime.tm_yday;}

        //int yearweek() const {return mDateTime.tm_yday;} ************

        /** retrieves the simple time time_t
            @return The simple time like used in FileInfo. */
        time_t simple() const;

        bool isLocal();

        /** @todo dont hardcode and clean this. may use 0 as str for strftime to get len*/
        string str(const string & temp="%c");

    private:
        struct tm mDateTime;

    };
} // xstd



/** @fn string xstd::DateTime::str(const string & temp="%F")
    Generates a formatted time-string.
    @param temp = formating flags as string described below
    @return string = DateTime-string formated by specified flags.
    \n\n

    Ordinary characters appearing in the TEMPLATE are copied to the
    output string S; this can include multibyte character sequences.
    Conversion specifiers are introduced by a `%' character, followed
    by an optional flag which can be one of the following.  These flags
    are all GNU extensions. The first three affect only the output of
    numbers:


     `_'
           The number is padded with spaces.


     `-'
           The number is not padded at all.


     `0'
           The number is padded with zeros even if the format specifies
           padding with spaces.


     `^'
           The output uses uppercase characters, but only if this is
           possible ( Case Conversion).


    The default action is to pad the number with zeros to keep it a
    constant width.  Numbers that do not have a range indicated below
    are never padded, since there is no natural width for them.


    Following the flag an optional specification of the width is
    possible.  This is specified in decimal notation.  If the natural
    size of the output is of the field has less than the specified
    number of characters, the result is written right adjusted and
    space padded to the given size.


    An optional modifier can follow the optional flag and width
    specification.  The modifiers, which were first standardized by
    POSIX.2-1992 and by ISO C99, are:


     `E'
           Use the locale's alternate representation for date and time.
           This modifier applies to the `%c', `%C', `%x', `%X', `%y' and
           `%Y' format specifiers.  In a Japanese locale, for example,
           `%Ex' might yield a date format based on the Japanese
           Emperors' reigns.


     `O'
           Use the locale's alternate numeric symbols for numbers.  This
           modifier applies only to numeric format specifiers.


    If the format supports the modifier but no alternate representation
    is available, it is ignored.


    The conversion specifier ends with a format specifier taken from
    the following list.  The whole `%' sequence is replaced in the
    output string as follows:


     `%a'
           The abbreviated weekday name according to the current locale.


     `%A'
           The full weekday name according to the current locale.


     `%b'
           The abbreviated month name according to the current locale.


     `%B'
           The full month name according to the current locale.


     `%c'
           The preferred calendar time representation for the current
           locale.


     `%C'
           The century of the year.  This is equivalent to the greatest
           integer not greater than the year divided by 100.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%d'
           The day of the month as a decimal number (range `01' through
           `31').


     `%D'
           The date using the format `%m/%d/%y'.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%e'
           The day of the month like with `%d', but padded with blank
           (range ` 1' through `31').


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%F'
           The date using the format `%Y-%m-%d'.  This is the form
           specified in the ISO 8601 standard and is the preferred form
           for all uses.


           This format was first standardized by ISO C99 and by
           POSIX.1-2001.


     `%g'
           The year corresponding to the ISO week number, but without
           the century (range `00' through `99').  This has the same
           format and value as `%y', except that if the ISO week number
           (see `%V') belongs to the previous or next year, that year is
           used instead.


           This format was first standardized by ISO C99 and by
           POSIX.1-2001.


     `%G'
           The year corresponding to the ISO week number.  This has the
           same format and value as `%Y', except that if the ISO week
           number (see `%V') belongs to the previous or next year, that
           year is used instead.


           This format was first standardized by ISO C99 and by
           POSIX.1-2001 but was previously available as a GNU extension.


     `%h'
           The abbreviated month name according to the current locale.
           The action is the same as for `%b'.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%H'
           The hour as a decimal number, using a 24-hour clock (range
           `00' through `23').


     `%I'
           The hour as a decimal number, using a 12-hour clock (range
           `01' through `12').


     `%j'
           The day of the year as a decimal number (range `001' through
           `366').


     `%k'
           The hour as a decimal number, using a 24-hour clock like
           `%H', but padded with blank (range ` 0' through `23').


           This format is a GNU extension.


     `%l'
           The hour as a decimal number, using a 12-hour clock like
           `%I', but padded with blank (range ` 1' through `12').


           This format is a GNU extension.


     `%m'
           The month as a decimal number (range `01' through `12').


     `%M'
           The minute as a decimal number (range `00' through `59').


     `%n'
           A single `\n' (newline) character.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%p'
           Either `AM' or `PM', according to the given time value; or the
           corresponding strings for the current locale.  Noon is
           treated as `PM' and midnight as `AM'.  In most locales
           `AM'/`PM' format is not supported, in such cases `"%p"'
           yields an empty string.


     `%P'
           Either `am' or `pm', according to the given time value; or the
           corresponding strings for the current locale, printed in
           lowercase characters.  Noon is treated as `pm' and midnight
           as `am'.  In most locales `AM'/`PM' format is not supported,
           in such cases `"%P"' yields an empty string.


           This format is a GNU extension.


     `%r'
           The complete calendar time using the AM/PM format of the
           current locale.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.  In the POSIX locale, this format is equivalent to
           `%I:%M:%S %p'.


     `%R'
           The hour and minute in decimal numbers using the format
           `%H:%M'.


           This format was first standardized by ISO C99 and by
           POSIX.1-2001 but was previously available as a GNU extension.


     `%s'
           The number of seconds since the epoch, i.e., since 1970-01-01
           00:00:00 UTC.  Leap seconds are not counted unless leap
           second support is available.


           This format is a GNU extension.


     `%S'
           The seconds as a decimal number (range `00' through `60').


     `%t'
           A single `\\t' (tabulator) character.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%T'
           The time of day using decimal numbers using the format
           `%H:%M:%S'.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%u'
           The day of the week as a decimal number (range `1' through
           `7'), Monday being `1'.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%U'
           The week number of the current year as a decimal number
           (range `00' through `53'), starting with the first Sunday as
           the first day of the first week.  Days preceding the first
           Sunday in the year are considered to be in week `00'.


     `%V'
           The ISO 8601:1988 week number as a decimal number (range `01'
           through `53').  ISO weeks start with Monday and end with
           Sunday.  Week `01' of a year is the first week which has the
           majority of its days in that year; this is equivalent to the
           week containing the year's first Thursday, and it is also
           equivalent to the week containing January 4.  Week `01' of a
           year can contain days from the previous year.  The week
           before week `01' of a year is the last week (`52' or `53') of
           the previous year even if it contains days from the new year.


           This format was first standardized by POSIX.2-1992 and by
           ISO C99.


     `%w'
           The day of the week as a decimal number (range `0' through
           `6'), Sunday being `0'.


     `%W'
           The week number of the current year as a decimal number
           (range `00' through `53'), starting with the first Monday as
           the first day of the first week.  All days preceding the
           first Monday in the year are considered to be in week `00'.


     `%x'
           The preferred date representation for the current locale.


     `%X'
           The preferred time of day representation for the current
           locale.


     `%y'
           The year without a century as a decimal number (range `00'
           through `99').  This is equivalent to the year modulo 100.


     `%Y'
           The year as a decimal number, using the Gregorian calendar.
           Years before the year `1' are numbered `0', `-1', and so on.


     `%z'
           RFC 822/ISO 8601:1988 style numeric time zone (e.g., `-0600'
           or `+0100'), or nothing if no time zone is determinable.


           This format was first standardized by ISO C99 and by
           POSIX.1-2001 but was previously available as a GNU extension.


           In the POSIX locale, a full RFC 822 timestamp is generated by
           the format `"%a, %d %b %Y %H:%M:%S %z"' (or the equivalent
           `"%a, %d %b %Y %T %z"').


     `%Z'
           The time zone abbreviation (empty if the time zone can't be
           determined).


     `%%'
           A literal `%' character.


    The SIZE parameter can be used to specify the maximum number of
    characters to be stored in the array S, including the terminating
    null character.  If the formatted time requires more than SIZE
    characters, `strftime' returns zero and the contents of the array
    S are undefined.  Otherwise the return value indicates the number
    of characters placed in the array S, not including the terminating
    null character.
*/



#endif // DATETIME_H_
