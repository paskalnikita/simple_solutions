#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int side;
    cout<<"Tell a size of the side of square:";
    cin>>side;
    if(side>0)
    {
        char **square = new char*[side];
        for (int i = 0; i < side; i++)
        {
            square[i] = new char[side];
        }
        int x1,y1,x2,y2,answer;

        cout<<"Do you want to enter coordinates?(1-yes;0-no)";
        cin>>answer;
        if(answer==1)
        {
            cout<<"Enter x1=";
            cin>>x1;
            cout<<"Enter y1=";
            cin>>y1;
            cout<<"Enter x2=";
            cin>>x2;
            cout<<"Enter y2=";
            cin>>y2;
            if(x1>side || y1>side || x2>side || y2 > side)
            {
                cout<<"You entered wrong values of coordinates";
                return 0;
            }
        }
        else
        {
            x1=rand()%side+1;
            y1=rand()%side+1;

            x2=rand()%side+1;
            y2=rand()%side+1;
        }

        for(int j=side; j>0; j--)
        {
            for(int i=1; i<=side; i++)
            {
                if((i-1)==x1-1 && (j-1)==y1-1)
                {
                    square[i-1][j-1]='+';
                }
                else if((i-1)==x2-1 && (j-1)==y2-1)
                {
                    square[i-1][j-1]='+';
                }
                else
                {
                    square[i-1][j-1]='*';
                }
                //cout<<"("<<i<<";"<<j<<")";
            }
            //cout<<endl;
        }

        cout<<"First point has coordinates ("<<x1<<";"<<y1<<")"<<endl;
        cout<<"Second point has coordinates ("<<x2<<";"<<y2<<")"<<endl;
        for(int j=side; j>0; j--)
        {
            for(int i=1; i<=side; i++)
            {
                cout<<square[i-1][j-1]<<" ";
            }
            cout<<endl;
        }
        float dist;
        double x,y;
        if(y1<y2)
        {
            y=y2-y1;
            if(x1<x2)
            {
                x=x2-x1;
            }
            else
            {
                x=x1-x2;
            }
        }
        else
        {
            y=y1-y2;
            if(x1<x2)
            {
                x=x2-x1;
            }
            else
            {
                x=x1-x2;
            }
        }
        dist = sqrt(x*x+y*y);

        cout<<"Distance between this two points is "<<dist<<"\n";

        //from x1 to x2
        int x_current=x1;
        int y_current=y1;
        int steps=0;
        int random_way;
        while(true)
        {
            random_way=rand()%2;
            switch (random_way)
            {
            case 0:
                if(x_current<x2)
                {
                    x_current++;
                    square[x_current-1][y_current-1]='.';
                    steps++;
                }
                else if(x_current>x2)
                {
                    x_current--;
                    square[x_current-1][y_current-1]='.';
                    steps++;
                }
            case 1:
                if(y_current<y2)
                {
                    y_current++;
                    square[x_current-1][y_current-1]='.';
                    steps++;
                }
                else if(y_current>y2)
                {
                    y_current--;
                    square[x_current-1][y_current-1]='.';
                    steps++;
                }
            }
            if(x_current==x2 && y_current==y2)
            {
                square[x_current-1][y_current-1]='!';
                break;
            }
        }
        cout<<"Steps you made:"<<steps<<"\n";
        cout<<"Way from 1 point to 2 will look like that: \n";
        for(int j=side; j>0; j--)
        {
            for(int i=1; i<=side; i++)
            {
                cout<<square[i-1][j-1]<<" ";
            }
            cout<<endl;
        }
        delete [] square;
    }
    else
    {
        cout<<"Side must be > 0";
    }
    return 0;
}
