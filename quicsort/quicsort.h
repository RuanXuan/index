#include <iostream>
void quicksort(table *teb,int left,int right){
	int i,j;
	if(left<right){
		i=left;
		j=right;
		tab->r[0]=tab->r[i];
		do{
			while(tab->r[j].key>tab->r[0].key&&i<j){
				j--;
			}
			if(i<j){
				tab->r[i].key=tab->r[j].key;
				j--;
			}
		}
		while(i!=j);
		tab->r[i]=tab->r[0];
		quicksort(tab,left,i-1);
		quicksort(tab,i+1,right);
		}
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

