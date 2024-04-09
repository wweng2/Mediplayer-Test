/*
File: MediaPlayer.cpp
Project: CMSC 202 Project 5 , Fall 2020
Author WEi zhang weng
Date: 11/18/2020
Section: 10
email: wweng2@umbc.edu

This file contain the function impemetation of the the MediaPlayer class that allows for the user to create a media player object
*/
#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(){
  LoadCatalog("Filename");// Load the file but use a dault name for file
}

MediaPlayer::MediaPlayer(string filename){

  LoadCatalog(filename);// Loads in the content of the file into m_catalog

}

MediaPlayer::~MediaPlayer(){
  for(unsigned int i = 0 ; i < m_mediaCatalog.size(); i++){//Loops through everything and delete everything in m_catalog
    delete m_mediaCatalog.at(i);
  }

}

void MediaPlayer::LoadCatalog(string filename){
  ifstream myfile(filename);    
  string Title;
  string Artist;
  string Type;
  string Year;
  string Rank;
  int MediaTotal = 0;


  if(myfile.is_open()){
    while(getline(myfile,Title,';')){// As long as the file still have string , the while won't stop 
      getline(myfile,Artist,';');
      getline(myfile,Type,';');
      getline(myfile,Year,';');
      getline(myfile,Rank);
      Media *media = new Media(Title,Artist,Type,stoi(Year),stoi(Rank));// a dynamically allocated media is created , and used stoi to turn year and rank back to ints
      m_mediaCatalog.push_back(media);// This is then add to mediaCatalog
      MediaTotal ++;
      
    }
  }
  else{
    cout<<"Unable to open file: please try again."<<endl;
  }
  cout<<MediaTotal<<" media files loaded"<<endl;
  myfile.close();// Close the file to prevent any memory issue or werid things from happening
}
 
void MediaPlayer::MainMenu(){
  int choice = 0;
  int total = 0;
  while(choice != 5){// Until the user quits the main menu will keep running
    cout<<" What would you like to do "<<endl;
    cout<<" 1. Display Media by Type and Year"<<endl;
    cout<<" 2. Add Media to Playlist"<<endl;
    cout<<" 3. Display Playlist"<<endl;
    cout<<" 4. Sort Playlist by Year"<<endl;
    cout<<" 5. Quit"<<endl;

    cin>> choice;
    if(choice == 1){
      DisplayPlaylist();// This will display everything
      total = DisplayMedia();// DisplayMedai return how many media was found of for the year the user inputs
      cout <<total<<" media found"<<endl;// This is then displayed
    }
    else if (choice == 2){
      AddMedia();
    }
    else if (choice == 3){
      DisplayPlaylist();
    }
    else if (choice == 4){
      SortPlaylist();
    }
    else if (choice == 5){// This is here so when the user hits 5 , the sentnece will be outputted instead of please enter a valid number
      cout<<"Thank you for using UMBC Media Player"<<endl;
    }
    else{// input validation
      cout<<"Please enter a valid number"<<endl;
    }
  }
}

int MediaPlayer::DisplayMedia(){
  int year = 0;
  string type;
  int Total = 0;
  string IsValid;
  
  while(IsValid != "Valid"){// until the user puts in the valid input of music or podcast , this will keep loop until it does
    cout<<" Which media type do you want display?"<<endl;
    cout<<"music"<<endl;
    cout<<"podcast"<<endl;
 
    cin>> type;

    if(type != "music"){// If the type is not music it will check to see if type is podcast and if it is then it will be valid
      if(type == "podcast"){
	
	IsValid = "Valid";
      }
      else{// This is when type is not music or podcast and such wil tell the user to put ina valid input
	cout<<"Please enter a valid input (music/podcast)"<<endl;
      }
    }   
    else{// If type is music Isvalid will become valid
      IsValid = "Valid";
    }
  }

  IsValid = "Invalid";// Rest Isvalid for use for years

while(IsValid != "Valid"){
    cout<<"Which year would you like to display? (1958-2020)"<<endl;

    cin>> year;

    if(year < 1958){// Checks to see if year is less than 1958 and if it is then it will tell the user it's invalid
      cout<<"Please enter in a valid year in between(1958-2020) "<<endl;
    }
    else if(year > 2020){// If the year is not less then 1958, it will then check to see if it is more than 2020 and if it is then it will output that it's invalid
      cout<<"Please enter in a valid year in between(1958-2020) "<<endl;
    }
    else{// If it is in the range between 1958 and 2020 then i=isvalid will become valid
      IsValid = "Valid";
    }
     
  }
    
  cout<<"******"<<year<<"******"<<endl;

  for(unsigned i = 0; i < m_mediaCatalog.size(); i++){// Loops through the MediaCatalog
    if(m_mediaCatalog.at(i)->GetYear() == year && m_mediaCatalog.at(i)->GetType() == type){// If the media has the right year and type it will display it
      cout<< i + 1 <<" . "<<m_mediaCatalog.at(i)->GetTitle()<<" by " <<m_mediaCatalog.at(i)->GetArtist()<<endl;// The plus 1 is to make the numeber start at 1 and not 0
      Total++;
    }
  }
  return Total;// Return the total medai that fit the qualifications
}

void MediaPlayer::AddMedia(){
  int choice = 0;
  int year = 0;
  int Total = 0;
  string type;
  string IsValid;
  int Start;
  int End;
  if(m_playList.IsFull() == 0){// If the playlist is not full then it will add a media to it
    DisplayPlaylist();// Display the one that are in the playlist
   
  while(IsValid != "Valid"){// until the user puts in the valid input of music or podcast , this will keep loop until it does
    cout<<" Which media type do you want display?"<<endl;
    cout<<"music"<<endl;
    cout<<"podcast"<<endl;

    cin>> type;

    if(type != "music"){// If the type is not music it will check to see if type is podcast and if it is then it will be valid
      if(type == "podcast"){

        IsValid = "Valid";
      }
      else{// This is when type is not music or podcast and such wil tell the user to put ina valid input
        cout<<"Please enter a valid input (music/podcast)"<<endl;
      }
    }
    else{// If type is music Isvalid will become valid
      IsValid = "Valid";
    }
  }

  IsValid = "Invalid";// Rest Isvalid for use for years
  
  while(IsValid != "Valid"){
    cout<<"Which year would you like to display? (1958-2020)"<<endl;
    
    cin>> year;
    
    if(year < 1958){// Checks to see if year is less than 1958 and if it is then it will tell the user it's invalid
      cout<<"Please enter in a valid year in between(1958-2020) "<<endl;
    }
    else if(year > 2020){// If the year is not less then 1958, it will then check to see if it is more than 2020 and if it is then it will output that it's invalid
      cout<<"Please enter in a valid year in between(1958-2020) "<<endl;
    }
    else{// If it is in the range between 1958 and 2020 then i=isvalid will become valid
      IsValid = "Valid";
    }
    
  }
  
  
  for(unsigned i = 0; i < m_mediaCatalog.size(); i++){
    if(m_mediaCatalog.at(i)->GetYear() == year && m_mediaCatalog.at(i)->GetType() == type){
      if (Total == 0){
	Start = i + 1;
      }
		    
      cout<< i+1 <<" . "<<m_mediaCatalog.at(i)->GetTitle()<<" by " <<m_mediaCatalog.at(i)->GetArtist()<<endl;// The plus one is to make sure the number start from 1 then 0
      Total++;
    }
  }
  
  cout <<Total<<" media found"<<endl; 
  if(Total != 0){

    IsValid = "Invalid";

    while(IsValid != "Valid"){
      cout<<"Enter the number of the media you would like to add: "<<endl;

      cin >> choice;
      if(choice  >= Start){

	End = Start + Total;
	if(choice <= End){

	  IsValid = "Valid";
	}
	else{
	  cout<<"Please enter in a Valid number in the range of of the media "<<endl;
        }

      }
      else{
	cout<<"Please enter in a Valid number in the range of of the media "<<endl;
	}
      }
      m_playList.Enqueue(m_mediaCatalog.at(choice - 1));// The minus 1 is to cancel the plus one so the acual index for the thing the  can be used
      cout<<m_mediaCatalog.at(choice -1)->GetTitle()<<" by "<<m_mediaCatalog.at(choice -1)->GetArtist()<<" added to the playlist"<<endl;// used the minus one to for the proper index that the user chosed
    
  }
  else{
    cout<<"There is no media of the the year you want please enter in a new year please "<<endl;
  }
  }
 else{
   cout<<"The playlist is full please make some room"<<endl;
  }

}

void MediaPlayer::DisplayPlaylist(){
  if(m_playList.IsEmpty() != 1){// If the playlist if not empty it will display every value in m_playsit, with it's title,author and year
    
    m_playList.DisplayAll();
  }
  else{
    cout<<"The playlist is empty"<<endl;
  }
  
}

void MediaPlayer::SortPlaylist(){
  if(m_playList.IsEmpty() != 1){// If the the playlist is not empty it will sort everything in it by year from oldest to newest
    cout<<"Done sorting by year "<<endl;
    cout<<m_playList.Size()<<" items sorted "<<endl;
    m_playList.Sort();
    
  }
  else{// If not then it will tell the user that the playlsit is empty
    cout<<"The playlist is empty"<<endl;
  }
}

