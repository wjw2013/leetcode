#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void selection_sort(vector<int> * sort_vector) {
	int size = (*sort_vector).size();
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i; j < size; j++)
		{
			if((*sort_vector)[j] < (*sort_vector)[min])
			{
				min = j;
			}

		}
		if(min != i)
		{
			int tmp = (*sort_vector)[i];
			(*sort_vector)[i] = (*sort_vector)[min];
			(*sort_vector)[min] = tmp;
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
	selection_sort(&i_v);
	f("after sort:");
}