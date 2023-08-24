#ifndef CREATEPLAYLIST_H
#define CREATEPLAYLIST_H

#include<bits/stdc++.h>

using namespace std;

class createplaylist
{
    string song_name;
    string artist_name;
    string category;
    int duration;
    int year;

    public:
        string getName();
        string getArtist();
        int getYear();
        string getCategory();
        int getDuration();
        void setdata();
};

#endif // CREATEPLAYLIST_H
