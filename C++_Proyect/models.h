#pragma once

enum Specialization
{
	Therapist,
	Surgeon,
	Cardiologist,
	Dentist
};


struct Doctor
{
	int id;
	char* name;
	char* surname;
	Specialization specialization;
	int experience;
	int roomNumber;
	char* email;

	Doctor()
	{
		id = 0;
		name = nullptr;
		surname = nullptr;
		specialization = Therapist;
		experience = 0;
		roomNumber = 0;
		email = nullptr;
	}

	Doctor(int id, char* name, char* surname, Specialization specialization, int experience, int roomNumber, char* email)
	{
		this->id = id;
		this->name = name;
		this->surname = surname;
		this->specialization = specialization;
		this->experience = experience;
		this->roomNumber = roomNumber;
		this->email = email;
	}

	const char* getSpecName(Specialization s)
	{
		switch (s)
		{
		case Therapist:
			return "Therapist";
		case Surgeon:
			return "Surgeon";
		case Cardiologist:
			return "Cardiologist";
		case Dentist:
			return "Dentist";
		default:
			return "Unknown";
		}
	}

	void printInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Specialization: " << getSpecName(specialization) << endl;
	}

	void printInfoWithId()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Specialization: " << getSpecName(specialization) << endl;
		cout << "Experience: " << experience << endl;
		cout << "Room number: " << roomNumber << endl;
		cout << "Email: " << email << endl;
	}

	~Doctor()
	{
		delete[] name;
		delete[] surname;
		delete[] email;
		name = surname = email = nullptr;
	}
};
