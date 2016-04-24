//0,1,...,n-1 form a circle. from 0, remove m th number, compute the last number. 

#include <iostream>
#include <list>

using namespace std;

int main(){

	list<int> numbers = {0,1,2,3,4};

	list<int>::iterator current = numbers.begin();

	int m = 3;

	while(numbers.size() > 1){

		for(int i=1; i<m ;i++){
			current ++;
			if(current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();

		--current;
		numbers.erase(current);
		current = next;
	}

	cout << *current << endl;
	return 0;
}