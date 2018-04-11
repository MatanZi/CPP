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
    static int ActiveMember;
    static int _MemberID;

private:
    int MemberID;
    map <int,Member*> Followers;
    map <int,Member*> Following;

public:
    Member();
    ~Member();
    int numFollowing();
    int numFollowers();
    static int count();
    void follow(Member& toAdd);
    void unfollow(Member& toRemove);
};

#endif //TASK3_2_MEMBER_H
