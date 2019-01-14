#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> & unsort_vector)
{
	for(int i = unsort_vector.size() -1; i > 0; i--)
	{
		bool sort_ok = true;
		for(int j = 0; j < i; j++)
		{

			if(unsort_vector[j] > unsort_vector[j+1])
			{
				int tmp = unsort_vector[j];
				unsort_vector[j]  = unsort_vector[j+1];
				unsort_vector[j+1] = tmp; 
				sort_ok = false;
			}
		}
		if(sort_ok)
			break;
	}

}

int main()
{
	int a[] = {8,7,9,4,6,5,10};
	std::cout<<"a size is :"<<sizeof(a)<<std::endl;
	std::vector<int> i_vector(a,a+6);
	std::cout<<"i_vector size is :"<<i_vector.size()<<std::endl;

	auto f = [&i_vector](std::string a){
		std::cout<<a<<std::endl;
		for(int i = 0; i < i_vector.size(); i++)
		{
			std::cout<<i_vector[i]<<" ";
		}
		std::cout<<std::endl;
	};

	f("before sort :");
	bubble_sort(i_vector);
	f("after sort:");



}