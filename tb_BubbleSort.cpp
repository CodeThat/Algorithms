#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort_students(const vector<int> &numbers) {
    int i, j;
	std::vector<int> output = numbers;
	
    for(i = 0; i < output.size(); i++)
    {
        for(j = i+1; j < output.size(); j++)
        {
            int temp;
            if(output[i] > output[j])
            {
                temp = output[i];
                output[i] = output[j];
                output[j] = temp;
            }
        }
    }

    for(i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}
