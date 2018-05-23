//
// Created by Matan Zilka on 4/9/2018.
//

#include "Member.h"

//---------------------------------------global parameters------------------------------
int Member::_MemberID=1; // uniqe id for each member
int Member::ActiveMember =0; // indicates the active memebrs


//--------------------------------------- Constractor / Destractur----------------------
//constractor
//set member id and incremenet param Activememebr 
Member::Member() {
    this->MemberID=_MemberID;
    _MemberID++;
    ActiveMember++;
}
//destractor 
//earse all memroy of this memebr (also within the folloing map container and the followers map container
Member::~Member() {
	map <int, Member*> :: iterator i;
	for(i=Following.begin(); i!=Following.end();i++)
	{
		i->second->Followers.erase(this->MemberID);
	}

	for(i=Followers.begin();i!=Followers.end();i++)
	{
		i->second->Following.erase(this->MemberID);
	}
    ActiveMember--;
}
//----------------------------- Functions -----------------------------------------------------
//return the size of the followers container
int Member::numFollowers() {return Followers.size();}
//return the size of the following container
int Member::numFollowing() {return Following.size();}
//return the size of the Active members
int Member::count() {return ActiveMember;}


//this function check if the new member isnt himself and isnt already in the Following map container
//if so the new memeber is enterd the Folloing container
//otherwise do nothing
void Member::follow(Member &toAdd) {

    if(&toAdd!= this){
        if(Following.count(toAdd.MemberID) == 0) {
            Following[toAdd.MemberID]=&toAdd;
            toAdd.Followers[MemberID]=this;
        }
    }
}


//this function check if the new member isnt himself and isnt already in the Folloers map container
//if so the new memeber is enterd the Followers container
//otherwise do nothing
void Member::unfollow(Member &toRemove) {
    if(&toRemove!= this){
        if(Following.count(toRemove.MemberID) == 1) {
            Following.erase(toRemove.MemberID);
            toRemove.Followers.erase(this->MemberID);
        }
    }
}

