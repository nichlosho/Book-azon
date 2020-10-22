#include <iostream>
#include "BST.h"
#include <string>
#include <fstream>
using namespace std;
/**
 * This is the main class for testing of the BST functionality
 *
 */



/**
 * This Loads the int.dat file
 * @tparam KeyType
 * @param bsti BST object
 */
template<typename KeyType>
void loadINTFile(BST<KeyType> &bsti) {
    char filename[256];
    cout << "Enter integer file: ";
    cin.getline(filename, 256);
    cout << endl;
    int str;
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cout << "File did not open. Try pasting the path name"
             << endl;
        exit(0);
    }
    while (infile >> str) {
        bsti.add(str);
    }
}

/**
 * Testing the creation of the BST object
 */
template<typename KeyType>
void testCreate(BST<KeyType> &bsti) {
    cout << "** CREATE BST **" << endl;
    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;
    cout << endl;
}

/**
 * prints the int bst header
 */
void header() {
    cout << "******************************\n"
            "* INTEGER BINARY SEARCH TREE *\n"
            "******************************" << endl;
    cout << endl;
}

/**
 * Testing the insert functionality of int bst
 */
template<typename KeyType>
void testInsert(BST<KeyType> &bsti) {
    cout << "** TEST INSERT **" << endl;
    cout << "Inserting in this order: 40 20 10 30 60 50 70 " << endl;
    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;
    cout << endl;
}

/**
 * Testing the traversals functionality of int bst
 */
template<typename KeyType>
void testTraversals(BST<KeyType> &bsti) {
    cout << "** TEST TRAVERSALS **" << endl;
    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}

/**
 * Testing the has functionality of int bst
 */
template<typename KeyType>
void testHas(BST<KeyType> &bsti) {
    cout << "** TEST CONTAINS **" << endl;
    cout << "has(20): " << boolalpha << bsti.has(20) << endl;
    cout << "has(40): " << boolalpha << bsti.has(40) << endl;
    cout << "has(10): " << boolalpha << bsti.has(10) << endl;
    cout << "has(70): " << boolalpha << bsti.has(70) << endl;
    cout << "has(99): " << boolalpha << bsti.has(99) << endl;
    cout << "has(-2): " << boolalpha << bsti.has(-2) << endl;
    cout << "has(59): " << boolalpha << bsti.has(59) << endl;
    cout << "has(43): " << boolalpha << bsti.has(43) << endl;
    cout << endl;
}

/**
 * Testing the remove functionality of int bst
 */
template<typename KeyType>
void testRemove(BST<KeyType> &bsti){
    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order: 20 40 10 70 99 -2 59 43" << endl;
    int array[8] = {20,40,10,70,99,-2,59,43};

    for(int num : array){
        bsti.remove(num);
    }

    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;

    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}

/**
 * Testing the insert functionality of int bst (again) after the removals
 */
template<typename KeyType>
void testInsertAgain(BST<KeyType> &bsti){
    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order: 20 40 10 70 99 -2 59 43" << endl;
    int array[8] = {20,40,10,70,99,-2,59,43};
    for(int num : array){
        bsti.add(num);
    }
    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;

    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}
/**
 * Test method to call all other test methods
 */
void testIntBST() {
    header();
    BST<int> bsti;
    testCreate(bsti);
    loadINTFile(bsti);
    testInsert(bsti);
    testTraversals(bsti);
    testHas(bsti);
    testRemove(bsti);
    testInsertAgain(bsti);
}

/**
 * Loads the string file and add into BST
 * @tparam KeyType
 * @param bsti reference to the BST object
 */
template<typename KeyType>
void loadStringFile(BST<KeyType> &bsti) {
    char filename[256];
    cout << "Enter string file: ";
    cin.getline(filename, 256);
    cout << endl;
    string str;
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cout << "File did not open. Try pasting the path name"
             << endl;
        exit(0);
    }
    while (infile >> str) {
        bsti.add(str);
    }
}

/**
 * Testing the insert functionality of string bst
 */
template<typename KeyType>
void testStringInsert(BST<KeyType> &bsti) {
    cout << "** TEST INSERT **" << endl;
    cout << "adding in this order: mary gene bea jen sue pat uma " << endl;
    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;
    cout << endl;
}

/**
 * Testing the traversals functionality of string bst
 */
template<typename KeyType>
void testStringTraversals(BST<KeyType> &bsti) {
    cout << "** TEST TRAVERSALS **\n" << endl;
    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}

/**
 * Testing the has functionality of string bst
 */
template<typename KeyType>
void testStringHas(BST<KeyType> &bsti) {
    cout << "** TEST CONTAINS **" << endl;
    cout << "has(gene): " << boolalpha << bsti.has("gene") << endl;
    cout << "has(mary): " << boolalpha << bsti.has("mary") << endl;
    cout << "has(bea): " << boolalpha << bsti.has("bea") << endl;
    cout << "has(uma): " << boolalpha << bsti.has("uma") << endl;
    cout << "has(yan): " << boolalpha << bsti.has("yan") << endl;
    cout << "has(amy): " << boolalpha << bsti.has("amy") << endl;
    cout << "has(ron): " << boolalpha << bsti.has("ron") << endl;
    cout << "has(opal): " << boolalpha << bsti.has("opal") << endl;
    cout << endl;
}

/**
 * Testing the remove functionality of string bst
 */
template<typename KeyType>
void testStringRemove(BST<KeyType> &bsti){
    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order: gene mary bea uma yan amy ron opal" << endl;
    string array[8] = {"gene", "mary", "bea", "uma", "yan", "amy", "ron", "opal"};

    for(const string& num : array){
        bsti.remove(num);
    }

    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;

    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}

/**
 * Testing the insert functionality of string bst (again)
 */
template<typename KeyType>
void testStringInsertAgain(BST<KeyType> &bsti){
    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order: gene mary bea uma yan amy ron opal" << endl;
    string array[8] = {"gene", "mary", "bea", "uma", "yan", "amy", "ron", "opal"};
    for(const string& num : array){
        bsti.add(num);
    }
    cout << "Number of Nodes:\t" << bsti.size() << endl;
    cout << "Number of leaves:\t" << bsti.getLeafCount() << endl;
    cout << "BST height:\t" << bsti.getHeight() << endl;
    cout << "BST Empty?\t" << boolalpha << bsti.isEmpty() << endl;

    cout << "pre-order:\t" << bsti.getPreOrderTraversal() << endl;
    cout << "in-order:\t" << bsti.getInOrderTraversal() << endl;
    cout << "post-order:\t" << bsti.getPostOrderTraversal() << endl;
    cout << endl;
}

/**
 * test method to call all other test methods
 */
void testStringBST(){
    cout << "********************\n"
            "* test string BST  *\n"
            "********************" << endl;
    BST<string> bsti;
    testCreate(bsti);
    cout << endl;
    loadStringFile(bsti);

    testStringInsert(bsti);
    testStringTraversals(bsti);
    testStringHas(bsti);
    testStringRemove(bsti);
    testStringInsertAgain(bsti);

}

/**
 * main method to call and print results of test methods
 * @return 0
 */
int main() {
    testIntBST();
    testStringBST();
    return 0;
}
