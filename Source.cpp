#include "Member.h"
using namespace std;

int Member::numUsers = 0;
int Member::nextId = 0;

Member::Member() {
	numUsers++;
	userId = nextId++;
}

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

	//for (int i = 0; i<followers.size(); i++) {
		//followers[i]->unfollow(*this);
	//}
	//for (int i = 0;i<following.size(); i++) {
		//unfollow(*following[i]);
	//}
	
}

int Member::numFollowers() {
	
	return followers.size();
}

int Member::numFollowing() {
	
	return following.size();
}

void Member::follow(Member& other) {
	if (this != &other) { // בדיקה שהוא לא עוקב אחרי עצמו
		Member *temp = &other;
		
		for (int i = 0; i < following.size(); i++) {

			if (following[i] == temp) //אם הוא כבר בחברים
				return;
		}
			following.push_back(temp);
			temp->followers.push_back(this);
		
	}
	return;
	
}

void Member::unfollow(Member& other)
{
	if (this != &other) {
		Member *temp = &other;

		for (int i = 0; i < following.size(); i++) {

			if (following[i] == temp) {
				following.erase(following.begin() + i);
			}
		}

		for (int i = 0; i < other.followers.size(); i++) {

			if (other.followers[i] == this) {
				other.followers.erase(other.followers.begin() + i);

				return;
			}
		}
	}
		return;
}
