#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
public:
    string title;
    string director;
    int year;
    int duration;

    Movie(string t, string d, int y, int dur) : title(t), director(d), year(y), duration(dur) {}
};

class Theater {
private:
    vector<Movie> movies;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void displayMovies() {
        cout << "Movies currently showing:" << endl;
        for (const auto& movie : movies) {
            cout << "Title: " << movie.title << ", Director: " << movie.director << ", Year: " << movie.year << ", Duration: " << movie.duration << " mins" << endl;
        }
    }
};

int main() {
    Theater theater;
    theater.addMovie(Movie("Inception", "Christopher Nolan", 2010, 148));
    theater.addMovie(Movie("The Shawshank Redemption", "Frank Darabont", 1994, 142));
    theater.addMovie(Movie("Pulp Fiction", "Quentin Tarantino", 1994, 154));

    theater.displayMovies();

    return 0;
}
