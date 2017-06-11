#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define M 10000
void ranking(){
int score[N];
int i,j,s,tmp;
char name_save,name[5][10];
FILE *rk;
	rk=fopen("ranking","w");
for(i=0;i<5;i++){
	for(s=0;s<10;s++){
		scanf("%c",&name[i][s]);
		if(name[i][s]=='\n')
		break;
	}
	score[i]=100-10*i;
}
for(i=0;i<N-1;i++)
for(j=N-1;j>i;j--)
if(score[j-1]>score[j]){
tmp=score[j-1];
score[j-1]=score[j];
score[j]=tmp;
for(s=0;s<10;s++){
	name_save=name[j-1][s];
	name[j-1][s]=name[j][s];
	name[j][s]=name_save;
	if(name[j-1][s]=='\n')
	break;
}
}
for(i=0;i<N;i++){
	for(s=0;s<10&&name[i][s]!='\n';s++){
		fprintf(rk,"%c",name[i][s]);
	}
fprintf(rk," : %d sec",score[i]);
fprintf(rk,"\n");
}
fclose(rk);
}
int main(){
	ranking();
	return 0;
}
