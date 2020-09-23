#include "../headers/headers.h"
#include <json-c/json.h>

struct json_object * load_movies() {
    FILE *fp;
	char buffer[1024];
	
    fp = fopen("./data/movies.json", "r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	return json_tokener_parse(buffer);
}

struct json_object * load_persons() {
    FILE *fp;
	char buffer[1024];
	
    fp = fopen("../data/persons.json","r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);

	return json_tokener_parse(buffer);
}