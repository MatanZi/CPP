//
// Created by Matan Zilka on 4/9/2018.
//
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

#ifndef TASK3_2_MEMBER_H
#define TASK3_2_MEMBER_H

class Member{
    //---------------------------------------global parameters------------------------------
    static int ActiveMember;
    static int _MemberID;

private:
    //------------------------------------ Private parameters -------------------------------
    int MemberID;
    map <int,Member*> Followers;
    map <int,Member*> Following;

public:
    //--------------------------------------- Constractor / Destractur----------------------
    Member();
    //destractor 
    //earse all memroy of this memebr (also within the folloing map container and the followers map container
    ~Member();
    //----------------------------- Functions -----------------------------------------------------
    int numFollowing();
    int numFollowers();
    static int count();
    //this function check if the new member isnt himself and isnt already in the Following map container
    //if so the new memeber is enterd the Folloing container
    //otherwise do nothing
    void follow(Member& toAdd);
    //this function check if the new member isnt himself and isnt already in the Folloers map container
    //if so the new memeber is enterd the Followers container
    //otherwise do nothing
    void unfollow(Member& toRemove);
};

#endif //TASK3_2_MEMBER_H
