// vector.h - Simple Vector class
// author Connor Nicholson
// 28 Apr 20

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>


        /**
         * @class Vector
         * @brief  Vector class (dynamic array)
         *
         *
         * @author Connor Nicholson
         * @version 03
         * @date 9 Jube 20
         *
         */
template <class T>
class Vector
{
public:
        /**
         * @brief default constructor
         */
    Vector();

        /**
        * @brief copy constructor
        * @param Vector
        */
    Vector(const Vector& other);

        /**
         * @brief Destructor
         */
    ~Vector();

        /**
        *@brief gets the current size of the array
        *@return the size of the array
        */
    int getSize() const;

        /**
        *@brief adds data to the end of array
        *@param new data
        */
    void push(T data);

        /**
        *@brief adds data to specific index
        *@param new data, index for data to be pushed
        */
    void push(T data, int index);

        /**
        *@brief Empties vector
        */
    void clearVector();

        /**
        *@brief increases the array size
        */
    void grow();

        /**
        *@brief prints the contents, current size and capacity of array. Used for testing and debugging
        */
    void print();

        /**
        *@brief overloaded [] operator
        *@param index
        *@return refence to element at that index
        */
    T& operator[](unsigned int index);

        /**
        *@brief overloaded = operator
        *@param other Vector
        *@return Vector reference
        */
    const Vector& operator=(const Vector& other);


private:
    std::vector<T> m_vector;
};


//implementation

template <class T>
Vector<T>::Vector()
    : m_vector() {}


template <class T>
Vector<T>::~Vector() {}

template <class T>
Vector<T>::Vector(const Vector& other)
    : m_vector(other.m_vector) {}

template <class T>
int Vector<T>::getSize() const {return(m_vector.size());}

template <class T>
void Vector<T>::push(T data)
{
    m_vector.push_back(data);
}

template <class T>
void Vector<T>::push(T data, int index)
{
    m_vector.insert(index, data);
}

template <class T>
void Vector<T>::clearVector()
{
    m_vector.clear();
}

template <class T>
T& Vector<T>::operator [](unsigned int index)   //returns by reference to be used for assignment and retrieval
{
    if(index > m_vector.size())
    {
        //std::cout << "ERROR: Array out of bounds";
        exit(-1);
    }
    else if(index == m_vector.size())     //if index == current size, likely they are tryint to push new elements
    {
        m_vector.resize(m_vector.size()+1);
        return(m_vector[index]);
    }
    else
        return(m_vector[index]);
}

template <class T>
const Vector<T>& Vector<T>::operator =(const Vector &other)
{
    m_vector = other.m_vector;
    return(*this);
}


//for testing
/*template <class T>
void Vector<T>::print()
{
    for(int i=0; i<m_cur; i++)
        std::cout << m_arr[i] << ", ";
    std::cout << std::endl;
    std::cout << "Current array size is: " << m_cur << std::endl;
    std::cout << "array capacity is: " << m_cap << std::endl;
}*/

#endif // VECTOR_H
