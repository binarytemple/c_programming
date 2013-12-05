#!/bin/bash

cat <<END > validate_boost_available_at_compile.cpp

#include <stdio.h>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/version.hpp>
#include <cstring>
#include <string>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

namespace po = boost::program_options;

int main(int argc, char **argv) {

    string message_text;

    po::options_description desc("Allowed options");
    desc.add_options()("help", "produce help message")
            ("name", po::value<string>(), "user to greet");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    const char * message_text_resolved = message_text.c_str();

    if (vm.count("help")) {
        cout << desc << "\n";
        return EXIT_SUCCESS;
    } else if (vm.count("name")) {
        string name = vm["name"].as<string>();
        cout << "Hello " << name << endl;
    } else {
        fprintf(stderr,"%s -- No arguments supplied, execute with --help flag for program options \n", argv[0]);
    }
    return (0);
}

END

g++ -c -g -O2  validate_boost_available_at_compile.cpp


g++ -o validate_boost_available_at_compile -g -O2 -L/usr/local/lib -Wl,-rpath,/usr/local/lib validate_boost_available_at_compile.o  -lboost_program_options-mt 


./validate_boost_available_at_compile
