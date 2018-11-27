
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

void QuickSort(edge edges[],int left,int right){
	edge x;
	int i,j,flag=1;
	if(left<right){
		i=left;
		j=right;
		x=edges[i];
		while(i<j){
			while(i<j && x.length<edges[j].length){
				j--;
			}
			if(i<j){
				edges[i++]=edges[j];
			}
			while(i<j && x.length>edges[i].length){
				i++;
			}
			if(i<j){
				edges[j--]=edges[i];
			}
		}
		edges[i]=x;
		QuickSort(edges,left,i-1);
		QuickSort(edges,i+1,right);
	}
}

void GetEdge(Mgraph g,edge edges[]){
	int i,j,k=0;
	for(i=0;i<g.n;i++){
		for(j=0;j<i;j++){
			if(g.edges[i][j]!=0 && g.edges[i][j]<FINITY){
				edges[k].beg=i;
				edges[k].en=j;
				edges[k++].length=g.edges[i][j];
			}
		}
	}
}

void kruskal(Mgraph g){
	int i,j,k=0,ltfl;
	int cnvx[M];
	edge edges[M*M];
	edge tree[M];
	GetEdge(g,edges);
	QuickSort(edges,0,g.e-1);
	for(i=0;i<g.n-1;i++){
		while(cnvx[edges[k].beg]==cnvx[edges[k].en]){
			k++;
		}
		tree[i]=edges[k];
		ltfl=cnvx[edges[k].en];
		for(j=0;j<g.n;j++){
			if(cnvx[j]==ltfl){
				cnvx[j]=cnvx[edges[k].beg];
			}
			k++;
		}
	}
	printf("最小生成树是：\n");
	for(j=0;j<g.n-1;j++){
		printf("%c---%c%6d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Mgraph g;
	char filename[20];
	printf("Please input filename of Graph:\n");
	gets(filename);
	creat(&g,filename,0);
	kruskal(g);
	return 0;
}
