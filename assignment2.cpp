// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2019

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " "
           << pData->firstName << " "
           << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.


int checkCase(list<Data *> &l){
        list<Data *>::iterator it= l.begin();
        it++;
        if ((l.front()->lastName == l.back()->lastName) && (l.front()->lastName == (*it)->lastName)){
                return 4;
        }
	else if (l.front()->lastName == (*it)->lastName){
                return 3;
        }
        return 0;
}

void insertionSort(int &array[], int size){

	return;
}

int SSNtoINT(string ssn){

	return ssnint;
}

void Case3(list <Data *> &l){
	int daddyArray[8];
	int 8array[8];
	int 7array[7];
	int 6array[6];
	int 5array[5];
	int 4array[4];
	int 3array[3];
	int 2array[2];
	int currentSize = 0;
	list<Data *>iterator nextit = l.begin();
	nexitit++;					//nextit will always be one after the listit
	list<Data *>iterator beginit = l.begin();
	for (list<Data *>::iterator listit = l.begin(); listit != l.end; listit++){
		if((*listit)->(firstName.front()) == (*nextit)->(firstName.front())){
			nextit++;
			daddyArray[currentSize] = SSNtoINT((*listit)->ssn);
			currentSize++;
		}
		else if ((*listit)->(firstName.front()) != (*nextit)->(firstName.front())){
			daddyArray[currentSize] = SSNtoINT((*listit)->ssn);
			currentSize++;				//currentSize will now match the size of the array, not the index of the array

			switch (currentSize) {				//ordered by most likely
				case 4:
					memcpy(4array, daddyArray, currentSize * sizeof(int));
					insertionSort(4array, currentSize);




			

			}
			beginit = nextit;		//make sure this happens after insertion sort
			currentSize = 0;
			nextit++;
		}
	}
	
	return;
}




void sortDataList(list<Data *> &l) {
  // Fill this in
        int size;
        size = l.size();
        int Case = checkCase(l);
        if (size <= 120000){
		cout << "we got a case 1" << endl;
                //probably do quicksort
        }
	else if (Case == 3){
		cout << "We got a case 3" << endl;
		Case3(l);
	}
        else if (Case == 4){
                cout << "We got a case 4" << endl;
        }
        return;
}
                                
