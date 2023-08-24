#include "Song.h"
#include "CreatePlayList.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
// Assigning head,last,queue_front,queue_rear to NULL
Song::Song()
{
    head=NULL;
    last=NULL;
    queue_front=NULL;
    queue_rear=NULL;
}
//Insert the Song Information in Linked List
void Song::Insert(string song_name,string artist_name,int duration,int year,string Category)
{
    Node* newNode=new Node(song_name,artist_name,duration,year,Category);
    // Base Condition
    if(head==NULL)
    {
        head=newNode;
        last=newNode;
    }
    else
    {
        last->next=newNode;
        last=newNode;
    }
}
//Delete Song Information from Linked List
void Song::Delete(string song_name)
{
    Node* temp=head;
    Node* prev=NULL;
    //Base Condition
    if(temp!=NULL && temp->song_name==song_name)
    {
        cout<< song_name<< " deleted"<< endl;
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    else
    {
        // Traversing till we find song name find in Linked List
        while(temp!=NULL && temp->song_name!=song_name)
        {
            prev=temp;
            temp=temp->next;
        }
        //If Song doesn't exist
        if(temp==NULL)
        {
            cout<<"Song doesn't exist"<<endl;
            return;
        }
        else
        {
            cout<< song_name<< " deleted"<< endl;
            prev->next=temp->next;
            delete temp;
        }
    }
}
//Search a Song and Display the Information Of Song
void Song::Search(string song_name)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->song_name==song_name)
        {
            cout<<"                 Details of the song"<<endl;
            cout<<"Song Name:"<<temp->song_name<<endl;
            cout<<"Artist Name:"<<temp->artist_name<<endl;
            cout<<"Year of Release:"<<temp->year<<endl;
            cout<<"Duration:"<<temp->duration<<endl;
            cout<<"Category of the song:"<<temp->Category<<endl;
            return;
        }
        temp=temp->next;
    }
    //If song doesn't found
    cout<<"Song doesn't exist"<<endl;
    return;
}
//Print the Linked List containing Information of the song
void Song::Print()
{
    Node* temp=head;
    cout<< "--------------------------------------"<< endl;
    if(temp==NULL)
    {
        cout<<"No song Found"<<endl;
        cout<< "--------------------------------------"<< endl;
    }
    while(temp!=nullptr)
    {
        cout<< "--------------------------------------"<< endl;
        cout<<"Song Name: "<<temp->song_name<<endl<<endl;
        cout<<"Artist Name: "<<temp->artist_name<<endl<<endl;
        cout<<"Duration of the Song: "<<temp->duration<<endl<<endl;
        cout<<"Year of Release of Song: "<<temp->year<<endl<<endl;
        cout<<"Category of the song: "<<temp->Category<<endl<<endl;
        cout<< "--------------------------------------"<< endl;
        temp=temp->next;
    }
}
// Modifying The Song Information in Linked List
void Song::modify(string old_song_name,string new_song_name,string artist_name,int duration,int year,string Category)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->song_name==old_song_name)
        {
            temp->song_name=new_song_name;
            temp->artist_name=artist_name;
            temp->duration=duration;
            temp->year=year;
            temp->Category=Category;
            return;
        }
    }
}
//Split Linked List in Two Parts
void Song::Split(Node* temp,Node** firstNode, Node** secondNode)
{
    Node* n1;
    Node* n2;
    n2 = temp;
    n1 = temp->next;

    //Splitting Linked List into Two Parts
    while (n1 != NULL)
    {
        n1 = n1->next;
        if (n1 != NULL)
        {
            n2 = n2->next;
            n1 = n1->next;
        }
    }

    *firstNode = temp;
    *secondNode = n2->next;
    n2->next = NULL;
}
//Sorting Linked List by duration using Merge Sort Algorithm
void Song::MergeSort_duration(Node** temp)
{
    Node* head = *temp;
    Node* List1;
    Node* List2;
    //Base Condition
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    Split(head,&List1,&List2);
    //Sorting First List
    MergeSort_duration(&List1);
    //Sorting Second List
    MergeSort_duration(&List2);
    //Merging Two List
    *temp = Merge_by_duration(List1, List2);
}
//For Merging Of Two list
Node* Song::Merge_by_duration(Node* List1, Node* List2)
{
    Node* temp = NULL;

    if (List1 == NULL)
    {
        return (List2);
    }
    else if(List2 == NULL)
    {
        return (List1);
    }
    //If First Song's duration is less than List2's First Song's duration then
    //Merging List1's Song into Linked List and Traversing List1
    if (List1->duration <= List2->duration)
    {
        temp = List1;
        temp->next = Merge_by_duration(List1->next, List2);
    }
    //If First Song's duration is less than List2's First Song's duration then
    //Merging List1's Song into Linked List and Traversing List1
    else
    {
        temp = List2;
        temp->next = Merge_by_duration(List1, List2->next);
    }
    return (temp);
}
//For Merging Of Two list
Node* Song::Merge_by_year(Node* List1, Node* List2)
{
    Node* temp = NULL;

    if (List1 == NULL)
    {
        return (List2);
    }
    else if(List2 == NULL)
    {
        return (List1);
    }
    //If First Song's year is less than List2's First Song's year then
    //Merging List1's Song into Linked List and Traversing List1
    if (List1->year <= List2->year)
    {
        temp = List1;
        temp->next = Merge_by_year(List1->next, List2);
    }
    //If First Song's year is greater than List2's First Song's year then
    //Merging List2's Song into Linked List and Traversing List2
    else
    {
        temp = List2;
        temp->next = Merge_by_year(List1, List2->next);
    }
    return (temp);
}
//Sorting Linked List by year using Merge Sort Algorithm
void Song::MergeSort_year(Node** temp)
{
    Node* head = *temp;
    Node* List1;
    Node* List2;
    //Base Condition
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    Split(head,&List1,&List2);
    //Sorting First List
    MergeSort_year(&List1);
    //Sorting Second List
    MergeSort_year(&List2);
    //Merging Two List
    *temp = Merge_by_year(List1, List2);
}
//Sorting Linked List by duration using Merge Sort Algorithm
void Song::MergeSort_Name(Node** temp)
{
    Node* head = *temp;
    Node* List1;
    Node* List2;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    //Split IT IN Two Linked List
    Split(head,&List1,&List2);
    //Sorting First List
    MergeSort_Name(&List1);
    //Sorting Second List
    MergeSort_Name(&List2);
    //Merging Two List
    *temp = Merge_by_Name(List1, List2);
}
//For Merging of Two List
Node* Song::Merge_by_Name(Node* List1, Node* List2)
{
    Node* temp = NULL;

    if (List1 == NULL)
    {
        return (List2);
    }
    else if(List2 == NULL)
    {
        return (List1);
    }
    //If First Song's Name is less than List2's First Song's Name then
    //Merging List1's Song into Linked List and Traversing List1
    if (List1->song_name.compare(List2->song_name)<=0)
    {
        temp = List1;
        temp->next = Merge_by_Name(List1->next, List2);
    }
    //If First Song's duration is greater than List2's First Song's duration then
    //Merging List2's Song into Linked List and Traversing List2
    else
    {
        temp = List2;
        temp->next = Merge_by_Name(List1, List2->next);
    }
    return (temp);
}
//Return head pointer
Node** Song::gethead()
{
    return &head;
}
//Delay of 5 seconds
void Song::timer(int s)
{
    for(;;)
    {
        if (s == 0)
        {
            break;
        }
        s--;
        Sleep(1000);
    }
}
//Playing the Song of PlayList
void Song::playsongsequence()
{
    cout<< "Here is the song-list:"<<endl;
    Node* temp=head;
    int i=0;
    while(temp!=NULL)
    {
        cout<<i+1<<". "<<temp->song_name<<endl;
        i++;
        temp=temp->next;
    }

    cout<< "Playing first song "<< endl;
    Node* tmp=head;
    if(tmp==nullptr)
    {
        cout<< "--------------------------------------"<< endl;
        cout<< "No song can be played"<< endl;
        cout<< "--------------------------------------"<< endl;
    }
    while(tmp!=nullptr)
    {
        cout<< "--------------------------------------"<< endl;
        cout<< "Playing song : "<<tmp->song_name<<endl;
        cout<< "Artist : "<< tmp->artist_name<< endl;
        cout<< "Category : ("<<tmp->Category<< ")"<<endl<<tmp->year<< endl<< tmp->duration<<" seconds"<< endl;
        cout<< "Playing song......"<< endl;
        timer(5);
        Beep(500,1000);
        cout<< "Hope you enjoyed"<< endl;
        cout<< "--------------------------------------"<< endl;
        cout<< "Add this to Queue ? : ";
        char r;
        cin>> r;
        cout<< "--------------------------------------"<< endl;
        if(r=='y' || r=='Y')
        {
            //Adding Song into Queue
            Enqueue(tmp);
        }


        while(tmp!=nullptr)
        {
            cout<< endl<< endl;
            cout<< "-------------------MENU-----------------"<< endl;
            cout<< "1.Repeat The song"<<endl<<endl;
            cout<< "2 Next Song"<<endl<<endl;
            cout<< "3 Skip the next song"<<endl<<endl;
            cout<< "4 Play the song according to your mood."<<endl<<endl;
            cout<< "5 End the playlist"<<endl<<endl;
            cout<< "--------------------------------------"<< endl;
            cout<<"Enter your choice:";
            int choice;
            cin>> choice;
            cout<< "--------------------------------------"<< endl;
            cout<< endl<< endl;
            switch(choice)
            {
            case 1:
            {
                cout<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "Playing song : "<<tmp->song_name<<endl;
                cout<< "Artist : "<< tmp->artist_name<< endl;
                cout<< "Category : ("<<tmp->Category<< ")"<<endl<<tmp->year<< endl<< tmp->duration<<" seconds"<< endl;
                cout<< "Playing song......"<< endl;

                timer(5);
                Beep(500,1000);
                cout<< "Hope you enjoyed"<< endl<< endl;
                cout<< "--------------------------------------"<< endl;

                cout<< "Add this to Queue ? : ";
                char r;
                cin>> r;
                cout<< "--------------------------------------"<< endl;
                if(r=='y' || r=='Y')
                {
                    Enqueue(tmp);
                }
                break;
            }
            case 2:
            {
                tmp=tmp->next;
                if(tmp==NULL)
                {
                    cout<<"PlayList Ended."<<endl;
                    break;
                }
                cout<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "Playing song : "<<tmp->song_name<<endl;
                cout<< "Artist : "<< tmp->artist_name<< endl;
                cout<< "Category : ("<<tmp->Category<< ")"<<endl<<tmp->year<< endl<< tmp->duration<<" seconds"<< endl;
                cout<< "Playing song......"<< endl;

                timer(5);
                Beep(500,1000);
                cout<< "Hope you enjoyed"<< endl<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "Add this to Queue ? : ";
                char r;
                cin>> r;
                cout<< "--------------------------------------"<< endl;
                if(r=='y' || r=='Y')
                {
                    Enqueue(tmp);
                }
                break;
            }
            case 3:
            {
                for(int i=0; i<2; i++)
                {
                    if(tmp!=nullptr)
                    {
                        tmp=tmp->next;
                    }
                    else
                    {
                        break;
                    }

                }
                if(tmp==nullptr)
                {
                    cout<<"PlayList Ended."<<endl;
                    cout<<"Press Enter to move ahead."<<endl;
                    getchar();
                    getchar();
                    break;
                }
                cout<< "--------------------------------------"<< endl;
                cout<< "Playing song : "<<tmp->song_name<<endl;
                cout<< "Artist : "<< tmp->artist_name<< endl;
                cout<< "Category : ("<<tmp->Category<< ")"<<endl<<tmp->year<<endl<< tmp->duration<<" seconds"<< endl;
                cout<< "Playing song......"<< endl;

                timer(5);
                Beep(500,1000);
                cout<< "Hope you enjoyed"<< endl<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "Add this to Queue ? : ";
                char r;
                cin>> r;
                cout<< "--------------------------------------"<< endl;
                if(r=='y' || r=='Y')
                {
                    Enqueue(tmp);
                }
                break;
            }
            case 4:
            {
                getchar();
                cout<< "How was your mood? ";
                string user_category;
                getline(cin,user_category);

                if(head==nullptr)
                {
                    cout<< "Oops ! No song found !!"<< endl;
                }
                else
                {
                    Node *Tmp = head;
                    int i=0;
                    while(Tmp!=nullptr)
                    {
                        transform(user_category.begin(), user_category.end(), user_category.begin(), ::tolower);
                        transform(Tmp->Category.begin(), Tmp->Category.end(), Tmp->Category.begin(), ::tolower);

                        int x = user_category.compare(Tmp->Category);

                        if(x==0)
                        {
                            cout<< "--------------------------------------"<< endl;
                            cout<< "Playing song : "<<Tmp->song_name<<endl;
                            cout<< "Artist : "<< Tmp->artist_name<< endl;
                            cout<< "Category : ("<<Tmp->Category<< ")"<<endl<<Tmp->year<<endl<< Tmp->duration<<" seconds"<< endl;
                            cout<< "Playing song......"<< endl;

                            timer(5);
                            Beep(500,1000);
                            cout<< "Hope you enjoyed"<< endl<< endl;
                            cout<< "--------------------------------------"<< endl;
                            cout<< "Add this to Queue ? : ";
                            char r;
                            cin>> r;
                            cout<< "--------------------------------------"<< endl;
                            if(r=='y' || r=='Y')
                            {
                                Enqueue(tmp);
                            }
                            i++;
                            break;
                        }
                        else
                            Tmp=Tmp->next;
                    }
                    if(i==0)
                    {
                        cout<< "Oops! No song Found"<< endl;
                    }
                }
                break;
            }
            case 5:
            {
                cout<< "--------------------------------------"<< endl;
                cout<< "Hope you enjoyed"<< endl<< endl;
                cout<< "--------------------------------------"<< endl;
                cout<< "--------------------------------------"<< endl;
                tmp=nullptr;
                break;
            }
            default:
                cout<< "Invalid choice"<< endl;
            }
        }
    }
}
//Adding song in Queue
void Song::Enqueue(Node *tmp)
{
    Node *tmp_queue = new Node(tmp->song_name,tmp->artist_name,tmp->duration,tmp->year,tmp->Category);

    if(queue_front==nullptr)
    {
        queue_front=tmp_queue;
        queue_rear=tmp_queue;
        cout<< "Added to Queue"<< endl;
    }
    else
    {
        Node *check= queue_front;
        int i=0;
        while( check != nullptr)
        {
            if((check->song_name == tmp->song_name) && (check->artist_name == tmp->artist_name) && (check->year == tmp->year))
            {
                cout<<"This song already exist in queue." << endl;
                i++;
                break;
            }
            else check=check->next;
        }
        if(i==0)
        {
            queue_rear->next= tmp_queue;
            queue_rear= tmp_queue;
            cout<< "Added to Queue"<< endl;
        }
    }
}
//Excessing The Queue
void Song::printQueue()
{
    if(queue_front==nullptr)
    {
        cout<< "Queue is Empty!!"<< endl;
        cout<<"Press Enter to move ahead."<<endl;
        getchar();
    }
    else
    {
        Node * play_queue = queue_front;
        char respo;
        do
        {
            if(play_queue == nullptr)
            {
                cout<< "Oops ! you reached END !!!"<< endl;
                cout<<"Press Enter to move ahead."<<endl;
                getchar();
                getchar();
                break;
            }
            else
            {
                cout<< "--------------------------------------"<< endl;
                cout<< "Playing song : "<<play_queue->song_name<<endl;
                cout<< "Artist : "<< play_queue->artist_name<< endl;
                cout<< "Category : ("<<play_queue->Category<< ")"<<endl<<play_queue->year<<endl<< play_queue->duration<<" seconds"<< endl;
                cout<< "Playing song......"<< endl;

                timer(5);
                Beep(500,1000);
                cout<< "Hope you enjoyed"<< endl<< endl;
                cout<< "--------------------------------------"<< endl;
            }
            play_queue=play_queue->next;
            cout<< "Want to play next song from Queue ? : ";
            cin >> respo;
            cout<< "--------------------------------------"<< endl;
        }
        while(respo == 'y' || respo == 'Y');
    }
}
//This Function is called from the driver code
//Perform the options of PlayList
void Song::Run()
{
    int choice;
    createplaylist c1;
    do
    {
        cout<<"********************************************************************************************************************"<<endl;
        cout<<"****************************                    MUSIC PLAYLIST                **************************************"<<endl;
        cout<<"****************************                    Enjoy the party               **************************************"<<endl;
        cout<<"********************************************************************************************************************"<<endl;
        cout<<"                                                     Made by-Manan Dankhara(202001133) and Gaurang Parmar(202001444)"<<endl;
        cout<< endl;
        string name;
        ifstream datafile;
        datafile.open("PlayList.txt");
        if(datafile)
        {
            int i=0;
            cout<<"List of PlayList."<<endl;
            cout<<"-----------------------------------------"<<endl;
            while(!(datafile.eof()))
            {

                getline(datafile,name);
                if(name!="\0")
                {
                    cout<<i+1<<". "<<name<<endl;
                    i++;
                }
            }
        }
        else
        {
            cout<<"No existing PlayList."<<endl;
        }
        datafile.close();
        cout<< "----------------MENU-----------------"<< endl;
        cout<<"1.Create PlayList."<<endl;
        cout<<"2.Access Existing PlayList."<<endl;
        cout<<"3.Delete PlayList ."<<endl;
        cout<<"4.Exit"<< endl;
        cout<< "--------------------------------------"<< endl;
        cout<< "Enter the choice : ";
        cin>>choice;
        cout<< "--------------------------------------"<< endl;
        switch(choice)
        {
        case 1:
        {
            system("CLS");
            cout<< endl<< endl;
            cout<<"\t\t\t     MAKE THE PLAYLIST TO ENJOY THE MEMORABLE MOVEMENT OF SONGS \t\t\t\t\t\t"<<endl<<endl;
            cout<<"Enter PlayList Name:";
            string Name;
            getchar();
            getline(cin,Name);
            ifstream file4;
            file4.open(Name+".txt");
            if(file4)                                               //If PlayList already exist then don't create
            {
                cout<<"PlayList already Exist."<<endl;
                cout<<"Please Enter to move ahead."<<endl;
                getchar();
                break;
            }
            else                                                    //If PlayList don't exist then create one and ask for add songs.
            {
                ofstream file3;
                file3.open("PlayList.txt",ios::app);
                file3<<Name<<endl;
                file3.close();
                ofstream file2;
                file2.open(Name +".txt");
                file2.close();
                while(1)
                {
                    cout<<"Do you want to enter Song(y/n)?";
                    char c;
                    cin>>c;
                    if(c=='y' || c=='Y')
                    {
                        c1.setdata();//storing the new song data in class object.
                        int flag=0;//to track if the song is updated or not.
                        ifstream file1;
                        file1.open(Name +".txt",ios::in);

                        ofstream file5;//open new file
                        file5.open("temp.txt", ios:: app);

                        while(!(file1.eof()))//this loop is for reading the old file until the end of file.
                        {
                            string s;
                            getline(file1,s);
                            if(s=="\0")
                            {
                                continue;
                            }
                            int pos=s.find(':');
                            s=s.substr(pos+1);

                            string s1;
                            getline(file1,s1);

                            int pos1=s1.find(':');
                            s1=s1.substr(pos1+1);

                            string s2;
                            getline(file1,s2);

                            string s3;
                            getline(file1,s3);

                            string s4;
                            getline(file1,s4);
                            if(c1.getName()==s && c1.getArtist()==s1)
                            {
                                flag++;//flag will increase if the song is same.

                                cout<< "Entered song already exist"<< endl;
                                cout<< "Want to update?(y/n) : ";
                                char response;
                                cin>> response;

                                if(response=='y' || response=='Y')
                                {
                                    string s=c1.getName();
                                    c1.setdata();
                                    file5<<"Song Name:"<<c1.getName()<<endl<<"Artist Name:"<<c1.getArtist()<<endl<<"Year of Release:"<<c1.getYear()<<endl<<"Duration Of the song:"<<c1.getDuration()<<endl<<"Category of the song:"<<c1.getCategory()<<endl<<endl;
                                    cout<< "Song is updated"<< endl;
                                    modify(s,c1.getName(),c1.getArtist(),c1.getDuration(),c1.getYear(),c1.getCategory());
                                }
                                else
                                {
                                    file5<<"Song Name:"<<s<<endl<<"Artist Name:"<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<endl;
                                }
                            }
                            else
                            {
                                file5<<"Song Name:"<<s<<endl<<"Artist Name:"<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<endl;
                            }

                        }
                        if(flag==0)//if the song is completely new then
                        {
                            file5<<"Song Name:"<<c1.getName()<<endl<<"Artist Name:"<<c1.getArtist()<<endl<<"Year of Release:"<<c1.getYear()<<endl<<"Duration Of the song:"<<c1.getDuration()<<endl<<"Category of the song:"<<c1.getCategory()<<endl<<endl;
                            Insert(c1.getName(),c1.getArtist(),c1.getYear(),c1.getDuration(),c1.getCategory());
                        }
                        file1.close();
                        file5.close();
                        string Name1=Name;
                        Name1+=".txt";
                        remove(Name1.c_str());
                        rename("temp.txt",Name1.c_str());
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            system("CLS");
            head=NULL;
            cout<< endl<< endl;
            cout<<"\t\t\t     ENJOY THE PLAYLIST \t\t\t\t\t\t"<<endl<<endl;
            cout<<"Enter PlayList Name:";
            string Name;
            getchar();
            getline(cin,Name);
            fstream file1;
            file1.open("PlayList.txt",ios::in | ios::app | ios::out);           //Opening Existing Playlist from PlayList file
            string s;
            int temp1=0;
            while(!(file1.eof()))
            {
                getline(file1,s);
                //If PlayList exist then open the playlist and enter the data into Linked List.
                if(s==Name)
                {
                    temp1=1;
                    ifstream file;
                    file.open(Name +".txt");
                    while(!(file.eof()))
                    {
                        //Taking Input of First song from name.
                        string s;
                        getline(file,s);
                        //If file contains empty line then it will continue(Ignore that Line)
                        if(s=="\0")
                        {
                            continue;
                        }
                        int pos=s.find(':');
                        s=s.substr(pos+1);

                        //Taking Input of Artist Name from file
                        string s1;
                        getline(file,s1);
                        pos=s1.find(':');
                        s1=s1.substr(pos+1);

                        //Taking Input of Year from file
                        string s2;
                        getline(file,s2);
                        pos=s2.find(':');
                        s2=s2.substr(pos+1);
                        stringstream s3(s2);
                        int year;
                        s3>>year;

                        //Taking Input of duration from file
                        string s4;
                        getline(file,s4);
                        pos=s4.find(':');
                        s4=s4.substr(pos+1);
                        stringstream s5(s4);
                        int duration;
                        s5>>duration;

                        //Taking Input of Category from file
                        string s6;
                        getline(file,s6);
                        pos=s6.find(':');
                        s6=s6.substr(pos+1);
                        Insert(s,s1,duration,year,s6);
                    }
                    file.close();
                    break;
                }
            }
            file1.close();
            //If PlayList doesn't exist then it will tell to create playlist first.
            if(temp1==0)
            {
                cout<< "--------------------------------------"<< endl;
                cout<<"No such PlayList exist please first create playlist."<<endl;
                cout<< "--------------------------------------"<< endl;
                cout<<"Press Enter to move ahead"<<endl;
                getchar();
                break;
            }

            while(1)
            {
                system("CLS");
                cout<<endl;
                cout<< "--------------------------------------"<< endl;
                cout<<Name<<endl;
                Node* temp=head;
                int i=0;
                cout<< "--------------------------------------"<< endl;
                cout<<"List Of Songs."<<endl;
                cout<< "--------------------------------------"<< endl;
                if(temp==NULL)
                {
                    cout<<"No Song Found."<<endl;
                }
                while(temp!=NULL)
                {
                    cout<<i+1<<". "<<temp->song_name<<endl;
                    temp=temp->next;
                    i++;
                }
                cout<< "--------------------------------------"<< endl;
                cout<< "-------------------MENU-----------------"<< endl;
                cout<<"1. Add a Song in PlayList."<<endl<<endl;
                cout<<"2. Remove a Song from PlayList."<<endl<<endl;
                cout<<"3. Search a Song in PlayList."<<endl<<endl;
                cout<<"4. Sort the Song in PlayList."<<endl<<endl;
                cout<<"5. Enjoy the Songs in PlayList."<<endl<<endl;
                cout<<"6. Add to Queue."<<endl<<endl;
                cout<<"7. Play the Queue."<<endl<<endl;
                cout<<"8. Exit"<<endl<<endl;
                cout<< "--------------------------------------"<< endl;
                cout<<"Enter your choice: ";
                int choice1;
                cin>>choice1;
                if(choice1==8)
                {
                    break;
                }
                cout<< "--------------------------------------"<< endl;
                switch(choice1)
                {
                case 1:
                {
                    while(1)
                    {
                        cout<<"Do you want to add the song?";
                        char c;
                        cin>>c;
                        if(c=='y' || c=='Y')
                        {
                            c1.setdata();//storing the new song data in class object.
                            int flag=0;//to track if the song is updated or not.

                            fstream file2;//open old file
                            file2.open(Name +".txt",ios::in);

                            ofstream file3;//open new file
                            file3.open("temp.txt", ios:: app);

                            while(!(file2.eof()))//this loop is for reading the old file until the end of file.
                            {
                                string s;
                                getline(file2,s);
                                if(s=="\0")
                                {
                                    continue;
                                }
                                int pos=s.find(':');
                                s=s.substr(pos+1);

                                string s1;
                                getline(file2,s1);

                                int pos1=s1.find(':');
                                s1=s1.substr(pos1+1);

                                string s2;
                                getline(file2,s2);

                                string s3;
                                getline(file2,s3);

                                string s4;
                                getline(file2,s4);
                                if(c1.getName()==s && c1.getArtist()==s1)
                                {
                                    flag++;//flag will increase if the song is same.

                                    cout<< "Entered song already exist"<< endl;
                                    cout<< "Want to update?(y/n) : ";
                                    char response;
                                    cin>> response;

                                    if(response=='y' || response=='Y')
                                    {
                                        string s=c1.getName();
                                        c1.setdata();
                                        file3<<"Song Name:"<<c1.getName()<<endl<<"Artist Name:"<<c1.getArtist()<<endl<<"Year of Release:"<<c1.getYear()<<endl<<"Duration Of the song:"<<c1.getDuration()<<endl<<"Category of the song:"<<c1.getCategory()<<endl<<endl;
                                        cout<< "Song is updated"<< endl;
                                        modify(s,c1.getName(),c1.getArtist(),c1.getDuration(),c1.getYear(),c1.getCategory());
                                    }
                                    else
                                    {
                                        file3<<"Song Name:"<<s<<endl<<"Artist Name:"<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<endl;
                                    }
                                }
                                else
                                {
                                    file3<<"Song Name:"<<s<<endl<<"Artist Name:"<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<endl;
                                }

                            }
                            if(flag==0)//if the song is completely new then
                            {
                                file3<<"Song Name:"<<c1.getName()<<endl<<"Artist Name:"<<c1.getArtist()<<endl<<"Year of Release:"<<c1.getYear()<<endl<<"Duration Of the song:"<<c1.getDuration()<<endl<<"Category of the song:"<<c1.getCategory()<<endl<<endl;
                                Insert(c1.getName(),c1.getArtist(),c1.getYear(),c1.getDuration(),c1.getCategory());
                            }
                            file2.close();
                            file3.close();
                            string Name1=Name;
                            Name1+=".txt";
                            remove(Name1.c_str());
                            rename("temp.txt",Name1.c_str());
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    while(1)
                    {
                        cout<<"Do you want to remove the song?"<<endl;
                        char c;
                        cin>>c;
                        if(c=='y' || c=='Y')
                        {
                            fstream file3;
                            file3.open(Name +".txt",ios::in | ios::out);
                            ofstream file4;
                            file4.open("temp.txt");
                            cout<<"Enter the song name you want to delete:";
                            string song_name;
                            getchar();
                            getline(cin,song_name);
                            string s4;
                            Delete(song_name);
                            cout<< "--------------------------------------"<< endl;
                            cout<< "--------------------------------------"<< endl;
                            //Make Temporary File
                            //Copy the content from old file except Removed content
                            //And Deleting Older File and Renaming Temporary File

                            while(getline(file3,s4))
                            {
                                int pos=s4.find(song_name);
                                if(pos!=-1)
                                {
                                    getline(file3,s4);
                                    getline(file3,s4);
                                    getline(file3,s4);
                                    getline(file3,s4);
                                }
                                else
                                {
                                    file4<<s4<<endl;
                                }
                            }
                            file3.close();
                            file4.close();
                            string Name1=Name;
                            Name1+=".txt";
                            char arr[50];
                            strcpy(arr,Name1.c_str());
                            remove(arr);
                            rename("temp.txt",arr);
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    cout<<"Enter the song name you want to search:"<<endl;
                    string song_name;
                    getchar();
                    getline(cin,song_name);
                    Search(song_name);
                    cout<<"Press Enter to move ahead."<<endl;
                    getchar();
                    break;
                }
                case 4:
                {
                    system("CLS");
                    cout<< "-------------------MENU-----------------"<< endl;
                    cout<<"1.Sort by Name."<<endl<<endl;
                    cout<<"2.Sort by duration."<<endl<<endl;
                    cout<<"3.Sort by Year Of Release."<<endl<<endl;
                    cout<< "----------------------------------------"<< endl;
                    cout<<"Enter your choice : ";
                    int choice3;
                    cin>>choice3;
                    Node** head=gethead();
                    switch(choice3)
                    {
                    case 1:
                    {
                        MergeSort_Name(head);
                        Print();
                        cout<<"Press Enter to move ahead."<<endl;
                        getchar();
                        getchar();
                        break;
                    }
                    case 2:
                    {

                        MergeSort_duration(head);
                        Print();
                        cout<<"Press Enter to move ahead."<<endl;
                        getchar();
                        getchar();
                        break;
                    }
                    case 3:
                    {
                        MergeSort_year(head);
                        Print();
                        cout<<"Press Enter to move ahead."<<endl;
                        getchar();
                        getchar();
                        break;
                    }
                    }
                    break;
                }
                case 5:
                {
                    system("CLS");
                    getchar();
                    playsongsequence();
                    break;
                }
                case 6:
                {
                    while(1)
                    {
                        cout<<"Do you want to add the song in Queue?(y/n)";
                        char c;
                        cin>>c;
                        if(c=='y' || c=='Y')
                        {
                            cout<<"Enter the song name you want to add in queue:";
                            string Song_name;
                            getchar();
                            getline(cin,Song_name);
                            Node* temp=head;
                            while(temp!=NULL && temp->song_name!=Song_name)
                            {
                                temp=temp->next;
                            }
                            if(temp==NULL)
                            {
                                cout<<"Song doesn't exist."<<endl;
                            }
                            else
                            {
                                Enqueue(temp);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
                case 7:
                {
                    printQueue();
                    break;
                }
                }
            }
            break;
        }
        case 3:
            {
                cout<<"Enter Name of PlayList you want to Delete:";
                string Name1;
                getchar();
                getline(cin,Name1);
                remove((Name1 + ".txt").c_str());
                ifstream datafile2;
                datafile2.open("PlayList.txt");
                ofstream datafile3;
                datafile3.open("Temporary.txt");
                int x=0;
                while(!(datafile2.eof()))
                {
                    string s1;
                    getline(datafile2,s1);
                    if(s1==Name1)
                    {
                        x=1;
                    }
                    else
                    {
                        if(s1!="\0")
                       datafile3<<s1<<endl;
                    }
                }
                datafile3.close();
                datafile2.close();
                if(x==0)
                {
                    remove("PlayList.txt");
                    rename("Temporary.txt","PlayList.txt");
                    cout<<"PlayList of Name "<<Name1<<" doesn't exist."<<endl;
                    cout<<"Press Enter to Move Ahead."<<endl;
                    getchar();
                    break;
                }
                else
                {
                    remove("PlayList.txt");
                    rename("Temporary.txt","PlayList.txt");
                    cout<<"PlayList Deleted Successfully."<<endl;
                    cout<<"Press Enter to Move Ahead."<<endl;
                    getchar();
                    break;
                }
            }
        case 4:
            break;

        }
        system("CLS");
    }
    while(choice !=4);
}
