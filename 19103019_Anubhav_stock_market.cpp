#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class node
{
public:
    int stock;
    float price;
    node*next;
    node(int p,float q)
    {
        stock=p;
        price=q;
        next=NULL;
    }
};
class  Queue
{
    node*head;
    float gain;
public:
    Queue()
    {
        head=NULL;
        gain=0;
    }
    void clear()
    {
        head=NULL;
        gain=0;
        cout<<"\n\n\n\n\n                                    ###  MEMORY CLEANED SUCCESSFULLY ### ";

    }
    void buy_stock(int s,float f)
    {
        node*ptr=new node(s,f);
        if(head==NULL)
        {
            head=ptr;
        }
        else
        {
            node*k=head;
            while(k->next!=NULL)
            {
                k=k->next;
            }
            k->next=ptr;
        }
        cout<<"\n\n\n                                                        *SUCCESSFULLY DONE*      ";
    }
    void sell_stock(int s,float f)
    {
        node*ptr=head;
        int k=0;
    while(ptr!=NULL)
    {
        k+=ptr->stock;
        if(k<=s)
        ptr=ptr->next;
        else
        break;
    }
    if((ptr==NULL)&&(k<s))
    {
        cout<<"\n\n\n\nYou are not having enough stocks to sell";
        return;
    }
    node*ktr=head;
    node*pk;
    k=0;
    while(ktr!=ptr)
    {
        gain=gain+ktr->stock*(f-ktr->price);
        k=k+ktr->stock;
        ktr=ktr->next;
        pk=head;
        head=ktr;
        delete pk;

    }
    ktr->stock=ktr->stock-(s-k);
    gain=gain+(s-k)*(f-ktr->price);
    cout<<"\n\n\n\n                                                       ###SUCCESSFULLY DONE####      ";

    }
    void show()
    {
        node*ptr=head;
        int i=1;
        cout<<"\n\n\n\n";
        cout<<"                                                       ## STATUS OF YOUR STOCKS ##   \n\n\n\n\n";
        while(ptr!=NULL)
        {
            cout<<"     "<<i<<"     :";
            cout<<"   Qty  : "<<ptr->stock<<"  | "<<"Price  :  "<<ptr->price<<"   "<<endl;
            ptr=ptr->next;
            cout<<endl<<endl;
            i++;
        }
    }
    void show_gain()
    {
        if(gain<0)
        {
            cout<<"\n\n\n\n           OMG ! You are in loss with amount "<<gain;
        }
        else if(gain==0)
        cout<<"\n\n\n\n         OHH SHIT ! You are with no gain and loss";
        else
        cout<<"\n\n\n\n        Congrats ! You are in profit with amount "<<gain;
    }
};
int main()
{
    system("color 1F");

    Queue Q;
    int n;
    int k;
    float f;
    while(1)
    {
        system("cls");
        int k;
        cout<<"\n\n\n                                              *WELCOME TO STOCK MARKET*     ";
        cout<<"\n                                              -------------------------";

        cout<<"\n\n\n  #        Press 1 for the menu in the program        :";
        cout<<"\n\n\n  #        press 2 for exit                           :";
        cout<<"\n\n\n\n        Enter your choice                             :";
        cin>>k;


        if(k==1)
        {   kp:
             system("cls");
        cout<<"\n                                  ###  MENU IN THE PROGRAM  #####   ";
        cout<<"\n\n\n    #    Press 1 for buying the stock ";
        cout<<"\n\n    #    Press 2 for selling the stocks";
        cout<<"\n\n    #    Press 3 for showing the status of stock";
        cout<<"\n\n    #    press 4 for showing the gain or loss";
        cout<<"\n\n    #    press 5 to clear all data";

         cout<<"\n\n\n\n\n     Enter your choice ";
         cin>>n;
         system("cls");
         switch(n)
         {
         case 1:cout<<"\n\n\n                                              *BUYING THE STOCK*         ";
             cout<<"\n\n\n\nEnter the amount of stock you want to purchase     :";
             cin>>k;
             cout<<"\n\n\n\nEnter the price of the stock                       :";
             cin>>f;
             system("cls");
            Q.buy_stock(k,f);
             break;
         case 2:cout<<"\n\n\n                                              *SELLING THE STOCK*                ";
                cout<<"\n\n\n\nEnter the stock you want to sell                     :";
                cin>>k;
                cout<<"\n\n\n\nEnter the price in which you want to sell stocks     :";
                cin>>f;
                system("cls");
                Q.sell_stock(k,f);
                break;
            case 3:Q.show();
                break;
            case 4:Q.show_gain();
            break;
        case 5: Q.clear();
             break;
            default:goto kp;



         }
        getch();
    }
    if(k==2)
    {
        cout<<"\n\n                                                           #### Thank You ###       "<<endl;
        break;
    }
   }




}
