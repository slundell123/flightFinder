#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <bits/stdc++.h> 
#include "BST.hpp"
using namespace std;

string runFile(){ 
  string userChoice;
  while(userChoice != "Yes" && userChoice != "No") {
    cout << "Would you like to read in an existing CSV file? (Yes/No)" << endl;
    cin >> userChoice;
  }
  if(userChoice == "Yes"){
    cout << "Enter CSV file name" << endl;
    string file;
    cin >> file;
    return file;
  } else {
    char filename[100];
    cin.ignore();
    cout << "Enter the departure and arrival airports and they date of travel\nFormat: [airport code] [airport code] [MM/DD/YYYY]" << endl;
    cin.getline(filename, 100);

    string str = "python "; // python is what we want to run in
    str = str + "expedia.py " + filename; //add expedia.py and the user's arguments to the command line args

    const char *command = str.c_str(); // system function needs a const char so we convert

    cout << "Compiling file using " << command << endl;
    system(command); // compile the code

    cout << "\nRunning file ";
    system("./a.out"); // run the compiled file
    string returningFile;
    for(int i = 0; i < 7; i++){
      if(filename[i] == ' ')
        returningFile += '-';
      else returningFile += filename[i];
    }
    returningFile += "-flight-results.csv";
    return returningFile;
  }
}

void menu(){
  cout << "Please choose how you would like to prioritize the data" << endl;
  cout << "1. By price" << endl;
  cout << "2. By number of stops" << endl;
  cout << "3. By flight duration" << endl;
  cout << "4. Leave menu" << endl;
}

int main(int argc, char* argv[]){
  vector<FlightInfo> v;
  FlightInfo FI;
  string stops = "";
  string priceS = "";
  string departure = "";
  string arrival = "";
  string duration = "";
  string airline = "";
  string plane = "";
  string timings = "";
  string flightCode = "";
  string userChoice;
  string userInfoYN;
  string userName = "";
  string homeAirport;
  string allPrice;
  string allStop;
  string allDur;
  string query;
  string theFile;

  
    theFile = runFile();
    ifstream myfile;
    string file = theFile;
    myfile.open(file);
    if(myfile.is_open()){
      while(getline(myfile, stops, ',')){
        if(stops != "stops"){
          if(stops == "Nonstop"){
            FI.stops = 0;
          }
          else if(stops == "1 Stop"){
            FI.stops = 1;
          }
          else if(stops == "2 Stop"){
            FI.stops = 2;
          }
          else if(stops == "3 Stop"){
            FI.stops = 3;
          }
        }
        getline(myfile, priceS, ',');
          if(priceS != "ticket price"){
            FI.price = stof(priceS);
          }
        getline(myfile, departure, ',');
          if(departure != "departure"){
            FI.departure = departure;
          }
        getline(myfile, arrival, ',');
          if(arrival != "arrival"){
            FI.arrival = arrival;
          }
        getline(myfile, duration, ',');
          if(duration != "flight duration"){
            FI.duration = duration;
          }
        getline(myfile, airline, ',');
          if(airline != "airline"){
            FI.airline = airline;
          }
        getline(myfile, plane, ',');
          if(plane != "plane"){
            FI.plane = plane;
          }
        getline(myfile, timings, ',');
          if(timings != "timings"){
            FI.timings = timings;
          }
        getline(myfile, flightCode);
        if(flightCode != "plane code"){
          FI.flightCode = flightCode;
        }
        v.push_back(FI);
      }

    cout << "Would you like to input user information? (Y/N)" << endl;
    cin.ignore();
    getline(cin, userInfoYN);
    if(userInfoYN == "Y" || userInfoYN == "y"){
      cout << "Please enter your name: " << endl;
      getline(cin, userName);
      cout << "Welcome, " << userName << "!" << endl;
      cout << "What is your home airport?" << endl;
      getline(cin, homeAirport);
    }
    else if(userInfoYN == "N" || userInfoYN == "Y"){
      cout << "Okay, maybe next time" << endl;
    }
    while(userChoice != "4"){
      menu();
      getline(cin, userChoice);
      switch(stoi(userChoice)){
        case 1:{
          BST Price;
          for(int i = 1; i < v.size(); i++){
            Price.addNodePRICE(v[i].stops, v[i].price, v[i].departure, v[i].arrival, v[i].duration, v[i].airline, v[i].plane, v[i].timings, v[i].flightCode);
          }
          cout << "*****************************" << endl << endl;
          cout << "This is the flight we chose for you " << userName << endl;
          Price.printLeft();
          cout << "Would you like to see all other flight options? (Y/N)" << endl;
          getline(cin, allPrice);
          if(allPrice == "Y" || allPrice == "y"){
            cout << "Here are all of the available flights: " << endl;
            Price.printTree();
          }
          else{
            cout << "Okay!" << endl;
          }
          cout << "*****************************" << endl << endl;
          break;
        }
        case 2:{
          BST Stops;
          for(int i = 1; i < v.size(); i++){
            Stops.addNodeSTOPS(v[i].stops, v[i].price, v[i].departure, v[i].arrival, v[i].duration, v[i].airline, v[i].plane, v[i].timings, v[i].flightCode);
          }
          cout << "*****************************" << endl;
          cout << "This is the flight we chose for you " << userName << endl;
          Stops.printLeft();
          cout << "Would you like to see all of your options? (Y/N)" << endl;
          getline(cin, allStop);
          if(allStop == "Y" || allStop == "y"){
            cout << "Here are all of the available flights: " << endl;
            Stops.printTree();
          }
          else{
            cout << "Okay!" << endl;
          }
          cout << "*****************************" << endl;
          break;
        }
        case 3:{
          BST Dur;
          for(int i = 1; i < v.size(); i++){
            Dur.addNodeDUR(v[i].stops, v[i].price, v[i].departure, v[i].arrival, v[i].duration, v[i].airline, v[i].plane, v[i].timings, v[i].flightCode);
          }
          cout << "*****************************" << endl;
          cout << "This is the flight that we chose for you " << userName << endl;
          Dur.printLeft();
          cout << "Would you like to see all of your options? (Y/N)" << endl;
          getline(cin, allDur);
          if(allDur == "Y" || allDur == "y"){
            cout << "Here are all of the available flights: " << endl;
            Dur.printTree();
          }
          else{
            cout << "Okay!" << endl;
          }
          cout << "*****************************" << endl;
          break;
        }

        case 4:
          cout << "Thank you!" << endl;
          break;
        default:
          cout << "Invalid Choice" << endl;
        }
      }
    }
  }
