/* Movie.h - Header for Movie class
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Review Exercise
 *
 *    Instance variables:
 *        title - the title of the movie
 *        year - the year the movie was released
 *        revenue - world-wide gross in billions of dollars
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std ;

class Movie {

    // instance variables
    private:
        string title ;
        int year ;
        double revenue ;

    // function prototypes (defined in the implementation file)
    public:
        Movie() ;
        Movie(string, int, double) ;
        string getTitle() ;
        int getYear() ;
        double getRevenue() ;
        void setTitle(string) ;
        void setYear(int) ;
        void setRevenue(double) ;
} ;

#endif


