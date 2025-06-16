

## 📚 Types of Databases

---

### 1️⃣ Relational Databases 🗃️

1. Based on **Relational Model**.
2. Relational databases are quite popular, even though it was a system designed in the 1970s. Also known as **Relational Database Management Systems (RDBMS)**, relational databases commonly use **Structured Query Language (SQL)** for operations such as creating, reading, updating, and deleting data.

   * Relational databases store information in **discrete tables**, which can be **JOINed** together by fields known as **foreign keys**.
   * For example, you might have a `User` table which contains information about all your users, and join it to a `Purchases` table, which contains information about all the purchases they’ve made.
   * Examples: `MySQL`, `Microsoft SQL Server`, `Oracle`.
3. ✅ They are **ubiquitous**, having acquired a steady user base since the 1970s.
4. ✅ Highly optimised for working with **structured data**.
5. ✅ Provide a stronger guarantee of **data normalisation**.
6. ✅ Use a well-known querying language through **SQL**.
7. ⚠️ Scalability issues (**Horizontal Scaling**).
8. ⚠️ When data becomes huge, the system becomes **more complex**.

---

### 2️⃣ Object Oriented Databases 🧱

1. The **Object-Oriented Data Model** is based on the **object-oriented programming (OOP)** paradigm.

   * Key concepts: **Inheritance**, **Object Identity**, **Encapsulation (Information Hiding)**, and **Methods**.
   * Supports rich type systems including structured and collection types.
   * Encapsulation and object-identity **distinguish** this model from the Entity-Relationship (E-R) model.
2. ⚠️ For very **complex databases**, maintaining relationships becomes **tedious**.

#### 🧩 Characteristics:

* In Object-Oriented Databases, **data is treated as an object**.
* All information comes in **one instantly available object package** instead of multiple tables.

#### ✅ Advantages:

1. Data storage and retrieval is **easy and quick**.
2. Handles **complex data** and a **variety of types**.
3. **Real-world modeling** becomes intuitive.
4. **Works well** with OOP-based programming languages.

#### ❌ Disadvantages:

1. High complexity can cause **performance issues** (read/write/update/delete).
2. Limited **community support** compared to relational databases.
3. Does **not support views** like RDBMS.

#### 🔧 Examples:

* `ObjectDB`, `GemStone`, etc.

---

### 3️⃣ NoSQL Databases 📦

1. **NoSQL** (Not Only SQL) databases are **non-tabular** and store data differently than relational tables.
2. Schema-free 📄
3. More **flexible data structures** (not tabular), can adjust dynamically.
4. Handles **large-scale data** (Big Data).
5. Most are **open-source** and support **horizontal scaling**.
6. Stores data in **formats other than relational**.
7. Refer **LEC-15 notes** for more.

---

### 4️⃣ Hierarchical Databases 🌲

1. Suited for data with a **clear hierarchy**, e.g., employees reporting to a department.

2. Uses a **tree-like structure**, with root (parent) → branches (child).

3. **One-to-many**:

   * One parent can have many children
   * But **each child has only one parent**

4. ⚙️ Works well with disk storage systems (also hierarchical).

5. ✅ **Fast and simple** data traversal — great for:

   * Website dropdowns
   * File systems (like Windows OS folders)

6. ❌ Limitations:

   * Inflexible — can’t model many-to-many relationships
   * **Sequential tree traversal** required
   * Redundant data storage

#### 🔧 Example:

* `IBM IMS`

---

### 5️⃣ Network Databases 🌐

1. Extension of **Hierarchical Databases**
2. Allows **child records to have multiple parent records** (many-to-many supported).
3. Organised using a **graph structure**
4. ✅ Can handle **complex relationships**
5. ❌ Maintenance is **tedious**
6. ❌ M\:N links can cause **slow retrieval**
7. ❌ Limited **community support**

#### 🔧 Examples:

* `Integrated Data Store (IDS)`, `IDMS`, `Raima Database Manager`, `TurboIMAGE`

---

### 📊 Comparison Table

| Feature        | Relational DB         | Object-Oriented DB      | NoSQL DB                 | Hierarchical DB           | Network DB             |
| -------------- | --------------------- | ----------------------- | ------------------------ | ------------------------- | ---------------------- |
| Structure      | Tables                | Objects                 | Documents, KV, Graph     | Tree (Parent-Child)       | Graph                  |
| Schema         | Fixed (Normalized)    | Flexible, OOP-based     | Schema-free              | Fixed                     | Flexible (but complex) |
| Query Language | SQL                   | OOP-based methods       | Varies (MongoQL, etc.)   | Navigational              | Navigational           |
| Scalability    | Limited (horizontal)  | Moderate                | High (horizontal)        | Low                       | Low                    |
| Complexity     | Medium                | High                    | Low–High                 | Medium                    | High                   |
| Best Use Case  | Structured enterprise | Complex real-world apps | Big Data, Real-Time Apps | Tree-like data (e.g., OS) | Complex relationships  |

---

```
                    A1
                   /  \
                 B1    B2
               / | \   | \
             C1 C2 C3  C4 C5 C6
                 |   \  |  |
                D1   D2 D3 D4

```