#ifndef SONG_H
#define SONG_H
#include<iostream>
using namespace std;
class Song;
class Node
{
    string song_name;
    string artist_name;
    int duration;
    int year;
    int counter;
    Node* next;
    string Category;
    friend class Song;
    Node(string song_name,string artist_name,int duration,int year,string Category)
    {
        this->song_name=song_name;
        this->artist_name=artist_name;
        this->duration=duration;
        this->year=year;
        this->Category=Category;
        counter=0;
        next=NULL;
    }
};
class Song
{
    Node* head;     // for Linked List
    Node* last;     // for Linked List

    Node *queue_front; // for access the queue
    Node *queue_rear; // for access the queue
    public:
       Song();
       void Insert(string ,string ,int ,int ,string );
       void CreatePlayList();
       void Print();
       void Delete(string );
       void Search(string );
       void modify(string ,string ,string ,int ,int ,string );
       void playsongsequence();
       void timer(int );
       void MergeSort_Name(Node** );
       void MergeSort_year(Node** );
       void MergeSort_duration(Node** );
       Node* Merge_by_duration(Node* ,Node* );
       Node* Merge_by_year(Node* ,Node* );
       Node* Merge_by_Name(Node* ,Node* );
       void Split(Node* ,Node** ,Node** );
       Node** gethead();
       void Enqueue(Node* );
       void printQueue();
       void Run();
};

#endif // SONG_H
