//Given a string, replace every space(blank) to '%20'
//For example, 'We are happy' ---> 'We%20are%20happy'

#include <iostream>
#include <cstring>
using namespace std;

void replaceBlank(char* str, int capacity){

	if (str == NULL)
		return;

	int numBlanks = 0;
	int originalLength = 0;
	int i=0;
	while(str[i] != '\0'){
		++ originalLength;
		if(str[i] == ' ')
			++numBlanks;
		i++;
	}

	int newLength = originalLength + numBlanks*2;
	if (newLength > capacity)
		return;

	int index1 = originalLength;
	int index2 = newLength;

	while(index1 >=0 && index2 > index1){
		if(str[index1] == ' '){
			str[index2--] = '0';
			str[index2--] = '2';
			str[index2--] = '%';
		}
		else{
			str[index2 --] = str[index1];
		}
		--index1;
	}
}


int main(){

	char input[20] = "We are happy.";
	cout << input << endl;
	replaceBlank(input, 20);
	cout << input << endl;
	return 0;
}