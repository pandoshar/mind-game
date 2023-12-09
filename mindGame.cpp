#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include <random>
using namespace std;
int nuM(){
    int n;
    int flag = true;
    while(flag){
        cout<<"Welcom to the Memory Game!"<<endl;
        cout<<"Enter the size of an array (6-20):";
        cin>>n;
        
        if(n>5 and n<21 and n%2==0){
            flag = false;
            return n;
        }
        system("CLS");
    }
}

int main(){
    int num = nuM();
    int sus = 0;
    int flag = true;
    int myNum[num];
    bool myGid[num];


    for(int i = 0;i<num;i++){
        myGid[i] = false;
        myNum[i] = 0;
    }
    for (int i = 0; i < num / 2; i++)
    {
        myNum[i] = 1 + rand() % 10;
    }
    for (int i = num / 2; i < num; i++)
    {
        myNum[i] = myNum[i - num / 2];
    }

    while(sus<num){
        cout<<"here is array:";
        int a,b,c;
        for(int i = 0;i<num;i++){
            if(myGid[i]==false){
                cout<<"? ";
            }
            else{
                cout<<myNum[i]<<" ";
            }
        }
        cout<<endl;
        cout<<endl;
        cout<<"Enter the index to show:";
        cin>>a;
        cout<<"The card at index "<<a<<" is "<<myNum[a]<<endl;
        cout<<"Enter the index to show:";
        while(flag){
            cin>>b;
            if(b!=a and b<num){
                flag = false;
            }
        }
        flag = true;
        cout<<"The card at index "<<b<<" is "<<myNum[b]<<endl;
        cin.ignore();
        if(myNum[b]==myNum[a] and a != b){
            myGid[a]=true;
            myGid[b]=true;
            cout<<"Great. Cards is matched"<<endl;
            cout<<"Press Enter to continue";
            cin.get();
            system("CLS");
            sus += 2;
        }
        else{
            cout<<"Oops you don't have one"<<endl;
            cout<<"Press Enter to continue";
            cin.get();
            system("CLS");
        }
    }

}