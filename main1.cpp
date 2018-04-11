#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " << avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

void test2() {
	Member yafa;
	avi.follow(yafa);
	yafa.follow(yafa);
	yafa.follow(beni);
	cout << "  " << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << "  " << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	yafa.unfollow(yafa);
	cout << "  " << yafa.numFollowers() << " " << yafa.numFollowing() << endl; // 1 1
	cout << "  " << Member::count() << endl; // 4
}

void test3() {
	Member jojo;
	chana.follow(jojo);
	jojo.follow(chana);
	cout << "  " << chana.numFollowers() << " " << chana.numFollowing() << endl; // 1 1
	cout << "  " << jojo.numFollowers() << " " << jojo.numFollowing() << endl; // 1 1
	jojo.unfollow(chana);
	cout <<  " " << jojo.numFollowing() << endl; // 0
	cout << "  " << Member::count() << endl; // 4
}

int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	cout << "test 1:" << endl;
	test1();
	cout << "test 2:" << endl;
	test2();
	cout << "test 3:" << endl;
	test3();
	cout << "end tests" << endl;
	cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
	getchar();
}