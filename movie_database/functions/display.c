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

    printf("Found %lu movies\n\n", n_movies);

    for(i=0; i < n_movies; i++) {
		movie = json_object_array_get_idx(movies, i);

		json_object_object_get_ex(movie, "title", &title);
        json_object_object_get_ex(movie, "director", &director);
        json_object_object_get_ex(movie, "release_year", &release_year);
        json_object_object_get_ex(movie, "duration", &duration);
        json_object_object_get_ex(movie, "genre", &genre);
        json_object_object_get_ex(movie, "main_actors", &main_actors);

        n_actors = json_object_array_length(main_actors);
        size_t j;

        printf("Title: \033[1;37m %s\033[0m\n", json_object_get_string(title));
        printf("Director: \033[1;37m %s\033[0m\n", json_object_get_string(director));
        printf("Release year: \033[1;37m %s\033[0m\n", json_object_get_string(release_year));
        printf("Duration: \033[1;37m %s\033[0m\n", json_object_get_string(duration));
        printf("Genre: \033[1;37m %s\033[0m\n", json_object_get_string(genre));
        printf("Main actors: ");
        for(j=0; j < n_actors; j++) {
            actor = json_object_array_get_idx(main_actors, j);
            if (j == n_actors - 1) {
                printf("\033[1;37m %s\033[0m", json_object_get_string(actor));
            } else {
                printf("\033[1;37m%s\033[0m / ", json_object_get_string(actor));
            }
        }
        printf("\n");
        printf("==================================\n");
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

    printf("Found %lu people\n\n", n_people);

    for(i=0; i < n_people; i++) {
		person = json_object_array_get_idx(people, i);

        json_object_object_get_ex(person, "last_name", &last_name);
        json_object_object_get_ex(person, "first_name", &first_name);
        json_object_object_get_ex(person, "date_of_birth", &date_of_birth);
        json_object_object_get_ex(person, "nationality", &nationality);

        printf("Lastname: \033[1;37m %s\033[0m\n", json_object_get_string(last_name));
        printf("Firstname: \033[1;37m %s\033[0m\n", json_object_get_string(first_name));
        printf("Date of birth: \033[1;37m %s\033[0m\n", json_object_get_string(date_of_birth));
        printf("Nationality:  \033[1;37m %s\033[0m\n", json_object_get_string(nationality));
        printf("==================================\n");
	}
}