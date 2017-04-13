#include<bits/stdc++.h>

using namespace std;

int knap(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}


int main(){
	string n;
	int m,sum,d,w,ans;
	int wt[21],val[21];
	
		cin>>m;
		getchar();
		while(m--){
			
			
			getline(cin,n);
			int num;
			istringstream str(n);
			
			int i=0; sum=0;
			while(str >> num){
				sum+=num;
				wt[i]=val[i]=num;
				i++;
				
			}
			
		
			
			if(sum%2==1){
				cout<<"NO"<<'\n';
			}
			else {
				
				w= sum / 2;
				d= knap(w,wt,val,i);
				
				if(d==w) cout<<"YES"<<'\n';
				else cout<<"NO"<<'\n';

			}
			
			}

	return 0;
}
