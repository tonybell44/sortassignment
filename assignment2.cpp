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

void insertionSort(int size, int *array){
	
	return;
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
	string ssnstr;
	ostringstream oss;
	//oss << ssnint;
	//cout << ssnint << endl; //test
	//oss << setfill('0');
	oss << std::setfill('0') << std::setw(9) << ssnint;
	return oss.str().insert(3, "-").insert(6, "-");
}

void Case3(list <Data *> &l){

	int i, key, j;

	int daddyArray[20];
	int twentyarray[20];
	int nineteenarray[19];
	int eighteenarray[18];
	int seventeenarray[17];
	int sixteenarray[16];
	int fifteenarray[15];
	int fourteenarray[14];
	int thirteenarray[13];
	int twelvearray[12];
	int elevenarray[11];
	int tenarray [10];
	int ninearray[9];
	int eightarray[8];
	int sevenarray[7];
	int sixarray[6];
	int fivearray[5];
	int fourarray[4];
	int threearray[3];
	int twoarray[2];
	
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
			switch (currentSize) {				//ordered by most likely
				case 4:
					memcpy(fourarray, daddyArray, (currentSize) * sizeof(int));
					//insertionSort(currentSize, fourarray);

					for (i = 1; i < currentSize; i++) {  
						key = fourarray[i];  
						j = i - 1;  
  
						while (j >= 0 && fourarray[j] > key) {  
							fourarray[j + 1] = fourarray[j];  
							j = j - 1;  
						}  
						fourarray[j + 1] = key;  
					}  

					for (int i = 0; i < currentSize; i++){

						(*beginit)->ssn = INTtoSSN(fourarray[i]);
						beginit++;
					}
					break;

				case 3:
					memcpy(threearray, daddyArray, (currentSize) * sizeof(int));
					//insertionSort(currentSize, threearray);
					
					 for (i = 1; i < currentSize; i++) {
                                                key = threearray[i];
                                                j = i - 1;
                                                while (j >= 0 && threearray[j] > key) {
                                                        threearray[j + 1] = threearray[j];
                                                        j = j - 1;
                                                }
                                                threearray[j + 1] = key;
                                        }

					

                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(threearray[i]);
                                                beginit++;
					}
					break;
				case 5:
					memcpy(fivearray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, fivearray);
					
					for (i = 1; i < currentSize; i++) {
                                                key = fivearray[i];
                                                j = i - 1;
                                                while (j >= 0 && fivearray[j] > key) {
                                                        fivearray[j + 1] = fivearray[j];
                                                        j = j - 1;
                                                }
                                                fivearray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(fivearray[i]);
                                                beginit++;
                                        }
					break;
				case 2:
					memcpy(twoarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize ,twoarray);
                                        
					for (i = 1; i < currentSize; i++) {
                                                key = twoarray[i];
                                                j = i - 1;
                                                while (j >= 0 && twoarray[j] > key) {
                                                        twoarray[j + 1] = twoarray[j];
                                                        j = j - 1;
                                                }
                                                twoarray[j + 1] = key;
                                        }
					
					
					for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(twoarray[i]);
                                                beginit++;
                                        }
					break;
				case 6:
					memcpy(sixarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, sixarray);
                                        
					for (i = 1; i < currentSize; i++) {
                                                key = sixarray[i];
                                                j = i - 1;
                                                while (j >= 0 && sixarray[j] > key) {
                                                        sixarray[j + 1] = sixarray[j];
                                                        j = j - 1;
                                                }
                                                sixarray[j + 1] = key;
                                        }
					
					for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(sixarray[i]);
                                                beginit++;
                                        }
					break;
				case 7:
					memcpy(sevenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, sevenarray);
                                        
					for (i = 1; i < currentSize; i++) {
                                                key = sevenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && sevenarray[j] > key) {
                                                        sevenarray[j + 1] = sevenarray[j];
                                                        j = j - 1;
                                                }
                                                sevenarray[j + 1] = key;
                                        }

					
					
					for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(sevenarray[i]);
                                                beginit++;
                                        }
					break;
				case 8:
					memcpy(eightarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, eightarray);
                                        
					for (i = 1; i < currentSize; i++) {
                                                key = eightarray[i];
                                                j = i - 1;
                                                while (j >= 0 && eightarray[j] > key) {
                                                        eightarray[j + 1] = eightarray[j];
                                                        j = j - 1;
                                                }
                                                eightarray[j + 1] = key;
                                        }

					
					
					
					for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(eightarray[i]);
                                                beginit++;
                                        }
					break;
				case 9:
					memcpy(ninearray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);
					
					for (i = 1; i < currentSize; i++) {
                                                key = ninearray[i];
                                                j = i - 1;
                                                while (j >= 0 && ninearray[j] > key) {
                                                        ninearray[j + 1] = ninearray[j];
                                                        j = j - 1;
                                                }
                                                ninearray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(ninearray[i]);
                                                beginit++;
					}
					break;
				case 10:
					memcpy(tenarray, daddyArray, (currentSize) * sizeof(int));
                                        
					for (i = 1; i < currentSize; i++) {
                                                key = tenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && tenarray[j] > key) {
                                                        tenarray[j + 1] = tenarray[j];
                                                        j = j - 1;
                                                }
                                                tenarray[j + 1] = key;
                                        }

					
					
					
					//insertionSort(currentSize, tenarray);
                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(tenarray[i]);
                                                beginit++;
					}
					break;

				 case 11:
                                        memcpy(elevenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = elevenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && elevenarray[j] > key) {
                                                        elevenarray[j + 1] = elevenarray[j];
                                                        j = j - 1;
                                                }
                                                elevenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(elevenarray[i]);
                                                beginit++;
                                        }
                                        break;


				case 12:
                                        memcpy(twelvearray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = twelvearray[i];
                                                j = i - 1;
                                                while (j >= 0 && twelvearray[j] > key) {
                                                        twelvearray[j + 1] = twelvearray[j];
                                                        j = j - 1;
                                                }
                                                twelvearray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(twelvearray[i]);
                                                beginit++;
                                        }
                                        break;

				 case 13:
                                        memcpy(thirteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = thirteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && thirteenarray[j] > key) {
                                                        thirteenarray[j + 1] = thirteenarray[j];
                                                        j = j - 1;
                                                }
                                                thirteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(thirteenarray[i]);
                                                beginit++;
                                        }
                                        break;
				case 14:
                                        memcpy(fourteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = fourteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && fourteenarray[j] > key) {
                                                        fourteenarray[j + 1] = fourteenarray[j];
                                                        j = j - 1;
                                                }
                                                fourteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(fourteenarray[i]);
                                                beginit++;
                                        }
                                        break;

				 case 15:
                                        memcpy(fifteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = fifteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && fifteenarray[j] > key) {
                                                        fifteenarray[j + 1] = fifteenarray[j];
                                                        j = j - 1;
                                                }
                                                fifteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(fifteenarray[i]);
                                                beginit++;
                                        }
                                        break;
				 case 16:
                                        memcpy(sixteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = sixteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && sixteenarray[j] > key) {
                                                        sixteenarray[j + 1] = sixteenarray[j];
                                                        j = j - 1;
                                                }
                                                sixteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(sixteenarray[i]);
                                                beginit++;
                                        }
                                        break;
				case 17:
                                        memcpy(seventeenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = seventeenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && seventeenarray[j] > key) {
                                                        seventeenarray[j + 1] = seventeenarray[j];
                                                        j = j - 1;
                                                }
                                                seventeenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(seventeenarray[i]);
                                                beginit++;
                                        }
                                        break;
				case 18:
                                        memcpy(eighteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = eighteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && eighteenarray[j] > key) {
                                                        eighteenarray[j + 1] = eighteenarray[j];
                                                        j = j - 1;
                                                }
                                                eighteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(eighteenarray[i]);
                                                beginit++;
                                        }
                                        break;
				

				 case 19:
                                        memcpy(nineteenarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = nineteenarray[i];
                                                j = i - 1;
                                                while (j >= 0 && nineteenarray[j] > key) {
                                                        nineteenarray[j + 1] = nineteenarray[j];
                                                        j = j - 1;
                                                }
                                                nineteenarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(nineteenarray[i]);
                                                beginit++;
                                        }
                                        break;

				 case 20:
                                        memcpy(twentyarray, daddyArray, (currentSize) * sizeof(int));
                                        //insertionSort(currentSize, ninearray);

                                        for (i = 1; i < currentSize; i++) {
                                                key = twentyarray[i];
                                                j = i - 1;
                                                while (j >= 0 && twentyarray[j] > key) {
                                                        twentyarray[j + 1] = twentyarray[j];
                                                        j = j - 1;
                                                }
                                                twentyarray[j + 1] = key;
                                        }


                                        for (int i = 0; i < currentSize; i++){
                                                (*beginit)->ssn = INTtoSSN(twentyarray[i]);
                                                beginit++;
                                        }
                                        break;


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


void Case4(list<Data *> &l){




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
		Case4(l);
        }
        return;
}
