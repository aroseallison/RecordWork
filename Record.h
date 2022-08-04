#include <iostream>
#include <string>
#ifndef RECORD_H
#define RECORD_H

class Record{
  public:

    explicit Record(std::string, std::string, int, std::string, double, double, double, double);

    Record();
    void print() const;
    int getDV(){
      return diversion_rate;
    }
    int getCRP(){
      return capture_rate_paper;
    }
    int getCRMGP(){
      return capture_rate_MGP;
    }
    int getCRT(){
      return capture_rate_total;
    }
    int get_year(){
      return year;
    }

  private:
    std::string borough;
    std::string district;
    int year;
    std::string month;
    double diversion_rate;
    double capture_rate_paper;
    double capture_rate_MGP;
    double capture_rate_total;
  
};

#endif