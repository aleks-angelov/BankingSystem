# Banking System

### Individual class project for COS221 - Fundamental Data Structures (Fall 2014)

##### Description:  
The goal of the project was to create a simple banking system. The banking system features the two fundamental types of bank accounts – Checking and Savings, as well as two popular derivative sub-types for both basic types – Credit Card and Debit Card Checking Accounts, and Certificate Deposit and Money Market Savings Accounts. All accounts support the operations: showing the current balance; depositing, withdrawing, and transferring of funds. Using the Qt Creator IDE, completing the project required about 40 hours of development.

##### Class profiles:  
The Account class is the base class for all bank accounts. It has instance variables for the account type, the balance, and the International Bank Account Number (IBAN). It also has a pointer to its owner (Customer instance), a method for depositing, and virtual methods for withdrawing and transferring funds. The Checking class has an instance variable for the monthly fee. It also has virtual methods for withdrawing and transferring funds. The Credit Card class has instance variables for the grace period and the annual percentage rate. It also has methods for withdrawing and transferring funds. The Debit Card class has instance variables for the daily transaction limit and the current transaction balance, and for the daily ATM withdrawal limit and the current ATM withdrawal balance. It also has methods for withdrawing and transferring funds. The Savings class has instance variables for the interest rate and the minimum balance requirement. It also has virtual methods for withdrawing and transferring funds. The Certificate Deposit class has instance variables for the deposit term and the withdrawal penalty. It also has methods for withdrawing and transferring funds. The Money Market class has instance variables for the number of allowed transactions per month and the current number of transactions, as well as for the transaction fee. It also has methods for withdrawing and transferring funds. The Customer class has instance variables for the customer’s name, Personal Identification Number (PIN), ID card number, address, and e-mail. It also has a list of pointers to all bank accounts which the customer owns.

##### Class hierarchy:
Here is the class diagram which was generated by Visual Studio 2012:
![Class Diagram](http://gdurl.com/a3Lc)

##### Collections of objects and their functionality:  
The project utilizes two AVL trees – one for all bank accounts and one for all customers. The IBANs serve as keys for the bank account AVL tree and the PINs serve as keys for the customer AVL tree. Both trees are able to perform insertions, removals, and searches.

##### Polymorphism:  
Polymorphic functions are essential for manipulating bank accounts. Both the withdrawal 
function and the transfer function are polymorphic. Polymorphism is also vital to organizing the bank account AVL tree, since it can contain up to six different types of objects at any time.

##### Graphical user interface:  
The project features a full-fledged graphical user interface, which facilitates testing.

##### External source code:  
[AvlTree.h – Prof. Mark Weiss, Florida International University](http://users.cis.fiu.edu/~weiss/dsaa_c++4/code/)

[Qt Framework (version 5.3.2) – The Qt Company](http://www.qt.io/)

