#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ColCount (string file){
	
	ifstream myfile;
	myfile.open(file);
	int COL = 1, ROW = 1, i = 0;
	string line;
	string myline;
    if (myfile.is_open()){
          while ( getline (myfile, myline)) { 
             for(int i = 0; i < myline.length(); i++) {
                if (myline.at(i) = ' ') {
                   COL++;
                } 
				else if (myline.at(i) = '\n') {
                   ROW++;
				}
              //cout << "Line " << ROW << " has " << COL << " columns.\n";
			  int firstCOL = COL;
				    if (COL != firstCOL){
					    cout << "COL INDEX ERROR" << endl;
					    break;
				    }
					   
              COL = 1;  // reset for next line.
            }
        }
	}
    else {
        cout << "Couldn't open file\n";
    } 
		return COL, ROW;
}

void CleanUp(){
    int size = 7000;

    float** MainArray = NULL;
    MainArray = new float*[size];

    cout <<"Allocating..."<<endl;
        for(int i = 0 ; i < size ; i++){	
           float* SubArray = NULL;
           SubArray = new float[size];	  
   
           for(int j = 0 ; j < size ; j++){
	           SubArray[j] = (float)j;
            }

            MainArray[i] = SubArray;
        }
    int key = 1 ;
    cout << "Press 0 then Enter to clean up the memory" << endl;
    cin >> key ;

        if(key == 0){
           for(int i = 0 ; i < size ; i++){
              delete[]  MainArray[i];
              MainArray[i] = NULL;
            }

            delete[] MainArray;
            MainArray = NULL;
            cout << "Memory cleared" << endl;

        }
    system("PAUSE");
}

int main (int argc, char **argv){
	
    ifstream input_file(argv[1]); // open the input file
       if (!input_file.is_open()) { // check for successful opening
          cout << "Input file could not be opened! Terminating!" << endl;
          return 1;
        }
    ofstream output_file(argv[2]); // open the output file
        if (!output_file.is_open()) { // check for successful opening
          cout << "Output file could not be opened! Terminating!" << endl;
          return 1;
        }
    // read as long as the stream is good - any problem, just quit.
    int datum;
         while (input_file >> datum) {
			 string fileName = argv[1];
             ColCount(fileName);
             output_file << datum << endl;
            }
    CleanUp();			
    input_file.close();
    output_file.close();
    cout << "Done!" << endl;
    return 0;
}