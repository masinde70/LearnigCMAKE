#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

using namespace boost::filesystem;

const char *say_what(bool b) { return b ? "true" : "false";}

int main(int argc, char * argv[]){
    if (argc < 2){
        cout << "Usage: path_info path element [path_element....]\n";
        "compose a path via operator/= from one or more path-element arguments\n"
        "Example: path_info fooo/bar baz\n";

        #ifdef BOOST_POSIX_API
                    "       would report path info about the composed foo/bar/baz\n";
        #else // BOOST_WINDOWS_API
                    "       Would report inof about the composed path foo/bar\\baz\n";
        #endif
            return 1;
    }
}