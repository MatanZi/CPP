//
// Created by Matan Zilka on 4/9/2018.
//

#include "Member.h"

int Member::_MemberID=1;
int Member::ActiveMember =0;

Member::Member() {
    this->MemberID=_MemberID;
    _MemberID++;
    ActiveMember++;
}

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

int Member::numFollowers() {return Followers.size();}
int Member::numFollowing() {return Following.size();}
int Member::count() {return ActiveMember;}

void Member::follow(Member &toAdd) {

    if(&toAdd!= this){
        if(Following.count(toAdd.MemberID) == 0) {
            Following[toAdd.MemberID]=&toAdd;
            toAdd.Followers[MemberID]=this;
        }
    }
}

void Member::unfollow(Member &toRemove) {
    if(&toRemove!= this){
        if(Following.count(toRemove.MemberID) == 1) {
            Following.erase(toRemove.MemberID);
            toRemove.Followers.erase(this->MemberID);
        }
    }
}

