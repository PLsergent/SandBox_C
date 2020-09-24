#include <stdio.h>
#include "./headers/headers.h"

int main() {
   struct json_object * parsed_json_movies = load_movies();
   struct json_object * parsed_json_people = load_people();

   print_movies(parsed_json_movies);
   print_people(parsed_json_people);
}