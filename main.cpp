#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(std::string name, int year,MovieType type)
    :name(name),year(year),type(type){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
};



int main(){
    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2001,Movie::MovieType::MovieType_Film),
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film),
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv),
        Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv),
    };
    // is there any movie created in 2000
    // bool found = false;
    // std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
    //     if(m.getYear() == 2000){
    //         found = true;
    //         break;
    //     }
    // });    
    int count = std::count_if(std::begin(greatMovies),std::end(greatMovies),[](Movie const &movie){
        return movie.getYear()  > 2010;
    });

    bool found = std::any_of(std::begin(greatMovies),std::end(greatMovies),[](Movie const &movie){
        return movie.getYear()  == 2000;
    });


    // std::for_each(greatMovies.begin(),greatMovies.end(),[](auto const &m){
    //     std::cout << m.getName() << std::endl;
    // });

    int i[123];

    std::cout << "Forwards" << std::endl;
    std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });
//    std::cout << "Backwards" << std::endl;

    // std::for_each(std::end(greatMovies)-1,std::begin(greatMovies)-1,[](auto const &m){
    //     std::cout << m.getName() << std::endl;
    // });


    // for(int i = 0; i < greatMovies.size();i++){
    //     std::cout << greatMovies[i].getName() << std::endl;
    //     if(i == 1){
    //         break;
    //     }
    // }

    // for(auto const &m : greatMovies ){
    //     std::cout << m.getName() << std::endl;
    // }



}