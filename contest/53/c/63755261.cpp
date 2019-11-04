#include <bits/stdc++.h>
 
using namespace std;
 
int main ()
 	{
 		ios :: sync_with_stdio(false);
 		cin.tie(0); 
 		
 		int n; 
 		
 		cin >> n; 
 		
 		int i = 1; int j = n; 
 		
 		while (1) 
 			{
 				if (i == j) 
 					{
 						cout << i; 
 						return 0; 
 					}
 				else 
 				if (i > j) return 0; 
 				
 				cout << i << ' ' << j << ' '; 
 				i++; 
 				j--; 
 			}
 		return 0; 
 	}