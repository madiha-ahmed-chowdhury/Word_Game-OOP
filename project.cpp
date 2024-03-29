#include<bits/stdc++.h>
using namespace std;
int ans;
int ans1;
int n;
int score=50;
int yes=0;
class word
{
public:
    string s;
    string h1;
    word()
    {
        if(n==0)
        {
            cout<<"PLEASE CHOOSE A MEANINGFUL WORD"<<endl;
            cout<<"COME ON BE A SPORT."<<endl;
            cout<<"DON'T SPOIL IT FOR THE OTHER PLAYER"<<endl;
            cout<<"PRESS ENTER"<<endl;
            getchar();
            system("CLS");
            cout<<endl;
            cout<<"ENTER WORD\n"<<endl;
            cin>>s;
            //cout<<"PRESS ENTER"<<endl;
            //getchar();
            system("CLS");
        }
        else
        {
            ;
        }
    }
    void hint1()
    {
        cout<<"TYPE A SENTENCE OR WORD TO HELP THE NEXT PLAYER GUESS IT"<<endl;
        cout<<endl;
        cout<<"\nENTER FIRST HINT\n"<<endl;
        //cin>>h1;
        getchar();
        getline(cin,h1);
        cout<<"\nPRESS ENTER"<<endl;
        getchar();
        system("CLS");
    }
    friend class user;
    //friend void c();//output function
};
class user
{
public:
    friend void fun();
    user()
    {
        if(n==0)
        {
            cout<<"HELLO NEW USER"<<endl;
            cout<<"WANNA GUESS SOMEONES ELSE'S WORD"<<endl;
            cout<<"YOU BETTER PROVE YOU ARE A HUMAN\n"<<endl;
        }
        else
        {
            cout<<"YOU ARE A HUMAN\n\n"<<endl;
            cout<<"PRESS ENTER"<<endl;
            getchar();
            getchar();
            system("CLS");
        }
    }
};
class game:public user,public word
{
public:
    string guess;
    void Hint1(word a)
    {
        cout<<"\nHERE GOES YOUR HINT"<<endl<<endl;
        cout<<a.h1<<endl<<endl;
        //cout<<"hello"<<endl;
        cout<<"PRESS ENTER"<<endl;
        getchar();
        system("CLS");
    }
    void Hint2(word a)
    {
        int sz=a.s.size();
        cout<<"\n\nDo you want to know the size of the word"<<endl
        <<"Type 'yes' to know the size"<<endl
        <<"This will deduct 10 from your total score"<<endl
        <<"SO BE SURE OF IT\n\n"<<endl;

        string option;
        cin>>option;
        //tolower(option);
        if(option=="yes")
        {
            score-=10;
            cout<<"\nTHE SIZE OF THE WORD IS "<<sz<<endl;
        }
        cout<<"PRESS ENTER"<<endl;
        getchar();
        getchar();
        system("CLS");
    }
    void Hint3(word a)
    {
        cout<<"\n\nDo you want to know any letter from the word?"<<endl
        <<"THIS WILL AGAIN DEDUCT 10 FROM YOUR DEDUCTED SCORE"<<endl
        <<"Type 'yes' if you want to know\n\n"<<endl;
        string option1;
        cin>>option1;
        if(option1=="yes")
        {
            cout<<"WHICH LETTER DO YOU WANT TO KNOW?\n"<<endl
            <<"Enter the position (like 1,2,3,.......)"<<endl;
            int u;
            cin>>u;
            cout<<"THE LETTER AT "<<u<<"TH PLACE IS "<<a.s[u-1]<<endl;
            score-=10;
        }
        cout<<"PRESS ENTER"<<endl;
        getchar();
        getchar();
        system("CLS");
    }
};
void fun()
{
    srand(time(NULL));
    int i;
    int a[2];
    ans=0;
    for(i = 0; i<2; i++)
    {
        a[i]=rand()%100;
        cout<<a[i];
        if(i==0) cout<<" + ";
        ans+=a[i];
    }
    cout<<endl;
    cin>>ans1;
    if(ans==ans1) *(&n)=1;
    else *(&n)=0;
    //cout<<ans<<endl;
}
int main()
{
    word p;
    p.hint1();
    user u;
    fun();
    if(n==0)
    {
        cout<<"SUS!!!"<<endl;
        return 1;
    }
    game player;
    player.Hint1(p);
    if(yes==1)
    {
        //cout<<score<<endl;
        return 1;
    }
    player.Hint2(p);
    player.Hint3(p);
    cout<<"\n!NOW YOU WOULD GET THREE CHANCES TO GUESS THE WORD!"<<endl<<endl;
    cout<<"     GUESS IT"<<endl;
    for(int i=0;i<3;i++)
    {
        string d;
        cin>>d;
        if(d==p.s)
        {
            cout<<"     YES YOU GUESSED IT RIGHT"<<endl;

            cout<<"     Your obtained score is: "<<score<<endl;
            return 1;
        }
        else cout<<"    OOPS"<<endl;
    }
    cout<<"     YOU LOST"<<endl;
}
