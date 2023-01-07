
//Estudiantes:  Yenifer Mata y Tamara Vargas 
#include<Windows.h>
#include <iostream>
#include "Matricula.h"
#include <string>
#include <ctime>
using namespace std; 
Matricula newRecord;
string professor;
string seccion;
string nivel;
string nameInstitution;
string fecha;
void optionNewRecord(); 
void continueUse(); 
void printReports();
void loadData();

int main()
{

    cout << "\n           Para empezar ingrese el nombre de la intitucion: "; 
    getline (cin,nameInstitution);
    newRecord.setNameIntitution(nameInstitution);
    cout << "\n            Digite su nombre: "; 
    getline(cin, professor);
    cout << "\n            Digite el nivel de la clase: ";
    getline(cin,nivel );
    cout << "\n            Digite la seccion: ";
    getline(cin, seccion);
    cout << "\n            Digite la fecha: ";
    getline(cin, fecha);

    int option=0;  
   
    
    cout << "\n\n\n\n                        Bienvenido al sistema de matricula" << endl;
    cout << "\n\n";

    do
    {
       
        cout << "\n\n            Digite: \n\n";
        cout << "            [1] Para un nuevo registro" << endl;
        cout << "            [2] Para continuar uso en caso de que existan datos ingresados " << endl;
        cout << "            [3] Imprimir reportes" << endl;
        cout << "            [4] Cargar informacion (Pruebas de la aplicacion)" << endl;
        cout << "            [5] Salir del programa \n\n";
        cout << "             Ingrese la opcion: ";
        cin >> option;
     
        switch (option)
        {

        case 1:

            optionNewRecord();

            break;

        case 2:

            continueUse();

            break;


        case 3:

            printReports();

            break;

        case 4:
         
            loadData(); 
            
            
            break;

       
      

        default:
           
            break;
        }
    } while (option != 5);

   
    cout << endl; 
    cout << "            Se ha finalizado el programa" << endl; 
}




void optionNewRecord()
{
    
    
    int option = 0;
    int numberOfStudents = 0;
    int typeSubject = 0;
    int numberOfSubjectsAdd=0; 
    
    

    cout << "\n\n\n\n";
    

    do
    {
        cout << "\n\n            A continuacion digite: " << endl;
        cout << "            [1] Para ingresar la cantidad y el nombre de sus estudiantes" << endl;
        cout << "            [2] Para seleccionar las materias y agregar las notas de los estudiantes" << endl;
        cout << "            [3] Para agregar notas" << endl;
        cout << "            [4] Para regresar al menu principal" << endl;
        cout << "            Ingrese la opcion: ";
        cin >> option;
        switch (option)
        {

        case 1:
            
            cout << "          Digite la cantidad de estudiantes :";
            cin >> numberOfStudents;
            newRecord.setNumberOfStudents(numberOfStudents); 
            newRecord.createStudentsVector();
            cout << "         Ahora debe agregar los nombres de los estudiantes: "<<endl;
            newRecord.fillStudentsVector();
            break; 

        case 2:
           
            cout << "          Eliga las materias que desa agregar " << endl;
            cout << "          [1] Para las materias basicas: Espanol,Estudios Sociales, Matematicas" << endl;
            cout << "          [2] Para las materis de ciencia: Quimica, Fisica, Biologia" << endl;
            cout << "          [3] Full: Espanol,Estudios Sociales, Matematicas,Ingles, Informatica, Nutricion, Sexualidad, Finanzas " << endl;
            cout << "          Ingrese opcion: ";
            cin >> typeSubject;
            newRecord.fillSubjectsVector(typeSubject);
            newRecord.createGradeMatrix();

            cout << "\n\n";
            cout << "            ¿Cauntas materias nuevas desea agregar?" << endl; 
            cout << "            Si no desea agregar una nueva materia digite 0: "; 
            cin >> numberOfSubjectsAdd; 

            newRecord.addNewSubject(numberOfSubjectsAdd); 


            break; 

        case 3:
            system("cls"); 
            cout << "\n            Ahora deberá agregar las notas de los estudiantes" << endl;
            newRecord.fillGradeMatrix();

            break; 

      
        default:

           
            break;


        }

    } while (option != 4);
}

void continueUse()
{
    if (newRecord.getNumberOfStudents() != 0)
    {
       

        int numberOfStudents=0;
        cout << "            Digite la cantidad de nuevos estudiantes que desea registrar: ";
        cin >> numberOfStudents;
        newRecord.addNewStudents(numberOfStudents);
        cout << endl;

        cout << "            Estudiantes registrados con exito \n\n";

     
    }

    if (newRecord.getNumberOfStudents() == 0) {

        cout << "            No hay estudiantes registrados aun" << endl; 
    }
}

void printReports()
{
    
    
    int numberOfStudents = 0; 
    numberOfStudents = newRecord.getNumberOfStudents();
    int option = 0; 
    int student = 0; 
    int condition = 0; 
    string conditionInLetters = "";
    
    

    do
    {
        
      
        cout << "\n\n            A continuacion digite: " << endl; 
        cout << "            [1] Para imprimir el listado de todas las notas y todos los estudiantes" << endl;
        cout << "            [2] Para imprimir las notas de un estudiante en especifico" << endl;
        cout << "            [3] Para imprimir la lista de los estudiantes en un estado en especifico" << endl;
        cout << "            [4] Para imprimir el promedio por materia, el maximo, el minimo y la cantidad de estudiantes " << endl;
        cout << "            [5] Para regresar al menu principal" << endl;
        cin >> option;

        switch (option)
        {

        case 1: 
            
            cout << "\n\n                               Listado de Calificaciones " << "\n\n";
            cout << "            " <<newRecord.getNameInstitution() << "/ Sistema de matricula "<<"\n\n";
            cout << "            Nivel: " << nivel; cout << "   Seccion:" << seccion<< "\n\n";
            cout << "            Consultado por: " << professor; 
            cout << "            Fecha: "<<fecha;
          
             
            cout << "\n\n";
            newRecord.mostrarMatriz(); 
            cout << "\n\n";
            break; 

        case 2: 
           
            cout << "\n\n                 Estos son los estudiantes registrados actualmente." << endl;
            for (int index = 0; index < numberOfStudents; index++) {
               cout<<"["<<index<<"] = "<< newRecord.printStudents(index)<<endl;

            }
            cout << "                  Digite el numero correspondiente del estudiante para ver sus notas y estado: "; 
            cin >> student; 

            cout << "\n\n                      Notas del estudiante "<< newRecord.printStudents(student) << "\n\n";
            cout << "            " << newRecord.getNameInstitution() << "/ Sistema de matricula " << "\n\n";
            cout << "            Nivel: " << nivel; cout << "   Seccion:" << seccion << "\n\n";
            cout << "            Consultado por: " << professor;
            cout << "            Fecha: " << fecha;

            cout << "\n\n "; 
            newRecord.printStudentGrades(student); 
         
            cout << "\n\n";
            break;

        case 3: 
            
            cout << " \n\n                 Digite :" << endl; 
            cout << "                  [1] Para ver la lista de estudiantes en condicion aprobada " << endl;
            cout << "                  [2] Para ver la lista de estudiantes en condicion reprobada" << endl;
            cout << "                  Ingrese opcion: ";
            cin >> condition; 
            if (condition == 1) {
                conditionInLetters = "Aprobada"; 
            }
            if (condition == 2) {
                conditionInLetters = "Reprobada";
            }
     
            cout << "\n\n                  Estudiantes en condicion  " << conditionInLetters<<endl; 
            cout << "            " << newRecord.getNameInstitution() << "/ Sistema de matricula " << "\n\n";
            cout << "            Nivel: " << nivel; cout << "   Seccion:" << seccion << "\n\n";
            cout << "            Consultado por: " << professor;
            cout << "            Fecha: " << fecha;
            cout << "\n\n ";
            newRecord.studentStatusList(condition); 
            cout << "\n\n";

            break;
        case 4: 
            
            cout << "\n\n                       Listado Resumen  " << "\n\n";
            cout << "           " << newRecord.getNameInstitution() << "/ Sistema de matricula " << "\n\n";
            cout << "            Nivel: " << nivel; cout << "   Seccion:" << seccion << "\n\n";
            cout << "            Consultado por: " << professor;
            cout << "            Fecha: " << fecha;
            cout << "\n\n";
            newRecord.summaryList(); 
            cout << "\n\n";

            break;
        default:
           
            break;
        }

    } while (option!=5);

}

void loadData()
{
    int option = 0; 
    do
    {
       
        cout << "            A continuacion digite: \n\n";
        cout << "            [1] Para cargar 20 estudiantes, notas de todo tipo y materias basicas" << endl;
        cout << "            [2] Para cargar 15 estudiantes, notas de todo tipo y materias de ciencia" << endl;
        cout << "            [3] Para cargar 10 estudiantes con notas altas y dos con nulos, todas las materias" << endl;
        cout << "            [4] Para regresar al menu principal \n\n";
        cout << "            Ingrese opcion:"; 
        cin >> option; 
        cout << "\n\n";
        switch (option)
        {

        case 1: 
            
            newRecord.aplicationTest1(); 
            cout << "            Listo, ahora puede imprimir los reprotes \n\n" << endl; 
        
            break; 
        case 2: 
            newRecord.aplicationTest2(); 
            cout << "            Listo, ahora puede imprimir los reportes \n\n" << endl;
          
            break; 
        case 3: 

            newRecord.aplicationTest3(); 
            cout << "            Listo, ahora puede imprimir los reportes \n\n" << endl;
           
            break; 
        default:
            
           
            break;
        }

    } while (option!=4);

    
}

