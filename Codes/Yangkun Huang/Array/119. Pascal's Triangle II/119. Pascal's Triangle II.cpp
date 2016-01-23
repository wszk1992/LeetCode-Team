#include<iostream>
#include<vector>

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<vector<int>> v;
	vector<int> row1(1, 1), row2(2, 1);
	if (rowIndex == 0)
		v.push_back(row1);
	if (rowIndex == 1)
	{
		v.push_back(row1);
		v.push_back(row2);
	}
	if (rowIndex> 1)
	{
		v.push_back(row1);
		v.push_back(row2);
		int i = 0, n = 0;
		vector<int> p_row, l_row;
		vector<int>::iterator iter;
		for (n = 2, p_row = row2; n <= rowIndex; n++)
		{
			iter = p_row.begin();
			for (i = 0; i < n+1; i++)
			{
				if (i == 0 || i == n)
					l_row.push_back(1);
				else
				{
					l_row.push_back(*iter + *(iter + 1));
					iter++;
				}
			}
			p_row = l_row;
			v.push_back(l_row);
			l_row.clear();
		}
	}
	vector<vector<int>>::iterator it=v.begin()+rowIndex;
	return *it;
}

