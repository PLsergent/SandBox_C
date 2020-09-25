// Pierre-Louis SERGENT et Younes BOUCHAKOUR
// TP Cinema BDD

#include <stdio.h>
#include "./headers/headers.h"

int main() {
   int choice;
   struct json_object * parsed_json_movies;
   struct json_object * parsed_json_people;

   do {
      printf("\033[01;33m");
      printf("\n==========Movie database==========\n\n");
      printf("\033[0m");
      
      printf("\033[1;34m");
      printf("Menu :\n");
      printf("\033[0m");
      
      printf("1. Display all movies\n");
      printf("2. Display all actors / directors\n");
      printf("3. Search a movie by title\n");
      printf("4. Add a movie\n");
      printf("0. Quit\n");

      printf("\033[1;31m");
      printf("Your choice : ");
      printf("\033[0m");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
         case 1:
            parsed_json_movies = load_movies();
            print_movies(parsed_json_movies);
            break;

         case 2:
            parsed_json_people = load_people();
            print_people(parsed_json_people);
            break;
         
         case 3:
            parsed_json_movies = load_movies();
            char search_text[256];
            printf("(Enter a movie title) : ");
            scanf("%s", search_text);
            printf("\n");
            search_by_title(parsed_json_movies, search_text);
            break;
         
         case 4:
            // statements
            break;

         case 0:
            printf("Exit program...");
            break;
         
         default:
            printf("Please make choose a number between 1 to 4.\n\n");
      }
   } while (choice != 0);
}