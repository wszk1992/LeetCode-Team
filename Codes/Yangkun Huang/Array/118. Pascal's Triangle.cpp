#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> v;
	vector<int> row1(1, 1), row2(2, 1);
	if (numRows == 0)
		return v;
	v.push_back(row1);
	if (numRows >= 2)
	{
		v.push_back(row2);
		int i = 0, n = 0;
		vector<int> p_row, l_row;
		vector<int>::iterator iter;
		for (n = 3, p_row = row2; n <= numRows; n++)
		{
			iter = p_row.begin();
			for (i = 0; i < n; i++)
			{
				if (i == 0 || i == n - 1)
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
	return v;
}

// vector¿ÉÒÔÓÃ=¿½±´ 
// empty()ÅÐ¶ÏÈÝÆ÷ÊÇ·ñÎª¿Õ clear()Çå¿ÕÈÝÆ÷

