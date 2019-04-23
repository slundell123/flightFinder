#include <iostream>
#include <string>
#define COUNT 10
using namespace std;

struct FlightInfo{
  int stops;
  float price;
  string departure;
  string arrival;
  string duration;
  string airline;
  string plane;
  string timings;
  string flightCode;
  FlightInfo* parent;
  FlightInfo* leftChild;
  FlightInfo* rightChild;
};

int convert(string time){
  string total = "";
  for(int i = 0; i < time.size(); i++){
    if(time[i] == '0' || time[i] == '1' || time[i] == '2' || time[i] == '3' || time[i] == '4' || time[i] == '5' || time[i] == '6' || time[i] == '7' || time[i] == '8' || time[i] == '9'){
      total += time[i];
    }
  }
  return stoi(total);
}

class BST{
private:

  FlightInfo* root;

  FlightInfo* createNode(int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    FlightInfo* newNode = new FlightInfo;
    newNode->stops = stops;
    newNode->price = price;
    newNode->departure = departure;
    newNode->arrival = arrival;
    newNode->duration = duration;
    newNode->airline = airline;
    newNode->plane = plane;
    newNode->timings = timings;
    newNode->flightCode = flightCode;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;
    return newNode;
  }

  FlightInfo* addNodeHelperSTOPS(FlightInfo* curr, int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    if(curr == NULL){
      return createNode(stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    if(curr->stops <= stops){
      curr->rightChild = addNodeHelperSTOPS(curr->rightChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    else if(curr->stops > stops){
      curr->leftChild = addNodeHelperSTOPS(curr->leftChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    return curr;
  }


  FlightInfo* addNodeHelperPRICE(FlightInfo* curr, int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    if(curr == NULL){
      return createNode(stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    if(curr->price <= price){
      curr->rightChild = addNodeHelperPRICE(curr->rightChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    else if(curr->price > price){
      curr->leftChild = addNodeHelperPRICE(curr->leftChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    return curr;
  }

  FlightInfo* addNodeHelperDUR(FlightInfo* curr, int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    if(curr == NULL){
      return createNode(stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    if(convert(curr->duration) <= convert(duration)){
      curr->rightChild = addNodeHelperDUR(curr->rightChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    else if(convert(curr->duration) > convert(duration)){
      curr->leftChild = addNodeHelperDUR(curr->leftChild, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
    }
    return curr;
  }

  void printTreeHelper(FlightInfo* currNode){
    if(currNode){
      printTreeHelper(currNode->leftChild);
      cout << "STOPS: ";
      cout << currNode->stops << endl;
      cout << "PRICE: ";
      cout << currNode->price << endl;
      cout << "DEPARTING FROM: ";
      cout << currNode->departure << endl;
      cout << "ARRIVING TO: ";
      cout << currNode->arrival << endl;
      cout << "FLIGHT DURATION: ";
      cout << currNode->duration << endl;
      cout << "AIRLINE: ";
      cout << currNode->airline << endl;
      cout << "PLANE: ";
      cout << currNode->plane << endl;
      cout << "TIMINGS: ";
      cout << currNode->timings << endl;
      cout<< "FLIGHT NUMBER: ";
      cout << currNode->flightCode << endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
      printTreeHelper(currNode->rightChild);
    }
  }

  void printLeftHelper(FlightInfo* currNode){
    while(currNode->leftChild != NULL){
      currNode = currNode->leftChild;
    }
    cout << "STOPS: ";
    cout << currNode->stops << endl;
    cout << "PRICE: ";
    cout << currNode->price << endl;
    cout << "DEPARTING FROM: ";
    cout << currNode->departure << endl;
    cout << "ARRIVING TO: ";
    cout << currNode->arrival << endl;
    cout << "FLIGHT DURATION: ";
    cout << currNode->duration << endl;
    cout << "AIRLINE: ";
    cout << currNode->airline << endl;
    cout << "PLANE: ";
    cout << currNode->plane << endl;
    cout << "TIMINGS: ";
    cout << currNode->timings << endl;
    cout<< "FLIGHT NUMBER: ";
    cout << currNode->flightCode << endl;
  }

public:
  void printTree(){
    printTreeHelper(root);
    cout << endl;
  }

  void addNodeSTOPS(int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    root = addNodeHelperSTOPS(root, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
  }

  void addNodePRICE(int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    root = addNodeHelperPRICE(root, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
  }

  void addNodeDUR(int stops, float price, string departure, string arrival, string duration, string airline, string plane, string timings, string flightCode){
    root = addNodeHelperDUR(root, stops, price, departure, arrival, duration, airline, plane, timings, flightCode);
  }

  void destroyNode(FlightInfo* currNode){
    if(currNode != NULL){
      destroyNode(currNode->leftChild);
      destroyNode(currNode->rightChild);
      delete currNode;
      currNode = NULL;
    }
  }

  void printLeft(){
    printLeftHelper(root);
    cout << endl;
  }

  BST(){
    root = NULL;
  }

  BST(int data){

  }

  ~BST(){
    destroyNode(root);
  }
};
