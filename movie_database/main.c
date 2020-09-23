#include <stdio.h>
#include "./headers/headers.h"

int main() {
   struct json_object * parsed_json = load_movies();
   print_movies(parsed_json);
}