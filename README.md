# 🛫 Airport Management System — C++ OOP Showcase

An educational project demonstrating **Object-Oriented Programming** principles in C++ through the simulation of an **airport system**.  
The system handles flight operations, passenger management, and file-based persistence, highlighting **inheritance and abstraction**.

---

## ✈️ Features
- **Aeropuerto**: main controller class for managing flights and passengers.
- **Vuelo**: abstract base class for different flight types (domestic/international).
- **Pasajero**: polymorphic behavior for passenger types (e.g., VIP, regular).
- **Archivo**: manages I/O operations (`Users.dat`, `vuelos.txt`).

---

## 🧩 Technologies
- **Language:** C++ (Object-Oriented)
- **Concepts:** Inheritance, Encapsulation, Abstraction
- **Data Management:** File I/O with text and binary files

---

## ⚙️ Structure
- Aeropuerto.cpp
- Aeropuerto.h
- Archivo.cpp
- Archivo.h
- Vuelo.cpp
- Vuelo.h
- Pasajero.cpp
- Pasajero.h
- main.cpp
- Users.dat
- vuelos.txt


---

## 🚀 Execution
```bash
g++ main.cpp Aeropuerto.cpp Archivo.cpp Vuelo.cpp Pasajero.cpp -o program.exe
./program.exe
