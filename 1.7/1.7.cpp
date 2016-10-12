#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//void zero(int **a, int m, int n){
//    bool row[m], col[n];
//    memset(row, false, sizeof(row));
//    memset(col, false, sizeof(col));
//    for(int i=0; i<m; ++i)
//        for(int j=0; j<n; ++j)
//            if(a[i][j] == 0){
//                row[i] = true;
//                col[j] = true;
//            }
//    for(int i=0; i<m; ++i)
//        for(int j=0; j<n; ++j)
//            if(row[i] || col[j])
//                a[i][j] = 0;
//}

void zero0(int **a, int m, int n)
{
	bool *r = new bool[m];
	bool *c = new bool[n];

	for (int i = 0; i < m; i++)
	{
		r[i] = false;
		for (int j = 0; j < n; j++)
		{
			r[i] |= (a[i][j] == 0);
			if (r[i] == true)
			{
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		c[i] = false;
		for (int j = 0; j < m; j++)
		{
			c[i] |= (a[j][i] == 0);
			if (c[i] == true)
			{
				break;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (r[i])
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i])
		{
			for (int j = 0; j < m; j++)
			{
				a[j][i] = 0;
			}
		}
	}
}

int main()
{
	int m, n;
	cout << "please input the rows(M) and cols(N) of a matrix" << endl;
	cin >> m >> n;
	cout << "start to input a " << m << " x " << n << " 's matrix,split by blank." << endl;
	int **a;
	a = new int*[m];
    for(int i=0; i<m; ++i)
        a[i] = new int[n];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>a[i][j];
    //for(int i=0; i<m; ++i){
    //    for(int j=0; j<n; ++j)
    //        cout<<a[i][j]<<" ";
    //    cout<<endl;
    //}
    cout<<endl;
    zero0(a, m, n);
	cout << "after process ,the new matrix is below,see what happen." << endl;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    fclose(stdin);
    return 0;
}
