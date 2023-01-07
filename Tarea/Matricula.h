#pragma once
#include <iostream>
#include <string>
using namespace std; 

class Matricula
{
private: 
	
	string nameInstitution = "";
	int numberOfSubjects = 0; 
	int numberOfStudents = 0; 
	string *studentsVector=NULL;
	string *subjectsVector=NULL;  
	int **gradesMatrix=NULL; 
	
	
	
public:

	
	string printStudents(int student); 
	string getNameInstitution(); 
	void setNameIntitution(string institution); 
	int getNumberOfSubjects();
	void setNumberOfSubjects(int numberOfSubjects);
	int getNumberOfStudents();
	void setNumberOfStudents(int numberOfStudents);
	void createStudentsVector();
	void createSubjectsVector();
	void fillStudentsVector();
	void fillSubjectsVector(int typeOfSubjects);
	void createGradeMatrix();
	void fillGradeMatrix(); 
	void addNewStudents(int);
	void printStudentGrades(int );
	string subjectCondition(int note);
	string studentCondition(int student);
	void studentStatusList(int estado);
	void addNewSubject(int numberOfSubjectAdd);
	void summaryList();
	void mostrarMatriz();
	int averageSubject(int subject);
	int maxGradeOfSubject(int subject);
	int minGradeOfSubject(int subject); 

	void aplicationTest1();
	void fillRandGradeMatrix();
	
	void aplicationTest2();
	void aplicationTest3(); 


};

