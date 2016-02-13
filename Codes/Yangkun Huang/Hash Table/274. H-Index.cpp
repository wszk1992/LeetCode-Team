 int hIndex(vector<int>& citations) {
        int count=0;
        int h_index=citations.size();
        // Bubble(citations);
        QuickSort(citations);
        for(vector<int>::iterator i=citations.begin();i!=citations.end();i++)
        if(*i<h_index)
        h_index--;
        return h_index;
    }
  void QuickSort(vector<int>& v)
{
	Qsort(0,v.size()-1,v);
}
void Qsort(int low, int high,vector<int>& v)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(low, high, v);
		Qsort(low, pivot - 1,v);
		Qsort(pivot + 1, high,v);
	}
}
int Partition(int low, int high, vector<int>& v)
{
	int pivotkey, temp;
	temp = pivotkey = v[low];
	for (; low < high;)
	{
		for (; low < high&&v[high] >= pivotkey;)
			high--;
		v[low]= v[high];
		for (; low < high&&v[low] <= pivotkey;)
			low++;
		v[high] = v[low];
	}
	v[low] = temp;
	return low;	
}
