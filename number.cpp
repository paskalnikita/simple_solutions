#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int  random_number=rand()%101;
    int user_number;
    int tries=0;

    cout<<"I choose number which is bigger than 0 and less than 100"<<"\n";
    cout<<"Please,guess a number which I choose ";

    while(true)
    {
        cin>>user_number;
        while(random_number!=user_number)
        {

            if(user_number<random_number)
            {
                cout<<"My number bigger than your's. Try again. Your number=";
                tries++;
            }

            if(user_number>random_number)
            {
                cout<<"My number less than your's. Try again. Your number=";
                tries++;
            }
            break;
        }

        if(user_number==random_number)
        {
            tries++;
            cout<<"My number is "<<random_number<<endl;
            cout<<"You made "<<tries<<" tries.";
            break;

        }
    }

    return 0;
}
