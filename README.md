# GeoCLI

GeoCLI is a command-line computational geometry utility toolkit written in C++.  
It is developed as a **capstone project for a C++ Programming Fundamentals course** and is inspired by the design philosophy of libraries such as CGAL.

The project focuses on **clean structure, validated input, modular design, and reproducible builds**, rather than advanced templates or heavy abstractions.

---

## 📐 Project Goals

- Apply core C++ programming fundamentals in a complete project
- Practice modular, multi-file program structure
- Implement foundational computational geometry algorithms
- Demonstrate proper input validation and error handling
- Understand and use the C++ compilation pipeline (`.cpp → .o → binary`)
- Maintain a clear debugging and error-logging workflow

---

## 🧰 Utility Overview

Each GeoCLI utility follows the same workflow:

**User input → Validation → Geometric computation → Output**

---

### 1️⃣ Distance Between Points

Computes distances between two points in 2D space.

**Inputs**
- Point A: `(x₁, y₁)`
- Point B: `(x₂, y₂)`

#### a) Euclidean Distance
Calculates the straight-line distance between two points:

distance = sqrt((x₂ − x₁)² + (y₂ − y₁)²)


**Use cases**
- Geometric measurements
- Nearest-neighbor queries
- Spatial analysis

---

#### b) Squared Distance
Computes the squared Euclidean distance without using a square root:

distance² = (x₂ − x₁)² + (y₂ − y₁)²


**Why this matters**
- Faster computation
- Avoids unnecessary floating-point operations
- Commonly used in geometry algorithms

---

### 2️⃣ Orientation Test (Geometric Predicate)

Determines the relative orientation of three points.

**Inputs**
- Point A `(x₁, y₁)`
- Point B `(x₂, y₂)`
- Point C `(x₃, y₃)`

---

#### a) Orientation of Three Points
Uses a signed cross product to classify orientation:

value = (x₂ − x₁)(y₃ − y₁) − (y₂ − y₁)(x₃ − x₁)


**Interpretation**
- `value > 0` → Counterclockwise
- `value < 0` → Clockwise
- `value = 0` → Collinear

**Why this matters**
- Core predicate in computational geometry
- Used in convex hulls and intersection algorithms

---

#### b) Point Relative to a Line
Determines whether a point lies:
- to the **left** of a directed line
- to the **right**
- or **on** the line

Optionally computes the perpendicular distance from the point to the line.

---

### 3️⃣ Line Segment Intersection

Determines whether two line segments intersect in 2D.

**Inputs**
- Segment AB
- Segment CD

---

#### a) Intersection Test (Yes / No)
Checks whether the two segments intersect using orientation tests and special collinearity cases.

---

#### b) Intersection Classification
Classifies the type of interaction:
- No intersection
- Proper intersection
- Endpoint touching
- Collinear overlap

**Use cases**
- Collision detection
- Map overlays
- Computational geometry pipelines

---

### 4️⃣ Polygon Tools

Analyzes basic geometric properties of polygons.

**Inputs**
- Number of vertices `n ≥ 3`
- Vertices `(x₀, y₀)…(xₙ₋₁, yₙ₋₁)` in order

---

#### a) Polygon Area (Shoelace Formula)
Computes polygon area using:

area = ½ |Σ (xᵢ yᵢ₊₁ − yᵢ xᵢ₊₁)|


**Applications**
- GIS
- CAD
- Spatial statistics

---

#### b) Polygon Orientation & Perimeter
- Determines clockwise or counterclockwise vertex order
- Computes the polygon perimeter

---

## 🧱 Project Structure

GeoCLI/
├── include/ # Header files
├── src/ # Source files
├── build/ # Compiled binaries (ignored by Git)
├── logs/ # Error and build logs
├── README.md
├── Makefile
└── .gitignore


---

## 🔐 Input Validation

All user input is validated through centralized CLI helper functions:

- `read_int(...)`
- `read_double(...)`
- `read_choice(...)`

This prevents crashes due to invalid input and keeps the code clean and reusable.

---

## 🛠️ Build Instructions

Compile the project from the root directory:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o build/geocli