#pragma once

#include <string>
#include <ostream>
using std::ostream;
using std::string;
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	string name;
	string major;
	int ID;
	float GPA;
public:
	Student(): name(""),major(""), ID(0), GPA(0.0){};
	Student(string n_name, string n_major, int n_ID, float n_GPA) : name(n_name), major(n_major), ID(n_ID), GPA(n_GPA) {};
	Student(const Student& obj) {
			name = obj.name;
			major = obj.major;
			ID = abs(obj.ID);
			GPA = obj.GPA;
	}

	string getName()const noexcept { return name; }
	string getMajor()const noexcept { return major; };
	int getID()const noexcept { return ID; };
	float getGPA()const noexcept{ return GPA; };

	//dont declare noexcept in case std::string throws
	bool setName(const string& n_name) {
		if (n_name.empty())return false;
		name = n_name;
		return true;
	}
	//dont declare noexcept in case std::string throws
	bool setMajor(const string& n_major) {
		if (n_major.empty())return false;
		major = n_major;
		return true;
	}
	bool setID(int n_id)noexcept {
		if (n_id < 0)return false;
		ID = n_id;
		return true;
	}
	//although special cases exist of 4.1 GPA, keep simple.
	bool setGPA(float n_GPA)noexcept {
		if (n_GPA < 0.0f || n_GPA > 4.0f)return false;
		GPA = n_GPA;
		return true;
	}

	Student& operator=(const Student& other) {
		if (this != &other) {
			name = other.name;
			major = other.major;
			ID = other.ID;
			GPA = other.GPA;
		}
		return *this;
	}

	bool operator==(const Student& other) {
		if (this != &other) {
			//use unique identifier as criteria (Same name, Major, and GPA could exist)
			return (ID == other.ID);
		}
		// the same object is equal to itself
		return true;
	}

	friend ostream& operator<<(ostream& os, const Student& obj) {
		os << obj.getID() << ", " << obj.getName() << ", " << obj.getMajor() << ", and " << obj.getGPA() << " GPA.";
		return os;
	}
};

#endif

