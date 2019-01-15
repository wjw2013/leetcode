#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


void  partition_sort(vector<int>* sort_vector,int left, int right) {
	if(left >= right)
		return;
	int key = (*sort_vector)[left];
	int i = left;
	int j = right;
	while(i != j) {
		while(j>i && (*sort_vector)[j] > key) {
			j--;
		}
		(*sort_vector)[i] = (*sort_vector)[j];

		while(j>i && (*sort_vector)[i] < key) {
			i++;
		}
		(*sort_vector)[j] = (*sort_vector)[i];
	}
	(*sort_vector)[i] = key;
	partition_sort(sort_vector,left,i-1);
	partition_sort(sort_vector,i+1,right);	
}

void quick_sort(vector<int> * sort_vector) {
	int size = (*sort_vector).size();
	partition_sort(sort_vector,0,size-1);		
	
}

int main(){
	int a[] = {9,10,8,6,12,3,20};
	vector<int> i_v(a,a+7);
	auto f = [&i_v](const string display) {
		cout<<display<<endl;
		for (auto val : i_v)
		{
		    cout << val << " ";
		}
		cout<<endl;
	};

	f("before sort:");
	quick_sort(&i_v);
	f("after sort:");
}