#include "Matricula.h"


string Matricula::printStudents(int student)
{
	return this->studentsVector[student];
}

string Matricula::getNameInstitution()
{
	return this->nameInstitution;
}

void Matricula::setNameIntitution(string nameInstitution)
{
	this->nameInstitution = nameInstitution;
}

int Matricula::getNumberOfSubjects()
{
	return this->numberOfSubjects;
}
void Matricula::setNumberOfSubjects(int numberOfSubjects) {

	this->numberOfSubjects = numberOfSubjects;

}
int Matricula::getNumberOfStudents()
{
	return this ->numberOfStudents;
}
void Matricula::setNumberOfStudents(int numberOfStudents) {

	this->numberOfStudents = numberOfStudents; 

}
void Matricula::createStudentsVector()
{
	
	studentsVector = new string[numberOfStudents];

}

void Matricula::createSubjectsVector()
{
	subjectsVector = new string[numberOfSubjects];
}

void Matricula::fillStudentsVector()
{
	string nameStudent; 
	for (int index = 0; index < numberOfStudents; index++) {
		nameStudent = "";
		cout << "            Digite el nombre del estudiante numero " << index<<" :  ";
		cin >> nameStudent; 
		studentsVector[index] = nameStudent;
	}

}


void Matricula::fillSubjectsVector(int typeOfSubjects) {
	int basic = 3;
	int sciences = 3;
	int full = 8;
	switch (typeOfSubjects)
	{
	case 1:
	
		numberOfSubjects = basic;
		subjectsVector = new string[numberOfSubjects]; 
		subjectsVector[0] = "Espanol"; 
		subjectsVector[1] = "Estudios Sociales"; 
		subjectsVector[2] = "Matematicas"; 
		
		break; 
	case 2:

		numberOfSubjects = sciences;
		subjectsVector = new string[numberOfSubjects];
		subjectsVector[0] = "Quimica";
		subjectsVector[1] = "Biologia";
		subjectsVector[2] = "Fisica";
		
		break;
	case 3:
	
		numberOfSubjects = full; 
		subjectsVector = new string[numberOfSubjects];
		subjectsVector[0] = "Espanol";             subjectsVector[4] = "Informatica";
		subjectsVector[1] = "Estudios Sociales";   subjectsVector[5] = "Nutricion";
		subjectsVector[2] = "Matematicas";	       subjectsVector[6] = "Sexualidad"; 
		subjectsVector[3] = "Ingles";              subjectsVector[7] = "Finanzas";
		
		break; 

	default:
		break;
	}

}

void Matricula:: createGradeMatrix() {

	gradesMatrix = new int* [numberOfStudents]; 
	for (int index = 0; index < numberOfStudents; index++) {
		gradesMatrix[index] = new int[numberOfSubjects]; 
	}
}

void Matricula::fillGradeMatrix()
{ 
	int note = 0;
	for (int indexStudents= 0; indexStudents < numberOfStudents; indexStudents++)
	{
		cout << "            Digite las notas de " << studentsVector[indexStudents] << " en las siguientes materias: " << endl;
		for (int subjectColumn= 0; subjectColumn < numberOfSubjects; subjectColumn++)
		{
			note=0;
			cout << "  "<<subjectsVector[subjectColumn] << " : ";
			cin >> note; 
			gradesMatrix[indexStudents][subjectColumn] = note;
		
		}
	}
}

void Matricula::addNewStudents(int newStudents)
{
	string* provisionalVector = NULL; 
	setNumberOfStudents(numberOfStudents + newStudents);
	provisionalVector = new string[numberOfStudents]; 

	for (int index = 0; index < numberOfStudents-newStudents; index++) {
		provisionalVector[index] = studentsVector[index];
	}
	createStudentsVector();
	for (int index = 0; index < numberOfStudents - newStudents; index++) {
		studentsVector[index] = provisionalVector[index];
	}
	
	
	for (int index = numberOfStudents-newStudents; index < numberOfStudents; index++) {
		string nameStudent = "";
		cout << "            Digite el nombre del estudiante numero"  << index<<":  ";
		cin >> nameStudent;
		studentsVector[index] = nameStudent;
	}
	for (int index = numberOfStudents-newStudents; index < numberOfStudents; index++) {
		gradesMatrix[index] = new int[numberOfSubjects];
	}
	int note = 0;
	for (int i = numberOfStudents-newStudents; i < numberOfStudents; i++)
	{
		cout << "            Digite las notas de " << studentsVector[i] << " en las siguientes materias: " << endl;
		for (int j = 0; j < numberOfSubjects; j++)
		{
			note = 0;
			cout << subjectsVector[j] << ": ";
			cin >> note;
			gradesMatrix[i][j] = note;

		}
	}
	
	delete[] provisionalVector;
}

void Matricula::mostrarMatriz()
{

	cout.width(10);
	cout << " "; 
	for (int i= 0; i < numberOfSubjects; i++)
	{
		cout.width(10);
		cout << subjectsVector[i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout.width(10);
		cout << studentsVector[i];
		for (int j = 0; j < numberOfSubjects; j++)
		{
			cout.width(10);
			cout<<gradesMatrix[i][j] << "|";
		}
		cout << endl;
	}
}

int Matricula::averageSubject(int subject)
{
	int total = 0; 
	for (int index = 0; index < numberOfStudents; index++) {
		total += gradesMatrix[index][subject];

	}
	return total/numberOfStudents;
}

int Matricula::maxGradeOfSubject(int subject)
{
	int maxNote = 0;
	int student = 0;
	for (int index = 0; index < numberOfStudents; index++) {
		if (maxNote < gradesMatrix[index][subject]) {
			maxNote = gradesMatrix[index][subject];
			student = index; 
		}

	}
	
	return  student; 
}

int Matricula::minGradeOfSubject(int subject)
{
	int minNote = 100;
	int student = 0;
	for (int index = 0; index < numberOfStudents; index++) {
		if (minNote > gradesMatrix[index][subject]) {
			minNote = gradesMatrix[index][subject];
			student = index;
		}

	}
	return student;
}


void Matricula::printStudentGrades(int number)
{
	cout.width(40); cout << "                  Notas " << "           Estado " << endl;
	cout << endl;
	for (int i = 0; i < numberOfSubjects; i++) {
		cout.width(20);
		cout << subjectsVector[i]; cout.width(20); cout << gradesMatrix[number][i]; cout.width(20); cout << subjectCondition(gradesMatrix[number][i]) << endl;


	}

}

string Matricula::subjectCondition(int note)
{
	if ((note < 50) && (note > 0))
	{

		return "Reprobado";
	}
	if ((note > 49) && (note < 70)) 
	{
		return "Parcial";
	}
	if ((note > 69) && (note < 101)) 
	{
		return "Aprobado";

	}
	if (note == NULL) 
	{
		return "Nota no definida";
	}
	return "Nota invalida"; 
}


string Matricula::studentCondition(int student) 
{
	int numberOfSubjectsPassed=0;

	for (int indexOfSubjects = 0; indexOfSubjects < numberOfSubjects; indexOfSubjects++) {
		
		if (gradesMatrix[student][indexOfSubjects] > 69) {
				numberOfSubjectsPassed++;
				}
	}
	if (numberOfSubjectsPassed == numberOfSubjects) {
		return "Aprobado";
	}

	return "Reprobado";
}



void Matricula::studentStatusList(int estado)
{
	int aprobado = 1;
	int reprobado = 2; 
	if ((estado != 2) && (estado != 1)) {
		cout<< "Debe digitar 1 o 0"; 
	}

	if (estado == aprobado) {

		for (int indexStudents = 0; indexStudents < numberOfStudents; indexStudents++)
		{
			if (studentCondition(indexStudents) == "Aprobado") {
				cout << studentsVector[indexStudents]<<endl; 
			}
		}
	}

	if (estado == reprobado) {

		for (int indexStudents = 0; indexStudents < numberOfStudents; indexStudents++)
		{
			if (studentCondition(indexStudents) == "Reprobado") {
				cout << studentsVector[indexStudents] << endl;
			}
		}
	}
}
void Matricula::addNewSubject(int numberOfSubjectAdd) {

	
	string *provisionalVector=NULL;
	string newSubject=" ";
	setNumberOfSubjects(numberOfSubjects + numberOfSubjectAdd);
	provisionalVector = new string[numberOfSubjects];
	
	for (int index = 0; index < (numberOfSubjects-numberOfSubjectAdd); index++) 
	{
			provisionalVector[index] = subjectsVector [index];
	}

	delete[] subjectsVector; 
	subjectsVector = provisionalVector;
	
	createGradeMatrix();
	
	for (int index = numberOfSubjects - numberOfSubjectAdd; index < numberOfSubjects; index++)
	{
		cout << "            Digite el nombre de la asignatura "<<index<<": ";
		cin >> newSubject;
		subjectsVector[numberOfSubjects - numberOfSubjectAdd ] = newSubject;
	}


	
}


void Matricula::summaryList() {
	int student;
	for (int indexSubject = 0; indexSubject < numberOfSubjects; indexSubject++)
 {
		student = 0;
		cout << "            Nota promedio de " << subjectsVector[indexSubject] << " : " << averageSubject(indexSubject)<<"\n";

		student = maxGradeOfSubject(indexSubject); 
		cout << "            Nota maxima: " << studentsVector[student] << " con un :" << gradesMatrix[student][indexSubject]<< "\n";

		student = minGradeOfSubject(indexSubject); 
		cout << "            Nota minima: " << studentsVector[student] << " con un :" << gradesMatrix[student][indexSubject] << "\n";
		cout << "\n\n"; 

			
	}



}


void Matricula::aplicationTest1()
{
	setNumberOfStudents(20); 
	createStudentsVector(); 
	
	studentsVector[0] = "Juan";    studentsVector[1] = "Pablo";    studentsVector[2] = "Pedro";    studentsVector[3] = "Martha";
	studentsVector[4] = "Jonas";    studentsVector[5] = "Luis";    studentsVector[6] = "Jose";    studentsVector[7] = "Joel";
	studentsVector[8] = "Ana";    studentsVector[9] = "Rosa";    studentsVector[10] = "Judith";   studentsVector[11] = "Yeni";
	studentsVector[12] = "Kevin";   studentsVector[13] = "Paul";   studentsVector[14] = "Emma";   studentsVector[15] = "Sofia";
	studentsVector[16] = "Maria";   studentsVector[17] = "Messi";   studentsVector[18] = "Itzel";   studentsVector[19] = "Dinia";

	fillSubjectsVector(1); 
	
	createGradeMatrix(); 
	fillRandGradeMatrix(); 


}


void Matricula::fillRandGradeMatrix() {
	
	/*srand(time(NULL));*/
	
	for (int indexStudents = 0; indexStudents < numberOfStudents; indexStudents++)
	{
		for (int  indexSubjects = 0; indexSubjects < numberOfSubjects; indexSubjects++)
		{
			gradesMatrix[indexStudents][indexSubjects] = rand() % 101; 
		}

	}
}

void Matricula::aplicationTest2()
{
	setNumberOfStudents(15);
	createStudentsVector();

	studentsVector[0] = "Messi";    studentsVector[1] = "Pablo";    studentsVector[2] = "Pedro";
	studentsVector[3] = "Martha";  studentsVector[4] = "Jonas";    studentsVector[5] = "Luis";
	studentsVector[6] = "Jose";    studentsVector[7] = "Joel";	   studentsVector[8] = "Ana";
	studentsVector[9] = "Rosa";  studentsVector[10] = "Judith";   studentsVector[11] = "Yeni";
	studentsVector[12] = "Kevin";   studentsVector[13] = "Paul";   studentsVector[14] = "Emma";


	fillSubjectsVector(2);

	createGradeMatrix();
	fillRandGradeMatrix();
}

void Matricula::aplicationTest3()
{
	setNumberOfStudents(10);
	createStudentsVector();

	studentsVector[0] = "Messi";    studentsVector[1] = "Pablo";    
	studentsVector[2] = "Pedro";    studentsVector[3] = "Martha";  
	studentsVector[4] = "Jonas";    studentsVector[5] = "Luis";
	studentsVector[6] = "Jose";     studentsVector[7] = "Joel";	   
	studentsVector[8] = "Ana";      studentsVector[9] = "Rosa";  
	

	fillSubjectsVector(3);

	createGradeMatrix();
	for (int indexStudents = 0; indexStudents < numberOfStudents-2; indexStudents++)
	{
		for (int indexSubjects = 0; indexSubjects < numberOfSubjects; indexSubjects++)
		{
			gradesMatrix[indexStudents][indexSubjects] = 90;
		}

	}
	for (int indexStudents = numberOfStudents-2; indexStudents < numberOfStudents; indexStudents++)
	{
		for (int indexSubjects = 0; indexSubjects < numberOfSubjects; indexSubjects++)
		{
			gradesMatrix[indexStudents][indexSubjects] = 0;
		}

	}
	
}




