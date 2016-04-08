
#include <iostream>

#include <directory.h>
#include <fileinfo.h>
#include <datetime.h>

using namespace xstd;

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    DateTime dt; // sets automatically the current time

    cout << "current time:" << "\n\n";
    cout << "timestring:" << dt.str() << "\n\n";

    cout << "day: " << dt.day() << "\n";
    cout << "month: " << dt.month() << "\n";
    cout << "year: " << dt.year() << "\n\n";

    cout << "hour: " << dt.hour() << "\n";
    cout << "minute: " << dt.min() << "\n";
    cout << "seconds: " << dt.sec() << "\n\n";

    return 0;
}
