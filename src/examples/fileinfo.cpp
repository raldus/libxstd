
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
