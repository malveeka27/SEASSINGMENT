#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 40000000

void merge_sort(int *array, int *tmp, int size);
void merge_r(int *src, int *tmp, int start, int mid, int end);
void ins_sort(int *src, int start, int end);

int main() {
  int i;
  int *src, *tmp;
   src=(int *)malloc(ARRAY_SIZE * sizeof(int));
   tmp=(int *)malloc(ARRAY_SIZE * sizeof(int));

  srand(time(NULL));
  
  // generate random numbers for int type array
  for (i = 0; i < ARRAY_SIZE; i++) {
    src[i] = rand();
  }
/*
printf("before sorting\n");
for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d \t",src[i]);	
  }
printf("\n");*/

  // sort int type array
  merge_sort(src, tmp, ARRAY_SIZE);

/*printf("after sorting\n");
for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d \t",src[i]);
	
  }
printf("\n");*/
  for(i=1;i<ARRAY_SIZE&&(src[i-1]<=src[i]);i++);
  if(i==ARRAY_SIZE) { printf("Test passed");}
  else { printf("Test Failed");}
  free(src);
  free(tmp);

  return 0;
}

void merge_sort(int *src, int *tmp, int size) {
  int i, stride=100;
    for(i=0;i+stride<size;i=i+stride){
	    ins_sort(src, i, i+stride-1);
    }
    if(i<size){ ins_sort(src, i, size-1); }

   while(stride<size){	
    for(i=0;i+2*stride<size;i=i+2*stride){
	    merge_r(src, tmp, i, i+stride, i+2*stride-1);
    }
    if(i+stride<size){ merge_r(src,tmp, i, i+stride, size-1); } 
    stride=2*stride;
   }
}
void ins_sort(int *src, int start, int end){
	for(int pos=start+1; pos<=end; pos++){
		int temp=src[pos];
		while(pos>start && src[pos-1]>temp){ src[pos]=src[pos-1]; pos=pos-1; }
		if(pos>=start){ src[pos]=temp; }
	}	
}

void merge_r(int *src, int *tmp, int start, int mid, int end) {
int i=start, j=mid, k=start;
	while (i <=mid-1 && j <=end) {
		if (src[i] <= src[j]) { tmp[k++] = src[i++]; }
	       	else { tmp[k++] = src[j++]; }
	}
	while (i<=mid-1) { tmp[k++] = src[i++]; }	
	while (j<=end) { tmp[k++] = src[j++];}
	i=start;
	j=end;
	while(i<=j){ src[i]=tmp[i]; i++;}
}