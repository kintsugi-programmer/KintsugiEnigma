## Relational Model

### 🔷 1. Relational Model (RM)

* The Relational Model (RM) organises the data in the form of **relations (tables)**.
* A **relational DB** consists of a **collection of tables**, each of which is assigned a **unique name**.
* A **row** in a table represents a **relationship among a set of values**, and table is a **collection of such relationships**.

---

### 🧾 2. Tuple and Columns

* **Tuple**: A single row of the table representing a **single data point / a unique record**.
* **Columns**: Represents the **attributes** of the relation.

  * For each attribute, there is a permitted value, called the **domain** of the attribute.

---

### 🧩 3. Relation Schema

* **Relation Schema**: Defines the **design and structure** of the relation.

  * Contains the **name of the relation** and all the **columns/attributes**.

---

### 💻 4. Common RM-Based DBMS Systems (RDBMS)

* Oracle
* IBM
* MySQL
* MS Access

---

### 🔢 5. Table Characteristics

| Term            | Meaning                                  |
| --------------- | ---------------------------------------- |
| **Degree**      | Number of attributes/columns in a table  |
| **Cardinality** | Total number of tuples (rows) in a table |

---

### 🔑 6. Relational Key

* Set of attributes which can **uniquely identify each tuple**.

---

### 📋 7. Important Properties of a Table in RM

1. The name of relation is **distinct** among all other relations.
2. The values have to be **atomic** (can’t be broken down further).
3. The name of each attribute/column must be **unique**.
4. Each tuple must be **unique** in a table.
5. The **sequence** of rows and columns has **no significance**.
6. Tables must follow **integrity constraints** — to maintain data consistency across the tables.

---

### 🔐 8. Relational Model Keys

#### ✅ Super Key (SK)

* Any **P\&C (permutation and combination)** of attributes present in a table which can **uniquely identify** each tuple.

#### ✅ Candidate Key (CK)

* **Minimum subset** of super keys that can uniquely identify each tuple.
* Contains **no redundant attribute**.
* **CK value shouldn’t be NULL**.

#### ✅ Primary Key (PK)

* Selected **out of CK set**.
* Has the **least number of attributes**.

#### ✅ Alternate Key (AK)

* All **Candidate Keys except the Primary Key**.

#### ✅ Foreign Key (FK)

* **Creates relation** between two tables.
* A relation, say `r1`, may include among its attributes the **PK of another relation**, say `r2`.

  * This attribute is called the **FK from `r1` referencing `r2`**.
* `r1` is known as the **Referencing (Child) relation**, and `r2` is called the **Referenced (Parent) relation**.
* FK helps to **cross-reference** between two different relations.

#### ✅ Composite Key

* A **PK formed using at least 2 attributes**.

#### ✅ Compound Key

* A **PK formed using 2 FKs**.

#### ✅ Surrogate Key

* **Synthetic PK**.
* Generated automatically by DB, usually an **integer value**.
* May be used as **PK**.

---

### 📊 Comparison Table: Types of Keys

| Key Type      | Uniqueness | Nullable | Based on                      | Special Note                  |
| ------------- | ---------- | -------- | ----------------------------- | ----------------------------- |
| Super Key     | ✅          | ✅        | Any combo of attributes       | May be redundant              |
| Candidate Key | ✅          | ❌        | Minimal Super Key             | No redundancy                 |
| Primary Key   | ✅          | ❌        | Chosen from CK                | Only one per table            |
| Alternate Key | ✅          | ❌        | Remaining CKs                 | Can be declared as UNIQUE     |
| Foreign Key   | ❌          | ✅        | Refers to PK of another table | Ensures referential integrity |
| Composite Key | ✅          | ❌        | 2+ attributes                 | PK with multiple fields       |
| Compound Key  | ✅          | ❌        | 2 FKs                         | Rare case                     |
| Surrogate Key | ✅          | ❌        | Auto-generated                | Often integers                |

---

### 🧩 9. Integrity Constraints

* **CRUD Operations** must follow some **integrity policy** so that DB is always **consistent**.
* Introduced to **prevent accidental corruption** of the DB.

---

#### 🎯 Domain Constraints

* Restricts the **value** in the attribute of relation.
* Specifies the **Domain** (data type, range).
* Example:

  > We want to specify that the **enrolment should happen for candidate birth year < 2002**.

---

#### 🎯 Entity Constraints

* Every relation **should have a PK**.
* **PK != NULL**.

---

#### 🎯 Referential Constraints

* Specified **between two relations**.
* Helps maintain **consistency** among tuples of two relations.
* It requires that the value appearing in specified attributes of any tuple in referencing relation **also appear** in the specified attributes of at least one tuple in the referenced relation.

✅ Rules:

1. If FK in referencing table refers to PK of referenced table, then **every value of FK must be**:

   * Either **NULL**
   * Or **available in referenced table**

---

### 🔒 10. Key Constraints

#### 🔹 NOT NULL

* Restricts the user from having a **NULL value**.
* Ensures that **every element** has a value.

#### 🔹 UNIQUE

* Ensures that **all values in a column are different**.

#### 🔹 DEFAULT

* Used to **set a default value** to the column.
* Applied if **no value is specified** during insertion.

#### 🔹 CHECK

* Ensures that the **integrity of data** is maintained before and after CRUD operations.

#### 🔹 PRIMARY KEY

* An attribute or set of attributes that can **uniquely identify each entity**.
* Must be **NOT NULL** and **UNIQUE**.

#### 🔹 FOREIGN KEY

* Ensures **relationship** between two entities by linking a column from one table to a **PK of another**.
* Prevents **loss of connection** between related tables.

---

### ✅ Takeaway Summary Box

* 🧱 RM is based on **tables**, where rows = tuples and columns = attributes.
* 🔑 Use **Keys** (PK, CK, FK, etc.) to **maintain uniqueness and establish relationships**.
* 🚫 Nulls and duplicates are **restricted by constraints** like PK, NOT NULL, UNIQUE.
* 🔄 **Integrity Constraints** like Domain, Entity, and Referential constraints **ensure data consistency**.
* 🛡️ Keys and constraints prevent **inconsistent or orphan data** across tables.

---

Great! Here's a **code-based SQL example** 🧑‍💻 demonstrating the **Relational Model** concepts you studied — including **Primary Key**, **Foreign Key**, **Composite Key**, **Constraints**, and **Defaults** — using a mini **Student–Course–Enrollment** schema.

---

## 🧱 SQL Table Creation Example

```sql
-- 🎓 STUDENT table
CREATE TABLE Student (
    student_id INT PRIMARY KEY,             -- PK
    name VARCHAR(100) NOT NULL,             -- NOT NULL
    birth_year INT CHECK (birth_year < 2002),  -- CHECK Constraint
    email VARCHAR(100) UNIQUE               -- UNIQUE
);

-- 📘 COURSE table
CREATE TABLE Course (
    course_id VARCHAR(10) PRIMARY KEY,      -- PK
    title VARCHAR(100) NOT NULL,
    credits INT DEFAULT 4                   -- DEFAULT value
);

-- 🧾 ENROLLMENT table (uses Composite Key and FKs)
CREATE TABLE Enrollment (
    student_id INT,                         
    course_id VARCHAR(10),
    enroll_date DATE DEFAULT CURRENT_DATE,
    grade CHAR(1) CHECK (grade IN ('A','B','C','D','F')),

    -- Composite Primary Key
    PRIMARY KEY (student_id, course_id),

    -- Foreign Keys
    FOREIGN KEY (student_id) REFERENCES Student(student_id),
    FOREIGN KEY (course_id) REFERENCES Course(course_id)
);
```

---

## 📌 What This Covers:

| Concept              | Where It's Used                                                        |
| -------------------- | ---------------------------------------------------------------------- |
| **Primary Key (PK)** | `student_id`, `course_id` in respective tables                         |
| **Composite Key**    | `PRIMARY KEY (student_id, course_id)` in `Enrollment`                  |
| **Foreign Key (FK)** | `Enrollment.student_id` → `Student`, `Enrollment.course_id` → `Course` |
| **NOT NULL**         | `Student.name`, `Course.title`                                         |
| **UNIQUE**           | `Student.email`                                                        |
| **CHECK**            | `birth_year < 2002`, `grade IN (...)`                                  |
| **DEFAULT**          | `Course.credits = 4`, `Enrollment.enroll_date = CURRENT_DATE`          |

---

## 💡 ASCII Diagram (Simplified)

```text
+------------+        +-------------+        +---------------+
|  Student   |        |   Course    |        |  Enrollment   |
+------------+        +-------------+        +---------------+
| student_id |◄────┐  | course_id   |◄──┐    | student_id    |
| name       |     └──| title       |   └───►| course_id     |
| birth_year |        | credits     |        | enroll_date   |
| email      |                            ──►| grade         |
+------------+        +-------------+        +---------------+
```

---

Perfect! Let's go step-by-step with all three 🚀

---

## ✅ 1. Sample `INSERT` Queries

### 👤 Insert into `Student`

```sql
INSERT INTO Student (student_id, name, birth_year, email)
VALUES (1, 'Aditi Sharma', 2001, 'aditi@example.com');

INSERT INTO Student (student_id, name, birth_year, email)
VALUES (2, 'Ravi Mehta', 2000, 'ravi@example.com');
```

### 📚 Insert into `Course`

```sql
INSERT INTO Course (course_id, title, credits)
VALUES ('CS101', 'Intro to Programming', 3);

INSERT INTO Course (course_id, title) -- credits will default to 4
VALUES ('MA101', 'Calculus I');
```

### 📝 Insert into `Enrollment`

```sql
INSERT INTO Enrollment (student_id, course_id, grade)
VALUES (1, 'CS101', 'A');

INSERT INTO Enrollment (student_id, course_id, grade)
VALUES (2, 'MA101', 'B');
```

---

## ⚠️ 2. Simulating Constraint Violations

| Constraint Type  | Violation Example                                                                                           | Description                                                 |
| ---------------- | ----------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| **NOT NULL**     | `INSERT INTO Student (student_id, name) VALUES (3, NULL);`                                                  | `name` is NOT NULL — will throw error                       |
| **UNIQUE**       | `INSERT INTO Student (student_id, name, birth_year, email) VALUES (4, 'John', 2001, 'aditi@example.com');`  | `email` already used — violates UNIQUE                      |
| **CHECK**        | `INSERT INTO Student (student_id, name, birth_year, email) VALUES (5, 'Kiran', 2010, 'kiran@example.com');` | `birth_year < 2002` check fails                             |
| **DEFAULT**      | `INSERT INTO Course (course_id, title) VALUES ('PH101', 'Physics I');`                                      | No credits given — DB sets `credits = 4` automatically      |
| **FK Violation** | `INSERT INTO Enrollment (student_id, course_id, grade) VALUES (10, 'CS999', 'A');`                          | No `student_id = 10` or `course_id = 'CS999'` — violates FK |

---

## 🧬 3. ASCII Diagram: Keys & Constraints

```text
  ┌─────────────┐
  │  STUDENT    │
  ├─────────────┤
  │ PK: student_id       ◄──┐
  │ name (NOT NULL)         │
  │ birth_year (CHECK)      │
  │ email (UNIQUE)          │
  └─────────────────────────┘

  ┌─────────────┐
  │  COURSE     │
  ├─────────────┤
  │ PK: course_id        ◄──┐
  │ title (NOT NULL)        │
  │ credits (DEFAULT = 4)   │
  └─────────────────────────┘

  ┌──────────────────────────────┐
  │  ENROLLMENT                  │
  ├──────────────────────────────┤
  │ PK: (student_id, course_id)  │
  │ FK: student_id → STUDENT     │
  │ FK: course_id → COURSE       │
  │ enroll_date (DEFAULT = now)  │
  │ grade (CHECK IN A–F)         │
  └──────────────────────────────┘
```

---

## 💡 Bonus Tip: Safe Insert Order

Always insert in this order to avoid FK violations:

1. **Student**
2. **Course**
3. **Enrollment**

---

