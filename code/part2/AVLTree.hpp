#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include "Farmer.hpp"
using namespace std;

class AvlTree
{
public:
    AvlTree() : root{nullptr} {}

    // Copy constructor
    AvlTree(const AvlTree &rhs) : root{nullptr}
    {
        root = clone(rhs.root);
    }

    // Destructor
    virtual ~AvlTree()
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

    AvlTree &operator=(const AvlTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty(root);
            root = clone(rhs.root);
        }
        return *this;
    }
    // dunno if we remove it
    AvlTree *GetLeft()
    {
        root->GetLeftNode();
    }

    AvlTree *GetRight()
    {
        root->GetRightNode();
    }

    Farmer GetFarmer()
    {
        root->GetFarmerNode();
    }

    // function that inserts a farmer into the AVL tree according to the product produced
    // use a random tree in main to call this function on the farmer to store him in corresponding tree
    void InsertFarmer(Farmer &obj);

    // function that returns root of tree according to the product made by the farmer
    AvlTree *GetProductTreeRoot(const string &product);

    struct AvlNode
    {
        AvlNode *left;
        AvlNode *right;
        Farmer element;
        int height;

        AvlNode(Farmer &TheFarmer, AvlNode *lt, AvlNode *rt, int h = 0) : element(TheFarmer), left(lt), right(rt), height(h) {}

        // Private member functions for AvlNode
        AvlNode *GetLeftNode()
        {
            return left;
        }
        AvlNode *GetRightNode()
        {
            return right;
        }
        Farmer GetFarmerNode()
        {
            return element;
        }

        void insert(Farmer &x, AvlNode *&t)
        {
            if (t == nullptr)
            {
                t = new AvlNode{x, nullptr, nullptr};
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

            balance(t);
        }

        void remove(Farmer &x, AvlNode *&t)
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
                AvlNode *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }

            balance(t);
        }

        bool contains(Farmer &x, AvlNode *t)
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

        void makeEmpty(AvlNode *&t)
        {
            if (t != nullptr)
            {
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = nullptr;
        }

        void printTree(AvlNode *t, ostream &out) const
        {
            if (t != nullptr)
            {
                printTree(t->left, out);
                out << t->element.GetId();
                out << endl;
                printTree(t->right, out);
            }
        }

        AvlNode *clone(AvlNode *t) const
        {
            if (t == nullptr)
                return nullptr;
            else
                return new AvlNode{t->element, clone(t->left), clone(t->right), t->height};
        }

        AvlNode *findMin(AvlNode *t) const
        {
            if (t == nullptr)
                return nullptr;
            while (t->left != nullptr)
                t = t->left;
            return t;
        }

        int GetHeight(AvlNode *t) const
        {
            return t == nullptr ? -1 : t->height;
        }

        void rotateWithLeftChild(AvlNode *&k2)
        {
            AvlNode *k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = std::max(GetHeight(k2->left), GetHeight(k2->right)) + 1;
            k1->height = std::max(GetHeight(k1->left), k2->height) + 1;
            k2 = k1;
        }

        void rotateWithRightChild(AvlNode *&k2)
        {
            AvlNode *k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = std::max(GetHeight(k2->left), GetHeight(k2->right)) + 1;
            k1->height = std::max(GetHeight(k1->right), k2->height) + 1;
            k2 = k1;
        }

        void doubleWithLeftChild(AvlNode *&k3)
        {
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        void doubleWithRightChild(AvlNode *&k1)
        {
            rotateWithLeftChild(k1->right);
            rotateWithRightChild(k1);
        }

        void balance(AvlNode *&t)
        {
            if (t == nullptr)
                return;

            if (GetHeight(t->left) - GetHeight(t->right) > ALLOWED_IMBALANCE)
            {
                if (GetHeight(t->left->left) >= GetHeight(t->left->right))
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
            else if (GetHeight(t->right) - GetHeight(t->left) > ALLOWED_IMBALANCE)
            {
                if (GetHeight(t->right->right) >= GetHeight(t->right->left))
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }

            t->height = std::max(GetHeight(t->left), GetHeight(t->right)) + 1;
        }
    };
    AvlNode *GetRoot()
    {
        GetRootNode();
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

private:
    AvlNode *root;

    AvlNode *GetRootNode()
    {
        return root;
    }

    // Private member functions for AvlTree
    void insert(Farmer &x, AvlNode *&t)
    {
        if (t == nullptr)
            t = new AvlNode{x, nullptr, nullptr};
        else if (x.GetId() < t->element.GetId())
            insert(x, t->left);
        else if (t->element.GetId() < x.GetId())
            insert(x, t->right);
        else
            return;

        balance(t);
    }

    void remove(Farmer &x, AvlNode *&t)
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
            AvlNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }

        balance(t);
    }

    bool contains(Farmer &x, AvlNode *t) const
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

    void makeEmpty(AvlNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    void printTree(AvlNode *t, std::ostream &out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element.GetId();
            out << endl;
            printTree(t->right, out);
        }
    }

    AvlNode *clone(AvlNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else
            return new AvlNode{t->element, clone(t->left), clone(t->right), t->height};
    }

    AvlNode *findMin(AvlNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        while (t->left != nullptr)
            t = t->left;
        return t;
    }

    void balance(AvlNode *&t)
    {
        if (t == nullptr)
            return;

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
        {
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
        {
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }

        t->height = std::max(height(t->left), height(t->right)) + 1;
    }

    int height(AvlNode *t) const
    {
        return t == nullptr ? -1 : t->height;
    }

    void rotateWithLeftChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->right), k2->height) + 1;
        k2 = k1;
    }

    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(AvlNode *&k1)
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    static const int ALLOWED_IMBALANCE = 1;

    // utility function to print all farmers in a specific area
    // handles area repitition by precising which city we are in
    void printFarmersArea(AvlNode *t, string areaName, int year, int month)
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
    void printFarmersCity(AvlNode *t, string cityName, int year, int month)
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

    void printFarmersWilaya(AvlNode *t, string wilayaName, int year, int month)
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
};

extern AvlTree *Cereals;
extern AvlTree *Vegetables;
extern AvlTree *Fruits;
extern AvlTree *Dates;
extern AvlTree *Olives;