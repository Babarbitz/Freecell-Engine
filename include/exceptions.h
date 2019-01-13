/**
    \file exceptions.h
    \author Lucas Zacharewicz
    \brief Defines exceptions for the rest of the program
    \date 6/4/2018
 */
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

/// Defines the invalid move exception
class invalid_move : public std::exception
{
   const char * what () const throw ()
   {
      return "invalid move";
   }
};

/// Defines the outside bounds exception
class outside_bounds : public std::exception
{
   const char * what () const throw ()
   {
      return "outside bounds";
   }
};

#endif
