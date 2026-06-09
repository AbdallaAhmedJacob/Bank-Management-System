# Bank Management System (OOP & C++)

> A comprehensive system for managing banking operations and client accounts, built entirely using C++ and applying advanced Object-Oriented Programming (OOP) principles, with local data management and security.

## Table of Contents
- About the Project
- Applied Engineering and Programming Concepts
- Core Technical Features
- Project Structure

## About the Project
An educational project aimed at simulating a real banking system to manage accounts, users, transfers, and currency rates. The project focuses primarily on how to build maintainable and scalable systems by separating user interfaces from the internal business logic, and efficiently managing data in memory.

## Applied Engineering and Programming Concepts
This project focuses on applying the fundamentals of software engineering through:
* **Strict Application of OOP:** Using inheritance concepts (`Inheritance`) where user and client classes inherit from a base human class (`clsPerson`), abstraction (`Abstraction`), and encapsulation (`Encapsulation`).
* **In-Memory Data Management (Memory Management):** Using `std::vector` as a primary tool to store, retrieve, and process data with high speed and efficiency during program execution.
* **Data Persistence & Security:** Storing data in text files (`.txt`), while applying a **Custom Encryption Function** to secure sensitive data (such as passwords) before writing it to files and decrypting it upon reading.
* **Data Validation:** Building a dedicated library (`clsInputValidate`) to ensure no incorrect data is entered that could crash the system, supporting runtime environment stability.

## Core Technical Features

### 1. Clients & Transactions Management System
* Adding, updating, deleting, and searching for clients.
* Executing deposit and withdrawal operations and calculating total balances.
* An integrated financial transfer system between accounts with full logging and documentation of each transfer operation in a dedicated log (`TransferLogRegister.txt`).

### 2. Users & Permissions Management System
* Secure login based on a custom permissions system for each user (admin, employee, etc.).
* Logging users' daily activities and login times in the log file (`LoginRegister.txt`).

### 3. Currency Exchange Management System
* Internal database for currencies, exchange rates, and updating them.
* A smart currency calculator for instant conversions and exchange operations.

## Project Structure
The project is programmatically divided into separate classes performing specific functions for ease of readability and modification (Separation of Concerns):

* **Core Models:** `clsPerson`, `clsUser`, `clsBankClient`, `clsCurrency`.
* **UI Screens:** `clsMainScreen`, `clsLoginScreen`, `clsTransactionsScreen`, `clsCurrencyExchangeScreen` and the rest of the sub-operational screens.
* **Utilities:** `clsUtil`, `clsString`, `clsDate`, `clsInputValidate`.
* **Data Files:** `Clients.txt`, `Users.txt`, `Currencies.txt`, `LoginRegister.txt`, `TransferLogRegister.txt`.
