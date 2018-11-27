#include <iostream>
#define M 20
typedef char vertextype;
typedef struct node{
	int adjvex;
	int len;
	struct node *next;
}EdgeNode;

typedef struct de{
	EdgeNode *FirstEdge;
	vertextype vertex;
	int id;
}vertexnode;

typedef struct{
	vertexnode adjlist[M];
	int n,e;
}AoeGraph;

int EarlistTime(AoeGraph gout,int ve[],int seq[]){
	int count=0,i,j,v,flag[M];
	int queue[M];
	int front=0,rear=0;
	EdgeNode *p;
	for(i=0;i<gout.n;i++){
		ve[i]=0;
	}
	for(i=0;i<gout.n;i++){
		flag[i]=0;
	}
	for(i=0;i<gout.n;i++){
		if(gout.adjlist[i].id=0 && flag[i]==0){
			queue[rear++]=i;
			flag[i]=1;
		}
	}
	while(front<rear){
		v=queue[front++];
		printf("%c---->",gout.adjlist[v].vertex);
		seq[count]=v;
		count++;
		p=gout.adjlist[v].FirstEdge;
		while(p){
			j=p->adjvex;
			if(--gout.adjlist[j].id==0 && flag[j]==0){
				queue[rear++]=j;
				flag[j]=1;
			}
			if(ve[v]+p->len>ve[j]){
				ve[j]=ve[v]+p->len;
			}
			p=p->next;
		}
	}
	return count;
}

void LataTime(AoeGraph gin,int ve[],int vl[],int seq[]){
	int k=gin.n-1,i,j,v;
	EdgeNode *p;
	for(i=0;i<gin.n;i++){
		vl[i]=ve[seq[gin.n-1]];
	}
	while(k>-1){
		v=seq[k];
		p=gin.adjlist[v].FirstEdge;
		while(p){
			j=p->adjvex;
			if(vl[v]-p->len < vl[j]){
				vl[j]=vl[v]-p->len;
			}
			p=p->next;
		}
		k--;
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
