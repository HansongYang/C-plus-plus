#include <iostream>

using namespace std;

int main()
{
    std::string A;
    std::string B;
    int b;
    cout<<"Please enter the two symbols of element and the atoms of the second element, thank you."<<endl;

    cin>>A;
    cin>>B;
    cin>>b;

    cout<< "The geometrical shape of one "<< A <<" atom surrouded by "<< b <<" "<< B <<" atoms is ";

    int v = 0;

    if(B == "Be"){
        v = 3;
    }
    else if(B == "C"){
        v = 4;
    }
     else if(B == "Si"){
        v = 4;
    }
     else if(B == "N"){
        v = 5;
    }
     else if(B == "P"){
        v = 5;
    }
     else if(B == "As"){
        v = 5;
    }
     else if(B == "O"){
        v = 6;
    }
     else if(B == "S"){
        v = 6;
    }
     else if(B == "Se"){
        v = 6;
    }
     else if(B == "F"){
        v = 7;
    }
     else if(B == "Cl"){
        v = 7;
    }
     else if(B == "Br"){
        v = 7;
    }
     else if(B == "I"){
        v = 7;
    }
     else if(B == "Xe"){
        v = 8;
    }

    int e = v - b;
    int n = e/2;

    if(b == 2 && n == 0){
        cout<< "liner."<<endl;
    }
    else if(b == 2 && n == 1){
        cout<<"bent."<<endl;
    }
    else if(b == 2 && n == 2){
        cout<<"bent."<<endl;
    }
    else if(b == 2 && n == 3){
        cout<<"linear."<<endl;
    }
    else if(b == 3 && n == 0){
        cout<<"trigonal planar."<<endl;
    }
    else if(b == 3 && n == 1){
        cout<<"trigonal pyramidal."<<endl;
    }
    else if(b == 3 && n == 2){
        cout<<"T-shaped."<<endl;
    }
    else if(b == 4 && n == 0){
        cout<<"tetrahedral."<<endl;
    }
    else if(b == 4 && n == 1){
        cout<<"seesaw."<<endl;
    }
    else if(b == 4 && n == 2){
        cout<<"square planar."<<endl;
    }
    else if(b == 5 && n == 0){
        cout<<"trigonal bipyramidal."<<endl;
    }
    else if(b == 5 && n == 1){
        cout<<"square pyramidal."<<endl;
    }
    else if(b == 6 && n == 0){
        cout<<"octahedral."<<endl;
    }
    else{
        cout<<"unknown."<<endl;
    }
    return 0;
}
