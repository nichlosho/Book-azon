//
// Created by Nichlos Ho on 10/17/20.
//

#ifndef PROJECT3_BST_H
#define PROJECT3_BST_H
#include <sstream>
/**
 * @class BST - Binary Search Tree implementation of the Set ADT
 *
 * An element is either in the set or not, solely as determined
 * by the equality operator (operator==). There is no
 * concept in this class of multiple equivalent elements.
 *
 */

template<typename KeyType>
class BST {
public:
    /**
     * Simple constructor creates an empty set.
     */
    BST();

    /**
     * Destructor
     */
    ~BST();

    /**
     * Copy constructor creates a copy of the set.
     * @param other another IntBST to copy
     */
    BST(const BST &other);

    /**
     * Assignment operator.
     * Destroys current set and makes a copy of the rhs set.
     * @param rhs  another IntBST to copy (right-hand side of = expression)
     * @return *this
     */
    BST &operator=(const BST &rhs);

    /**
     * Determine if the given key is currently in this set
     * @param key  possible element of this set
     * @return     true if key is an element, false otherwise
     */
    bool has(KeyType key) const;

    /**
     * Insert a new element into the set.
     * If the element was already in the set, this method does nothing.
     * @param newKey to insert
     * @post has(newKey) is true
     */
    void add(KeyType newKey);

    /**
     * Remove the given key from this set
     *
     * It is irrelevant how many times this key has been added to the set
     * or even if it is currently an element or not.
     * @param key  an element (possibly) of this set
     * @post       has(key) is false
     */
    void remove(KeyType key);

    /**
     * Check if this is an empty set.
     */
    bool isEmpty();

    /**
     * Count the number of elements in this set. This must be implemented recursively
     * and actually count the number of nodes (do not store the size in a data member).
     * @return the total node in the tree
     */
    int size();

    /**
     * Count the number of leaves in this IntBST. Along with size(),
     * this should give some sense of the overall balance.
     * Must use Node::isLeaf and must be implemented recursively.
     */
    int getLeafCount();

    /**
     * Returns height of the BST. The height is the number of levels it contains.
     * An empty BST has a height of 0. A BST with 1 element has the height of 1.
     * @return height of the tree
     */
    int getHeight();

    /**
     * Returns a string of elements in the order specified
     * by the in-order traversal of the BST. Must use recursion.
     * @return string of elements
     */
    std::string getInOrderTraversal();

    /**
     * Returns a string of elements in the order specified by
     * the pre-order traversal of the BST. Must use recursion.
     * @return string of elements
     */
    std::string getPreOrderTraversal();

    /**
     * Returns a string of elements in the order specified by the
     * post-order traversal of the BST. Must use recursion.
     * @return string of elements
     */
    std::string getPostOrderTraversal();

private:
    struct Node {
        KeyType key;
        Node *left, *right;

        // Convenience constructor
        Node(KeyType newKey, Node *lch = nullptr, Node *rch = nullptr) {
            key = newKey;
            left = lch;
            right = rch;
        }

        /**
        * Find the maximum node's value.
        *
        * @return  key of the right-most node in this subtree
        */
        KeyType findMax() const;

        /**
         * Checks if this is a leaf node.
         * @return true if leaf
         */
        bool isLeaf() const;

        /**
         * helper function to count the size of tree
         * @return number of nodes in a tree
         */
        int size(Node *n);
    };

    /**
     * Only data element of IntBST -- the root of the binary search tree.
     */
    Node *root;

    /**
    * Recursive helper method for has.
    * @param me   sub-IntBST in which to look for key
    * @param key  key to search for
    * @return     true if found, false otherwise
    */
    bool has(Node *me, KeyType key) const;

    /**
    * Recursive helper method for add.
    * @param me      sub-IntBST to which to add key
    * @param newKey  key to add
    * @return        me, or if me is nullptr, the new Node with newKey
    */
    Node *add(Node *me, KeyType newKey);

    /**
     * Recursive helper method for remove.
     * @param me   sub-IntBST from which to remove key
     * @param key  key to remove
     * @return     me, or my replacement if I get deleted (could be nullptr
     *             if I'm it and also a leaf)
     */
    Node *remove(Node *me, KeyType key);

    /**
     * Recursive helper method to delete a subtree.
     * @param me the root of the subtree to delete
     */
    void clear(Node *me);

    /**
     * Recursive helper method to copy a subtree.
     * @param me the root of the subtree to copy
     * @return   a fresh copy of the subtree
     */
    Node *copy(Node *me);

    /**
     * Recursive helper method to get the leaf count of a tree
     * @param node the root of the subtree to start counting
     * @return total number of leaf in a tree
     */
    int getLeafCount(Node *node);

    /**
     * Helper function for getInOrderTraversal()
     * @param node
     * @return In order traversal
     */
    std::string getInOrderTraversal(Node *node);

    /**
     * Helper functions for getPreOrderTraversal()
     * @param node
     * @return pre order traversal
     */
    std::string getPreOrderTraversal(Node *node);

    /**
     * Helper function for getPostOrderTraversal()
     * @param node
     * @return post order traversal
     */
    std::string getPostOrderTraversal(Node *node);
    /**
     * Helper function for the getHeight();
     * @param node
     * @return height of the tree
     */
    int getHeight(Node *node);
};

template<typename KeyType>
BST<KeyType>::BST() {
    root = nullptr;
}

template<typename KeyType>
BST<KeyType>::~BST() {
    clear(root);
}

template<typename KeyType>
BST<KeyType>::BST(const BST &other) {
    root = copy(other.root);
}

template<typename KeyType>
BST<KeyType> &BST<KeyType>::operator=(const BST &rhs) {
    if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

template<typename KeyType>
bool BST<KeyType>::has(KeyType key) const {
    return has(root, key);
}

template<typename KeyType>
void BST<KeyType>::add(KeyType newKey) {
    root = add(root, newKey);
}

template<typename KeyType>
void BST<KeyType>::remove(KeyType key) {
    root = remove(root, key);
}

template<typename KeyType>
bool BST<KeyType>::isEmpty() {
    if (root == nullptr)
        return true;
    return false;
}

template<typename KeyType>
int BST<KeyType>::size() {
    return (root->size(root));
}

template<typename KeyType>
int BST<KeyType>::getLeafCount() {
    return getLeafCount(root);
}

//helper private functions
template<typename KeyType>
bool BST<KeyType>::has(BST::Node *me, KeyType key) const {
    if (me == nullptr)
        return false; // not found
    if (key < me->key)
        return has(me->left, key);
    else if (key > me->key)
        return has(me->right, key);
    else  // key == me->key
        return true;
}

template<typename KeyType>
typename BST<KeyType>::Node *BST<KeyType>::add(BST::Node *me, KeyType newKey) {
    if (me == nullptr)
        me = new Node(newKey);
    else if (newKey < me->key)
        me->left = add(me->left, newKey);
    else if (newKey > me->key)
        me->right = add(me->right, newKey);
    return me;
}

template<typename KeyType>
typename BST<KeyType>::Node *BST<KeyType>::remove(BST::Node *me, KeyType key) {
    if (me == nullptr)
        return nullptr;

    if (key < me->key) {
        me->left = remove(me->left, key);
        return me;

    } else if (key > me->key) {
        me->right = remove(me->right, key);
        return me;

    } else {
        if (me->left == nullptr) {
            Node *myReplacement = me->right;
            delete me;
            return myReplacement;

        } else if (me->right == nullptr) {
            Node *myReplacement = me->left;
            delete me;
            return myReplacement;

        } else {
            me->key = me->left->findMax();
            me->left = remove(me->left, me->key);
            return me;
        }
    }
}

template<typename KeyType>
void BST<KeyType>::clear(BST::Node *me) {
    if (me != nullptr) {
        clear(me->left);
        clear(me->right);
        delete me;
    }
}

template<typename KeyType>
typename BST<KeyType>::Node *BST<KeyType>::copy(BST::Node *me) {
    if (me == nullptr)
        return nullptr;
    else
        return new Node(me->key, copy(me->left), copy(me->right));
}

template<typename KeyType>
int BST<KeyType>::getLeafCount(BST::Node *node) {
    if (node == nullptr) {
        return 0;
    } else if (node->isLeaf()) {
        return 1;
    }
    return getLeafCount(node->left) + getLeafCount(node->right);
}

template<typename KeyType>
KeyType BST<KeyType>::Node::findMax() const {
    if (right == nullptr)
        return this->key;
    else
        return right->findMax();
}

template<typename KeyType>
bool BST<KeyType>::Node::isLeaf() const {
    if (right == nullptr && left == nullptr)
        return true;
    return false;
}

template<typename KeyType>
int BST<KeyType>::Node::size(BST::Node *n) {
    if (n == nullptr)
        return 0;

    return size(n->right) + 1 + size(n->left);
}

template<typename KeyType>
int BST<KeyType>::getHeight() {
    return getHeight(root);
}

template<typename KeyType>
std::string BST<KeyType>::getInOrderTraversal() {
    return getInOrderTraversal(root);
}

template<typename KeyType>
std::string BST<KeyType>::getPreOrderTraversal() {
    return getPreOrderTraversal(root);
}

template<typename KeyType>
std::string BST<KeyType>::getPostOrderTraversal() {
    return getPostOrderTraversal(root);
}

template<typename KeyType>
std::string BST<KeyType>::getInOrderTraversal(BST::Node *node) {
    if (node == nullptr)
        return "";

    std::ostringstream ss;
    ss << getInOrderTraversal(node->left);
    ss << node->key << " ";
    ss <<getInOrderTraversal(node->right);
    return ss.str();
}

template<typename KeyType>
std::string BST<KeyType>::getPreOrderTraversal(BST::Node *node) {
    if (node == nullptr)
        return "";
    std::ostringstream ss;
    ss << node->key << " ";
    ss << getPreOrderTraversal(node->left);
    ss << getPreOrderTraversal(node->right);
    return ss.str();
}

template<typename KeyType>
std::string BST<KeyType>::getPostOrderTraversal(BST::Node *node) {
    if (node == nullptr)
        return "";

    std::ostringstream ss;
    ss << getPostOrderTraversal(node->left);
    ss << getPostOrderTraversal(node->right);
    ss << node->key << " ";
    return ss.str();
}

template<typename KeyType>
int BST<KeyType>::getHeight(BST::Node *node) {
    if (node == nullptr)
        return 0;
    else{
        int lHeight = getHeight(node->left) + 1;
        int rHeight = getHeight(node->right) + 1;

        if (lHeight > rHeight){
            return lHeight;
        }else{
            return rHeight;
        }
    }
}

#endif //PROJECT3_BST_H
