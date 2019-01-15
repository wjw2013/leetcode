#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


void insert_sort(vector<int>* sort_vector,int start, int dx) {
	int size = (*sort_vector).size();
	for(int i = start + dx; i < size; i += dx){
	int tmp = (*sort_vector)[i];
	int j = i;
	while((j>start) && (tmp < (*sort_vector)[j-dx])) {
		(*sort_vector)[j] = (*sort_vector)[j-dx];
		j-=dx;
	}

	if(i != j) {
		(*sort_vector)[j] = tmp;
	}
		
	}	


}

void shell_sort(vector<int> * sort_vector) {
	int size = (*sort_vector).size();
	int dx = size/2;
	while(dx>=1){
		for(int i = 0; i < dx; i++){
			insert_sort(sort_vector,i,dx);
		}
		dx = dx/2;
	} 		
	
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
	shell_sort(&i_v);
	f("after sort:");
}