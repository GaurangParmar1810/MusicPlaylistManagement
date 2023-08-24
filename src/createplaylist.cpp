#include "createplaylist.h"
#include<bits/stdc++.h>

using namespace std;

//Return Song Name
string createplaylist::getName()
{
    return song_name;
}
//Return Artist Name
string createplaylist::getArtist()
{
    return artist_name;
}
//Return Year
int createplaylist::getYear()
{
    return year;
}
//Return Duration of the song
int createplaylist::getDuration()
{
    return duration;
}
//Return Category of the Song
string createplaylist::getCategory()
{
    return category;
}
//Set Information of the song
void createplaylist::setdata()
{
    getchar();
    cout<<"Enter song name:";
    getline(cin,song_name);
    cout<<endl;
    cout<<"Enter Artist name:";
    getline(cin,artist_name);
    cout<<endl;
    cout<<"Enter the release year of Song:";
    cin>>year;
    cout<<endl;
    getchar();
    cout<<"Enter the duration of the song in seconds:";
    cin>>duration;
    cout<<endl;
    getchar();
    cout<<"Enter category of the song:";
    getline(cin,category);
    cout<<endl;
}
