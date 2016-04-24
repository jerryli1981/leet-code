//find a number that the times of appears more than half of the lenght of the array. 

#include <iostream>

int RandomInRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//o(n)
class Solution{
public:
	int moreThanHalfNum(int* a, int length){

		int middle = length >> 1;
		int start = 0;
		int end = length-1;

		int index = Partition(a, length, start, end);

		while(index != middle){
			if(index > middle){
				end = index-1;
				index = Partition(a, length, start, end);
			}
			else{
				start = index + 1;
				index = Partition(a, length, start, end);

			}
		}

		return a[index];

	}

	int Partition(int* data, int length, int start, int end){

	    int index = RandomInRange(start, end);
	    Swap(&data[index], &data[end]);

	    int small = start - 1;
	    for(index = start; index < end; ++index)
	    {
	        if(data[index] < data[end])
	        {
	            ++small;
	            if(small != index)
	                Swap(&data[index], &data[small]);
	        }
	    }

	    ++small;
	    Swap(&data[small], &data[end]);

	    return small;
	}

};

int main(){

	int a[] = {1,2,3,2,2,2,5,4,2};
	Solution s;
	int midean = s.moreThanHalfNum(a, 9);
	std::cout << midean << std::endl;

}