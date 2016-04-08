
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
