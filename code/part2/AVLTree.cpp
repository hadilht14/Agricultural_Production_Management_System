#include <iostream>
#include "AVLTree.hpp"

using namespace std;

// initializing 5 AVL trees each correspond to a product and each store farmers
AvlTree *Cereals = new AvlTree();
AvlTree *Vegetables = new AvlTree();
AvlTree *Fruits = new AvlTree();
AvlTree *Dates = new AvlTree();
AvlTree *Olives = new AvlTree();

void AvlTree::InsertFarmer(Farmer &obj)
{
    for (int i = 0; i < obj.GetMonthlyStat().GetNumOfProducts(); i++)
    {
        if (obj.GetMonthlyStat().GetProductName() == "cereals" || obj.GetMonthlyStat().GetProductName() == "Cereals")
        {
            Cereals->insert(obj);
            cout << "cereals tree: ";
            Cereals->printTree();
            cout << endl;
        }
        if (obj.GetMonthlyStat().GetProductName() == "dates" || obj.GetMonthlyStat().GetProductName() == "Dates")
        {
            Dates->insert(obj);
            cout << "dates tree: ";
            Dates->printTree();
            cout << endl;
        }
        if (obj.GetMonthlyStat().GetProductName() == "olives" || obj.GetMonthlyStat().GetProductName() == "Olives")
        {
            Olives->insert(obj);
            cout << "olives tree: ";
            Olives->printTree();
            cout << endl;
        }
        if (obj.GetMonthlyStat().GetProductName() == "vegetables" || obj.GetMonthlyStat().GetProductName() == "Vegetables")
        {
            Vegetables->insert(obj);
            cout << "vegetables tree: ";
            Vegetables->printTree();
            cout << endl;
        }
        if (obj.GetMonthlyStat().GetProductName() == "fruits" || obj.GetMonthlyStat().GetProductName() == "Fruits")
        {
            Fruits->insert(obj);
            cout << "fruits tree: ";
            Fruits->printTree();
            cout << endl;
        }
    }
}

AvlTree *AvlTree::GetProductTreeRoot(const string &product)
{
    string lowercaseProduct = product; // Make a copy to avoid modifying the original string
    transform(lowercaseProduct.begin(), lowercaseProduct.end(), lowercaseProduct.begin(), ::tolower);

    if (lowercaseProduct == "cereals")
        return Cereals;
    else if (lowercaseProduct == "vegetables")
        return Vegetables;
    else if (lowercaseProduct == "fruits")
        return Fruits;
    else if (lowercaseProduct == "dates")
        return Dates;
    else if (lowercaseProduct == "olives")
        return Olives;
    else
        return nullptr; // Return nullptr for unknown products
}
