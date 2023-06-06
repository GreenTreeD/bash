#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;   //  объявление пространства имен

int main(int argc, char* argv[])
{
	char ch;

	if (argc < 2) {
		cout << "insufficient files" << endl;
	}


	if(!output.is_open()) {
	        cerr<< "Can't create output file :(" << endl;
	        return(-1);
	    }

	for (int i = 1; i < argc; i++){
		ifstream input;
		input.open(argv[i]);
	    if(!input.is_open()) {
	        cerr<< '\n' << argv[i] << ": Can't open to read" << endl;
	        return(-1);
	    }
		input.close();}

		ofstream output;
	output.open("merged_file");
	for (int i = 1; i < argc; i++){
		ifstream input;
		input.open(argv[i]);
	    while((ch = input.get()) != EOF) {
	    	cout << ch;
	    	output << ch;
	    }

	    input.close();
	}
	output.close();
	cout << endl;
	cout << setw(50) << "Look for result in \"merged_file\"!" << endl;
}