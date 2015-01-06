#include <string>
#include <iostream>
 #include<iomanip>
#include <math.h>
#include<time.h>
#include <sys/timeb.h>
//#include<conio.h>
#define MAX 60000 /*��¼����ĸ���*/
#define NUM 50000/*ʵ����������ĸ���*/
using namespace std;
 
typedef struct	/*�����¼Ϊ�ṹ������*/  
{ 
	int key;	/*��¼�Ĺؼ�����*/
	int oth;	/*��¼��������*/
}rectype;

rectype *s1,s[MAX];	/*s[MAX]���ԭʼ�������*s1ȡ��ԭʼ���ݺ��������*/

/*ֱ�Ӳ��������㷨����*/
void insert_sort(rectype r[]) /*������r������˳����в��������㷨*/
{  
	int i,j,n=NUM;            /*NUMΪʵ������ļ�¼������һ������*/
	for(i=1;i<=n;i++)         /* i<NUM ��������Ҫ��NUMΪʵ�ʼ�¼��*/
	{ 
		r[0]=r[i];             /*r[0]Ϊ������*/
		j=i-1;                 /*���β����¼r[1],������r[NUM]*/
		while(r[0].key<r[j].key) /*����r[i]���ʵ�λ��*/
		{
			r[j+1]=r[j--];
		}         /*����¼�ؼ��ʴ���r[i].key�ļ�¼����*/
		    r[j+1]=r[0];               /*����¼r[i]���뵽�����ĺ��ʵ�λ����*/
	}
}/*INSERTSORT*/

/*ϣ�������㷨����*/
void shell_sort(rectype r[]) /*ȡ����Ϊd(i+1)=[d(i)/2]��ϣ��������㷨*/

{    int i,n,jump,change,temp,m; /*changeΪ������־��jumpΪ��������*/
        jump=NUM;  n=NUM; /*NUMΪ˳����ʵ�ʳ���*/
     while(jump>0)
	 { jump=jump/2; /*ȡ����d(i+1)=[d(i)/2]*/
         do { change=0; /*���ý�����־��change=0��ʾδ����*/
             for(i=1;i<=n-jump;i++)
			 { m=i+jump; /*ȡ���˵�����*/
	             if(r[i].key>r[m].key) /*��¼����*/
				 { temp=r[m].key;
	              r[m].key=r[i].key;
       	          r[i].key=temp;
	              change=1; /*change=1��ʾ�н���*/
				 }/*if*/
			 }/*for*/ /*�����������*/
		 }while(change==1); /*��change=0ʱ��ֹ��������*/
	 }/*while*/		/*������jump=1��change=0ʱ��ֹ�㷨*/
}/*SHELLSORT*/

/*ð�������㷨����*/
void bubble_sort(rectype r[]) /*��������ɨ���ð������*/
{ int i,j,noswap=0,n=NUM;	/*noswapΪ������־,NUMΪʵ�������¼��*/
rectype temp;
for(i=1;i<n;i++)		    /*����n-1��ð������*/
{ noswap=1;					/*���ý�����־��noswap=1��ʾû�м�¼����*/
for(j=n;j>=i;j--)			/*��������ɨ��*/						
 if(r[j].key<r[j-1].key)	/*������¼*/
 { temp.key=r[j-1].key;
 r[j-1].key=r[j].key;
 r[j].key=temp.key;
 noswap=0; /*��������¼ʱ����������־��0��noswap=0 */
 }/*if*/
 if(noswap) break; /*������������δ������¼����������ֹ����*/
}/*for*/		   /*��ֹ�����㷨*/
}/*BUBBLESORT*/

/*���������㷨����*/
int partition(rectype r[],int s,int t) /*���������㷨�е�һ�˻��ֺ���*/
 { int i,j;rectype temp;
   i=s;j=t;temp=r[i];                 /*��ʼ����tempΪ��׼��¼*/
do {while((r[j].key>=temp.key)&&(i<j))
    j--;			 /*��������ɨ�裬���ҵ�һ���ؼ���С��temp�ļ�¼*/
   if(i<j) r[i++]=r[j];	/*����r[i]��r[j]*/
   while((r[i].key<=temp.key)&&(i<j))
    i++;			/*��������ɨ�裬���ҵ�һ���ؼ��ʴ���temp�ļ�¼*/
   if(i<j) r[j--]=r[i]; /*����r[i]��r[j]*/
}while(i!=j);/*i=j,z��һ�λ��ֽ�������׼��¼�ﵽ������λ��*/
r[i]=temp; /*��󽫻�׼��¼temp��λ*/
return(i);
}/*PARTITION*/
void quick_sort(rectype r[],int hs,int ht)/*��r[hs]��r[ht]���п�������*/
{ int i;
if(hs<ht) /*ֻ��һ����¼���޼�¼ʱ��������*/
{ i=partition(r,hs,ht); /*��r[hs]��r[ht]����һ�λ���*/
  quick_sort(r,hs,i-1);	/*�ݹ鴦��������*/
  quick_sort(r,i+1,ht);	/*�ݹ鴦��������*/
}
}/*QUICK_SORT*/

/*ֱ��ѡ�������㷨����*/
void select_sort(rectype r[])        
{ rectype temp;
int i,j,k,n=NUM; /*NUMΪʵ�������¼��*/
for(i=1;i<=n;i++)/*��n-1��ѡ������*/
{ k=i;
for(j=i+1;j<=n;j++)/*�ڵ�ǰ��������ѡ��ؼ�����С�ļ�¼r[k]*/
   if(r[j].key<r[k].key) k=j;
   if(k!=i) {temp=r[i];/*������¼r[i]��r[k]*/
             r[i]=r[k];
			 r[k]=temp;
   }
}/*for*/
}/*SELECT_SORT*/

/*�������㷨����*/
void shift(rectype r[],int i,int m)/*�ѵ�ɸѡ�㷨,��������r[i]��r[m]�У�������r[i]*/
{ int j; rectype temp;
  temp=r[i]; j=2*i;
  while (j<=m)/*j<=m,r[2*i]��r[i]������*/
  { if((j<m)&&(r[j].key<r[j+1].key))
           j++; /*jָ��r[i]�����Һ����йؼ��ʽϴ���*/
    if(temp.key<r[j].key) /*�����ӽ��Ĺؼ��ʴ��ڸ����*/
	{   r[i]=r[j];	     /*��r[j]�������׽���λ����*/
	   i=j;			    /*����i��j��ֵ���Ա����"ɸ"���*/
       j=2*i;
	}
    else 
		j=m+2;		  /*������ϣ��˳�ѭ��*/
  }
  r[i]=temp;		 /*����ɸѡ�Ľ�������ȷ��λ��*/
}/*SHIFT*/
void heap_sort(rectype r[])/*������r[1]��r[NUM]���ж�����*/                       
{   rectype temp; 
	int i,n;
     n=NUM;		    /*NUMΪ�����ʵ�ʳ���*/
  for(i=n/2;i>0;i--)/*������ʼ��*/
	  shift(r,i,n);
  for(i=n;i>1;i--)/*����n-1��ɸѡ����������������ɶ�����*/
  { temp=r[1];/*���Ѷ�Ԫ��r[1]�����һ��Ԫ�ؽ���λ��*/
    r[1]=r[i];
	r[i]=temp;
	shift(r,1,i-1);/*������Ԫ��r[1]��r[i-1]���µ�����Ϊһ���¶�*/
  }/*FOR*/
}/*HEAP_SORT*/

/*��·�鲢�����㷨����*/
void merge(rectype a[],rectype r[],int low,int mid,int high)
{ int i,j,k; 
i=low;j=mid+1;k=low;
while((i<=mid)&&(j<=high))/*���������������ӱ���кϲ�*/
{ if(a[i].key<=a[j].key)/*ȡ������С�߸���*/
    r[k++]=a[i++];
else r[k++]=a[j++];
}
while(i<=mid) r[k++]=a[i++];/*���Ƶ�һ�������ӱ��ʣ���¼*/
while(j<=high) r[k++]=a[j++];/*���Ƶڶ��������ӱ��ʣ���¼*/
}/*MERGE*/
void merge_pass(rectype r[],rectype r1[],int length)
{ int i=1,j,n=NUM;
while ((i+2*length-1)<=n)/*�鲢���ɳ���Ϊ2*length���������������ӱ�*/
{ merge(r,r1,i,i+length-1,i+2*length-1);
  i=i+2*length;/*iָ����һ�������ӱ�����*/
}
if(i+length-1<n)
  merge(r,r1,i,i+length-1,n);/*���������2*length�Ĳ���*/
else for(j=i;j<=n;j++)
     r1[j]=r[j];/*�����һ���ӱ��Ƶ�r1��*/
}/*MERGEPASS*/
void merge_sort(rectype r[])
{ int length;
rectype r1[MAX];
 length=1;/*�鲢���ȴ�1��ʼ*/
 while(length<NUM)
 { merge_pass(r,r1,length);/*һ�˹鲢����������r1��*/
   length=2*length;/*�鲢�������ĳ��ȼӱ�*/
   merge_pass(r1,r,length);/*�ٴι鲢����������r��*/
   length=2*length;/*�ٴν��鲢�������ĳ��ȼӱ�*/
 }
}/*MERGE_SORT*/

void creat_randnum(int a[] )/*�������������ͷ�Χ�������������*/
{ int i;
int range=30000;
srand(time(NULL));
for(i=1;i<=NUM;i++)
{a[i]=rand();} /*����rand�����������*/
}/*CREAT_RANDNUM*/
void create() /*����NUM��������������浽��¼����s��*/
{ int b[MAX];
  int range=30000,i;
  creat_randnum(b); /*��������������ɺ�����������������b��*/
  for(i=1;i<=NUM;i++)
	  s[i].key=b[i];/*�����������ŵ�����s��*/
  s1=s;/*s1ָ��s,�Ա㱣��ԭʼ����*/
}/*CREAT*/

void print_record(rectype r[])/*��¼������������*/
{ int i;
cout<<endl<<"			"<<"�����������������:"<<endl<<endl<<"	";
for(i=1;i<=NUM;i++)
{printf("%6d",r[i].key);
   if(i%10==0) cout<<endl<<endl<<"	";
}getchar();getchar();
}/*PRINTRECORD*/

int menu_select()/*���˵�ѡ��ģ��*/
{ char c; int kk;
//system("cls");/*��������*/
cout<<"�������㷨�ıȽ�----����ģ��:"<<endl<<endl;
cout<<"		"<<"1. ֱ�Ӳ�������"<<endl;
cout<<"		"<<"2. ϣ������"<<endl;
cout<<"		"<<"3. ð������"<<endl;
cout<<"		"<<"4. ��������"<<endl;
cout<<"		"<<"5. ֱ��ѡ������"<<endl;
cout<<"		"<<"6. ������"<<endl;
cout<<"		"<<"7. ��·�鲢����"<<endl;
cout<<"		"<<"0. �˳�"<<endl;
do {cout<<endl<<"�밴ѡ��0-7��ѡ����:";
    c=getchar(); kk=c-48;
}while ((kk<0)||(kk)>7);
return(kk);
}/*MENU_SELECT*/
main()  /*�㷨�Ƚ�--������ģ��*/
{   
	
	struct timeb startTime , endTime;
	int kk;
     do {kk=menu_select(); /*�������˵�ѡ��ģ��*/
    if(kk!=0) create();    /*������¼����*/
	switch(kk)
	{ 
		case 1:{	
				   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "ֱ�Ӳ�������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break; 
		case 2:{    
			   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "ϣ������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
		      }break;
      case 3:{   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "ð������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break; 
      case 4:{   ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "��������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break; 
	  case 5:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "��ѡ������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break;     
	  case 6:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "������ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break;        
      case 7:{    ftime(&startTime);
				   insert_sort(s1); 
				   ftime(&endTime);
				   cout << "��·�鲢����ѭ����������ˣ�" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;
			   }break;   
	  case 0:{            exit(0);}
	}//print_record(s1);
	getchar();
}while (kk!=0);
}/*MAIN*/
