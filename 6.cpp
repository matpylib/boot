#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter size of the matrix and vextor\n";
	cin>>n;
	
	omp_set_num_threads(32);
	
	int mat[n][n] , vec[n] , out[n];
	
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			mat[i][j] = rand()%10;
		}
	}
	
	for(int i = 0 ; i <n; i++)
	{
		vec[i] = rand()%10;
	}
	
	cout<<"\nPARALLEL\n";
	
	double start , end , time;
	start = omp_get_wtime();
	
	#pragma omp parallel for
	for(int i = 0 ; i < n ; i++)
	{
		out[i]=0;
		#pragma omp parallel for
		for(int j = 0 ; j <n ;j++)
		{
			out[i] += mat[i][j] * vec[j];
		}
	}
	end = omp_get_wtime();
	time = (double)(end-start);
	cout<<"\nTime for parallel : "<<time<<endl;
	
	for(int i = 0 ; i<n ; i++)
	{
		cout<<out[i]<<endl;
	}
	
	cout<<"\nSERIAL\n";
	clock_t c1 = clock();
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j <n ;j++)
		{
			out[i] += mat[i][j] * vec[j];
		}
	}
	double t =(double) (clock() - c1) / CLOCKS_PER_SEC;
	cout<<"\nTime for Serial : "<<t<<endl;
		
	return 0;
}
