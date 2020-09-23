#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#ifndef HEADERS_H
#define HEADERS_H

    struct json_object * load_movies();
    struct json_object * load_persons();
    void print_movies(struct json_object * parsed_json);
    void print_directors();
    void search(char * title);
#endif