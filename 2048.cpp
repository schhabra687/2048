#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int game[5][5];
void display()
{
int i,j;
cout<<endl<<endl;
for(i=1;i<=4;i++)
{
    for(j=1;j<=4;j++)
    {
        if(game[i][j]==95)
        cout<<char(game[i][j])<<"          ";
        else
        cout<<game[i][j]<<"          ";
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
}
}

int empty(int i,int j)
{
    if(game[i][j]=='_')
    return 1;
    else
    return 0;
}

void obstacle()
{
 int x,y;
 x = rand() % 4 + 1;
 y = rand() % 4 + 1;
 while(!empty(x,y))
 {
    x = rand() % 4 + 1;
    y = rand() % 4 + 1;
 }
 game[x][y] = 2;
}

bool finish()
{
    int i,j;

    for(i=1;i<=4;i++)
    {
    for(j=1;j<=4;j++)
    {
        if(game[i][j]=='_' || game[i][j]==2048)
        return false;
    }
    }

    for(i=1;i<=4;i++)
    {
    for(j=1;j<=4;j++)
    {
        if(i-1>=1 && game[i-1][j]==game[i][j])
        return false;
        if(i+1<=4 && game[i+1][j]==game[i][j])
        return false;
        if(j-1>=1 && game[i][j-1]==game[i][j])
        return false;
        if(j+1<=4 && game[i][j+1]==game[i][j])
        return false;
    }
    }
    return true;
}

void lshift()
{
int i,j,k,val;
for(i=1;i<=4;i++)
    {
    for(j=2;j<=4;j++)
    {
    if(game[i][j]!=95)
    {
    k = j-1;
    while(k>0 && game[i][k]==95)

    {
    k--;
    }
    if(k==j-1)
    {
    // do zero
    }
    else
    {
    val = game[i][j];
    game[i][j] = 95;
    game[i][++k] = val;
    }
    }
    }
    }
}

void left()
{
 int i,j,dist,k,flag[5]={0};
 for(i=1;i<=4;i++)
    {
    memset(flag,0,sizeof(flag));
    for(j=4;j>=2;j--)
    {
        if(game[i][j]!=95)
        {
            dist = j;
            for(k=j-1;k>=1;k--)
            {
                if(game[i][k]==95)
                dist = k;
                else if(flag[j]==0 && game[i][k] == game[i][j])
                {
                    dist = k;
                    break;
                }
                else
                break;
            }
        if(flag[j]==0 && game[i][k] == game[i][j])
        {
        flag[dist]=1;
        int val = game[i][j];
        game[i][j] = 95;
        game[i][dist] = 2 * val;
        }
        else
        {
        int val = game[i][j];
        game[i][j] = 95;
        game[i][dist] = val;
        }
        }
  }
 }
 lshift();
}

void rshift()
{
int i,j,k,val;
for(i=1;i<=4;i++)
    {
    for(j=3;j>=1;j--)
    {
    if(game[i][j]!=95)
    {
    k = j+1;
    while(k<5 && game[i][k]==95)
    {
    k++;
    }
    if(k==j+1)
    {
    // do zero
    }
    else
    {
    val = game[i][j];
    game[i][j] = 95;
    game[i][--k] = val;
    }
    }
    }
    }
}

void right()
{
 int i,j,dist,k,flag[5]={0};
 for(i=1;i<=4;i++)
    {
    memset(flag,0,sizeof(flag));
    for(j=1;j<=3;j++)
    {
        if(game[i][j]!=95)
        {
            dist = j;
            for(k=j+1;k<=4;k++)
            {
                if(game[i][k]==95)
                dist = k;
                else if(flag[j]==0 && game[i][k] == game[i][j])
                {
                    dist = k;
                    break;
                }
                else
                break;
            }
        if(flag[j]==0 && game[i][k] == game[i][j])
        {
        flag[dist]=1;
        int val = game[i][j];
        game[i][j] = 95;
        game[i][dist] = 2 * val;
        }
        else
        {
        int val = game[i][j];
        game[i][j] = 95;
        game[i][dist] = val;
        }
        }
  }
 }
 rshift();
}
void ushift()
{
int i,j,k,val;
for(j=1;j<=4;j++)
    {
    for(i=2;i<=4;i++)
    {
    if(game[i][j]!=95)
    {
    k = i-1;
    while(k>0 && game[k][j]==95)
    {
    k--;
    }
    if(k==i-1)
    {
    // do zero
    }
    else
    {
    val = game[i][j];
    game[i][j] = 95;
    game[++k][j] = val;
    }
    }
    }
    }
}

void up()
{
 int i,j,dist,k,flag[5]={0};
 for(j=1;j<=4;j++)
    {
    memset(flag,0,sizeof(flag));
    for(i=4;i>=2;i--)
    {
        if(game[i][j]!=95)
        {
            dist = i;
            for(k=i-1;k>=1;k--)
            {
                if(game[k][j]==95)
                dist = k;
                else if(flag[i]==0 && game[k][j] == game[i][j])
                {
                    dist = k;
                    break;
                }
                else
                break;
            }
        if(flag[i]==0 && game[k][j] == game[i][j])
        {
        flag[dist]=1;
        int val = game[i][j];
        game[i][j] = 95;
        game[dist][j] = 2 * val;
        }
        else
        {
        int val = game[i][j];
        game[i][j] = 95;
        game[dist][j] = val;
        }
        }
  }
 }
 ushift();
}

void dshift()
{
int i,j,k,val;
for(j=1;j<=4;j++)
    {
    for(i=3;i>=1;i--)
    {
    if(game[i][j]!=95)
    {
    k = i+1;
    while(k<5 && game[k][j]==95)
    {
    k++;
    }
    if(k==i+1)
    {
    // do zero
    }
    else
    {
    val = game[i][j];
    game[i][j] = 95;
    game[--k][j] = val;
    }
    }
    }
    }
}


void down()
{
 int i,j,dist,k,flag[5]={0};
 for(j=1;j<=4;j++)
    {
    memset(flag,0,sizeof(flag));
    for(i=1;i<=3;i++)
    {
        if(game[i][j]!=95)
        {
            dist = i;
            for(k=i+1;k<=4;k++)
            {
                if(game[k][j]==95)
                dist = k;
                else if(flag[i]==0 && game[k][j] == game[i][j])
                {
                    dist = k;
                    break;
                }
                else
                break;
            }
        if(flag[i]==0 && game[k][j] == game[i][j])
        {
        flag[dist]=1;
        int val = game[i][j];
        game[i][j] = 95;
        game[dist][j] = 2 * val;
        }
        else
        {
        int val = game[i][j];
        game[i][j] = 95;
        game[dist][j] = val;
        }
        }
  }
 }
 dshift();
}
void create()
{
    int x1,y1,x2,y2,i,j;

    for(i=1;i<=4;i++)
    {
    for(j=1;j<=4;j++)
    {
        game[i][j]='_';
    }
    }


    x1 = rand() % 4 + 1;
    y1 = rand() % 4 + 1;
    x2 = rand() % 4 + 1;
    y2 = rand() % 4 + 1;
    while(x1==x2 && y1==y2)
    {
        x2 = rand() % 4 + 1;
        y2 = rand() % 4 + 1;
    }
    game[x1][y1] = 2;
    game[x2][y2] = 2;

    display();


}

int main()
{
 int ch;
 /*
 game[1][1]=2; game[1][2]=2; game[1][3]=2; game[1][4]=2;
 game[2][1]=2; game[2][2]=16; game[2][3]=8; game[2][4]=4;
 game[3][1]=2; game[3][2]=8; game[3][3]=32; game[3][4]=2;
 game[4][1]=32; game[4][2]=8; game[4][3]=8; game[4][4]=16;
 display();
 cout<<endl;
 left();
 display();
 cout<<endl;
 cout<<endl;
 lshift();
 display();
 cout<<endl;
 down();
 display();
*/

create();

while(!finish())
    {
        //system("cls");
        cout<<endl<<"Choose a direction->   1 for LEFT,2 for RIGHT,3 for UP,4 for DOWN"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1 : cout<<"Left"<<endl; left(); obstacle(); break;
        case 2 : cout<<"Right"<<endl; right(); obstacle(); break;
        case 3 : cout<<"Up"<<endl; up(); obstacle(); break;
        case 4 : cout<<"Down"<<endl; down(); obstacle(); break;
        default : cout<<"Wrong Choice,Choose again"<<endl;
        }
        display();
    }

return 0;
}
