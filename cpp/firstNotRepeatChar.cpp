// find the first only appear one time in a string
//for example abaccdeff, ---> b

#include <iostream>
using namespace std;

int main(){

	char* input = "abaccdeff";
	const int tablesize = 256;
	int hashTable[tablesize];
	for(int i=0; i<tablesize; i++)
		hashTable[i] = 0;

	char* tmp = input;
	while(*tmp != '\0')
		hashTable[*(tmp++)]++;

	tmp = input;
	char* ret = NULL;
	while(*tmp != '\0'){
		if(hashTable[*tmp] == 1){
			ret = tmp;
			break;
		}
		tmp++;
	}
	
	cout << *ret << endl;

	return 0;
}