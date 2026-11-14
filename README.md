Name: J K Anjanai

Register Number: 1911260255

Subject: Object-Oriented Programming using C++

Programming Language: C++

Compiler: GCC (g++)

Compiler Version: 

Software Requirements

C++ compiler (GCC)

VS Code / Code::Blocks / any C++ IDE

C++17 standard

Compilation Command

The following command is used to compile each program:

g++ -std=c++17 -Wall -Wextra Task01.cpp -o Task01

Replace Task01 with the respective task filename when compiling other programs.

How to Compile and Run

Open the project folder in VS Code or a terminal.

Open the terminal.

Compile the required program using the g++ command.

Run the generated executable.

Check the output and compare it with the expected result.

Windows:

g++ -std=c++17 -Wall -Wextra Task01.cpp -o Task01

Task01.exe

Linux / macOS:

g++ -std=c++17 -Wall -Wextra Task01.cpp -o Task01
./Task01

Task List and Results

Task 1 – Class Design Review: Diagnose and Repair Duplicated Classes

File: Task01.cpp

Concepts Covered:

Inheritance

Base and derived classes

Protected and private members

Function overriding

UML class diagram

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task01.cpp -o Task01

Result: Successfully redesigned the duplicated classes using a common base class and derived classes, reducing repeated code and making it easier to add new staff categories.

Task 2 – From Requirement to Hierarchy: University People Management

File: Task02.cpp

Concepts Covered:

Multiple inheritance

Virtual base classes

Diamond inheritance problem

Constructor initialization

Inheritance relationships

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task02.cpp -o Task02

Result: Successfully implemented the university people hierarchy using virtual inheritance to avoid duplicate Person objects and ambiguity.

Task 3 – Constructors in Derived Classes and Member Classes

File: Task03.cpp

Concepts Covered:

Base class constructors

Derived class constructors

Member class objects

Constructor initialization lists

Order of construction and destruction

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task03.cpp -o Task03

Result: Successfully demonstrated constructor and destructor execution order in base classes, member objects and derived classes.

Task 4 – Pointers to Derived Classes: Forensics

File: Task04.cpp

Concepts Covered:

Base class pointers

Derived class objects

Virtual destructors

Dynamic memory allocation

Object copying and pointer handling

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task04.cpp -o Task04

Result: Successfully demonstrated safe pointer handling, virtual destructors and correct object management.

Task 5 – Pointers to Objects and the This Pointer

File: Task05.cpp

Concepts Covered:

Object pointers

The this pointer

Pointer arithmetic

Member functions

Returning object references

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task05.cpp -o 

Task05

Result: Successfully implemented the Cart class using object pointers and the this pointer to add items, update discounts and calculate the total amount.

Task 6 – Design Challenge: Vehicle Rental Fleet

File: Task06.cpp

Concepts Covered:

Abstract base classes

Pure virtual functions

Inheritance and polymorphism

Virtual functions

Base class pointer arrays

Function overriding

Compilation Command:

g++ -std=c++17 -Wall -Wextra Task06.cpp -o Task06

Result: Successfully designed a vehicle rental system using an abstract base class and derived vehicle classes. The program supports renting, returning and calculating rental charges for different vehicle types.
