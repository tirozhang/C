#include<stdio.h>
#include<stdint.h>
/*
int max = 0;

void mid_max(int a[],int start,int end ){
	int	i; 
	//printf("%d",end );
	if( a[start] <= a[end] && start != end ){
		for( i=start+1; i<end ; i++ ){
			if( a[start] > a[i]){
				max += a[start]-a[i];
			}else{
				mid_max( a,i,end);
				break;
			}	
		}
	}else if( start != end ){

		for( i=end-1; i>start ; i--){
			if( a[end] > a[i]){
				printf("%d",max);
				max += a[end]-a[i];
			}else{
				mid_max(a,start,i);	
				break;
			}
		}
	}
}

void volume( int a[],int b){
	mid_max( a, 0 , b-1 );
}

int main(){
	int arr[] = {10,0,2,1,0,1,3,2,1,2,1};
	int len = sizeof(arr)/sizeof(int);
	volume( arr, len );
	printf("%d",max );
}
*/
void print_size( int32_t arr[10] ){
	printf("%d\n",sizeof(arr));
}
int main(){
	int32_t myarray[10];
	printf("%d\n",sizeof(myarray));
	print_size( myarray);


}


