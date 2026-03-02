

#  Agricultural Production Management System (APMS)

##  Overview

The **Agricultural Production Management System (APMS)** is a mini-project developed under the supervision of the **Ministry of Higher Education and Scientific Research – People’s Democratic Republic of Algeria**.

The system aims to promote responsible agricultural production by monitoring farmers’ sales, water and electricity consumption, and pesticide usage. Based on performance and sustainability criteria, the system selects winners at different administrative levels (Area, City, Wilaya, and Country).

---

##  Project Objectives

* Manage farmer information efficiently.
* Monitor monthly agricultural production data.
* Detect excessive pesticide use and apply penalties.
* Select winners in different product categories:

  * Fruits
  * Vegetables
  * Cereals
  * Olives
  * Dates
* Compare performance across:

  * Area
  * City
  * Wilaya
  * Country
* Analyze performance differences between **BST** and **AVL Tree** implementations.

---

##  Dataset Description

The system works with three CSV files:

### 1️ FarmerInformation.csv

Contains static farmer data:

* FarmerID
* LastName
* Age
* Gender
* LandID
* Area
* City
* Wilaya

### 2️ MonthlyReport.csv

Contains dynamic monthly data:

* FarmerID
* Number of Helpers
* Product Categories (Fruits, Vegetables, etc.)
* Sales per category
* Water Consumption
* Electricity Consumption
* Month
* Year

### 3️ FarmerLocation.csv

Contains location hierarchy:

* Area
* City
* Wilaya
* Wilaya Code

---

## System Architecture

The project is divided into **two main parts**:

---

###  Part 1: Ministry Interface (Administrative Side)

Includes the following classes:

* **Area**
* **City**
* **Wilaya**
* **Country**

Each level stores its sub-level using **Vectors**:

* City → Vector of Areas
* Wilaya → Vector of Cities
* Country → Vector of Wilayas

These classes allow:

* Finding winners at each level
* Viewing penalties
* Retrieving farmers
* Accessing sales data

---

###  Part 2: Farmer Interface

Includes:

* **Farmer Class**
  Stores constant information (ID, name, age, etc.)

* **MonthlyReport Class**
  Stores dynamic data (sales, water, electricity, penalties)

---

##  Data Structures Used

###  1. Binary Search Tree (BST)

* Used to store farmers.
* FarmerID is used as the key.
* 5 BSTs were created (one per product category).
* Allows efficient searching and structured storage.

---

###  2. AVL Tree

* Self-balancing version of BST.
* Ensures better performance.
* Used to compare execution time with normal BST.

---

###  3. Stack (ADT)

Used to determine winners:

Process:

1. Push first farmer onto stack.
2. Compare each new farmer with top of stack.
3. Replace top if better performance found.
4. Re-compare in case of equal results using:

   * Electricity consumption
   * Pesticide level

Time complexity advantage:

* O(1) push and pop operations.

---

###  4. Vector (ADT)

Used for:

* Storing Areas in a City
* Storing Cities in a Wilaya
* Storing Wilayas in a Country

Chosen to simplify traversal and avoid complex code.

---

##  Winner Selection Process

The competition occurs in **4 stages**:

1. **Area Level**
   Compare all farmers → select Area winner.

2. **City Level**
   Compare Area winners → select City winner.

3. **Wilaya Level**
   Compare City winners → select Wilaya winner.

4. **National Level**
   Compare Wilaya winners → select Country winner.

Criteria:

* Higher sales
* Lower water consumption
* Lower electricity usage
* Acceptable pesticide levels
* Penalties deducted before comparison

---

##  Performance Comparison

| Structure | Running Time |
| --------- | ------------ |
| BST       | 25433 ms     |
| AVL Tree  | 15278 ms     |

###  Conclusion:

AVL Tree performs significantly better due to automatic balancing, making it the preferred structure for consistent performance.

---

##  System Features

* Farmer account creation
* Monthly report submission
* Pesticide level inspection
* Automatic penalty application
* Winner selection at all levels
* Search farmer by ID
* View penalties by Area or City
* Runtime testing module

---

## Team Members

* **KHEFFACHE Semhane**

  * AVL & BST Implementation
  * Data generation
  * Introduction & conclusion

* **HATTABI Hadil**

  * Area/City/Wilaya/Country classes
  * Main implementation
  * Graphical representation
  * Report writing

* **SOUAK Maroua**

  * Administrative classes
  * Runtime testing
  * Debugging

* **MAHFOUDIA Nour el houda Imene**

  * AVL & BST Implementation
  * Farmer & MonthlyReport classes
  * File reading/printing
  * Project linking

---

##  Technologies Used

* C++
* OOP Concepts
* ADTs (Stack, Vector)
* BST & AVL Trees
* CSV File Handling

---

## Key Learning Outcomes

* Implementation of BST and AVL from scratch
* Performance analysis of data structures
* Application of OOP design principles
* Hierarchical data modeling
* Algorithm optimization
* Team collaboration & project structuring

---

##  Conclusion

The Agricultural Production Management System successfully demonstrates how data structures such as BST and AVL Trees can be applied in real-world scenarios.

The comparison between BST and AVL confirmed that AVL trees ensure better runtime stability and efficiency, making them more suitable for scalable systems.

This project highlights the importance of sustainable agricultural management supported by efficient computational design.


