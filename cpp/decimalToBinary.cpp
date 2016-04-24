// convert a decimal to binary

#include <iostream>
using namespace std;
int main(){
	int a[100], i=0, j, n;
	cout << "Enter a positive number:";
	cin >> n;
	while(n > 0){
		a[i] = n%2;
		i++;
		n/=2;
	}
	cout << "Binary number is:";
	for(j = i-1; j>=0; j--){
		cout << a[j];
	}

	return 0;

}