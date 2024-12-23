# UrbanFlow - Urban Transportation Management System

## 🚀 Project Overview
UrbanFlow is a modern urban transportation management system developed in C++. The project aims to streamline the management of city transit by providing essential features such as adding and managing transit lines, monitoring their status, and handling passenger flow.

---

## 📋 Features
- **Add Transit Lines:** Easily add new transit lines to the system.
- **Monitor Line Status:** View real-time status and capacity of each line.
- **Passenger Management:**
  - Add passengers to specific lines.
  - Remove passengers when they reach their destination.
  - Display current passenger load on each line.
- **System Overview:** Get a detailed overview of the entire transit system, including active lines and passenger distribution.

---

## 🛠️ Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/l6ml6/UrbanFlow.git
   ```
2. Navigate to the project directory:
   ```bash
   cd UrbanFlow
   ```
3. Compile the project:
   ```bash
   g++ -o UrbanFlow main.cpp transit.cpp passenger.cpp
   ```
4. Run the executable:
   ```bash
   ./UrbanFlow
   ```

---

## 📂 Project Structure
```
UrbanFlow/
│
├── src/
│   ├── main.cpp          # Main program logic
│   ├── transit.cpp       # Transit line management
│   ├── transit.h         # Transit line definitions
│   ├── passenger.cpp     # Passenger management
│   └── passenger.h       # Passenger definitions
│
├── README.md             # Project documentation
└── LICENSE               # Project license
```

---

## 🧪 Usage
1. **Adding New Lines:**
   ```
   Enter line name: Metro Line 1
   Line added successfully.
   ```
2. **Adding Passengers:**
   ```
   Enter passenger name: John Doe
   Select line: Metro Line 1
   Passenger added to Metro Line 1.
   ```
3. **Displaying Status:**
   ```
   Metro Line 1 - 45 passengers
   Metro Line 2 - 30 passengers
   ```

---

## 🤝 Contribution
Contributions are welcome! Feel free to submit a pull request or open an issue if you encounter any bugs or have feature requests.

---

## 📜 License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

