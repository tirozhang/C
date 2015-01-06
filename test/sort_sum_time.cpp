#include <string>
#include <iostream>
 #include<iomanip>
#include <math.h>
#include<time.h>
#include <sys/timeb.h>
//#include<conio.h>
#define MAX 60000 /*记录数组的个数*/
#define NUM 50000/*实际输入数组的个数*/
using namespace std;
 
typedef struct	/*定义记录为结构体类型*/  
{ 
	int key;	/*记录的关键词域*/
	int oth;	/*记录的其它域*/
}rectype;

rectype *s1,s[MAX];	/*s[MAX]存放原始随机数，*s1取出原始数据后进行排序*/

/*直接插入排序算法如下*/
void insert_sort(rectype r[]) /*对数组r按递增顺序进行插入排序算法*/
{  
	int i,j,n=NUM;            /*NUM为实际输入的记录数，是一个常量*/
	for(i=1;i<=n;i++)         /* i<NUM 条件很重要，NUM为实际记录数*/
	{ 
		r[0]=r[i];             /*r[0]为监视哨*/
		j=i-1;                 /*依次插入记录r[1],……，r[NUM]*/
		while(r[0].key<r[j].key) /*查找r[i]合适的位置*/
		{
			r[j+1]=r[j--];
		}         /*将记录关键词大于r[i].key的记录后移*/
		    r[j+1]=r[0];               /*将记录r[i]插入到有序表的合适的位置上*/
	}
}/*INSERTSORT*/

/*希尔排序算法如下*/
void shell_sort(rectype r[]) /*取增量为d(i+1)=[d(i)/2]的希尔排序的算法*/

{    int i,n,jump,change,temp,m; /*change为交换标志，jump为增量步长*/
        jump=NUM;  n=NUM; /*NUM为顺序表的实际长度*/
     while(jump>0)
	 { jump=jump/2; /*取步长d(i+1)=[d(i)/2]*/
         do { change=0; /*设置交换标志，change=0表示未交换*/
             for(i=1;i<=n-jump;i++)
			 { m=i+jump; /*取本趟的增量*/
	             if(r[i].key>r[m].key) /*记录交换*/
				 { temp=r[m].key;
	              r[m].key=r[i].key;
       	          r[i].key=temp;
	              change=1; /*change=1表示有交换*/
				 }/*if*/
			 }/*for*/ /*本趟排序完成*/
		 }while(change==1); /*当change=0时终止本趟排序*/
	 }/*while*/		/*当增量jump=1且change=0时终止算法*/
}/*SHELLSORT*/

/*冒泡排序算法如下*/
void bubble_sort(rectype r[]) /*从下往上扫描的冒泡排序*/
{ int i,j,noswap=0,n=NUM;	/*noswap为交换标志,NUM为实际输入记录数*/
rectype temp;
for(i=1;i<n;i++)		    /*进行n-1趟冒泡排序*/
{ noswap=1;					/*设置交换标志，noswap=1表示没有记录交换*/
for(j=n;j>=i;j--)			/*从下往上扫描*/						
 if(r[j].key<r[j-1].key)	/*交换记录*/
 { temp.key=r[j-1].key;
 r[j-1].key=r[j].key;
 r[j].key=temp.key;
 noswap=0; /*当交换记录时，将交换标志置0即noswap=0 */
 }/*if*/
 if(noswap) break; /*若本趟排序中未发生记录交换，则终止排序*/
}/*for*/		   /*终止排序算法*/
}/*BUBBLESORT*/

/*快速排序算法如下*/
int partition(rectype r[],int s,int t) /*快速排序算法中的一趟划分函数*/
 { int i,j;rectype temp;
   i=s;j=t;temp=r[i];                 /*初始化，temp为基准记录*/
do {while((r[j].key>=temp.key)&&(i<j))
    j--;			 /*从右往左扫描，查找第一个关键词小于temp的记录*/
   if(i<j) r[i++]=r[j];	/*交换r[i]和r[j]*/
   while((r[i].key<=temp.key)&&(i<j))
    i++;			/*从左往右扫描，查找第一个关键词大于temp的记录*/
   if(i<j) r[j--]=r[i]; /*交换r[i]和r[j]*/
}while(i!=j);/*i=j,z则一次划分结束，基准记录达到其最终位置*/
r[i]=temp; /*最后将基准记录temp定位*/
return(i);
}/*PARTITION*/
void quick_sort(rectype r[],int hs,int ht)/*对r[hs]到r[ht]进行快速排序*/
{ int i;
if(hs<ht) /*只有一个记录或无记录时无需排序*/
{ i=partition(r,hs,ht); /*对r[hs]到r[ht]进行一次划分*/
  quick_sort(r,hs,i-1);	/*递归处理左区间*/
  quick_sort(r,i+1,ht);	/*递归处理右区间*/
}
}/*QUICK_SORT*/

/*直接选择排序算法如下*/
void select_sort(rectype r[])        
{ rectype temp;
int i,j,k,n=NUM; /*NUM为实际输入记录数*/
for(i=1;i<=n;i++)/*做n-1趟选择排序*/
{ k=i;
for(j=i+1;j<=n;j++)/*在当前无序区中选择关键词最小的记录r[k]*/
   if(r[j].key<r[k].key) k=j;
   if(k!=i) {temp=r[i];/*交换记录r[i]和r[k]*/
             r[i]=r[k];
			 r[k]=temp;
   }
}/*for*/
}/*SELECT_SORT*/

/*堆排序算法如下*/
void shift(rectype r[],int i,int m)/*堆的筛选算法,在数组中r[i]到r[m]中，调整堆r[i]*/
{ int j; rectype temp;
  temp=r[i]; j=2*i;
  while (j<=m)/*j<=m,r[2*i]是r[i]的左孩子*/
  { if((j<m)&&(r[j].key<r[j+1].key))
           j++; /*j指向r[i]的左右孩子中关键词较大者*/
    if(temp.key<r[j].key) /*若孩子结点的关键词大于父结点*/
	{   r[i]=r[j];	     /*将r[j]调到父亲结点的位置上*/
	   i=j;			    /*调整i和j的值，以便继续"筛"结点*/
       j=2*i;
	}
    else 
		j=m+2;		  /*调整完毕，退出循环*/
  }
  r[i]=temp;		 /*将被筛选的结点放入正确的位置*/
}/*SHIFT*/
void heap_sort(rectype r[])/*对数组r[1]到r[NUM]进行堆排序*/                       
{   rectype temp; 
	int i,n;
     n=NUM;		    /*NUM为数组的实际长度*/
  for(i=n/2;i>0;i--)/*建立初始堆*/
	  shift(r,i,n);
  for(i=n;i>1;i--)/*进行n-1趟筛选，交换，调整，完成堆排序*/
  { temp=r[1];/*将堆顶元素r[1]与最后一个元素交换位置*/
    r[1]=r[i];
	r[i]=temp;
	shift(r,1,i-1);/*将数组元素r[1]到r[i-1]重新调整成为一个新堆*/
  }/*FOR*/
}/*HEAP_SORT*/

/*二路归并排序算法如下*/
void merge(rectype a[],rectype r[],int low,int mid,int high)
{ int i,j,k; 
i=low;j=mid+1;k=low;
while((i<=mid)&&(j<=high))/*将两个相邻有序子表进行合并*/
{ if(a[i].key<=a[j].key)/*取两表中小者复制*/
    r[k++]=a[i++];
else r[k++]=a[j++];
}
while(i<=mid) r[k++]=a[i++];/*复制第一个有序子表的剩余记录*/
while(j<=high) r[k++]=a[j++];/*复制第二个有序子表的剩余记录*/
}/*MERGE*/
void merge_pass(rectype r[],rectype r1[],int length)
{ int i=1,j,n=NUM;
while ((i+2*length-1)<=n)/*归并若干长度为2*length的两个相邻有序子表*/
{ merge(r,r1,i,i+length-1,i+2*length-1);
  i=i+2*length;/*i指向下一对有序子表的起点*/
}
if(i+length-1<n)
  merge(r,r1,i,i+length-1,n);/*处理表长不足2*length的部分*/
else for(j=i;j<=n;j++)
     r1[j]=r[j];/*将最后一个子表复制到r1中*/
}/*MERGEPASS*/
void merge_sort(rectype r[])
{ int length;
rectype r1[MAX];
 length=1;/*归并长度从1开始*/
 while(length<NUM)
 { merge_pass(r,r1,length);/*一趟归并，结果存放在r1中*/
   length=2*length;/*归并后有序表的长度加倍*/
   merge_pass(r1,r,length);/*再次归并，结果存放在r中*/
   length=2*length;/*再次将归并后有序表的长度加倍*/
 }
}/*MERGE_SORT*/

void creat_randnum(int a[] )/*产生给定个数和范围的随机整数函数*/
{ int i;
int range=30000;
srand(time(NULL));
for(i=1;i<=NUM;i++)
{a[i]=rand();} /*调用rand生成随机整数*/
}/*CREAT_RANDNUM*/
void create() /*产生NUM个随机整数并保存到记录数组s中*/
{ int b[MAX];
  int range=30000,i;
  creat_randnum(b); /*调用随机整数生成函数，结果存放在数组b中*/
  for(i=1;i<=NUM;i++)
	  s[i].key=b[i];/*将随机整数存放到数组s中*/
  s1=s;/*s1指向s,以便保存原始数据*/
}/*CREAT*/

void print_record(rectype r[])/*记录数组的输出函数*/
{ int i;
cout<<endl<<"			"<<"排序后的有序随机整数:"<<endl<<endl<<"	";
for(i=1;i<=NUM;i++)
{printf("%6d",r[i].key);
   if(i%10==0) cout<<endl<<endl<<"	";
}getchar();getchar();
}/*PRINTRECORD*/

int menu_select()/*主菜单选择模块*/
{ char c; int kk;
//system("cls");/*清屏函数*/
cout<<"内排序算法的比较----主控模块:"<<endl<<endl;
cout<<"		"<<"1. 直接插入排序"<<endl;
cout<<"		"<<"2. 希尔排序"<<endl;
cout<<"		"<<"3. 冒泡排序"<<endl;
cout<<"		"<<"4. 快速排序"<<endl;
cout<<"		"<<"5. 直接选择排序"<<endl;
cout<<"		"<<"6. 堆排序"<<endl;
cout<<"		"<<"7. 二路归并排序"<<endl;
cout<<"		"<<"0. 退出"<<endl;
do {cout<<endl<<"请按选择0-7键选择功能:";
    c=getchar(); kk=c-48;
}while ((kk<0)||(kk)>7);
return(kk);
}/*MENU_SELECT*/
main()  /*算法比较--主程序模块*/
{   
	
	struct timeb startTime , endTime;
	int kk;
     do {kk=menu_select(); /*进入主菜单选择模块*/
    if(kk!=0) create();    /*建立记录数组*/
	switch(kk)
	{ 
		case 1:{	
				   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "直接插入排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break; 
		case 2:{    
			   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "希尔排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
		      }break;
      case 3:{   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "冒泡排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break; 
      case 4:{   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "快速排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break; 
	  case 5:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "简单选择排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break;     
	  case 6:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "堆排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break;        
      case 7:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "二路归并排序：循环语句运行了：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
			   }break;   
	  case 0:{            exit(0);}
	}//print_record(s1);
	getchar();
}while (kk!=0);
}/*MAIN*/
