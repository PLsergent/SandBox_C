#include "../headers/headers.h"
#include <json-c/json.h>
#include <regex.h>

void search_by_title(struct json_object * parsed_json, char * search_text) {
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

    regex_t regex;
    int result;

    n_movies = json_object_array_length(movies);

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

        const char * movie_title = json_object_get_string(title);
        result = regcomp(&regex, movie_title, REG_ICASE);
        result = regexec(&regex, search_text, 0, NULL, 0);

        if (result == 0) {
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
}