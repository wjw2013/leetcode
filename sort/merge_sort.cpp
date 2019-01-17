#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


void merge(vector<int> * sort_vector, vector<int>* tmp_vector,int left,int mid, int right) {
	

	int i = left;
	int j=mid+1;
	int k = left;

	while(i<(mid+1) && j<(right+1)) {
		if((*sort_vector)[i] < (*sort_vector)[j]) {
			(*tmp_vector)[k++] = (*sort_vector)[i++];
		} else {
			(*tmp_vector)[k++] = (*sort_vector)[j++];
		}
	}

	while (i < mid + 1) {
		(*tmp_vector)[k++] = (*sort_vector)[i++];
	}

	while (j < right + 1) {
		(*tmp_vector)[k++] = (*sort_vector)[j++];
	}

	for (int i = left ; i<(right+1); i++) {
		(*sort_vector)[i] = (*tmp_vector)[i];
	}



}

void merge_sort(vector<int> * sort_vector, vector<int>* tmp_vector,int left, int right) {
	
	if (left < right) {
		int mid = left + (right - left)/2;
		merge_sort(sort_vector,tmp_vector,left,mid);
		merge_sort(sort_vector,tmp_vector,mid+1,right);
		merge(sort_vector,tmp_vector,left,mid,right);
	}
}

int main(){
	int a[] = {9,10,8,6,12,3,20};
	int len = sizeof(a)/sizeof(a[0]);
	cout<< "len is "<<len<<endl;
	vector<int> i_v(a,a+len);
	vector<int> tmp(a,a+len);
	auto f = [&i_v](const string display) {
		cout<<display<<endl;
		for (auto val : i_v)
		{
		    cout << val << " ";
		}
		cout<<endl;
	};

	f("before sort:");
	merge_sort(&i_v,&tmp,0,len-1);
	f("after sort:");
}