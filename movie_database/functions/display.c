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

void print_people(struct json_object * parsed_json) {
    struct json_object *people;
    struct json_object *person;

    struct json_object *id;
    struct json_object *last_name;
	struct json_object *first_name;
	struct json_object *date_of_birth;
	struct json_object *nationality;

    json_object_object_get_ex(parsed_json, "people", &people);
    size_t n_people;
    size_t i;

    n_people = json_object_array_length(people);

    printf("Found %lu people\n", n_people);

    for(i=0; i < n_people; i++) {
		person = json_object_array_get_idx(people, i);
		printf("%s\n", json_object_to_json_string(person));
	}
}