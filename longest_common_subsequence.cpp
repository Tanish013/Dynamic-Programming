#include<iostream>
#include<string>
using namespace std;
int maxi(int a,int b){
return (a>b?a:b);
}
void index(int l2,int l1,int **table,string s1,string s2){
    //cout<<l2<<endl<<l1<<endl;
    int indi=table[l2][l1];
    if(indi==0)
        return;
    else{
            int x=l1,y=l2;
            //cout<<"indi="<<indi<<endl;
            //cout<<"start"<<endl<<x<<endl<<y;
            //cout<<endl<<"final"<<endl;
        for(int i=l1-1;i>0;i--){
            if(table[l2][i]==indi){
                x=i;
            }
            else
                break;
        }
        //cout<<x<<endl<<y<<endl;
        index(y-1,x,table,s1,s2);
        cout<<s1[x-1]<<" "<<x<<" "<<y<<endl;
    }
}
void subsequence(string s1,string s2,int l1,int l2,int c){
int **table=new int*[l2+1];
for(int i=0;i<=l2;i++){
    table[i]=new int[l1+1];
}
for(int i=0;i<=l2;i++){
    for(int j=0;j<=l1;j++){
        if(i==0||j==0){
            table[i][j]=0;
        }
    else if(s2[i-1]==s1[j-1]){
        table[i][j]=table[i-1][j-1]+1;
    }
    else{
        table[i][j]=maxi(table[i-1][j],table[i][j-1]);
    }
    }
}
/*for(int i=0;i<=l2;i++){
    for(int j=0;j<=l1;j++){
    cout<<table[i][j]<<" ";
    }
      cout<<endl;
    }*/
if(table[l2][l1]>1){
    cout<<"Case "<<c<<" Y"<<endl<<table[l2][l1]<<endl;
    //int indi=table[l2][l1];
    index(l2,l1,table,s1,s2);
    //cout<<indi;
}
else{
    cout<<"Case "<<c<<" N"<<endl;
}
}
int main(){
int l1,l2;
cin>>l1;
string s1,s2;
cin>>s1>>l2>>s2;
//cout<<s1<<endl<<s2;
subsequence(s1,s2,l1,l2,1);
}
//code chef sol
/*#include <iostream>
using namespace std;
int maxi(int a,int b){
return (a>b?a:b);
}
void index(int l2,int l1,int **table,string s1,string s2){
    //cout<<l2<<endl<<l1<<endl;
    int indi=table[l2][l1];
    if(indi==0)
        return ;
    else{
            int x=l1,y=l2;
            //cout<<"indi="<<indi<<endl;
            //cout<<"start"<<endl<<x<<endl<<y;
            //cout<<endl<<"final"<<endl;
        for(int i=l1-1;i>0;i--){
            if(table[l2][i]==indi){
                x=i;
            }
            else
                break;
        }
        //cout<<x<<endl<<y<<endl;
        index(y-1,x,table,s1,s2);
        cout<<s2[y-1]<<" "<<x<<" "<<y<<endl;
    }
}
void subsequence(string s1,string s2,int l1,int l2,int c){
int **table=new int*[l2+1];
for(int i=0;i<=l2;i++){
    table[i]=new int[l1+1];
}
for(int i=0;i<=l2;i++){
    for(int j=0;j<=l1;j++){
        if(i==0||j==0){
            table[i][j]=0;
        }
    else if(s2[i-1]==s1[j-1]){
        table[i][j]=table[i-1][j-1]+1;
    }
    else{
        table[i][j]=maxi(table[i-1][j],table[i][j-1]);
    }
    }
}
/*for(int i=0;i<=l2;i++){
    for(int j=0;j<=l1;j++){
    cout<<table[i][j]<<" ";
    }
      cout<<endl;
    }*/
/*if(table[l2][l1]>1){
    cout<<"case "<<c<<" Y"<<endl<<table[l2][l1]<<endl;
    index(l2,l1,table,s1,s2);
    //score++;
}
else{
    cout<<"case "<<c<<" N"<<endl;
}
}
int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int l1,l2;
cin>>l1;
string s1,s2;
cin>>s1>>l2>>s2;
//cout<<s1<<endl<<s2;
subsequence(s1,s2,l1,l2,z+1);
    }
    //cout<<"Score"<<endl<<score;
	return 0;
}*/
