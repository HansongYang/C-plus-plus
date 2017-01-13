#include <iostream>

using namespace std;

void numbers(int a){
    int num = 1;
    int original = 1;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < (2*a - 1); j++){
            if((j + num) == a && j < a){
                cout<<num;
                if(num != 1){
                num--;
                }
                else{
                    num++;
                }
            }
            else if(j >= a && num <= i + 1){
                cout<<num;
                num++;
            }
            else{
                cout<<" ";
            }

        }
            cout<<endl;
            original++;
            num = original;
        }
    }


int main()
{
    numbers(9);
    return 0;
}
