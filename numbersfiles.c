#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Write C source code for a computer program that receives number of values user is going to enter, 
//allocates enough memory, receives values and save them in a text file, 
//computes average and standard deviation by reading numbers from the text file and result should be added to the text file.  

int main(){
	
	FILE *f=fopen("numbers.txt","w+");
	int n;
	printf("How many numbers will you enter?:");
	scanf("%d",&n);
	int *p;
	p=malloc(n*sizeof(int));
	int i;
	printf("Enter numbers:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	fprintf(f,"Numbers:");
	for(i=0;i<n;i++){
		fprintf(f,"%d",p[i]);
		if(i<n-1){
			fprintf(f,",");
		}
	}
	
    int j,sum=0;
    
    fscanf(f,"%d",p);
    for(j=0;j<n;j++){
    	sum+=p[j];
	}
	int sq=0;
	for(j=0;j<n;j++){
    	sq+=p[j]*p[j];
	}
	
	float avrg=sum/(n*1.0);
	
	printf("Sum of numbers:%d",sum);
	printf("\nAverage of numbers:%.2f",avrg);
	
	float deviation=sqrt(sq/(n*1.0));
	
	printf("\nDeviation:%.2f",deviation);
	
	fprintf(f,"\nSum of numbers:%d\nAverage of numbers:%.2f\nDeviation:%.2f",sum,avrg,deviation);
	
	fclose(f);

	return 0;
}
 
