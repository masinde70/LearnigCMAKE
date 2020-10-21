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

    path p;
    for (; argc > 1; --argc, ++argv)
        p /= argv[1]; // compose path p from the command line arguments

        cout << "\ncomposed path:\n";
        cout << " operator<<()------:" << p << "\n";
        cout << " make_preferred()----:" << p.make_preferred() << "\n";

        cout << "\nelements:\n";
        for (auto element : p)
            cout << " " << element <<"\n";

        cout << "\nobservers, native format:"<<endl;
        #ifdef BOOST_POSIX_API
            cout << " native()-----:" <<p.native() <<endl;
            cout << " c_str()-----: "<<p.c_str() <<endl;
        #else // BOOST_WINDOWS_API
}