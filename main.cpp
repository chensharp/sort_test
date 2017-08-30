/********************************
all sort algorithm
1,直接插入
2,折半插入
3,冒泡排序


*********************************/

#include <iostream>
using namespace std;

#define N 10 //数据长度


typedef struct elemtype
{
    int key;
    int info;
};

//直接插入
void insertSort(elemtype A[],int n)
{
    int i,j;
    elemtype temp;
    for(i=1;i<n;i++){
        if(A[i].key < A[i-1].key){//每次假定i 前为有序增，若小于i-1 则进行插入排序
            temp = A[i];//复制待排序i 到 临时
            for(j=i-1;temp.key<A[j].key && j>=0 ;j--){//从i-1 向前找 直至为 0,比较key
                A[j+1]=A[j];
            }
            A[j+1]=temp;
        }
    }
}

//折半插入
void insertSort_half(elemtype A[],int n)
{
    elemtype temp;
    int i,j,low,high,mid;
    for(i=1;i<n;i++){
        temp=A[i];
        low = 0;
        high = i-1;
        while(low <= high){
            mid = (low+high)/2;
            if(A[mid].key>temp.key)
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;--j){
            A[j+1]=A[j];
        }
        A[high+1]=temp;
    }
}

//冒泡排序法
void swapSort_bubble(elemtype A[],int n)
{
    int i,j;
    bool flag;//标记适用有序情况下，
    for(i=0;i<n-1;i++){//0 - n-2
        flag=false;
        for(j=n-1;j>i;j--){ //n-1 - i+1
            if(A[j-1].key > A[j].key){
                //交换 j-1 j
                elemtype temp = A[j-1];
                A[j-1]=A[j];
                A[j]=temp;

                flag = true;//
            }
        }
        if(flag==false)//未发生交换，有序，退出排序
            return;
    }
}

//快排
int Partition(elemtype A[], int low,int high ){
    elemtype pivot=A[low];

    while(low < high ){
        while(low<high && A[high].key >= pivot.key){
            high--;
        }
        A[low]=A[high];
        while(low<high && A[low].key<= pivot.key){
            low++;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void quickSort(elemtype A[], int low,int high){
    if(low<high){
        int pivotpos = Partition(A,low,high);
        quickSort(A,low,pivotpos-1);
        quickSort(A,pivotpos+1,high);
    }
}

//简单选择排序
void selectSort(elemtype A[],int n){
    for(int i=0;i<n-1;i++){//从0 - n-1
        int amin=i;
        for(int j=i+1;j<n;j++){
            if(A[j].key<A[amin].key)
                amin=j;
        }
        if(amin!=i){
            elemtype temp = A[i];
            A[i]=A[amin];
            A[amin]=temp;
        }
    }
}
//堆排序
//堆调节  A[0]做临时储存，为了方便下标
void adjustDown(elemtype A[],int k,int n){
    A[0]=A[k];
    for(int i=2*k;i<=n;i*=2){
        if(i<n && A[i].key<A[i+1].key){
            i++;
        }
        if(A[0].key>=A[i].key){
            break;
        }else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
void BuildMaxHeap(elemtype A[],int n){
    for(int i=n/2;i>0;i--){//从 n/2 - 1  调节堆
        adjustDown(A,i,n);
    }
}
void HeapSort(elemtype A[],int n){
    BuildMaxHeap(A,n);
    for(int i=n;i>1;i--){
        elemtype temp = A[i];
        A[i] = A[1];
        A[1]=temp;
        adjustDown(A,1,i-1);
    }
}


//归并排序
void mergSort(){


}



//打印数据
void printdata(elemtype A[],int n,char* name){
    cout<<"------"<<name<<"--------"<<endl;
    for(int i =0;i< n;i++){
        cout<<A[i].key<<" "<<A[i].info<<endl;

    }
    cout<<"------end----------"<<endl;
}


int main()
{
    cout << "Hello world 排序算法合集 !" << endl;
/*
    elemtype data2[N] = { {49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{21,9},{6,10} };

    printdata(data2,N,"origin");
    //insertSort(data2,N);
    insertSort_half(data2,N);
    //swapSort_bubble(data2,N);//冒泡法
    //quickSort(data2,0,N-1);//
    //selectSort(data2,N);

    printdata(data2,N,"sort result");

*/

    elemtype data1[N+1] = { {-1,-1},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{21,9},{6,10} };
    printdata(data1,N+1,"origin");
    HeapSort(data1,N+1);

    printdata(data1,N+1,"sort result");


    return 0;
}
