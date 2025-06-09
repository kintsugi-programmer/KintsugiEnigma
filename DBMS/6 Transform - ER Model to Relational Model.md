## Transform – ER Model to Relational Model

#### ✅ Overview

1. Both **ER-Model** and **Relational Model** are abstract logical representations of real-world enterprises.
   Because the two models imply similar design principles, we can convert **ER design into Relational design**.
2. Converting a DB representation from an **ER diagram to a table format** is the way we arrive at **Relational DB design** from an ER diagram.

---

### 🔁 ER Diagram Notations to Relations

#### 🔹 1. Strong Entity

* ✅ Becomes an **individual table** with entity name.
* ✅ Attributes become **columns** of the relation.
* ✅ Entity’s **Primary Key (PK)** is used as Relation’s PK.
* ✅ **Foreign Keys (FK)** are added to establish relationships with other relations.

---

#### 🔹 2. Weak Entity

* ✅ A **table is formed** with all the attributes of the entity.
* ✅ PK of its corresponding **Strong Entity is added as FK**.
* ✅ PK of the relation will be a **composite key**: `{FK + Partial Discriminator Key}`.

📌 **Example:**

| Weak Entity Table | Partial Key  | FK from Strong Entity | Composite PK            |
| ----------------- | ------------ | --------------------- | ----------------------- |
| `payment`         | `install_no` | `loan_id`             | `{loan_id, install_no}` |

---

#### 🔹 3. Single-Valued Attributes

* ✅ Represented as **columns directly** in the tables/relations.

---

#### 🔹 4. Composite Attributes

* ✅ Handled by **creating separate attributes** for each component in the original relation.
* ❌ Ignore the composite attribute itself.

📌 **Example:**

* `Address: {street-name, house-no}`
  becomes
  → `address_streetname`, `address_houseno` as new columns
  ❌ No column named just `address`

---

#### 🔹 5. Multivalued Attributes

* ✅ **New table is created** (named as original attribute name).
* ✅ PK of the entity becomes **FK in the new table**.
* ✅ Multivalued attribute is a **separate column**.
* ✅ PK of new table: `{FK + multivalued attribute}`.

📌 **Example:**

* For strong entity `Employee`, `dependent-name` is a multivalued attribute.

```plaintext
Table: dependent-name
Columns: emp-id (FK), dname
PK: {emp-id, dname}
FK: {emp-id}
```

🧾 **Visual Table:**

| Table Name       | Columns           | PK                | FK       |
| ---------------- | ----------------- | ----------------- | -------- |
| `dependent-name` | `emp-id`, `dname` | `{emp-id, dname}` | `emp-id` |

---

#### 🔹 6. Derived Attributes

* ❌ **Not considered** in the tables.

---

#### 🔹 7. Generalisation

##### ✅ Method-1: Separate Table for Higher-Level and Lower-Level Entities

* Create a table for the **higher-level entity set**.
* For each lower-level entity set, create a table including:

  * Attributes of that entity set
  * PK attributes of higher-level entity set

📌 **Example: Banking System (Account → Savings & Current)**

```plaintext
Table 1: account(account-number, balance)
Table 2: savings-account(account-number, interest-rate, daily-withdrawal-limit)
Table 3: current-account(account-number, overdraft-amount, per-transaction-charges)
```

##### ✅ Method-2: No Table for Higher-Level Entity (for disjoint & complete generalisation)

* Only create tables for **lower-level entity sets**.
* Include attributes of higher + lower-level entity in those tables.

📌 **Tables:**

```plaintext
Table 1: savings-account(account-number, balance, interest-rate, daily-withdrawal-limit)
Table 2: current-account(account-number, balance, overdraft-amount, per-transaction-charges)
```

##### ⚠️ Drawbacks of Method-2:

* ❗ If overlapping generalisation is used, **data like balance gets duplicated**.
* ❗ If generalisation is **not complete** (e.g., account is neither savings nor current), it **cannot be represented**.

---

#### 🔹 8. Aggregation

* ✅ Table of the **relationship set** is made.
* ✅ Attributes include:

  * PKs of the participating entity sets
  * PKs of any aggregation entity sets
* ✅ Add any **descriptive attributes** on the relationship.

---

# Example

1. A full **ER Diagram in ASCII**
2. Its **step-by-step transformation to relational schema**
3. Final **SQL code for table creation**
   Everything included!

---

# ✅ Example ER Diagram (in ASCII)

Let’s model a simple **University Database**:

```plaintext
           +-------------+
           |  STUDENT    |
           |-------------|
           | sid (PK)    |
           | name        |
           | address     |
           +-------------+
                 |
                 | Enrolls
                 |
           +-------------+
           | ENROLLMENT  |
           |-------------|
           | sid (FK)    |
           | cid (FK)    |
           | grade       |
           +-------------+
                 |
                 |
                 |
           +-------------+
           |  COURSE     |
           |-------------|
           | cid (PK)    |
           | title       |
           | credits     |
           +-------------+
```

Features:

* `STUDENT` and `COURSE` are strong entities.
* `ENROLLMENT` is a **relationship** with its own attribute `grade`.
* `address` in `STUDENT` is a **composite attribute**: `{street, city, zip}`.
* Let's also assume `STUDENT` has a **multivalued attribute**: `phone`.

---

# 🔁 Step-by-Step ER → Relational Transformation

## 1️⃣ STUDENT (Strong Entity)

* Attributes: `sid (PK), name, address → [street, city, zip]`
* Composite attribute `address` is broken into columns.

```plaintext
Table: STUDENT
Columns: sid (PK), name, street, city, zip
```

## 2️⃣ COURSE (Strong Entity)

```plaintext
Table: COURSE
Columns: cid (PK), title, credits
```

## 3️⃣ ENROLLMENT (Relationship Table)

* Many-to-Many between STUDENT and COURSE
* Add `sid` and `cid` as FKs, and `grade` as descriptive attribute.

```plaintext
Table: ENROLLMENT
Columns: sid (FK), cid (FK), grade
PK: {sid, cid}
```

## 4️⃣ PHONE (Multivalued Attribute)

* One student can have multiple phones → separate table needed.

```plaintext
Table: PHONE
Columns: sid (FK), phone_number
PK: {sid, phone_number}
```

---

# 🧑‍💻 Final SQL Code

```sql
-- 1. STUDENT Table
CREATE TABLE STUDENT (
    sid INT PRIMARY KEY,
    name VARCHAR(100),
    street VARCHAR(100),
    city VARCHAR(50),
    zip VARCHAR(10)
);

-- 2. COURSE Table
CREATE TABLE COURSE (
    cid INT PRIMARY KEY,
    title VARCHAR(100),
    credits INT
);

-- 3. ENROLLMENT Table (relationship)
CREATE TABLE ENROLLMENT (
    sid INT,
    cid INT,
    grade CHAR(2),
    PRIMARY KEY (sid, cid),
    FOREIGN KEY (sid) REFERENCES STUDENT(sid),
    FOREIGN KEY (cid) REFERENCES COURSE(cid)
);

-- 4. PHONE Table (multivalued)
CREATE TABLE PHONE (
    sid INT,
    phone_number VARCHAR(15),
    PRIMARY KEY (sid, phone_number),
    FOREIGN KEY (sid) REFERENCES STUDENT(sid)
);
```

---

# 📦 Summary Table: ER to Relational

| ER Element          | Transformation                | Notes                               |
| ------------------- | ----------------------------- | ----------------------------------- |
| Strong Entity       | Separate table                | PK retained                         |
| Composite Attribute | Flatten into multiple columns | e.g., `address → street, city, zip` |
| Multivalued Attr    | Separate table with FK        | PK = `{entity PK + attribute}`      |
| Relationship        | Table with FKs + attributes   | PK = `{all participating PKs}`      |

---
