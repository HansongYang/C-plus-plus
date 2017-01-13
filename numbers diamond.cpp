#include <iostream>

using namespace std;
    char ** di (int size){
        char ** arr = new char*[size];
        for(int i = 0; i < size; i++){
            arr[i] = new char[size];
        }
        int star = size - size/2 + 1;
        int dash = size -1;

        for(int i = 0; i < size; i++){
            if(i ==0 || i == size - 1){
                for(int j = 0; j < size/2 + 1; j++){
                    if(j == size/2){
                        arr[i][j]= '*';
                    }
                    else{
                        arr[i][j] = ' ';
                    }
                }
            }
            else if(i == size / 2){
                for(int j = 0; j < size; j++){
                arr[i][j] = '*';
                }
            }

            else if( i != 0 && i < size/2){

                for(int j = 0; j < star; j++){
                    if(j < size/2 - i ){
                        arr[i][j] = ' ';
                    }
                    else{
                        arr[i][j] = '*';
                    }
                }
                star++;
            }
            else{
                for(int j = 0; j < dash; j++){
                     if(j < i - size/2 ){
                        arr[i][j] = ' ';
                    }
                    else{
                        arr[i][j] = '*';
                    }
                }
                dash--;
            }
        }
        return arr;
    }

int main()
{
   char ** z = di(9);
   for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
        if(z[i][j] == ' ' || z[i][j] == '*')
        cout<< z[i][j];
    }
    cout<<endl;
   }
    return 0;
}
