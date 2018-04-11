#include "Member.h"
using namespace std;

int Member::numUsers = 0;
int Member::nextId = 0;

//constructor
Member::Member() {
	numUsers++; // numbers of users 
	userId = nextId++; // id of each user
}

//distructor
Member::~Member() {

	for (Member *member : following) {
		this->unfollow(*member);
	}

	for (Member *member : followers) {
		member->unfollow(*this);
	}

	followers.clear();
	following.clear();

	numUsers--;
	
}

int Member::numFollowers() {
	
	return followers.size();
}

int Member::numFollowing() {
	
	return following.size();
}

void Member::follow(Member& other) {
	if (this != &other) { // check if the user not following himself
		Member *temp = &other;
		
		for (int i = 0; i < following.size(); i++) {

			if (following[i] == temp) // check if he is already following "other"
				return;
		}
			following.push_back(temp);
			temp->followers.push_back(this);
		
	}
	return;
	
}

void Member::unfollow(Member& other)
{
	if (this != &other) { // check if the user is unfollowing himself
		Member *temp = &other;

		for (int i = 0; i < following.size(); i++) {

			if (following[i] == temp) { // check if he is following "other"
				following.erase(following.begin() + i);
			}
		}

		for (int i = 0; i < other.followers.size(); i++) {

			if (other.followers[i] == this) { // check if the user is in the followers of "other"
				other.followers.erase(other.followers.begin() + i);

				return;
			}
		}
	}
		return;
}
