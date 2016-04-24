// implement quick sort

#include <iostream>

int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

class Solution{
public:
	void quickSort(int* data, int length, int start, int end){
		if(start == end)
			return;
		int index = Partition(data, length, start, end);
		if(index > start)
			quickSort(data, length, start, index-1);
		if(index < end)
			quickSort(data, length, index+1, end);
	}

	int Partition(int* data, int length, int start, int end){

	    int index = RandomInRange(start, end);
	    Swap(&data[index], &data[end]);

	    int small = start - 1;
	    for(index = start; index < end; ++index)
	    {
	        if(data[index] < data[end])
	        {
	            ++ small;
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
	int data[] = {3,1,2,5,4};
	Solution s;
	s.quickSort(data, 5, 0, 4);

	for(int i=0; i<5; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl; 

}