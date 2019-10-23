#include<iostream>
#include<stdio.h>
using namespace std;
#include<omp.h>
#include<time.h>

int bin_par(int *a, int l, int h, int k)
{
	int m = (l+h)/2;
	int res = -1;
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			int l1 = l;
			int h1 = m;
			while(l1 <= h1)
			{
				int m1 = (l1 + h1)/2;
				if(a[m1] == k)
				{
					res = m1;
					break;
				}
				if(a[m1] < k)
					l1 = m1 + 1;
				else
					h1 = m1 - 1;
			}
		}
		#pragma omp section
		{
			int l2 = m;
			int h2 = h;
			while(l2 <= h2)
			{
				int m2 = (l2 + h2)/2;
				if(a[m2] == k)
				{
					res = m2;
					break;
				}
				if(a[m2] < k)
					l2 = m2 + 1;
				else
					h2 = m2-1;
			}
		}
	}
}

int main()
{
	int n,k,r;
	float st,en,t;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	int a[n];
	cout << "Enter the elements of the array in ascending order" << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	cout << "Enter the element to be found" << endl;
	cin >> k;
	st = omp_get_wtime();
	r = bin_par(a,0,n-1,k);
	en = omp_get_wtime();
	if(r == -1)
		cout << "Element not found" << endl;
	else
		cout << "Element found at index - " << r << endl;
	cout << "Time taken = " << (en-st) << " seconds" << endl;
	return 0;
}