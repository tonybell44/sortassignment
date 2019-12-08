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

#include <iomanip>

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
	


int SSNtoINT(string ssn){
	string::iterator stit = ssn.begin();
	return ((stit[0])-48)*100000000
		+ ((stit[1])-48)*10000000
		+ ((stit[2])-48)*1000000
		+ ((stit[4])-48)*100000
		+ ((stit[5])-48)*10000
		+ ((stit[7])-48)*1000
		+ ((stit[8])-48)*100
		+ ((stit[9])-48)*10
		+ ((stit[10])-48);
}

string INTtoSSN(int ssnint){
	ostringstream oss;
	oss << std::setfill('0') << std::setw(9) << ssnint;
	return oss.str().insert(3, "-").insert(6, "-");
}

void Case3(list <Data *> &l){

	int i, key, j;
	int daddyArray[23];
	int size = 1; //size
	int fullsize = l.size();
	int currentSize = 0;
	list<Data *>::iterator nextit = l.begin();
	nextit++;					//nextit will always be one after the listit
	list<Data *>::iterator beginit = l.begin();
	for (list<Data *>::iterator listit = l.begin(); size < fullsize; listit++){
		if((*listit)->firstName == (*nextit)->firstName){

			nextit++;
			daddyArray[currentSize] = SSNtoINT((*listit)->ssn);
			currentSize++;
			size++;
                }

		
		else if ((*listit)->firstName != (*nextit)->firstName){
			daddyArray[currentSize] = SSNtoINT((*listit)->ssn);
			currentSize++;				//currentSize will now match the size of the array, not the index of the array

					for (i = 1; i < currentSize; i++) {  
						key = daddyArray[i];  
						j = i - 1;  
  
						while (j >= 0 && daddyArray[j] > key) {  
							daddyArray[j + 1] = daddyArray[j];  
							j = j - 1;  
						}  
						daddyArray[j + 1] = key;  
					}  

					for (int i = 0; i < currentSize; i++){

						(*beginit)->ssn = INTtoSSN(daddyArray[i]);
						beginit++;
					}

			beginit = nextit;		//make sure this happens after insertion sort
			currentSize = 0;
			if (size < fullsize){
				nextit++;
			}
			size++;
		}
	}
	return;
}

//CASE 4 STARTS RIGHT AFTER HERE!!!


void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

//for case 1 and 2 HERE!!!





void Case4(list<Data *> &l){

	int radixSize = l.size();
	int fullArray[radixSize];
	int stopper = 0;
	list<Data *>::iterator listit = l.begin();
	for (int j = 0; listit != l.end(); listit++, j++){
		fullArray[j] = SSNtoINT((*listit)->ssn);
	}

	//for below function
	int i, count[10] = {0};
	int sortArray[radixSize];

	for (int digit = 1; stopper < 10; stopper++, digit *= 10){
		memset(count, 0, 40);
		for (i = 0; i < radixSize; i++){
			count[ (fullArray[i]/digit)%10 ]++;
		}
		for (i = 1; i < 10; i++){
			count[i] += count [i-1];
		}
		for(i = radixSize-1; i>=0; i--){
			sortArray[count[(fullArray[i]/digit)%10] - 1] = fullArray[i];
			count[(fullArray[i]/digit)%10]--;
		}
		for(i = 0; i < radixSize; i++){
			fullArray[i] = sortArray[i];
		}
		
	}
	listit = l.begin();
	for (int j = 0; listit != l.end(); listit++, j++){
		(*listit)->ssn=INTtoSSN(fullArray[j]);
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
		Case3(l);
	}
        else if (Case == 4){
		Case4(l);
        }
        return;
}
