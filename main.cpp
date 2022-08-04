#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include "Record.h"
using namespace std;


bool binarySearch(vector<Record>&, int);
void bubbleSort(vector<Record>&);
bool readCSVtovector(string, vector<Record>&);
void print_all(vector<Record>&);
void add_record(vector<Record>&);
int highestDVValue(vector<Record>&);
int highestCRPValue(vector<Record>&);
int highestCRMGPValue(vector<Record>&);
int highestCRTValue(vector<Record>&);
int averageDVValue(vector<Record>&);
int averageCRPValue(vector<Record>&);
int averageCRMGPValue(vector<Record>&);
int averageCRTValue(vector<Record>&);
int teststatus(int);


int main() {
   
   string filename = "Recycling_Diversion_and_Capture_Rates.csv";

   vector<Record> recyclingRecords;

//read in dataset: needs to be before the fuctions in menu (!)
if (readCSVtovector(filename, recyclingRecords)){
    cout <<"Data read successfully\n";

   }
else
  cout <<"Couldn't read data\n";

//menu
bool print_menu;
int user_input;
while (user_input != -1){
cout <<"\nMENU: ";
cout <<"\n\n1: Add a new record to the dataset. ";
cout <<"\n2: Print the full dataset. ";
cout <<"\n3: Find the highest value of a variable of your choosing. ";
cout <<"\n4: Find the average of a variable of your choosing. ";
cout <<"\n5: Perform a binary search on chosen year.";
cout <<"\n-1: Exit the menu.";
cout <<"\n\nSelection: ";
cin >> user_input;
teststatus(user_input);

//1: add record
if (user_input == 1){
 
    add_record(recyclingRecords);

  }
//2: print dataset
if (user_input == 2){

  if (readCSVtovector(filename, recyclingRecords)){
     cout <<"Data read successfully\n";

    print_all(recyclingRecords);

   }
  else
   cout <<"Couldn't read data\n";
  
}
//3: find highest value
if (user_input == 3){
  bool print_menu2;
  int user_highest{0};
  do{
    cout<<"\n\nPlease chose a number for the variable you would like to find: \n";
    cout<<"\n1: Highest Diversion Rate.";
    cout<<"\n2: Highest Capture Rate - Paper.";
    cout<<"\n3: Highest Capture Rate - MGP.";
    cout<<"\n4: Highest Capture Rate - Total.";
    cout<<"\n-2: Exit";
    cout<<"\nSelection: ";
    cin >> user_highest;
    teststatus(user_highest);

    if (user_highest == 1){
      cout <<"\nThe largest Diversion Rate value is: " << highestDVValue(recyclingRecords);
  }
    if (user_highest == 2){
      cout <<"\nThe largest Capture Rate of Paper value is: " << highestCRPValue(recyclingRecords);
  }
    if (user_highest == 3){
     cout<<"\nThe largest Capture Rate of MGP value is: " << highestCRMGPValue(recyclingRecords);
  }
    if (user_highest == 4){
     cout<<"\nThe largest Capture Rate Total value is: " << highestCRTValue(recyclingRecords);
  }
    if (user_highest > 4){
      cout<<"\nInvalid Selection.\n";
  }
  if (user_highest < -2 || user_highest == -1){
    cout<<"\nInvalid Selection.\n";
  }
    
  if (user_highest == -2){
      cout <<"Returning to Primary Menu...";
      break;
  }
  
  }while (user_highest != -2);
}

if (user_input == 4){
  bool print_menu3;
  int user_average{0};
  do{
    cout<<"\n\nPlease select a number for the variabe you'd like to find the average of.";
    cout<<"\n1: Average Diversion Rate.";
    cout<<"\n2: Average Capture Rate - Paper.";
    cout<<"\n3: Average Capture Rate - MGP.";
    cout<<"\n4: Average Capture Rate - Total.";
    cout<<"\n-3: Exit";
    cout<<"\nSelection: ";
    cin >> user_average;
    teststatus(user_average);

    if (user_average == 1){
      cout <<"\nThe average Diversion Rate is: " << averageDVValue(recyclingRecords);
    }
    if (user_average == 2){
      cout <<"\nThe average Capture Rate of Paper is: " << averageCRPValue(recyclingRecords);
    }
    if (user_average == 3){
      cout <<"\nThe average Capture Rate of MGP is: " << averageCRMGPValue(recyclingRecords);
    }
    if (user_average == 4){
      cout <<"\nThe average Capture Rate Total is: " << averageCRTValue(recyclingRecords);
    }
    if (user_average > 4 || user_average == -2){
      cout<<"\nInvalid Selection.\n";
    }
    if (user_average < -3 || user_average == -1){
      cout <<"\nInavlid Selection.\n";
    }
    if (user_average == -3){
      cout <<"\n\nExiting to Primary Menu...";
      break;

    }

  }while (user_average != -3);
}

//5: bubble sort and binary search
if (user_input == 5){
  int user_variable;
  do{
  bubbleSort(recyclingRecords);
  bool result;
  cout <<"\nPlease enter the year you would like to search for or -1 to Exit:";
  cin >> user_variable;
  teststatus(user_variable);

 result = binarySearch(recyclingRecords, user_variable);
  if (user_variable != -1){
  if (result)
      cout << "\nEvents exist for year " << user_variable << "\n";
    else
      cout << "\nNo events for year " << user_variable <<"\n";
}
if (user_variable == 0){
  cout <<"Exiting to Primary Menu...";
  break;
}
}while (user_variable != -1);
}
//invalid number:
if (user_input > 5){
  cout<<"\nInvalid Selection.\n";
}
if (user_input < -1){
  cout<<"\nInvalid Selection.\n";
}
//-1: break
if (user_input == -1){
  cout <<"Exiting Menu...";
  break;
}

}
}

//read CSV file:
bool readCSVtovector(string q, vector<Record>& records){
  
  bool success = false;

  ifstream infile(q, ios::in);  
  string line; 

  if (infile){ 
    cout << "\nFile opened\n";
    getline(infile, line); 
    
    string borough, district, year, month, division_rate, capture_rate_paper, capture_rate_MGP, capture_rate_total;

    while (getline(infile, line)){
      istringstream row{line};
      getline(row, borough, ',');
      getline(row, district, ',');
      getline(row, year, ',');
      getline(row, month, ',');
      getline(row, division_rate, ',');
      getline(row, capture_rate_paper, ',');
      getline(row, capture_rate_MGP, ',');
      getline(row, capture_rate_total);

    Record newrec{borough, district, stoi(year), month, stod(division_rate), stod(capture_rate_paper), stod(capture_rate_MGP), stod(capture_rate_total)};
        records.push_back(newrec);
    }
    

  }
  success = true; 
  
  return success;
}

//print function
void print_all(vector<Record>& records){
  cout << "\nPrinting all " << records.size() << " records.\n";
  for (Record rec : records){
    rec.print();
  }
}
//function for user to add a record to the data
void add_record(vector<Record>& records){
  string user_boro;
  string user_district;
  int user_year;
  string user_month;
  double user_divrate;
  double user_capratepap;
  double user_capratemgp;
  double user_capratetotal;

    cout <<"\n\nAdd a record to the dataset";
    cout <<"\nEnter the borough: ";
    cin >> user_boro;
    cout <<"Enter the district: ";
    cin >> user_district;
    cout <<"Enter the year: ";
    cin >> user_year;
    cout <<"Enter the month: ";
    cin >> user_month;
    cout <<"Enter the Division Rate: ";
    cin >> user_divrate;
    cout <<"Enter the Capture Rate of Paper: ";
    cin >> user_capratepap;
    cout <<"Enter the Capture Rate of MGP:  ";
    cin >> user_capratemgp;
    cout <<"Enter the Capture Rate Total: ";
    cin >> user_capratetotal;

  Record newrec{user_boro, user_district, user_year, user_month, user_divrate, user_capratepap, user_capratemgp, user_capratetotal};
      records.push_back(newrec); 
}
//functions allowing the user to find the max value of a specified variable:
int highestDVValue(vector<Record>& records){ 
 int highest = 0;
 for (int i = 0; i < records.size(); i++){
 if (records[i].getDV() > highest){
      highest = records[i].getDV();
    }
  }
 return highest;
}

int highestCRPValue(vector<Record>& records){
  int largest = 0;
    for (int i =0; i <= records.size()-1; i++){
    if (records[i].getCRP()> largest)
    largest = records[i].getCRP();
  }
  return largest;

}

int highestCRMGPValue(vector<Record>& records){
  int largest = 0;
    for (int i =0; i <= records.size()-1; i++){
    if (records[i].getCRMGP()> largest)
    largest = records[i].getCRMGP();
  }
  return largest;

}

int highestCRTValue(vector<Record>& records){
  int largest = 0;
    for (int i =0; i <= records.size()-1; i++){
    if (records[i].getCRT()> largest)
    largest = records[i].getCRT();
  }
  return largest;

}

//functions that allow the user to find the average of a specified variable:
int averageDVValue(vector<Record>& records){
 double average = 0;
 string newrec;
 int sum{0};
 vector<double> tempVector;
  for (Record rec : records){
    tempVector.push_back(rec.getDV());
    }
    for (int i{0}; i <= tempVector.size() - 1; i++){
    sum += tempVector.at(i);
    average = sum/tempVector.size();
    }
  
  return average;
}

int averageCRPValue(vector<Record>& records){
 double average = 0;
 string newrec;
 int sum{0};
 vector<double> tempVector;
  for (Record rec : records){
    tempVector.push_back(rec.getCRP());
    }
    for (int i{0}; i <= tempVector.size() - 1; i++){
    sum += tempVector.at(i);
    average = sum/tempVector.size();
    }
  
  return average;
}

int averageCRMGPValue(vector<Record>& records){
 double average = 0;
 string newrec;
 int sum{0};
 vector<double> tempVector;
  for (Record rec : records){
    tempVector.push_back(rec.getCRMGP());
    }
    for (int i{0}; i <= tempVector.size() - 1; i++){
    sum += tempVector.at(i);
    average = sum/tempVector.size();
    }
  
  return average;
}

int averageCRTValue(vector<Record>& records){
 double average = 0;
 string newrec;
 int sum{0};
 vector<double> tempVector;
  for (Record rec : records){
    tempVector.push_back(rec.getCRT());
    }
    for (int i{0}; i <= tempVector.size() - 1; i++){
    sum += tempVector.at(i);
    average = sum/tempVector.size();
    }
  
  return average;
}
//bubble sort function:
void bubbleSort(vector<Record>& records){
  bool swapped; 
  do{
    swapped = false; 
    for (int i = 0; i < records.size() - 1; i++){
      if (records[i].get_year() > records[i+1].get_year()){ 
        swap(records[i], records[i+1]); 
        swapped = true; 
      } 
    } 
  }while (swapped == true); 
}
//binary search function:
bool binarySearch(vector<Record>& records, int year){
  int position = -1;
  int low = 0;
  int high = records.size() -1;
  int middle = (low + high) / 2;
  bool found = false;
  vector<int> tempVect;
  for (Record rec : records) {
    tempVect.push_back(rec.get_year());
  }
  for (int i{0}; i < tempVect.size(); i++){
    do {
      if (year == tempVect[middle]){
        position = middle;
        found = true;
      }
      else if (year < tempVect[middle])
        high = middle -1;
      else 
      low = middle + 1;
    middle = (low + high) /2;
    } while (low <= high && position == -1);  
    }
    return found;
  }

//test for bad input:
int teststatus(int){
int number;
while(cin.fail()){
  cout <<"\nInvalid, not an integer.\n";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout <<"Returning to Menu...\n";
}
return number;
}