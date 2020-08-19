#ifndef MAP_H
#define MAP_H

#include <map>


        /**
        * @class Map
        * @brief Encapsulates std::map
        *
        * @author Connor Nicholson
        * @version 01
        * @date 09 Jun 20
        */
template <class Key, class T>
class Map
{
public:
        /**
        * @brief Default constructor
        */
    Map();

        /**
        * @brief Overloaded constructor
        * @param Key and value
        */
    Map(T first, T last);

        /**
        * @brief adds to the map
        * @param the key and the value
        */
    void add(Key key, T value);

        /**
        * @brief gets the value at the specified key
        * @param Key
        * @return the value
        */
    T getAt(Key key);

        /**
        * @brief returns iteratro at begining of map
        * @return iterator at begining of map
        */
    typename std::map<Key, T>::iterator itBegin();

        /**
        * @brief returns iteratro at end of map
        * @return iterator at end of map
        */
    typename std::map<Key, T>::iterator itEnd();

        /**
        * @brief returns current iterator of map
        * @return current iterator of map
        */
    typename std::map<Key, T>::iterator& getIt();

        /**
        * @brief returns size of map
        * @return size of map
        */
    int getSize();

        /**
        * @brief overloaded [] operator
        * @param key
        * @return Reference to map value at key
        */
    T& operator[](Key &&key);

private:
    std::map<Key, T> m_map;
    typename std::map<Key, T>::iterator m_iterator;
};

template <class Key, class T>
Map<Key, T>::Map()
    : m_map(), m_iterator() {}

template <class Key, class T>
Map<Key, T>::Map(T first, T last)
    : m_map(first, last) {}

template <class Key, class T>
void Map<Key, T>::add(Key key, T value)
{
    m_map[key] = value;
}

template <class Key, class T>
T Map<Key, T>::getAt(Key key)
{
    return(m_map.at(key));
}


template <class Key, class T>
typename std::map<Key, T>::iterator Map<Key, T>::itBegin()
{
    return(m_map.begin());
}

template <class Key, class T>
typename std::map<Key, T>::iterator Map<Key, T>::itEnd()
{
    return(m_map.end());
}

template <class Key, class T>
typename std::map<Key, T>::iterator& Map<Key, T>::getIt()
{
    return(m_iterator);
}

template <class Key, class T>
int Map<Key, T>::getSize()
{
    return(m_map.size());
}

template <class Key, class T>
T& Map<Key, T>::operator[](Key &&key)
{
    return(m_map[key]);
}




#endif
