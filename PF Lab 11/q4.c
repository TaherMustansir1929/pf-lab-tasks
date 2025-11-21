#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define MAX_MOVIES 10

typedef struct {
    char title[MAX_STR_LEN];
    char genre[MAX_STR_LEN];
    char director[MAX_STR_LEN];
    int releaseYear;
    float rating;
} Movie;


void displayMovie(const Movie *movie) {
    printf("  - Title: %s\n", movie->title);
    printf("    Genre: %s\n", movie->genre);
    printf("    Director: %s\n", movie->director);
    printf("    Year: %d\n", movie->releaseYear);
    printf("    Rating: %.1f / 10.0\n", movie->rating);
}

void displayAllMovies(const Movie *movies, int count) {
    printf("\n--- All Movies in Catalog (%d) ---\n", count);
    if (count == 0) {
        printf("No movies currently in the system.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Movie #%d:\n", i + 1);
        displayMovie(&movies[i]);
    }
    
}


void searchMoviesByGenre(const Movie *movies, int count, const char *searchGenre) {
    int foundCount = 0;
    
    printf("\n--- Search Results for Genre: '%s' ---\n", searchGenre);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0) {
            displayMovie(&movies[i]);
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("No movies found matching the genre '%s'.\n", searchGenre);
    } else {
        printf("Found %d movie(s) in the '%s' genre.\n", foundCount, searchGenre);
    }
}

int addNewMovie(Movie *movies, int *count) {
    if (*count >= MAX_MOVIES) {
        printf("\n*** ERROR: Movie catalog is full! Cannot add more than %d movies. ***\n", MAX_MOVIES);
        return 0;
    }

    Movie *newMovie = &movies[*count];
    
    printf("\n--- Add New Movie ---\n");
    
    
    printf("Enter Title (one word): ");
    scanf("%s", newMovie->title);
    
    printf("Enter Genre (e.g., Action, Drama, Comedy): ");
    scanf("%s", newMovie->genre);
    
    printf("Enter Director (one word): ");
    scanf("%s", newMovie->director);
    
    printf("Enter Release Year: ");
    scanf("%d", &newMovie->releaseYear);
    
    printf("Enter Rating (e.g., 8.5): ");
    scanf("%f", &newMovie->rating);

    while (getchar() != '\n'); 

    (*count)++;
    printf("*** Movie '%s' added successfully! ***\n", newMovie->title);
    return 1;
}

int main() {
    Movie movieCatalog[MAX_MOVIES];
    int movieCount = 0;

    
    strcpy(movieCatalog[movieCount].title, "Prestige");
    strcpy(movieCatalog[movieCount].genre, "Drama");
    strcpy(movieCatalog[movieCount].director, "Nolan");
    movieCatalog[movieCount].releaseYear = 2006;
    movieCatalog[movieCount].rating = 8.5; 
    movieCount++;

    
    strcpy(movieCatalog[movieCount].title, "Matrix");
    strcpy(movieCatalog[movieCount].genre, "Action");
    strcpy(movieCatalog[movieCount].director, "Wachowskis");
    movieCatalog[movieCount].releaseYear = 1999;
    movieCatalog[movieCount].rating = 8.7; 
    movieCount++;
    
    
    strcpy(movieCatalog[movieCount].title, "Godfather");
    strcpy(movieCatalog[movieCount].genre, "Drama");
    strcpy(movieCatalog[movieCount].director, "Coppola");
    movieCatalog[movieCount].releaseYear = 1972;
    movieCatalog[movieCount].rating = 9.2;
    movieCount++;
    
    printf("MOVIE INFORMATION MANAGEMENT SYSTEM (C)\n");

    
    displayAllMovies(movieCatalog, movieCount);

    
    searchMoviesByGenre(movieCatalog, movieCount, "Drama");
    
    
    searchMoviesByGenre(movieCatalog, movieCount, "Action");

    
    searchMoviesByGenre(movieCatalog, movieCount, "Horror");

    
    addNewMovie(movieCatalog, &movieCount);
    displayAllMovies(movieCatalog, movieCount);


    return 0;
}