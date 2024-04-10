#include<iostream>
using namespace std;

int main() {
    float a[3][4]; //code can be adjusted with any matrix size more with help of a[n][n+1]

//Taking the values in the eclon matrix
    for(int i = 0; i < 3; ++i) {
        cout << "Equation number " << i + 1 << endl;
        for(int j = 0; j < 4; ++j) {
            cout << "Enter coefficient x" << j + 1 << ": ";
            cin >> a[i][j];
        }
    }
//making the given matrix a upper trianular matrix with self made algorithm
    for(int i = 0; i < 3; ++i) {
        for(int j = i + 1; j < 3; ++j) { 
            float pivot = a[j][i] / a[i][i]; 
            for(int k = 0; k < 4; ++k) { 
                a[j][k] -= pivot * a[i][k];
            }
        }
    }

    float arr[3]={0,0,0};

//Self made algorithm for backward replacement of the values 
    for(int i = 2; i >= 0 ; --i ){
      float s = 0;
      for(int h = i+1; h < 3 ; ++ h){
        s = a[i][h]* arr[h];
      }
      arr[i]=(a[i][3]-s)/a[i][i];
    }

    //Displaying the values at the end
    cout<<endl<<endl<<"The required solution of the equation is : "<<endl;
    for(int i = 0 ; i < 3 ; ++i){
      cout<<"x"<<i+1<<" : "<<arr[i]<<endl;

    }
   

    return 0;
}
