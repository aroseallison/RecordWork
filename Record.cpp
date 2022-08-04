#include <iostream>
#include "Record.h"

Record::Record(std::string bour, std::string dist, int yr, std::string mon, double divrate, double capratepaper, double caprateMGP, double capratetotal){
      borough = bour;
      district = dist;
      year = yr;
      month = mon;
      diversion_rate = divrate;
      capture_rate_paper = capratepaper;
      capture_rate_MGP = caprateMGP;
      capture_rate_total = capratetotal;

    }

    Record::Record(){}
    void Record::print() const {
      std::cout
         << "\n\nBorough: " << borough
         <<"\nDistrict: " <<district
         <<"\nDate: " << month <<" " << year
         <<"\nDiversion Rate: " << diversion_rate
         <<"\nCapture Rate of Paper: " << capture_rate_paper
         <<"\nCapture Rate of MGP: " << capture_rate_MGP
         <<"\nTotal Capture Rate: " << capture_rate_total;

    }