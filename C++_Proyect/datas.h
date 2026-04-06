#pragma once

char* copyStr(const char* str)
{
	int len = strlen(str) + 1;
	char* newStr = new char[len];
	strcpy_s(newStr, len, str);

	return newStr;
}


//Doctor* doctors = new Doctor[20]{
//	{1, copyStr("Ali"), copyStr("Mammadov"), Therapist, 5, 101, copyStr("ali@mail.com")},
//	{2, copyStr("Veli"), copyStr("Aliyev"), Surgeon, 10, 102, copyStr("veli@mail.com")},
//	{3, copyStr("Aysel"), copyStr("Huseynova"), Cardiologist, 3, 103, copyStr("aysel@mail.com")},
//	{4, copyStr("Rashad"), copyStr("Karimov"), Dentist, 8, 104, copyStr("rashad@mail.com")},
//	{5, copyStr("Nigar"), copyStr("Ismayilova"), Therapist, 6, 105, copyStr("nigar@mail.com")},
//
//	{6, copyStr("Elvin"), copyStr("Hasanov"), Surgeon, 12, 106, copyStr("elvin@mail.com")},
//	{7, copyStr("Sabina"), copyStr("Guliyeva"), Cardiologist, 4, 107, copyStr("sabina@mail.com")},
//	{8, copyStr("Tural"), copyStr("Rzayev"), Dentist, 7, 108, copyStr("tural@mail.com")},
//	{9, copyStr("Leyla"), copyStr("Sadiqova"), Therapist, 2, 109, copyStr("leyla@mail.com")},
//	{10, copyStr("Orxan"), copyStr("Jafarov"), Surgeon, 15, 110, copyStr("orxan@mail.com")},
//
//	{11, copyStr("Aysu"), copyStr("Ismayilova"), Cardiologist, 5, 111, copyStr("aysu@mail.com")},
//	{12, copyStr("Ramil"), copyStr("Hasanov"), Dentist, 9, 112, copyStr("ramil@mail.com")},
//	{13, copyStr("Zarina"), copyStr("Aliyeva"), Therapist, 3, 113, copyStr("zarina@mail.com")},
//	{14, copyStr("Togrul"), copyStr("Karimov"), Surgeon, 11, 114, copyStr("togrul@mail.com")},
//	{15, copyStr("Lala"), copyStr("Huseynova"), Cardiologist, 6, 115, copyStr("lala@mail.com")},
//
//	{16, copyStr("Samir"), copyStr("Abbasov"), Dentist, 8, 116, copyStr("samir@mail.com")},
//	{17, copyStr("Afaq"), copyStr("Rahimova"), Therapist, 4, 117, copyStr("afaq@mail.com")},
//	{18, copyStr("Nijat"), copyStr("Salmanov"), Surgeon, 13, 118, copyStr("nijat@mail.com")},
//	{19, copyStr("Gunay"), copyStr("Veliyeva"), Cardiologist, 2, 119, copyStr("gunay@mail.com")},
//	{20, copyStr("Elshad"), copyStr("Qurbanov"), Dentist, 10, 120, copyStr("elshad@mail.com")}
//};