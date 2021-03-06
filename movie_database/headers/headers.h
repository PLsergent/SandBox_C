#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#ifndef HEADERS_H
#define HEADERS_H

    struct json_object * load_movies();
    struct json_object * load_people();
    
    void print_movies(struct json_object * parsed_json);
    void print_people(struct json_object * parsed_json);

    void search_by_title(struct json_object * parsed_json, char * search_text);
#endif