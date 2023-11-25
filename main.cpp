#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;
    Movie(){}
    Movie(std::string name, int year,MovieType type, int price)
    :name(name),year(year),type(type),price(price){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    int getPrice() const{
        return price;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
    int price;
};

//1, rbegin


// Functor object
struct PriceFilter{
    PriceFilter(int minPrice):minPrice(minPrice){
    }
    bool operator()(Movie const &m){
        return m.getPrice() < minPrice;
    }
private:
    int minPrice;
};




template<typename T>
T findBiggest(T i, T j, T k){
    if(i > j && i > k){
        return i;
    }
    if(j > i && j > k){
        return j;
    }
    return k;
}

template<typename T, int size>
class MyArray{
public:

private:    
    T things[size];
};




int main(){

    MyArray<int,10> array;

    MyArray<Movie,5> array2;
    MyArray<std::string,5> array3;

    MyArray<Movie,100> array4;
    
    int i= 19;
    int j = 20;
    int k = 21;

    //int biggest = findBiggest<int>(i,j,k);
    int biggest = findBiggest(i,j,k);
    std::cout << biggest << std::endl;


    float i2= 19.0;
    float j2 = 20.0;
    float k2 = 21.0;

    float biggest2 = findBiggest(i2,j2,k2);
    std::cout << biggest2 << std::endl;


    std::string s1= "Stefan"; 
    std::string s2= "Oliver"; 
    std::string s3= "Josefine"; 

    std::string stringBig = findBiggest(s1,s2,s3);
    std::cout << stringBig << std::endl;



    // templates = generics
    // List<T>   ArrayList<T>

    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2001,Movie::MovieType::MovieType_Film,109),
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,200),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
    };


    //std::cin >> price;
    // I want to list all movies costing less than price
    // PriceFilter priceFilter(90);
    // auto i = std::begin(greatMovies),end = std::end(greatMovies);
    // while(i != end){
    //     i = std::find_if(i,end,priceFilter);
    //     // hello
    //     if(i != end){
    //         std::cout << i->getName() << std::endl;
    //         i++;
    //     }
    // }    

    // int price = 90;
    // //std::cin >> price;
    // // I want to list all movies costing less than price
    // auto i = std::begin(greatMovies),end = std::end(greatMovies);
    // while(i != end){
    //     i = std::find_if(i,end,[price](auto const &m){
    //         return m.getPrice() < price;
    //     });
    //     // hello
    //     if(i != end){
    //         std::cout << i->getName() << std::endl;
    //         i++;
    //     }
    // }






    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &item1,const Movie &item2){
        return item1.getName() > item2.getName();                    
    });

    std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });

    int resultPrice = std::accumulate(std::begin(greatMovies),std::end(greatMovies),0,[](int result,Movie const &m){
        return result + m.getPrice();
    });
    std::cout << resultPrice << std::endl;




    std::cout << "Forwards" << std::endl;
    std::for_each(std::begin(greatMovies),std::end(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });
    std::cout << "Backwards" << std::endl;

    std::for_each(std::rbegin(greatMovies),std::rend(greatMovies),[](auto const &m){
        std::cout << m.getName() << std::endl;
    });




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