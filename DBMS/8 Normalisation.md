

## Normalisation

#### ✅ 1. Normalisation is a step towards DB optimisation.

---

### 🔗 2. Functional Dependency (FD)

#### 🔍 Definition:

* It's a relationship between the **primary key attribute** (usually) of the relation to that of the other attribute of the relation.

📌 Example Notation: `X → Y`

* **X** (left side) is called the **Determinant**
* **Y** (right side) is the **Dependent**

---

#### 🔢 3. Types of Functional Dependencies

##### 🟩 Trivial FD

* A → B has **trivial functional dependency** if **B is a subset of A**
* Also examples:

  * A → A ✅
  * B → B ✅

##### 🟥 Non-trivial FD

* A → B has **non-trivial functional dependency** if **B is not a subset of A**
* Formally: `A ∩ B = ∅`

---

### 📐 4. Rules of FD (Armstrong’s Axioms)

#### 📏 1. Reflexive Rule

* If **A** is a set of attributes and **B** is a subset of **A**, then:

```text
A ⊇ B ⇒ A → B
```

#### ➕ 2. Augmentation Rule

* If B can be determined from A, then adding an attribute **X** to both sides won’t change anything:

```text
If A → B then AX → BX
```

#### 🔁 3. Transitivity Rule

* If A determines B and B determines C, then A determines C:

```text
If A → B and B → C then A → C
```

---

### ❓ 3. Why Normalisation?

* To avoid **redundancy** in the DB.
* Aim: **Not to store redundant data**.

---

### ⚠️ 4. What happens if we have redundant data?

* **Insertion**, **Deletion**, and **Updation** anomalies arise.

---

### 🚨 5. Anomalies

#### 🔎 Anomalies = Abnormalities

* Caused by **data redundancy**

---

#### 1️⃣ Insertion Anomaly

* When certain data (attribute) **cannot be inserted** into the DB **without the presence of other data**

---

#### 2️⃣ Deletion Anomaly

* When deleting some data causes **unintended loss** of other important data

---

#### 3️⃣ Updation (Modification) Anomaly

* Updating a single value requires **modification in multiple rows**
* Can lead to **data inconsistency** if one forgets to update everywhere

---

📉 **Impact**:

* Increased DB size
* Slower DB performance

✅ **Solution**: Use **Database Optimisation** → **NORMALISATION**

---

### 🔧 6. What is Normalisation?

* Used to **minimise redundancy** from relations
* Eliminates:

  * Insertion Anomalies
  * Update Anomalies
  * Deletion Anomalies

#### 🧱 How?

* **Divides composite attributes** into individual attributes
* **Breaks larger tables** into smaller tables and **links** them via relationships

#### 🎯 Purpose:

* Normal Forms are used to reduce redundancy

---

### 🧮 7. Types of Normal Forms (NFs)

#### ✅ 1NF – First Normal Form

* Every **relation cell** must have an **atomic value**
* Must **not have multi-valued attributes**

```sql
-- Example of 1NF violation
Student(Name, Phone) -- Phone = {987654, 123456} ❌

-- Fixed for 1NF
Student(Name, Phone)
('Alex', 987654)
('Alex', 123456)
```

---

#### ✅ 2NF – Second Normal Form

* Relation must be in **1NF**
* No **partial dependency**

📌 Rules:

* All **non-prime attributes** must be **fully dependent** on **Primary Key**
* **Non-prime attribute** must not depend on part of composite PK

```text
If PK = {A, B}, then C must depend on both A & B
```

---

#### ✅ 3NF – Third Normal Form

* Relation must be in **2NF**
* **No transitive dependency**

📌 Rule:

* A **non-prime attribute** should **not determine another non-prime attribute**

```text
If A → B and B → C, then A → C is transitive (not allowed)
```

---

#### ✅ BCNF – Boyce-Codd Normal Form

* Must be in **3NF**
* For every FD: `A → B`, **A must be a super key**

📌 Note:

* We must not derive **prime attribute** from **any prime or non-prime** attribute

---

#### 📊 Comparison Table of Normal Forms

| Normal Form | Key Rule                      | Disallows               | Requirement        |
| ----------- | ----------------------------- | ----------------------- | ------------------ |
| 1NF         | Atomic values only            | Multivalued attributes  | All columns atomic |
| 2NF         | Full functional dependency    | Partial dependencies    | Must be in 1NF     |
| 3NF         | No transitive dependency      | Transitive dependencies | Must be in 2NF     |
| BCNF        | Determinant must be super key | All anomalies           | Must be in 3NF     |

---

### 🌟 8. Advantages of Normalisation

* ✅ Helps to **minimise data redundancy**
* ✅ Enables **greater database organisation**
* ✅ Maintains **data consistency**

---

### 🔚 Summary ASCII Flow

```text
Data Redundancy
      ↓
 Anomalies (Insert, Delete, Update)
      ↓
 Slow DB Performance + Inconsistency
      ↓
      Use Normalisation
      ↓
  Split Tables, Remove FD Issues
      ↓
  ⬆️ Consistency ⬇️ Redundancy
```

---

Let me know if you'd like:

* ✅ SQL code examples for 2NF/3NF transformation
* ✅ Real-life case study (like Student–Course DB)
* ✅ A printable PDF version of this note

Would you like the next lecture in the same format too?
Perfect! Let’s now add both:

---

## 💻 ✅ SQL Code Examples for 2NF & 3NF Transformation

### 🧩 **Case: A table in 1NF but not in 2NF**

Suppose we have a relation:

```sql
Student_Course(StudentID, CourseID, StudentName, CourseName, InstructorName)
```

* 🔑 Composite Primary Key: `(StudentID, CourseID)`
* ❌ Problem: `StudentName` depends only on `StudentID`, not `CourseID`
* ❌ Also, `CourseName`, `InstructorName` depend only on `CourseID`

---

### 🧮 **Step 1: Already in 1NF**

* No multivalued attributes ✅
* All atomic values ✅

---

### 🔁 **Step 2: Convert to 2NF (Remove Partial Dependencies)**

**Split into multiple tables:**

```sql
-- Student Table
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50)
);

-- Course Table
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    InstructorName VARCHAR(50)
);

-- Enrollment Table (Junction table)
CREATE TABLE Enrollments (
    StudentID INT,
    CourseID INT,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);
```

📌 Now:

* `StudentName` depends only on `StudentID` ✅
* `CourseName`, `InstructorName` depend only on `CourseID` ✅

---

### 🔁 **Step 3: Convert to 3NF (Remove Transitive Dependencies)**

Let’s say we find:

```text
CourseID → InstructorID
InstructorID → InstructorName
```

That’s a transitive dependency: `CourseID → InstructorName`

---

### ✅ Final 3NF Schema

```sql
-- Instructors Table
CREATE TABLE Instructors (
    InstructorID INT PRIMARY KEY,
    InstructorName VARCHAR(50)
);

-- Updated Courses Table
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    InstructorID INT,
    FOREIGN KEY (InstructorID) REFERENCES Instructors(InstructorID)
);
```

---

## 📚 Real-Life Case Study: Student–Course DB

### 💡 Original Flat Table (Unnormalized / 1NF)

| StudentID | StudentName | CourseID | CourseName | InstructorName |
| --------- | ----------- | -------- | ---------- | -------------- |
| 1         | Alice       | C1       | DBMS       | Prof. Roy      |
| 1         | Alice       | C2       | OS         | Prof. Gupta    |
| 2         | Bob         | C1       | DBMS       | Prof. Roy      |

### ❌ Problems:

* Redundancy of `StudentName`, `CourseName`, `InstructorName`
* Insert/Delete/Update anomalies

---

### ✅ 3NF Final Design:

#### 📋 Students

| StudentID | StudentName |
| --------- | ----------- |
| 1         | Alice       |
| 2         | Bob         |

#### 📋 Courses

| CourseID | CourseName | InstructorID |
| -------- | ---------- | ------------ |
| C1       | DBMS       | I1           |
| C2       | OS         | I2           |

#### 📋 Instructors

| InstructorID | InstructorName |
| ------------ | -------------- |
| I1           | Prof. Roy      |
| I2           | Prof. Gupta    |

#### 📋 Enrollments

| StudentID | CourseID |
| --------- | -------- |
| 1         | C1       |
| 1         | C2       |
| 2         | C1       |

---

### 🔐 Benefits in Practice:

| Problem         | Solved by | How?                                    |
| --------------- | --------- | --------------------------------------- |
| Redundant data  | 2NF       | Split by dependency on full PK          |
| Transitive dep. | 3NF       | Created Instructor table                |
| Insert anomaly  | 2NF–3NF   | Add course without student              |
| Delete anomaly  | 2NF–3NF   | Delete enrollment without losing course |
| Update anomaly  | 3NF       | Instructor name updated in one place    |

---

Let me know if you’d like:

* 🔁 Transformation to BCNF for this case
* 📈 Normalisation diagrams (ER → Table form)
* 📄 PDF export of this whole guide
* 💥 MCQs/Practice questions based on this example

Would you like to continue with **LEC-12** next?
Absolutely! Let's cover both:

---

## 🔁 **BCNF Transformation for Student–Course Case**

### 🔁 Reminder: BCNF Rule

For every functional dependency `X → Y`,
✅ `X` must be a **superkey**.

---

### ⚠️ Violation in 3NF Design (Hypothetical Case)

Suppose in the `Courses` table we had:

```text
InstructorName → CourseName
```

🔍 This means: Instructor uniquely teaches one Course. But:

* **InstructorName is not a superkey**, yet it determines another attribute.
* ❌ This violates **BCNF**.

---

### ✅ BCNF Fix

We must decompose the table such that **all determinants are superkeys**.

### 🔧 Step-by-Step Fix:

#### Existing Table:

```sql
Courses(CourseID, CourseName, InstructorName)
```

#### Problem FD:

```text
InstructorName → CourseName
```

#### ✂️ Split Tables:

```sql
-- Instructors teach unique courses
CREATE TABLE InstructorCourse (
    InstructorName VARCHAR(50) PRIMARY KEY,
    CourseName VARCHAR(50)
);

-- Course Info now references Instructor
CREATE TABLE Courses (
    CourseID VARCHAR(10) PRIMARY KEY,
    InstructorName VARCHAR(50),
    FOREIGN KEY (InstructorName) REFERENCES InstructorCourse(InstructorName)
);
```

🎯 Now:

* `InstructorName` is a superkey in `InstructorCourse` ✅
* BCNF is satisfied

---

## 📈 Normalisation Diagrams (ER → Table Conversion)

Let’s use a simple **ER Diagram** for:

### 🧠 Scenario: Student Enrolls in Course Taught by Instructor

```text
         +------------+        +-------------+       +-------------+
         |  Student   |        |   Enrolls   |       |   Course    |
         |------------|        |-------------|       |-------------|
         | ID (PK)    |<------>| StudentID   |       | ID (PK)     |
         | Name       |        | CourseID    |<----->| Name        |
         +------------+        +-------------+       | Instructor  |
                                                     +-------------+
```

---

### 📥 Conversion to Tables (Normalized Form)

| Entity / Relation | Table Structure                               |
| ----------------- | --------------------------------------------- |
| **Student**       | `Student(StudentID PK, StudentName)`          |
| **Course**        | `Course(CourseID PK, CourseName, Instructor)` |
| **Enrolls**       | `Enrollment(StudentID FK, CourseID FK)`       |
| (If BCNF applied) | Instructor split as separate table            |

---

### 📊 ASCII Table Mapping Summary

```text
Entity             → Table
-----------------------------------------------
Student(ID, Name)  → Student(StudentID, StudentName)
Course(ID, Name)   → Course(CourseID, CourseName, InstructorName)
Enrolls            → Enrollment(StudentID, CourseID)

If BCNF:
InstructorName → CourseName 
⇒ InstructorCourse(InstructorName PK, CourseName)
```

---

## ✅ Summary of All Normalisation Steps

| Step | Action                         | Goal                       | Anomalies Solved         |
| ---- | ------------------------------ | -------------------------- | ------------------------ |
| 1NF  | Remove multivalued/composite   | Atomic cells               | Insert, Search anomalies |
| 2NF  | Remove partial dependencies    | Full functional dependence | Insert, Update           |
| 3NF  | Remove transitive dependencies | All non-prime ↛ non-prime  | Update anomaly           |
| BCNF | Superkey on all LHS of FDs     | Full lossless dependency   | All redundancy risks     |

---

Let me know if you want:

* 📄 A 1NF → BCNF flow visual
* 📝 Practice MCQs based on this schema
* 📘 PDF export of this complete Normalisation guide
* 🧠 ERD-to-SQL exercises with solutions

Ready to move to **LEC-12** or continue building practice sets from LEC-11?
Here’s a 📄 **1NF → BCNF Flow Visual** using clean **ASCII diagrams** that walk you through each step of normalization:

---

## 📊 **Normalization Flow: 1NF → BCNF**

```text
┌────────────┐
│  UNF       │
│ Unnormalized│
│  Table      │
└────┬───────┘
     │ Remove multivalued attributes
     ▼
┌────────────┐
│   1NF      │
│ Atomic values only │
└────┬───────┘
     │ Remove partial dependencies
     ▼
┌────────────┐
│   2NF      │
│ Full dependency on PK │
└────┬───────┘
     │ Remove transitive dependencies
     ▼
┌────────────┐
│   3NF      │
│ No non-prime → non-prime FD │
└────┬───────┘
     │ Ensure all LHS of FDs are superkeys
     ▼
┌────────────┐
│   BCNF     │
│ All FDs: LHS is superkey │
└────────────┘
```

---

## 🎯 **Explanation for Each Step**

| Stage    | Key Focus                        | Fixes                             |
| -------- | -------------------------------- | --------------------------------- |
| **UNF**  | Multi-valued or composite values | Start here                        |
| **1NF**  | Atomic values only               | Removes repeating groups          |
| **2NF**  | Remove partial dependencies      | Each attribute depends on full PK |
| **3NF**  | Remove transitive dependencies   | Only direct dependencies allowed  |
| **BCNF** | LHS of each FD must be superkey  | Stronger than 3NF                 |

---

## 💡 Visual Example:

Imagine we start with:

```text
Student(StudentID, StudentName, CourseID, CourseName, InstructorName)
```

### 🔁 Transformation:

```text
UNF ➝ 1NF     ➝ 2NF             ➝ 3NF              ➝ BCNF
      ↓             ↓                   ↓                  ↓

Atomic     Remove partial    Remove transitive     Ensure all LHS
Values     dep: Course info  dep: Instructor info   are superkeys
           in separate table in separate table      InstructorName → CourseName
```

---

Would you like me to generate this as a **graphical PNG/diagram** image too (for your notes or print)?
Also, shall I bundle the entire Normalisation Guide with this visual into a **single PDF**?
