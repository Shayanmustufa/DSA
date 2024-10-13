#include<iostream>
using namespace std;


void merge(int arr[],int f,int mid,int l){

int an=mid-f+1;
int bn=l-mid;

int* a=new int[an];
int* b=new int[bn];

for(int i=0;i<an;i++){
a[i]=arr[i+f];
}

for(int i=0;i<bn;i++){
b[i]=arr[mid+1+i];
}

int i=0;int j=0;int k=f;
while(i<an && j<bn){
if(a[i]<=b[j]){
arr[k]=a[i];
i++;
}else{
arr[k]=b[j];
j++;
}k++;
}



while(i<an){
arr[k]=a[i];
i++;k++;
}



while(j<bn){
arr[k]=b[j];
j++;k++;
}
}

void mergesort(int arr[],int f,int l){
if(f<l){

int mid=(f+l)/2;
for(int i=0;i<=7;i++){

cout<<arr[i]<<" ";
}cout<<endl;
mergesort(arr,f,mid);

mergesort(arr,mid+1,l);



merge(arr,f,mid,l);
}

}

int main(){

int arr[]={38 ,27 ,43 ,3 , 9 ,82 ,10 ,56};
mergesort(arr,0,7);


for(int i=0;i<=7;i++){

cout<<arr[i]<<" ";
}

}
