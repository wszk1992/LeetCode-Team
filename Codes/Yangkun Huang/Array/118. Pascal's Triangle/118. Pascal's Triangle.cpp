#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> v;
	vector<int> row1(1, 1), row2(2, 1);
	if (numRows == 1)
		v.push_back(row1);
	if (numRows == 2)
	{
		v.push_back(row1);
		v.push_back(row2);
	}
	if (numRows > 2)
	{
		v.push_back(row1);
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
					cout << "else" <<endl;
					l_row.push_back(*iter + *(iter + 1));
					iter++; 
				}
			}	
			for (int j = 0; j < l_row.size(); j++)
					cout << l_row[j] << " ";
			p_row = l_row;
			v.push_back(l_row);	
			l_row.clear();
		}
	}
	return v;
}

// vector¿ÉÒÔÓÃ=¿½±´ 
// empty()ÅÐ¶ÏÈÝÆ÷ÊÇ·ñÎª¿Õ clear()Çå¿ÕÈÝÆ÷

int main()
{
	//vector<int> v,w(3,2);
	//for (int i = 0; i < 10; i++)
	//v.push_back(i);
	//v.push_back(1); v.push_back(2); v.push_back(1);
	///*for (int i = 0; i < v.size(); i++)
	//	cout << v[i] << endl;*/
	//w = v;
	//for (int i = 0; i < w.size(); i++)
	//	cout << w[i] << endl;
	vector<vector<int>> w;
	w=generate(5);

	system("pause");
}