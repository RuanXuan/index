
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
typedef struct edgedata{
	int beg,en;
	int length;
}edge;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void prim(Mgraph g,edge tree[M-1]){
	edge x;
	int d,min,j,k,s,v;
	for(v=1;v<=g.n-1;v++){
		tree[v-1].beg=0;
		tree[v-1].en=v;
		tree[v-1].length=g.edges[0][v];
	}
	for(k=0;k<=g.n-3;k++){
		min=tree[k].length;
		s=k;
		for(j=k+1;j<=g.n-2;j++){
			if(tree[j].length<min){
				min=tree[j].length;
				s=j;
			}
			v=tree[s].en;
			tree[s]=tree[k];
			for(j=k+1;j<=g.n-2;j++){
				d=g.edges[v][tree[j].en];
				if(d<tree[j].length){
					tree[j].length=d;
					tree[j].beg=v;
				}
			}
		}
	}
	printf("\n The minimum cost spanning tree is:\n");
	for(j=0;j<=g.n-2;j++){
		printf("\n %c---%c  %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
		printf("\nThe root of is %c\n",g.vexs[0]);
	}
}
int main(int argc, char** argv) {
	Mgraph g;
	edge tree[M-1];
	char filename[20];
	printf("Please input filename of Graph:\n");
	gets(filename);
	creat(&g,filename,0);
	prim(g,tree);
	return 0;
}
