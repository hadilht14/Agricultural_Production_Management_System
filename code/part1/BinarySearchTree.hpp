#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <stack>
#include "Farmer.hpp"

using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr} {}

    struct BinaryNode
    {
        BinaryNode *left;
        BinaryNode *right;
        Farmer element;

        BinaryNode(Farmer &TheFarmer, BinaryNode *lt, BinaryNode *rt) : element(TheFarmer), left(lt), right(rt){};

        // Private member functions for BinaryNode
        BinaryNode *GetLeftNode()
        {
            return left;
        }
        BinaryNode *GetRightNode()
        {
            return right;
        }
        Farmer GetFarmerNode()
        {
            return element;
        }

        void insert(Farmer &x, BinaryNode *&t)
        {
            if (t == nullptr)
            {
                t = new BinaryNode{x, nullptr, nullptr};
            }
            else if (x.GetId() < this->element.GetId())
            {
                insert(x, t->left);
            }
            else if (this->element.GetId() < x.GetId())
            {
                insert(x, t->right);
            }
            else
            {
                return;
            }
        }

        void remove(Farmer &x, BinaryNode *&t)
        {
            if (t == nullptr)
                return;
            if (x.GetId() < this->element.GetId())
                remove(x, t->left);
            else if (this->element.GetId() < x.GetId())
                remove(x, t->right);
            else if (t->left != nullptr && t->right != nullptr) // Two children
            {
                this->element = findMin(t->right)->element;
                remove(this->element, t->right);
            }
            else
            {
                BinaryNode *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }
        }

        bool contains(Farmer &x, BinaryNode *&t)
        {
            if (t == nullptr)
                return false;
            else if (x.GetId() < this->element.GetId())
                return contains(x, t->left);
            else if (this->element.GetId() < x.GetId())
                return contains(x, t->right);
            else
                return true;
        }

        void makeEmpty(BinaryNode *&t)
        {
            if (t != nullptr)
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }

        void printTree(BinaryNode *t, ostream &out) const
        {
            if (t != nullptr)
            {
                printTree(t->left, out);
                out << t->element.GetId();
                out << endl;
                printTree(t->right, out);
            }
        }

        BinaryNode *clone(BinaryNode *t) const
        {
            if (t == nullptr)
                return nullptr;
            else
                return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }

        BinaryNode *findMin(BinaryNode *t) const
        {
            if (t == nullptr)
                return nullptr;
            while (t->left != nullptr)
                t = t->left;
            return t;
        }
    };

    // Copy constructor
    BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }

    // Destructor
    virtual ~BinarySearchTree()
    {
        makeEmpty(root);
    }

    // Public member functions
    bool contains(Farmer &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void printTree() const
    {
        printTree(root, std::cout);
    }

    void insert(Farmer &x)
    {
        insert(x, root);
    }

    void remove(Farmer &x)
    {
        remove(x, root);
    }

    BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty(root);
            root = clone(rhs.root);
        }
        return *this;
    }

    BinarySearchTree *GetLeft()
    {
        root->GetLeftNode();
    }

    BinarySearchTree *GetRight()
    {
        root->GetRightNode();
    }

    BinaryNode *GetRoot()
    {
        return root;
    }

    Farmer GetFarmer()
    {
        root->GetFarmerNode();
    }

    // function to print id and name of farmer of a specific area
    void PrintFarmerByArea(string areaName, int year, int month)
    {
        printFarmersArea(this->GetRootNode(), areaName, year, month);
    }

    // function to print id and name of farmer of a specific city
    void PrintFarmerByCity(string cityName, int year, int month)
    {
        printFarmersCity(this->GetRootNode(), cityName, year, month);
    }

    // function to print id and name of farmer of a specific wilaya
    void PrintFarmerByWilaya(string wilayaName, int year, int month)
    {
        printFarmersWilaya(this->GetRootNode(), wilayaName, year, month);
    }

    // function that inserts a farmer into the binary search tree according to the product produced
    // use a random tree in main to call this function on the farmer to store him in corresponding tree
    void InsertFarmer(Farmer &obj);

    // function that returns root of tree according to the product made by the farmer
    BinarySearchTree *GetProductTreeRoot(const string &product);

private:
    BinaryNode *root;

    BinaryNode *GetRootNode()
    {
        return root;
    }

    // Private member functions for BinarySearchTree
    void insert(Farmer &x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if (x.GetId() < t->element.GetId())
            insert(x, t->left);
        else if (t->element.GetId() < x.GetId())
            insert(x, t->right);
        else
            return;
    }

    void remove(Farmer &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return;
        if (x.GetId() < t->element.GetId())
            remove(x, t->left);
        else if (t->element.GetId() < x.GetId())
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    bool contains(Farmer &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x.GetId() < t->element.GetId())
            return contains(x, t->left);
        else if (t->element.GetId() < x.GetId())
            return contains(x, t->right);
        else
            return true;
    }

    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    void printTree(BinaryNode *t, std::ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element.GetId();
            out << endl;
            printTree(t->right, out);
        }
    }

    // utility function to print all farmers in a specific area
    // handles area repitition by precising which city we are in
    void printFarmersArea(BinaryNode *t, string areaName, int year, int month)
    {
        if (t != nullptr)
        {
            printFarmersArea(t->left, areaName, year, month);
            if (t->element.GetArea() == areaName && t->element.GetMonthlyStat().GetMonth() == month && t->element.GetMonthlyStat().GetYear() == year)
            {
                cout << "Farmer " << t->element.GetId() << ": " << t->element.GetName() << ", " << t->element.GetArea() << ", " << t->element.GetCity() << endl;
            }
            printFarmersArea(t->right, areaName, year, month);
        }
    }

    // utility function to print all farmers in a specific city
    // handles area repitition by precising which wilaya we are in
    void printFarmersCity(BinaryNode *t, string cityName, int year, int month)
    {
        if (t != nullptr)
        {
            printFarmersCity(t->left, cityName, year, month);
            if (t->element.GetCity() == cityName && t->element.GetMonthlyStat().GetMonth() == month && t->element.GetMonthlyStat().GetYear() == year)
            {
                cout << "Farmer " << t->element.GetId() << ": " << t->element.GetName() << ", " << t->element.GetCity() << ", " << t->element.GetWilaya() << endl;
            }
            printFarmersCity(t->right, cityName, year, month);
        }
    }

    void printFarmersWilaya(BinaryNode *t, string wilayaName, int year, int month)
    {
        if (t != nullptr)
        {
            printFarmersWilaya(t->left, wilayaName, year, month);
            if (t->element.GetWilaya() == wilayaName && t->element.GetMonthlyStat().GetMonth() == month && t->element.GetMonthlyStat().GetYear() == year)
            {
                cout << "Farmer " << t->element.GetId() << ": " << t->element.GetName() << ", " << t->element.GetWilaya() << endl;
            }
            printFarmersWilaya(t->right, wilayaName, year, month);
        }
    }

    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        while (t->left != nullptr)
            t = t->left;
        return t;
    }
};

extern BinarySearchTree *Cereals;
extern BinarySearchTree *Vegetables;
extern BinarySearchTree *Fruits;
extern BinarySearchTree *Dates;
extern BinarySearchTree *Olives;