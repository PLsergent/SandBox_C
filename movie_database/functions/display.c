#include "../headers/headers.h"
#include <json-c/json.h>

void print_movies(struct json_object * parsed_json) {
    struct json_object *movies;
    struct json_object *movie;
	struct json_object *title;
	struct json_object *director;
	struct json_object *release_year;
	struct json_object *main_actors;
    struct json_object *actor;
    struct json_object *duration;
    struct json_object *genre;

    json_object_object_get_ex(parsed_json, "movies", &movies);
    size_t n_movies;
    size_t n_actors;
    size_t i;

    n_movies = json_object_array_length(movies);

    printf("Found %lu movies\n", n_movies);

    for(i=0; i < n_movies; i++) {
		movie = json_object_array_get_idx(movies, i);
		printf("%s\n", json_object_to_json_string(movie));
	}
}