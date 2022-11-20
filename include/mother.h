#ifndef MOTHER_H_
#define MOTHER_H_

#include <map>
#include <string>

enum reserved_words {   may,
                        ship,
                        lode,
                        cradle,
                        i,
                        you,
                        create,
                        pair,
                        help,
                        show,
                        add
                        };

std::map<std::string, reserved_words> reservations;

void declare_reserved_words();
void help_func();

#endif
