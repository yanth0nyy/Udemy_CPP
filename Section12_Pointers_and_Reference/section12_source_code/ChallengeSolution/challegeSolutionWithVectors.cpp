// Edited by Ahmed Karrar
//Replacing the static arrays with dynamic vectors (I've replaced them with dynamic arrays in a previous edit too!)

#include <iostream>
#include <vector>
using namespace std;

    int* new_vector (const vector <int> &vec1 , size_t size1 , const vector <int> &vec2 , size_t size2){
    int* result = new int [size1 * size2];
    int position {};
    for (size_t i{0} ; i<size2 ; ++i){
        for (size_t j{0} ; j<size1 ; ++j){
            result [position ++] = vec2[i] * vec1[j];
        }
    }
    return result;
}
void print (const int* vec , size_t size){
    for (size_t i{0} ; i<size ; ++i){
        cout<<vec[i]<<" ";
    }
}


int main (){

 size_t size1,size2;

 cout<<"Enter the size of the fisrt vector: ";
 cin>>size1;
 vector <int> vec1 (size1); 
 cout<<"Enter the elements of the first vector: ";
 for (size_t i{0}; i<size1; ++i){
    cin>>vec1[i];
 }
 cout<<"Enter the size of the second vector: ";
 cin>>size2;
 vector <int> vec2 (size2); 
 cout<<"Enter the elements of the second vector: ";
 for (size_t i{0}; i<size2; ++i){
    cin>>vec2[i];
 }
 //print both vectors
 cout<<"The first vector is: ";
 print (vec1.data() , vec1.size()); //cuz the function print parameters didn't declare vectors
                                    // so, we must pass the vector data to the raw pointer
                                    //However, we can declare it and remove .data() and .size()
 cout<<endl;
cout<<"The second vector is: ";
 print (vec2.data() , vec2.size());
 int* results = new_vector (vec1 , size1 , vec2 , size2);
 cout<<"\nResult: ";
 print (results, size1 * size2);
 delete [] results;

    return 0;
}
