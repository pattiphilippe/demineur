#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    /*
    int i { -1 };
    cout << "Valeur initiale de i : " << i << endl;

    cout << "Fournir un entier : ";
    try{
        //modif de i même si erreur
        lineFromKbd(i); //, true pour ignorer espaces ext

        /modif de i que sans erreur
        i = lineFromKbd(i)
    } catch (const exception & e){
        cout << e.what() << endl;
    }
    */
//TODO mettre un max de méthodes inline
    //TODO mettre un max de const (indique qu'une méthode ne modifie pas l'état de l'objet)

    return 0;
}
