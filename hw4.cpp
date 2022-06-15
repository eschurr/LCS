#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string DNA1;
string DNA2;

void PRINT_LCS(vector<vector<char> > b, string X, int i, int j)
{
	if(i == 0 || j == 0)
	{
		return;
	}
	if(b[i][j] == '!') //diagonal arrow
	{	
		PRINT_LCS(b, X, i - 1, j - 1);
		cout << X[i];
	}
	else if(b[i][j] == '@') //up arrow
	{	
		PRINT_LCS(b, X, i - 1, j);
	}
	else //left arrow
	{	
		PRINT_LCS(b, X, i, j - 1);
	}
}

int LCS_LENGTH(string X, string Y)
{
	int m = X.length();
	int n = Y.length();
	
	vector<vector<char> > b(m+1, vector<char>(n+1, 0));
	vector<vector<char> > c(m+1, vector<char>(n+1, 0));
	
	for (int i = 0; i <=m; i++)
		c[i][0] = 0;
	for (int j = 0; j <=n; j++)
		c[0][j] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(X[i] == Y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '!'; // diagonal arrow
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = '@'; // up arrow
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = '#'; // left arrow
			}
		}
	}

	PRINT_LCS(b, X, X.length(), Y.length());
	
	return c[m][n];
}	

int main()
{		
		DNA1 = " ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
		DNA2 = " GTCGTTCGGAATGCCGTTGCTCTGTAA";
		int lengthofLCS = LCS_LENGTH(DNA1, DNA2);
		cout << endl << lengthofLCS - 1 << endl;
}