#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    char a[20];
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        cin.getline(a,20);
        if(!strcmp(a,"Creeper?"))
            printf("Awww man.\n");
        else if(!strcmp(a,"Awww man."))
            printf("Se no!\n");
        else
            printf("Creeper?\n");
    }
    return 0;
}