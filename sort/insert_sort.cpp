#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void insert_sort(vector<int> * sort_vector) {
	int size = (*sort_vector).size();
	for(int i = 1; i < size; i++){
		int tmp = (*sort_vector)[i];
		int j = i;
		while((j>0) && (tmp < (*sort_vector)[j-1])) {
			(*sort_vector)[j] = (*sort_vector)[j-1];
			j--;
		}

		if(i != j)
		{
			(*sort_vector)[j] = tmp;
		}
		
	}	 		
	
}

int main(){
	int a[] = {9,10,8,6,12,3};
	vector<int> i_v(a,a+6);
	auto f = [&i_v](const string display) {
		cout<<display<<endl;
		for (auto val : i_v)
		{
		    cout << val << " ";
		}
		cout<<endl;
	};

	f("before sort:");
	insert_sort(&i_v);
	f("after sort:");
}