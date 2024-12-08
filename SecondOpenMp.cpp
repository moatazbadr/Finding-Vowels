/*#include <iostream>
#include <omp.h>
#include <ctime>

using namespace std;

int main() {


#pragma region Sequential solution of words and vowels
    
    char vowels[5] = { 'a', 'i', 'e', 'u', 'h' };

    cout << "Enter number of words: ";
    int number_words;
    cin >> number_words;

    

    string* words = new string[number_words];
   
    for (int i = 0; i < number_words; i++) {
        cout << "Word number " << i + 1 << ": ";
        cin >> words[i];
    }

    char** arr = new char* [number_words];


    for (int i = 0; i < number_words; i++) {
        arr[i] = new char[words[i].length()];
    }

    int number_of_vowels = 0;
    int number_of_letters = 0;

    clock_t t1 = clock();

    for (int i = 0; i < number_words; i++) {
        for (int j = 0; j < words[i].length(); j++) {
            arr[i][j] = words[i][j];
            number_of_letters++;
            for (int k = 0; k < 5; k++) {
                if (arr[i][j] == vowels[k]) {
                    number_of_vowels++;

                }
            }
        }
    }
    
    clock_t t2 = clock();


    for (int i = 0; i < number_words; i++) {
        for (int j = 0; j < words[i].length(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    double average_vowels = (double)(number_of_vowels) / number_of_letters;
    int pecent = average_vowels * 100;

    double time = (double)(t2 - t1)/CLOCKS_PER_SEC;

    cout << "chance of seeing a vowel: " <<pecent<<"%" << endl;
    cout << "time it took :" << time << endl;

#pragma endregion

    system("pause");
    return 0;
}
*/
#include <iostream>
#include<omp.h>
#include<vector>
#include<math.h>
#include<ctime>
using namespace std;

int main() {

    char vowels[5] = { 'a', 'i', 'e', 'u', 'h' }; 
    cout << "Enter number of words: ";
    int number_words;
    cin >> number_words;
    string* words = new string[number_words];
    for (int i = 0; i < number_words; i++)
    { 
        cout << "Word number " << i + 1 << ": ";
        cin >> words[i]; 
    
    } 
    char** arr = new char* [number_words];
    for (int i = 0; i < number_words; i++) { 
        arr[i] = new char[words[i].length()];
    }
    int number_of_vowels = 0;
    int number_of_letters = 0;
#pragma omp parallel for reduction(+:number_of_vowels,number_of_letters)
    for (int i = 0; i < number_words; i++) {
        for (int j = 0; j < words[i].length(); j++) {
            arr[i][j] = words[i][j]; 
            number_of_letters++;
            for (int k = 0; k < 5; k++) {
                if (arr[i][j] == vowels[k]) { 
                    number_of_vowels++; } 
            } 
        }
    } 
    for (int i = 0; i < number_words; i++) { 
        for (int j = 0; j < words[i].length(); j++) 
        {
            cout << arr[i][j] << " "; 
        } 
        cout << endl; 
    } 
    double average_vowels = (double)(number_of_vowels) / number_of_letters; 
    int pecent = average_vowels * 100;
    cout << "chance of seeing a vowel: " << pecent << "%" << endl;





    system("pause");
    return 0;
}
