#include<iostream>
using namespace std;


struct product{
	public:
		
		string name;
		int price;
};

int  partition(product arr[],int f,int l){
	product pivot=arr[l];
	int i=f-1;
	
	
	for(int j=f;j<l;j++){
		if(arr[j].price<=pivot.price){
			i++;
			swap(arr[i],arr[j]);
		}
		
	}
	swap(arr[i+1],arr[l]);
	
	return i+1;
}


void quick_sort(product arr[],int f,int l){
	
	if(f<l){
		int part=partition(arr,f,l);
		quick_sort(arr,f,part-1);
		quick_sort(arr,part+1,l);
	}
}

void same(product arr[],int n){
	int j=0;      
	for(int j=0;j<n;j++){
	for(int i=j+1;i<n;i++){
		if(arr[i].price==arr[j].price){
			if(arr[i].name<arr[j].name ){
				swap(arr[i],arr[j]);
			}
				
		}
	}

}
}
int main(){
	
	
	product p1[5]=
	{ {"Laptop",1000},
	
	{"Phone",700},
	{"Monitor",300},
	{"Tablet",600},
	{"Keyboard",300	}
	};
	quick_sort(p1,0,4);
	same(p1,4);
	
	for(int i=0;i<5;i++){
		cout<<p1[i].name<<" , "<<p1[i].price<<endl;
	}
}