/********************************
all sort algorithm
1,ֱ�Ӳ���
2,�۰����
3,ð������


*********************************/

#include <iostream>
using namespace std;

#define N 10 //���ݳ���


typedef struct elemtype
{
    int key;
    int info;
};

//ֱ�Ӳ���
void insertSort(elemtype A[],int n)
{
    int i,j;
    elemtype temp;
    for(i=1;i<n;i++){
        if(A[i].key < A[i-1].key){//ÿ�μٶ�i ǰΪ����������С��i-1 ����в�������
            temp = A[i];//���ƴ�����i �� ��ʱ
            for(j=i-1;temp.key<A[j].key && j>=0 ;j--){//��i-1 ��ǰ�� ֱ��Ϊ 0,�Ƚ�key
                A[j+1]=A[j];
            }
            A[j+1]=temp;
        }
    }
}

//�۰����
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

//ð������
void swapSort_bubble(elemtype A[],int n)
{
    int i,j;
    bool flag;//���������������£�
    for(i=0;i<n-1;i++){//0 - n-2
        flag=false;
        for(j=n-1;j>i;j--){ //n-1 - i+1
            if(A[j-1].key > A[j].key){
                //���� j-1 j
                elemtype temp = A[j-1];
                A[j-1]=A[j];
                A[j]=temp;

                flag = true;//
            }
        }
        if(flag==false)//δ���������������˳�����
            return;
    }
}

//����
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

//��ѡ������
void selectSort(elemtype A[],int n){
    for(int i=0;i<n-1;i++){//��0 - n-1
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
//������
//�ѵ���  A[0]����ʱ���棬Ϊ�˷����±�
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
    for(int i=n/2;i>0;i--){//�� n/2 - 1  ���ڶ�
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


//�鲢����
void mergSort(){


}



//��ӡ����
void printdata(elemtype A[],int n,char* name){
    cout<<"------"<<name<<"--------"<<endl;
    for(int i =0;i< n;i++){
        cout<<A[i].key<<" "<<A[i].info<<endl;

    }
    cout<<"------end----------"<<endl;
}


int main()
{
    cout << "Hello world �����㷨�ϼ� !" << endl;
/*
    elemtype data2[N] = { {49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{21,9},{6,10} };

    printdata(data2,N,"origin");
    //insertSort(data2,N);
    insertSort_half(data2,N);
    //swapSort_bubble(data2,N);//ð�ݷ�
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
