#include<bits/stdc++.h>

using namespace std;

int start[100],finish[100];
void maxactivity(int n){
    int i;
    i=0;
    printf("%d ",i+1);
    for(int j=1;j<n;j++){
        if(start[j]>=finish[i]){
            printf("%d ",j+1);
            i=j;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&start[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&finish[i]);
    }
    sort(finish,finish+n);
    maxactivity(n);

    return 0;
}


