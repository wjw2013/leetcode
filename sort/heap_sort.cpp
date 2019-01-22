#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


void heap_build(vector<int> * sort_vector, int right) {
	

	int last_root = right/2;
	for (int i = last_root;i>=0;i--) {
		int left_child = i*2 +1 ;
		int right_child = left_child + 1;
		int max_index =left_child;
		if(right_child<=right && (*sort_vector)[right_child] >
			(*sort_vector)[left_child]) {
			max_index = right_child;
		}
		if ((*sort_vector)[max_index] >(*sort_vector)[i]) {
			int tmp = (*sort_vector)[i];
			(*sort_vector)[i] = (*sort_vector)[max_index];
			(*sort_vector)[max_index] = tmp;
		}
	}
}

void heap_sort(vector<int> * sort_vector, int right) {
	
	for (int i = right; i>=0; i--) {
		heap_build(sort_vector,i);
		int tmp = (*sort_vector)[0];
		(*sort_vector)[0] = (*sort_vector)[i];
		(*sort_vector)[i] = tmp;
	}

}

int main(){
	int a[] = {9,10,8,6,12,3,20};
	int len = sizeof(a)/sizeof(a[0]);
	cout<< "len is "<<len<<endl;
	vector<int> i_v(a,a+len);
	auto f = [&i_v](const string display) {
		cout<<display<<endl;
		for (auto val : i_v)
		{
		    cout << val << " ";
		}
		cout<<endl;
	};

	f("before sort:");
	heap_sort(&i_v,len-1);
	f("after sort:");
}