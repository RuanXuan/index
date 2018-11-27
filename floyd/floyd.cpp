#include <iostream>
#include <iostream>
#include <stdio.h>
#define FINITY 5000
#define M 20

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

typedef int dist[M][M];
typedef int path[M][M];

void floyd(Mgraph g,path p,dist d){
	int i,j,k;
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++){
			d[i][j]=g.edges[i][j];
			if(i!=j && d[i][j]<FINITY ){
				p[i][j]=i;
			}
			else{
				p[i][j]=-1;
			}
		}
	}
	for(k=0;k<g.n;k++){
		for(i=0;i<g.n;j++){
			if(d[i][j]>(d[i][j]+d)[k][j]){
				d[i][j]=d[i][k]+d[k][j];
				p[i][j]=k;
			}
		}
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
