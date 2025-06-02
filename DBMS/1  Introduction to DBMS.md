## Introduction to DBMS

---

### 📖 **1. What is Data?**

* **Data** is a **collection of raw, unorganized facts** such as text, numbers, figures, symbols, or descriptions.
* By itself, data **lacks meaning** or context.
* It is **measured in bits and bytes** and can be **stored, transmitted, or processed** by computers.
* RAW MATERIAL

📝 Example: `"Robin"`, `42`, or `"blue"` — all are **data points**, but **not useful until processed**.

---

### 🔢 **2. Types of Data**

| **Type**     | **Description**          | **Examples**             |
| ------------ | ------------------------ | ------------------------ |
| Quantitative | Numeric, measurable      | Weight, cost, volume     |
| Qualitative  | Descriptive, not numeric | Name, gender, hair color |

---

### 🧠 **3. What is Information?**

* **Information** is **processed, structured, and meaningful data**.
* It provides **context** and supports **decision-making**.
* Derived from analyzing and interpreting raw data.

🧪 **Example**:
📊 Raw Data: List of residents in a locality
✅ **Information extracted**:

* 👴 100 senior citizens
* ⚖️ Sex ratio: 1.1
* 👶 100 newborn babies

```
+-------------------------------------------+
|                Raw Data                   |
|                                           |
|   BMI        Weight (lbs)    Height (in)  |
|  ------      ------------     ----------  |
|  21.16           112             61       |
|  21.79           135             66       |
|  28.29           213             73       |
+-------------------------------------------+
                  |
                  v
        +----------------------+
        |   Process / Interpret |
        +----------------------+
                  |
                  v
             +----------+
             |  Meaning |
             +----------+
                  |
                  v
          +----------------+
          |  Information   | CONCLUSION
          +----------------+

HELPS IN DESICION MAKING
```
```
Amazon → Product → Feedback
                ↓
           Text (in bytes)
                ↓
          +------------+
          |   Data     |
          +------------+
                ↓
           Process / Analyze
                ↓
          +--------------------+
          |   Information      |
          +--------------------+
                ↓
        ┌─────────────────────────────────────────────┐
        │         Use Cases of Processed Info         │
        │ ┌─────────────────────────────────────────┐ │
        │ │ ① Customer Age Group                    │ │
        │ │ ② Customer Sentiment / Reviews          │ │
        │ │ ③ Customer Recommendation Preferences   │ │
        │ └─────────────────────────────────────────┘ │
        └─────────────────────────────────────────────┘
                            ↓
                  +----------------+
                  |  Stakeholders  |
                  +----------------+
                            ↓
                  +------------------+
                  | Decision-Making  | WHETHER TO INC THE SALES OF PROD OR NOT ?
                  +------------------+

```
---

### 📊 **4. Data vs Information**
-  Data is a collection of facts, while information puts those facts into context.
-  Data points are individual and sometimes unrelated. Information maps out that data to provide a big-picture view of how it all fits together.
-  Data typically comes in the form of graphs, numbers, figures, or statistics. Information is typically presented through words, language, thoughts, and ideas

| **Aspect**      | **Data**                       | **Information**                   |
| --------------- | ------------------------------ | --------------------------------- |
| Nature          | Raw, unorganized facts         | Processed and organized data      |
| Usefulness      | Meaningless on its own         | Meaningful and useful             |
| Dependency      | Independent                    | Depends on data                   |
| Representation  | Numbers, graphs, statistics    | Sentences, summaries, conclusions |
| Decision-making | Cannot directly make decisions | Helps in making decisions         |

```
                 "Data is the new oil" 💡

+---------------------+               +----------------------+
|      Person A       |               |      Person B        |
+---------------------+               +----------------------+
| 🍽  10 Dishes        |               | 🍽  10 Dishes         |
| ❌ No Feedback       |               | ✅ Feedback Collected |
| ❌ No Data Collected |               | ✅ Data Available     |
+---------------------+               +----------------------+

                       ⇩
        Insight: Person B gains advantage through
                feedback → data → improvement 📈

- Now B will inc. raw material of only famous dishes.
- Where A will just buy uniform material
- B have Cost Optimization
- B Put Ads on famous material. Marketing inc.

```

⚠️ **Common Misconception**: Many students think data = information. But information only arises after **processing and context**.

---

### 💾 **5. What is a Database?**

* A **Database** is an **organized collection of data** stored electronically.
* It allows for **easy access, management, and updating** of data.
* Acts as the **foundation** for using any **DBMS**.
* To make real use Data, we need Database management systems. (DBMS)
* 1. it helps store data.
* 2. Then helps in access it.

---

### 🗂️ **6. What is DBMS (Database Management System)?**

* **DBMS** is a **software system/INTERFACE** that manages databases.
* It consists of:

  * **Data** (database itself)
  * **Programs** to **add, access, update, and delete** data.
* Goal: To offer a **convenient and efficient** way to **store and retrieve** data.

👨‍💼 Used in: Banking, Education, Airlines, E-commerce, and more.

```
                   +---------------------+
                   |     Database (DB)   |  <--- stored on disk 💽
                   +---------------------+
                             |
                             v
                        +--------+
                        | DBMS   |  <--- Database Management System
                        +--------+
                             |
        +--------------------+---------------------+ CONNECT THROUGH APIs
        |                    |                     |
        v                    v                     v
    +--------+         +----------+           +--------+
    |  App   |         |   User   |           |  App   |
    +--------+         +----------+           +--------+

```
---

### 📁 **7. DBMS vs File System**
- File system Coding is like Hardcoding stuff, no organisation, no relation, no editing, no appending in schema or functionality, no OOPS, no intelligent, no efficient
- DBMS Coding is complex but gives freedom
- Atomicity, means either full or not; never Partial Transaction.
- Concurrency, Parallel Process handing, Locking, Session Management, etc.
- Security, Rights Control
| **File System Drawbacks**          | **DBMS Advantages** (Solves These)   |
| ---------------------------------- | ------------------------------------ |
| 🔁 Data Redundancy & Inconsistency | Centralized control, less redundancy |
| 🔍 Difficulty in Accessing Data    | Efficient querying and indexing      |
| 🔒 Data Isolation                  | Logical data independence            |
| ⚠️ Integrity Problems              | Constraints and schema enforcement   |
| ❌ Atomicity Issues                 | Transaction management               |
| 🔄 Concurrent Access Anomalies     | Concurrency control                  |
| 🛡️ Security Issues                | Access controls and permissions      |
- All stuff can be included in file system but to code that, it would be toooooooo much hassle
- File system was Primitive Technology 

---

### 📦 **Key Takeaways**

✅ **Data** is unorganized and raw; **Information** is processed and meaningful
✅ Two types of data: **Quantitative** and **Qualitative**
✅ A **Database** stores data in an accessible and manageable format
✅ **DBMS** is a software system that **efficiently manages and manipulates databases**
✅ **DBMS > File Systems** in terms of **security, efficiency, and consistency**
✅ Real-world apps: Banking, Airline bookings, Hospital records, etc.

---

Here are simple **code-based examples** to help you understand the **difference between a File System and a DBMS (Database Management System)**:

---

### 💾 Example of File System

Imagine you store user data in a plain text file:

#### 🧱 File: `users.txt`

```
1, Alice, alice@example.com
2, Bob, bob@example.com
3, Charlie, charlie@example.com
```

#### 🧪 Code: Read users from file (Python)

```python
with open('users.txt', 'r') as file:
    for line in file:
        user_id, name, email = line.strip().split(', ')
        print(f"ID: {user_id}, Name: {name}, Email: {email}")
```

#### ⚠️ Limitations:

* No way to enforce constraints (e.g. unique emails)
* No efficient search or filtering
* Data integrity not guaranteed
* No concurrency control

---

### 🗃️ Example of DBMS (e.g. SQLite)

Here we store the same user data in a **SQLite database**.

#### 🧱 SQL Schema

```sql
CREATE TABLE users (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL
);
```

#### 🧪 Code: Insert and query users (Python + SQLite)

```python
import sqlite3

## Connect to database (or create it)
conn = sqlite3.connect('users.db')
cur = conn.cursor()

## Create table
cur.execute('''CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL
)''')

## Insert data
cur.execute("INSERT INTO users (name, email) VALUES (?, ?)", ("Alice", "alice@example.com"))
cur.execute("INSERT INTO users (name, email) VALUES (?, ?)", ("Bob", "bob@example.com"))
conn.commit()

## Query data
cur.execute("SELECT * FROM users")
for row in cur.fetchall():
    print(row)

conn.close()
```

#### ✅ Advantages:

* Enforces **uniqueness**, **constraints**
* Powerful **query language** (SQL)
* Supports indexing, transactions, multi-user access
* More scalable and reliable than file systems for structured data

---

### 🧠 Summary Table

| Feature       | File System            | DBMS (SQLite)                 |
| ------------- | ---------------------- | ----------------------------- |
| Data Access   | Manual (line-by-line)  | Query via SQL                 |
| Relationships | Not supported          | Supports joins, foreign keys  |
| Concurrency   | Difficult to manage    | Built-in support              |
| Constraints   | Not supported          | Enforced via schema           |
| Performance   | Slower with large data | Faster with indexing/querying |

---

Would you like MongoDB vs File System next (NoSQL example)?
