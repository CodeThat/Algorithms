void bubbleSort(vector<int>& vec, bool sortAccendingOrder = true){

	for(int i = 0; i < vec.size();i++)
		for(int j = i+1; j < vec.size(); j++)
		{
			if(sortAccendingOrder)
			{
				if(vec[i] > vec[j])
					std::swap(vec[i],vec[j]);
			}

			else if(vec[i] < vec[j]) //else decendingOrder
				std::swap(vec[i],vec[j]);
		}
			
}
