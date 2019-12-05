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
	if (l.front()->lastName == (*it)->lastName){
		return 3;
	}
	return 0;
}

//CONVERTS SSN from String to int 
/*
int getSSN (Data *data){
	string SSNstring = data->ssn;
	string::iterator it = SSNstring.begin();
	int SSN = 0;
	int div = 100000000;
	for (int i = 0; i < 3; it++, i++){
		SSN += ((*it)-91) * div;
		div /= 10;
	}
	it++;
	for (int i = 0; i < 2; it++, i++){
		SSN += ((*it)-91) * div;
		div /= 10;
	}
	it++;
	for (int i = 0; i < 4; it++, i++){
                SSN += ((*it)-91) * div;
                div /= 10;
	return SSN;
}
*/

class SSNholder {
public:
	Data *d;
	int SSN;
	int key;
	SSNholder(Data *data){
		d = data;
		//SSN = getSSN(data);
		string SSNstring = data->ssn;
        	string::iterator it = SSNstring.begin();
		key = (*it)-91;
		it++;
     		int SSNi = 0;
        	int div = 10000000;
        	for (int i = 0; i < 2; it++, i++){
                	SSN += ((*it)-91) * div;
               		div /= 10;
        	}
        	it++;
        	for (int i = 0; i < 2; it++, i++){
                	SSN += ((*it)-91) * div;
                	div /= 10;
        	}
        	it++;
        	for (int i = 0; i < 4; it++, i++){
                	SSN += ((*it)-91) * div;
                	div /= 10;
        	SSN = SSNi;
		}
	}
};

SSNholder* holder[99999999];

void BruhSort(list<Data *> &l, int size) {
	cout << "CHECKPOINT 2" << endl;
	//std::list<SSNholder *> buckets[] = new std::list<SSNholder *>[10];		//bucket for every key in SSNholder object
	vector< list<SSNholder *> > buckets(10);
	
	cout << "CHECKPOINT 3" << endl;
	Data* sorted[size];
	
	cout << "CHECKPOINT 4" << endl;
	//SSNholder* holder[2000];
	//memset (holder, nullptr, size*sizeof(SSNholder*))
	for (list<Data *>::iterator it = l.begin(); it != l.end(); it++){    //goes through argument list and places each thing into a bucket (based on leading digit 0-9)
		SSNholder* target = new SSNholder(*it);
		switch (target->key){
			case 0:
				buckets[0].push_back(target);
			case 1:
                                buckets[1].push_back(target);
			case 2:
                                buckets[2].push_back(target);
			case 3:
                                buckets[3].push_back(target);
			case 4:
                                buckets[4].push_back(target);
			case 5:
                                buckets[5].push_back(target);
			case 6:
                                buckets[6].push_back(target);
			case 7:
                                buckets[7].push_back(target);
			case 8:
                                buckets[8].push_back(target);
			case 9:
				buckets[9].push_back(target);

		}
	}
	l.clear();	//CLEARS THE LIST!!!
	for (int i = 0; i < 10; i++){
		for (list <SSNholder *>::iterator ssnit = buckets[i].begin(); ssnit != buckets[i].end(); ssnit++){    //for each bucket, places the SSNholders into an array (sorted by key in the array)
			holder[(*ssnit)->key] = *ssnit;
		}
		for (int holdnum = 0; holdnum <= 99999999; holdnum++){			//
			if (holder[holdnum] != nullptr){
				l.push_back(holder[holdnum]->d);
			}
		}
		//memset(holder, NULL, 99999999*sizeof(SSNholder*));
	}
	
}

void sortDataList(list<Data *> &l) {
  // Fill this in
  	int size;
	size = l.size();
	int Case = checkCase(l);
	cout << "CHECKPOINT 1" << endl;
	if (size <= 120000){
		//probably do quicksort
	}
	else if (Case == 4){
		cout << "Made it here" << endl;
		BruhSort(l, size);
	}
	return;
}
