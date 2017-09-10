#include<bits/stdc++.h>
using namespace std;
int n, cont;
int sd[9][9], sum;
int temp[81][2];
bool check(int x, int y, int num){
	if(sd[x][y])
		return 0;
	for(int i=0; i<9; i++){
		if(sd[i][y]==num||sd[x][i]==num)
			return 0;
	}
	return 1;
}
void dfs(int num, int p, int sum){
	if(sum==81){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(j)printf(" ");
				printf("%d",sd[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		cont++;
		if(cont==n)
			exit(0);
			return;
	}
	if(p==81)dfs(num%9+1, 0, sum);
	for(int i=0; i<9; i++){
		int x, y;
		x=temp[p+i][0];
		y=temp[p+i][1];
		if(check(x, y, num)){
			sd[x][y]=num;
			dfs(num, p+9, sum+1);
			sd[x][y]=0;
		}
	}
}
int main(){
	freopen("sudoku.txt", "w", stdout);
	scanf("%d", &n);
	int p=0,q=0,k=0;
	int t1[3]={0,1,2};
	int t2[3]={3,4,5};
	int t3[3]={6,7,8};
	for(int i=0; i<81; i++){
		if(k==0){
	    temp[i][0]=p;
		temp[i][1]=t1[q];
	    q=(q+1)%3;
	    if(q==0)p=(p+1)%9;
	    if(p+q==0){
	    	k++;
	    	continue;
		}
	}
	    if(k==1){
	    temp[i][0]=p;
		temp[i][1]=t2[q];
	    q=(q+1)%3;
	    if(q==0)p=(p+1)%9;
	    if(p+q==0){
	    	k++;
	    	continue;
		}
	    }
	    if(k==2){
		temp[i][0]=p;
		temp[i][1]=t3[q];
	    q=(q+1)%3;
	    if(q==0)p=(p+1)%9;
	    if(p+q==0){
	    	k++;
	    	continue;
		}
	    }
	}

	dfs(6, 0, 0);
	return 0;
}
