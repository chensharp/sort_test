/********************************
all sort algorithm
1,÷±Ω”≤Â»Î
2,’€∞Î≤Â»Î
3,√∞≈›≈≈–Ú


*********************************/

#include <iostream>
using namespace std;


#define N 10


typedef struct elemtype
{
    int key;
    int info;
};

//÷±Ω”≤Â»Î
void insertSort(elemtype A[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(A[i].key<A[i-1].key){
            A[0]= A[i];
            for(j=i-1;A[0].key<A[j].key;--j){
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
    }
}
//’€∞Î≤Â»Î
void insertSort_half(elemtype A[],int n)
{
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        A[0]=A[i];
        low = 1;
        high = i-1;
        while(low <= high){
            mid = (low+high)/2;
            if(A[mid].key>A[0].key)
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;--j){
            A[j+1]=A[j];
        }
        A[high+1]=A[0];
    }

}

//√∞≈›≈≈–Ú∑®
void swapSort_bubble(elemtype A[],int n)
{
    int i,j;
    bool flag;
    for(i=0;i<n-1;i++){
        flag=false;
        for(j=n-1;j>i;j--){
            if(A[j-1].key>A[j].key){
                //Ωªªª j-1 j
                elemtype temp = A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
                flag = true;
            }
        }
        if(flag==false)
            return;
    }
}



void printdata(elemtype A[],int n,char* name){
    cout<<"------"<<name<<"--------"<<endl;
    for(int i =0;i< n;i++){
        cout<<A[i].key<<" "<<A[i].info<<endl;

    }
    cout<<"------end----------"<<endl;
}




int main()
{
    cout << "Hello world!" << endl;

    //   ≤Â»Î≈≈–Ú

    elemtype data[N+1] = { {0,0},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{21,9},{6,10} };
    printdata(data,N+1,"origin");
    insertSort_half(data,N);
    printdata(data,N+1,"sort");

    //Ωªªª≈≈–Ú
   /* elemtype data2[N] = { {49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},{21,9},{6,10} };
    printdata(data2,N,"origin");
    swapSort_bubble(data2,N);
    printdata(data2,N,"sort");*/

    return 0;
}
