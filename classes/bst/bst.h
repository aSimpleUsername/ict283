// bst.h - binary search tree
// author Connor Nicholson
// 01 Jun 20

#ifndef BST_H
#define BST_H

#include <stdexcept>

        /**
         * @class BST
         * @brief  Binary Search Tree
         *
         *
         * @author Connor Nicholson
         * @version 01
         * @date  01 June 20
         *
         */
template <class T>
class BST
{
public:
        /**
        * @brief default constructor
        */
    BST();

        /**
        * @brief calls deleteSubtree with root as parameter
        */
    ~BST();

        /**
        * @brief calls copyTree
        * @param other BST
        */
    BST(const BST& other);

        /**
        * @brief calls copyTree
        * @param Other BST
        * @return BST reference
        */
    BST<T>& operator=(const BST& other);

        /**
        * @brief calls addLeafPrivate
        * @param Key
        */
    void addLeaf(T key);

        /**
        * @brief calls processInOrderPrivate
        * @param pointer to function that will process data
        */
    void processInOrder(void(*func)(T));

        /**
        * @brief calls processPreOrderPrivate
        * @param pointer to function that will process data
        */
    void processPreOrder(void(*func)(T));

        /**
        * @brief calls processPostOrderPrivate
        * @param pointer to function that will process data
        */
    void processPostOrder(void(*func)(T));

        /**
        * @brief Returns root of tree
        * @return m_key
        */
    T getRootKey();

        /**
        * @brief Finds the smallest node in subtree
        * @return smallest node key
        */
    T findSmallest();

        /**
        * @brief calls deleteNodePrivate
        * @param the node to delete
        */
    void deleteNode(T key);

        /**
        * @brief calls searchKeyPrivate
        * @param the key to search for
        * @return returns true if key in tree
        */
    bool searchKey(T key);      //returns true if found

        /**
        * @brief calls getKeyPrivate
        * @param key to search
        * @return Matching key
        */
    T getKey(T key);

private:
    struct node
    {
        T key;
        node* left;
        node* right;
    };
    node* m_root;

        /**
        * @brief creates a new leaf
        * @param the key of node
        * @return node pointer
        */
    node* createLeaf(T key);

        /**
        * @brief calls create leaf  in the correct place in tree
        * @param Key and node to start recursion
        */
    void addLeafPrivate(T key, node* node_ptr);

        /**
        * @brief processes nodes in order
        * @param note pointer to start recursion and function pointer that will do the processing
        */
    void processInOrderPrivate(node* node_ptr, void(*func)(T));

        /**
        * @brief processes nodes pre order
        * @param note pointer to start recursion and function pointer that will do the processing
        */
    void processPreOrderPrivate(node* node_ptr, void(*func)(T));

        /**
        * @brief processes nodes post order
        * @param note pointer to start recursion and function pointer that will do the processing
        */
    void processPostOrderPrivate(node* node_ptr, void(*func)(T));

        /**
        * @brief finds the smallest node in subtree
        * @param node pointer to start recursion
        * @return key of smalles node
        */
    T findSmallestPrivate(node* node_ptr);

        /**
        * @brief calls correct delete function to maintain tree integrity
        * @param Key to delete and node pointer to start recursion
        */
    void deleteNodePrivate(T key, node* parent_ptr);

        /**
        * @brief searches tree for key
        * @param Key to search for and node pointer to start recursuion
        * @return true if key is found in tree
        */
    bool searchKeyPrivate(T key, node* parent_ptr);

        /**
        * @brief returns matched key, useful for objects
        * @param key to search
        * @return Matching key
        */
    T getKeyPrivate(T key, node* node_ptr);

        /**
        * @brief deletes the root of tree and maintains tree integrity
        * @param key to search
        * @return Matching key
        */
    void deleteRootMatch();

        /**
        * @brief deletes node match if not root
        * @param parent node pointer, matching node pointer, and if the node is left child
        */
    void deleteMatch(node* parent_ptr, node* match_ptr, bool left);  //if bool true, match is left child of parent node, else, right child.

        /**
        * @brief deletes entire subtree under node
        * @param node pointer to start recursion
        */
    void deleteSubtree(node* node_ptr);

        /**
        * @brief coppys tree and ensure deep copy
        * @param node pointer to start recursion
        */
    void copyTree(node* node_ptr);
};

/*******************************************
            IMPLEMTATION
*******************************************/

//constructor
template <class T>
BST<T>::BST()
    : m_root(nullptr) {}

template <class T>
BST<T>::~BST()
{
    deleteSubtree(m_root);
}

template <class T>
BST<T>::BST(const BST& other)
{
    copyTree(other.m_root);
}

template <class T>
BST<T>& BST<T>::operator= (const BST& other)
{
    copyTree(other.m_root);
    return(*this);
}

//creates a new leaf - called when adding data and a node is empty
template <class T>
typename BST<T>::node* BST<T>::createLeaf(T key)
{
    node* newNode = new node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return(newNode);
}

//public method to add leaf - user only needs to know key
template <class T>
void BST<T>::addLeaf(T key)
{
    addLeafPrivate(key, m_root);
}

//private method to add leaf - program knows internal pointers
template <class T>
void BST<T>::addLeafPrivate(T key, node* node_ptr)
{
    if(m_root == nullptr)
    {
        m_root = createLeaf(key);       //if node is empty, a leaf is born
    }
    else if(key < node_ptr->key)        //if key is less than the node it nees to go left
    {
        if(node_ptr->left != nullptr)      //if there's another node there, repeat previous steps
            addLeafPrivate(key, node_ptr->left);
        else
            node_ptr->left = createLeaf(key);      //if node is empty create leaf
    }
    else if(key > node_ptr->key)        //same as above but for the right side
    {
        if(node_ptr->right != nullptr)
            addLeafPrivate(key, node_ptr->right);
        else
            node_ptr->right = createLeaf(key);
    }
    //else
        //std::cout << key << " - DUPLICATE DISCARDED\n";     //not dealing with duplicates - for testing
}

//calls the private function as the user doesn't know about the pointers
template <class T>
void BST<T>::processInOrder(void(*func)(T)) //TODO: change to 'T'
{
    processInOrderPrivate(m_root, func);
}

//In ordr
template <class T>
void BST<T>::processInOrderPrivate(node* node_ptr, void(*func)(T)) //TODO: change to 'T'
{
    if(m_root != nullptr)      //ensures not an empty tree
    {

        if(node_ptr->left != nullptr)      //go down the far left first to be in order
            processInOrderPrivate(node_ptr->left, func);

        func(node_ptr->key);     //process the data left - node - right to be in order

        if(node_ptr->right != nullptr)
            processInOrderPrivate(node_ptr->right, func);
    }
    else
        throw std::out_of_range("TREE EMPTY");
}

//Print pre order
template <class T>
void BST<T>::processPreOrder(void(*func)(T))
{
    processPreOrderPrivate(m_root, func);
}

//Pre-order
template <class T>
void BST<T>::processPreOrderPrivate(node* node_ptr, void(*func)(T))
{
    if(m_root != nullptr)      //ensures not an empty tree
    {
        func(node_ptr->key);     //process the data preOrdr

        if(node_ptr->left != nullptr)
            processPreOrderPrivate(node_ptr->left, func);

        if(node_ptr->right != nullptr)
            processPreOrderPrivate(node_ptr->right, func);
    }
    else
        throw std::out_of_range("TREE EMPTY");
}


//Print post order
template <class T>
void BST<T>::processPostOrder(void(*func)(T))
{
    processPostOrderPrivate(m_root, func);
}

//Post-order
template <class T>
void BST<T>::processPostOrderPrivate(node* node_ptr, void(*func)(T))
{
    if(m_root != nullptr)      //ensures not an empty tree
    {
        if(node_ptr->left != nullptr)      //go down the far left first to be in order
            processPostOrderPrivate(node_ptr->left, func);

        if(node_ptr->right != nullptr)
            processPostOrderPrivate(node_ptr->right, func);

        func(node_ptr->key);     //process the data post
    }
    else
       throw std::out_of_range("TREE EMPTY");
}


template <class T>
T BST<T>::getRootKey()
{
    if(m_root != nullptr)       //make sure it's not an empty tree
        return(m_root->key);
    else
        throw std::out_of_range("TREE EMPTY");
}

template <class T>
T BST<T>::findSmallest()
{
    return(findSmallestPrivate(m_root));        //starts recursion at the root
}

template <class T>
T BST<T>::findSmallestPrivate(node* node_ptr)
{
    if(m_root == nullptr)
        throw std::out_of_range("TREE EMPTY");
    else
    {
        if(node_ptr->left != nullptr)
            return(findSmallestPrivate(node_ptr->left));

        else
            return(node_ptr->key);
    }
}

template <class T>
void BST<T>::deleteNode(T key)
{
    deleteNodePrivate(key, m_root);     //starts recursion at the root
}

template <class T>
void BST<T>::deleteNodePrivate(T key, node* parent_ptr)
{
    if(m_root != nullptr)    //checks if tree empty
    {
        if(key == m_root->key)
            deleteRootMatch();
        else
        {
            if(key < parent_ptr->key && parent_ptr->left != nullptr)                //if key less than current node, and there's a left child
            {
                if(parent_ptr->left->key == key)
                    deleteMatch(parent_ptr, parent_ptr->left, true);     //we found what we want to delete
                else
                    deleteNodePrivate(key, parent_ptr->left);       //continue recursion to find what we're looking for
            }
            else if(key > parent_ptr->key && parent_ptr->right != nullptr)                //if key less than current node, and there's a left child
            {
                if(parent_ptr->right->key == key)
                    deleteMatch(parent_ptr, parent_ptr->right, false);     //same as above but for the right side
                else
                    deleteNodePrivate(key, parent_ptr->right);
            }
            //else
                //std::cout << key << " NOT FOUND\n";
        }
    }
    else
        throw std::out_of_range("TREE EMPTY");
}

template <class T>
bool BST<T>::searchKey(T key)
{
    if(m_root != nullptr)
    {
        if(key == m_root->key)
            return(true);
        else
            return(searchKeyPrivate(key, m_root));     //starts recursion at the root
    }
    else
        return(false);
}

template <class T>
bool BST<T>::searchKeyPrivate(T key, node* node_ptr)
{
    if(key == node_ptr->key)
        return(true);
    else if(key < node_ptr->key)
    {
        if(node_ptr->left != nullptr)
            return(searchKeyPrivate(key, node_ptr->left));
        else
            return(false);
    }
    else if(key > node_ptr->key)
    {
        if(node_ptr->right != nullptr)
            return(searchKeyPrivate(key, node_ptr->right));
        else
            return(false);
    }
    else
        throw std::out_of_range("ERROR: KEY NOT FOUND IN TREE");
}
template <class T>
T BST<T>::getKey(T key)
{
    if(m_root != nullptr)
    {
        if(key == m_root->key)
            return(m_root->key);
        else
            return(getKeyPrivate(key, m_root));     //starts recursion at the root
    }
    else
        throw std::out_of_range("TREE EMPTY");
}

template <class T>
T BST<T>::getKeyPrivate(T key, node* node_ptr)
{
    if(key == node_ptr->key)
    {
        return(node_ptr->key);
    }
    else if(key < node_ptr->key)
    {
        //if(node_ptr->left != nullptr)
            return(getKeyPrivate(key, node_ptr->left));
    }
    else if(key > node_ptr->key)
    {
        //if(node_ptr->right != nullptr)
            return(getKeyPrivate(key, node_ptr->right));
    }
    else
        throw std::out_of_range("ERROR: KEY NOT FOUND IN TREE");
}


template <class T>
void BST<T>::deleteRootMatch()
{
    if(m_root != nullptr)      //check tree empty
    {
        node* delPtr = m_root;
        T smallestInRightSubtree;

        //case 1: 0 children
        if(m_root->left == nullptr && m_root->right == nullptr)
        {
            m_root = nullptr;
            delete delPtr;
        }
        //case 2: 1 child
        else if(m_root->left == nullptr && m_root->right != nullptr)  //only has right child
        {
            m_root = m_root->right;     //right child now root
            delPtr->right = nullptr;
            delete delPtr;      //delete old root
        }
        else if(m_root->left != nullptr && m_root->right == nullptr)  //only has left child
        {
            m_root = m_root->left;     //left child now root
            delPtr->left = nullptr;
            delete delPtr;      //delete old root
        }
        //case 3: 2 children
        else
        {
            //making the smallest node in the right subtree the new root preseves the tree properties
            smallestInRightSubtree = findSmallestPrivate(m_root->right);    //store the smallest in right subtree
            deleteNodePrivate(smallestInRightSubtree, m_root);  //delete the old smallest in right subtree
            m_root->key = smallestInRightSubtree;      //make smallest in old subtree the new root
        }

    }
    else
        throw std::out_of_range("TREE EMPTY");
}

template <class T>
void BST<T>::deleteMatch(node* parent_ptr, node* match_ptr, bool left)
{
    node* delPtr;
    T smallestInRightSubtree;

    //case 1: match node had 0 children
    if(match_ptr->left == nullptr && match_ptr->right == nullptr)
    {
        delPtr = match_ptr; //no children, simple delete
        if(left)
            parent_ptr->left = nullptr;
        else
            parent_ptr->right = nullptr;
        delete delPtr;
    }
    //case 2: match node has 1 child
    else if(match_ptr->left == nullptr  && match_ptr->right != nullptr) // if match only right child
    {
        if(left)
            parent_ptr->left = match_ptr->right;
        else
            parent_ptr->right = match_ptr->right;
        match_ptr->right = nullptr;
        delPtr = match_ptr;
        delete delPtr;
    }
    else if(match_ptr->left != nullptr  && match_ptr->right == nullptr) // if only left child
    {
        if(left)
            parent_ptr->left = match_ptr->left;
        else
            parent_ptr->right = match_ptr->left;
        match_ptr->left = nullptr;
        delPtr = match_ptr;
        delete delPtr;
    }
    //case 3: match node has 2 children
    else
    {
        //replacing node with smallest in right subree preserves tree integrity
        smallestInRightSubtree = findSmallestPrivate(match_ptr->right);
        deleteNodePrivate(smallestInRightSubtree, match_ptr);
        match_ptr->key = smallestInRightSubtree;
    }
}

template <class T>
void BST<T>::deleteSubtree(node* node_ptr)
{
    if(node_ptr != nullptr) //if node not empty
    {
        if(node_ptr->left != nullptr)       //if there are left children
            deleteSubtree(node_ptr->left);
        if(node_ptr->right != nullptr)     //if there are right children
            deleteSubtree(node_ptr->right);

        delete node_ptr;    //deletes when at leaf
        node_ptr = nullptr;
    }
    else
        throw std::out_of_range("TREE EMPTY");
}

template <class T>
void BST<T>::copyTree(node* node_ptr)
{
    if(node_ptr !=  nullptr)        //ensures tree is not emppty
    {
        addLeaf(node_ptr->key);

        if(node_ptr->left != nullptr)       //if there are left children
            copyTree(node_ptr->left);
        if(node_ptr->right != nullptr)      //if there are right children
            copyTree(node_ptr->right);
    }
    else
        throw std::out_of_range("TREE EMPTY");
}




#endif // BST_H
