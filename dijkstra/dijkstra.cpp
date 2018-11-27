#include <iostream>
#include <stdio.h>
#define FINITY 5000
#define M 20
using namespace std;
typedef char vertextype;
typedef int edgetype;
typedef struct{
	vertextype vexs[M];
	edgetype edges[M][M];
	int n,e;
}Mgraph;

void creat(Mgraph *g,char *s,int c){
	int i,j,k,w;
	FILE *rf;
	rf=fopen(s,"r");
	if(rf){
		fscanf(rf,"%d%d",&g->n,&g->e);
		for(i=0;i<g->n;i++){
			fscanf(rf,"%ls",&g->vexs[i]);
		}
		for(i=0;i<g->n;i++){
			for(j=0;j<g->n;j++){
				if(i==j){
					g->edges[i][j]=0;
				}
				else{
					g->edges[i][j]=FINITY;
				}
			}
		}
		for(k=0;k<g->e;k++){
			fscanf(rf,"%d%d%d",&i,&j,&w);
			g->edges[i][j]=w;
			if(c==0){
				g->edges[j][i]=w;
			}
		}
		fclose(rf);
	}
	else{
		g->n=0;
	}
}

typedef enum{FALSE,TRUE} boolean;
typedef int dist[M];
typedef int path[M];

void dijkstra(Mgraph g,int v0,path p,dist d){
	boolean final[M];
	int i,j,k,v,min,x;
	for(v=0;v<g.n;v++){
		final[v]=FALSE;
		d[v]=g.edges[v0][v];
		if(d[v]<FINITY && d[v]!=0){
			p[v]=v0;
		}
		else{
			p[v]=-1;
		}
	}
	final[v0]=TRUE;
	d[v0]=0;
	for(i=1;i<g.n;i++){
		min=FINITY;
		for(k=0;k<g.n;++k){
			if(!final[k] && d[k]<min){
				v=k;
				min=d[k];
			}
		}
		printf("\n%c---%d\n",g.vexs[v],min);
		if(min==FINITY){
			return;
		}
		final[v]=TRUE;
		for(k=0;k<g.n;++k){
			if(!final[k] && (min+g.edges[v][k]<d[k])){
				d[k]=min+g.edges[v][k];
				p[k]=v;
			}
		}
	}
}

void print_gpd(Mgraph g,path p,dist d){
	int st[M],i,pre,top=-1;
	for(i=0;i<g.n;i++){
		printf("\nDistancd: %7d , path:",d[i]);
		st[++top]=i;
		pre=p[i];
		while(pre!=-1){
			st[++top]=pre;
			pre=p[pre]; 
		}
		while(top>0){
			printf("%2d",st[top--]);
		}
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Mgraph g;
	path p;
	dist d;
	int v0;
	char filename[20];
	cout << "input filename " << endl;
	cin >> filename;
	creat(&g, filename,1);
	printf("please input the source point v0:");
	scanf("%d",&v0);
	dijkstra(g,v0,p,d);
	print_gpd(g,p,d);
	return 0;
}
