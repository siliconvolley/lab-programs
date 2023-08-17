#include<stdio.h>
//Rat in a Maze

int l, k, m, n, r, c;
int maze[20][20];
int sol[20][20];

void display(){
	int i, j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%d\t", sol[i][j]);
		}
		printf("\n");
	}
}

int solve(int m, int n){
	if((m==r-1) && (n==c-1)){
		sol[m][n]=1;
		return 1;
	}
	
	if(m>=0 && n>=0 && m<r && n<c && sol[m][n]==0 && maze[m][n]==0){
		
		sol[m][n]=1;
		if(solve(m+1, n))
			return 1;
		if(solve(m, n+1))
			return 1;
		if(solve(m-1, n))
			return 1;
		if(solve(m, n-1))
			return 1;

		sol[m][n] = 0;
		return 0;
	}
	return 0;
}

int main(){
	int i, j;
	printf("Enter the size (no. of rows & columns): ");
	scanf("%d%d", &r, &c);
	printf("Enter the maze (0 = path is free, 1 = path is blocked): \n");

	for(k=0; k<r; k++){
		for(l=0; l<c; l++){
			scanf("%d", &maze[k][l]);
		}
	}
	
	printf("Enter starting point index:");
	scanf("%d%d", &m, &n);
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			sol[i][j]=0;
		}
	}
	if(solve(m, n))
		display();
	else
		printf("\nNo solution\n");
	return 0;
}
