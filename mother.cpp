#include <iostream>

#include "mother.h"

void declare_reserved_words() {
    reservations["may"] = may;
    reservations["ship"] = ship;
    reservations["lode"] = lode;
    reservations["cradle"] = cradle;
    reservations["i"] = i;
    reservations["you"] = you;
    reservations["create"] = create;
    reservations["pair"] = pair;
    reservations["help"] = help;
    reservations["show"] = show;
    reservations["delete"] = delete;
    reservations["add"] = add;
}

void help_func() {
    std::cout << "put help menu here" << std::endl;
    exit(0);
}

int main ( int argc, char *argv[] ) {
    declare_reserved_words();

    if ( argc < 2 ) {
        help_func();
    }

    switch ( reservations[argv[1]] ) {
        case may:
            if ( argc != 4 && argc != 5 ) { help_func(); }
            else {

            }
            break;
        case cradle:
            if ( argc != 4 ) { help_func(); }
            else {

            }
            break;
        case help:
        default:
            help_func();
            break;
    }
}
