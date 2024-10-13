#include <iostream>
using namespace std;


struct octet {
    public:
    int o1, o2, o3, o4;

    octet() : o1(0), o2(0), o3(0), o4(0) {}

    octet(int a, int b, int c, int d) : o1(a), o2(b), o3(c), o4(d) {}

    
    void print() const {
        cout << o1 << "." << o2 << "." << o3 << "." << o4 << endl;
    }
};

void printOctets(octet arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].print();
    }
}


void radix_sort(octet arr[], int n) {
    int pos[4] = {1, 10, 100, 1000};


    for (int j = 3; j >= 0; j--) {
        int array[256] = {0}; 

        for (int i = 0; i < n; i++) {
            int key;
            switch (j) {
                case 0: key = arr[i].o1; break;
                case 1: key = arr[i].o2; break;
                case 2: key = arr[i].o3; break;
                case 3: key = arr[i].o4; break;
            }
            array[key]++;
        }

   for (int i = 1; i < 256; i++) {
           	if(i==172){
           		cout<<"this is it"<<" "<<array[i]<<endl;
			}
        cout<<array[i]<<endl;
        }
        for (int i = 1; i < 256; i++) {
            array[i] += array[i - 1];
        }
         

        octet ans[n];  

        for (int i = n - 1; i >= 0; i--) {
            int key;
            switch (j) {
                case 0: key = arr[i].o1; break;
                case 1: key = arr[i].o2; break;
                case 2: key = arr[i].o3; break;
                case 3: key = arr[i].o4; break;
            }
            ans[--array[key]] = arr[i];
        }

        for (int i = 0; i < n; i++) {
        
            arr[i] = ans[i];
        }
    }
}

int main() {
 octet arr[5] = {
        {192, 168, 1, 1},   
        {10, 0, 0, 2},     
        {172, 16, 0, 1},    
        {192, 168, 0, 1},   
        {10, 0, 0, 1}      
    };

    radix_sort(arr, 5);


    cout << "Sorted IP addresses in ascending order:" << endl;
    printOctets(arr, 5);

}
