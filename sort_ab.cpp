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
	int daddyArray[100];
	int size = 0; //size
	int fullsize = l.size();
	int currentSize = 0;
	list<Data *>::iterator nextit = l.begin(), end = l.end();
	nextit++;					//nextit will always be one after the listit
	list<Data *>::iterator beginit = l.begin();
	for (list<Data *>::iterator listit = l.begin(); size < fullsize; listit++){
		if (size == fullsize-1 || (*listit)->firstName != (*nextit)->firstName){
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
			//if (size < fullsize){
				nextit++;
			//}
			size++;
		}
		else if((*listit)->firstName == (*nextit)->firstName){

			nextit++;
			daddyArray[currentSize] = SSNtoINT((*listit)->ssn);
			currentSize++;
			size++;
                }
		//cout << size << endl;
	}
	return;
}

//CASE 4 STARTS RIGHT AFTER HERE!!!


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

//CASE 1 HERE

bool sortCase(Data *a, Data *b){
    if (a->lastName != b->lastName){
        return a->lastName < b->lastName;
    }
    else if (a->firstName != b->firstName){
        return a->firstName < b->firstName;
    }
    else if(a->ssn != b->ssn){
        return a->ssn < b->ssn;
    }
}


struct Hold{
	//char LName[11];
	//char FName[11];
	char Name[30];
	//char Ssn[12];
	Data *Store;
};



Hold tempArray[1020000];

int sorty(const void* a, const void* b){
//	if (((Hold*)a)->Name == ((Hold*)b)->Name){
//		return ((Hold*)a)->Name < ((Hold*)b)->Name;
//
//	}
	if (strcmp(((Hold*)a)->Name, ((Hold*)b)->Name) == 0){
                return strcmp(((Hold*)a)->Name, ((Hold*)b)->Name) ? -1:1;
        }
	/*
	if (strcmp(((Hold*)a)->LName, ((Hold*)b)->LName) == 0){
		return strcmp(((Hold*)a)->LName, ((Hold*)b)->LName) ? 1 : -1;
	}
	
	else if (strcmp(((Hold*)a)->FName, ((Hold*)b)->FName) == 0){
		return strcmp(((Hold*)a)->FName, ((Hold*)b)->FName) ? 1 : -1;
	}
	
	else if(strcmp(((Hold*)a)->Ssn, ((Hold*)b)->Ssn) == 0){
		return strcmp(((Hold*)a)->Ssn, ((Hold*)b)->Ssn) ? 1 : -1;
	}
	*/
}
/*
bool regsort (Hold *a, Hold* b){
if (strcmp(a->LName, b->LName) != 0){
        return strcmp(a->LName, b->LName);
    }
    else if (strcmp(a->FName, b->FName) != 0){
        return strcmp(a->FName, b->FName);
    }
    else if(strcmp(a->Ssn, b->Ssn) != 0){
        return strcmp(a->Ssn, b->Ssn);
    }
    
}
*/


void Case1(list<Data *> &l){
	list<Data *>::iterator it = l.begin();
	for (int i = 0; i < l.size(); i++, it++){
		string fullfull = (*it)->lastName + " " + (*it)-> firstName;
		memmove(tempArray[i].Name, fullfull.c_str(), 30);		//new attempt
		//memmove (tempArray[i].LName, (*it)->lastName.c_str(), 11);		//check size
		//memmove (tempArray[i].FName, (*it)->firstName.c_str(), 11);		//check size 
		//memmove (tempArray[i].Ssn, (*it)->ssn.c_str(), 12);
		tempArray[i].Store = *it;
	}
	qsort(tempArray, l.size(), sizeof(Hold), sorty);


	it = l.begin();

	for (int i = 0; i < l.size(); i++, it++){
		(*it) = tempArray[i].Store;
	}
	Case3(l);
	return;
}


void sortDataList(list<Data *> &l) {
  // Fill this in
  /*
  	char Name1[30];
	char Name2[30];
  	string ln1 = "BECK";
	string fn1 = "ERIC";
	string ln2 = "BECKER";
	string fn2 = "ISABEL";
	ln1 = ln1 + fn1;
	ln2 = ln2 + fn2;
	memmove(Name1, ln1.c_str(), 30);
	memmove(Name2, ln2.c_str(), 30);
	cout << strcmp(Name1, Name2) << endl;
*/



  
        int size;
        size = l.size();
        int Case = checkCase(l);
        if (size <= 120000){
                //l.sort(sortCase);
		//Case3(l);
		Case1(l);
        }
	else if (Case == 0){
		//l.sort(sortCase);
		//Case3(l);
		Case1(l);
	}
	else if (Case == 3){
		Case3(l);
	}
        else if (Case == 4){
		Case4(l);
        }
        return;
}
