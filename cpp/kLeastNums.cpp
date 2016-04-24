// give n integers, find the minial k integers.
//for example, 4,5,1,6,2,7,3,8. then 4 least numbers are 1,2,3,4

#include <iostream>

int RandomInRange(int min, int max){
	return rand()%(max-min+1) + min;
}

void Swap(int* a, int* b){

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

class Solution{
public:
	void getLeastNums(int* input, int length, int k){
		int start = 0;
		int end = length-1;
		int index = Partition(input, length, start, end);
		while(index != k-1){
			if(index > k-1){
				end = index-1;
				index = Partition(input,length,start,end);
			}
			else{
				start = index+1;
				index = Partition(input,length,start,end);
			}
		}
	}


	int Partition(int* data, int length, int start, int end){

	    int index = RandomInRange(start, end);
	    Swap(&data[index], &data[end]);

	    int small = start - 1;

	    //swap
	    for(int i = start; i < end; ++i)
	    {
	    	//compare with that partition number
	        if(data[i] < data[end])
	        {
	        	// small will point to the big
	            ++ small;
	            if(small != i)
	                Swap(&data[i], &data[small]);
	        }
	    }

	    ++small;

	    Swap(&data[small], &data[end]);

	    return small;
	}
};

int main(){
	int a[] = {4,5,1,6,2,7,3,8};
	int k=2;
	Solution s;
	s.getLeastNums(a, 8, k);

	for(int i=0; i<k; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;


}