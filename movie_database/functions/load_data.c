#include "../headers/headers.h"
#include <json-c/json.h>

struct json_object * load_movies() {
    FILE *fp;
	char buffer[10000];
	
    fp = fopen("./data/movies.json", "r");
	fread(buffer, 10000, 1, fp);
	fclose(fp);

	return json_tokener_parse(buffer);
}

struct json_object * load_people() {
    FILE *fp;
	char buffer[10000];
	
    fp = fopen("./data/people.json", "r");
	fread(buffer, 10000, 1, fp);
	fclose(fp);

	return json_tokener_parse(buffer);
}