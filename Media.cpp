/*
File: Medai.cpp
Project: CMSC 202 Project 5 , Fall 2020
Author Wei zhang weng
Date: 11/18/2020
Section: 10
email: wweng2@umbc.edu

This file contain the function impemetation of the class of Media that 
can create a media object that has it's title, artist, type , year and rank of the media
*/
#include "Media.h"


Media::Media(){
  SetTitle("Wonderland");
  SetArtist("Alice");
  SetType("Music");
  SetYear(2000);// Set a default value of 2000 for year
  SetRank(100);// Set a defaul value of 100 for ranl as it's the lowest rank
    
}

Media::Media(string title, string artist, string type, int year, int rank ){

  SetTitle(title);
  SetArtist(artist);
  SetType(type);
  SetYear(year);
  SetRank(rank);
}


string Media::GetTitle()const{// The const is there to say the value won't change doesn't do anything else
  return m_title;
}
string Media::GetArtist()const{
  return m_artist;
}
string Media::GetType()const{
  return m_type;
}
int Media::GetYear()const{
  return m_year;
}
int Media::GetRank()const{
  return m_rank;
}
void Media::SetTitle(string title){
  m_title = title;
}
void Media::SetArtist(string artist){
  m_artist = artist;
}
void Media::SetType(string type){
  m_type = type;
}
void Media::SetYear(int year){
  if(year > -1){// Make sure the year is 0 and above, no negative years
    m_year = year;
  }
  else{
    m_year = 2000;// Default year since 0 is not a good year for meadia
  }
}
void Media::SetRank(int rank){
  if(rank > 0 && rank <= 100){// If the rank is greater then 0 and less or eqaul to 100 then it's valid and can beused
    m_rank = rank;
  }
    else{
      m_rank = 100; // defualt for rank if the rank is more than 100 or negative
    }
}

ostream& operator<<(ostream& out, Media& m){
  return cout<<m.GetTitle()<<" by "<<m.GetArtist()<<m.GetYear()<<endl;// Display the values
    
}

bool Media::operator<(const Media& m){
  if(m_year > m.GetYear()){// If m_year is greater then the passed media then it will return true
    return true;
  }
  else{
    return false;
  }
}
