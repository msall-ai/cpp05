# cpp05 - Repetition and Exceptions

By Fatoumata SALL

## Overview
C++ project focusing on exception handling, inheritance, and polymorphism through a bureaucratic system with forms and bureaucrats.

---

## Exercise Breakdown

### Exercise 00 - Bureaucrat
**Concepts**: Exception handling, custom exceptions, operator overloading

**Description**:
- Creation of a `Bureaucrat` class representing a bureaucrat with a name and a grade (1-150)
- Implementation of custom exceptions: `GradeTooHighException` and `GradeTooLowException`
- Methods to increment and decrement grade with proper validation
- Overload of the output operator (`<<`)

**Files**:
- `Bureaucrat.hpp` - Class definition
- `Bureaucrat.cpp` - Implementation
- `main.cpp` - Test cases

**Key Features**:
- Constant name attribute
- Grade validation (between 1 and 150)
- Exception throwing when grade boundaries are exceeded

---

### Exercise 01 - Form
**Concepts**: Abstract classes, exception handling, bureaucrat interaction

**Description**:
- Creation of a `Form` class representing a form with specific signing and execution grades
- Forms can be signed by bureaucrats if their grade is sufficient
- Implementation of exceptions for grade validation
- Overload of the output operator

**Files**:
- `Form.hpp` / `Form.cpp` - Form class
- `Bureaucrat.hpp` / `Bureaucrat.cpp` - Enhanced Bureaucrat class
- `main.cpp` - Test cases

**Key Features**:
- Form has a name, signing grade, and execution grade
- Bureaucrat can sign forms (`beSigned()` method)
- Validation of bureaucrat's grade before signing

---

### Exercise 02 - Abstract Form
**Concepts**: Abstract classes, polymorphism, inheritance, pure virtual functions

**Description**:
- Creation of an abstract base class `AForm` (replacing Form)
- Implementation of three concrete form types:
  - `PresidentialPardonForm` - Pardons a target
  - `RobotomyRequestForm` - Robotomizes a target
  - `ShrubberyCreationForm` - Creates ASCII art shrubbery
- Each form has specific signing and execution grades
- Execute method that validates bureaucrat grade and executes form action

**Files**:
- `AForm.hpp` / `AForm.cpp` - Abstract form class
- `PresidentialPardonForm.hpp` / `PresidentialPardonForm.cpp`
- `RobotomyRequestForm.hpp` / `RobotomyRequestForm.cpp`
- `ShrubberyCreationForm.hpp` / `ShrubberyCreationForm.cpp`
- `Bureaucrat.hpp` / `Bureaucrat.cpp` - Enhanced with execute method
- `main.cpp` - Test cases

**Key Features**:
- Pure virtual `executeAction()` method in AForm
- Each form implements its specific action
- `execute()` method validates and executes forms
- ShrubberyCreationForm creates ASCII art files

---

### Exercise 03 - Intern
**Concepts**: Factory pattern, polymorphism, object creation

**Description**:
- Creation of an `Intern` class that acts as a factory for creating forms
- Intern can create any of the three form types based on a form name string
- Implements the factory pattern with function pointers
- Throws `FormNotFoundException` for unknown forms

**Files**:
- `Intern.hpp` / `Intern.cpp` - Intern class with factory methods
- `AForm.hpp` / `AForm.cpp` - Abstract form class
- `PresidentialPardonForm.hpp` / `PresidentialPardonForm.cpp`
- `RobotomyRequestForm.hpp` / `RobotomyRequestForm.cpp`
- `ShrubberyCreationForm.hpp` / `ShrubberyCreationForm.cpp`
- `Bureaucrat.hpp` / `Bureaucrat.cpp`
- `main.cpp` - Test cases with Intern usage

**Key Features**:
- `makeForm()` method to dynamically create forms
- Uses function pointers to store form creators
- Exception handling for invalid form types

---

## Compilation & Execution

Each exercise has its own Makefile. To compile:

```bash
cd exXX
make
./bureaucrat
```

---

## Key C++ Concepts Demonstrated

- **Exception Handling**: Custom exception classes with `std::exception`
- **Polymorphism**: Virtual functions and abstract classes
- **Inheritance**: Form hierarchy with abstract base class
- **Factory Pattern**: Dynamic object creation in Intern class
- **Operator Overloading**: Stream insertion operator (`<<`)
- **Const Correctness**: Proper use of const members and methods
- **Memory Management**: Proper construction/destruction and object lifecycle
