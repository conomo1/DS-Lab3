//
//  Matrix.hpp
//  Lab3 _assignment
//
//  Created by Hazel Zhao on 2023-03-11.
//
#include <iostream>
#include <iterator>
using namespace std;
#ifndef Matrix_hpp
#define Matrix_hpp
#define MAX_COL_SIZE 10


 
class Node
{
public:
    int value;
    Node* next_col;
    Node* next_row;
    
    Node():value(0) , next_col(nullptr) , next_row(nullptr){};
    Node(int val) : value(val), next_row(nullptr), next_col(nullptr) {};
    Node(Node* ptr , int val , Node* next_rowptr):next_row(next_rowptr) , value(val) , next_col(ptr) {};
};

class Matrix
{
private:
    Node* head; //a pointer to the head of the matrix//
    int num_rows;
    int num_cols;
public:
    Matrix();
    Matrix(int array[][MAX_COL_SIZE], int row_size, int col_size);  
    Matrix(const Matrix& copy_m);
    Matrix& operator =(const Matrix& obj);
    Matrix(const Matrix&& obj); 
    Matrix& operator=(const Matrix&& obj);
    ~Matrix();
    void clear();
    Node* getRow(int row_num) const; //throw exception
    Node* getCol(int col_num) const;//throw exception
    Matrix& transpose(); // the user shouldnt be aware of the node type // should the 2d array be passed?// instead//
    Matrix operator+(Matrix obj); //throw exception if row not equal row
    Matrix operator*(Matrix obj); //throw exception if not multiplicable
    friend ostream& operator<<(ostream& output , Matrix& obj);

     
    class MyIterator : public std::iterator<std::forward_iterator_tag  , int>
    {
    private:
        Node* current_node;
        Node* startOfMatrix;
    public:
        MyIterator(Node* some_node , Node* some_head);
        MyIterator& operator++();
        MyIterator operator++(int dummy); //pre post fix
        int& operator*(); //dereference
        int* operator->();
        bool operator ==(const MyIterator& it);
        bool operator !=(const MyIterator& it);
        MyIterator& operator=(const MyIterator& it);
        
       //should consider implementing the allocate function to reuse//
    };
    
};

#endif /* Matrix_hpp */
